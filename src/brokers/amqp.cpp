//
// Created by texlo on 4/23/19.
//

#include "../../include/spectacles.h"
#include "SimpleAmqpClient/SimpleAmqpClient.h"
#include <thread>
#include <amqp.h>

namespace spectacles
{
    namespace brokers
    {
        void AmqpConsumer::connect(std::string uri, std::vector<std::string> events)
        {
            std::thread([events, uri, this]()
                        {
                            connection = AmqpClient::Channel::CreateFromUri(uri);
                            connection->DeclareExchange(group, AmqpClient::Channel::EXCHANGE_TYPE_DIRECT, false, true,
                                                        false);
                            std::string queue;
                            for (auto &event: events)
                            {
                                if (subgroup.empty())
                                {
                                    queue = group + ":" + event;
                                } else
                                {
                                    queue = group + ":" + subgroup + ":" + event;
                                }
                                std::string queueName = connection->DeclareQueue(queue, false, true, false, false);
                                connection->BindQueue(queueName, group);
                                std::string consumer_tag = connection->BasicConsume(queueName, "", false, false, false);
                                AmqpClient::Envelope::ptr_t envelope;
                                while ((envelope = connection->BasicConsumeMessage(consumer_tag)) && envelope)
                                {
                                    connection->BasicAck(envelope);
                                    eventHandler(event, envelope->Message());
                                }
                            };
                        }).detach();
        }

        void AmqpConsumer::onMessage(std::function<void(std::string, AmqpClient::BasicMessage::ptr_t)> handler)
        {
            eventHandler = handler;
        }

        void AmqpProducer::connect(std::string uri)
        {
            connection = AmqpClient::Channel::CreateFromUri(uri);
        }

        void AmqpProducer::publish(std::string event, AmqpClient::BasicMessage::ptr_t message)
        {
            connection->BasicPublish(group, event, message);
        }
    }
}