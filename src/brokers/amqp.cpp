//
// Created by texlo on 4/23/19.
//

#include "spectacles.h"
#include <thread>

void AmqpConsumer::consume(std::string event, std::function<void(std::string)> handler)
{
    if (connection == nullptr)
    {
        connection = AmqpClient::Channel::Create(amqp_uri);
    };

    connection->DeclareExchange(group, AmqpClient::Channel::EXCHANGE_TYPE_DIRECT, false, true, false);
    std::string queue;
    if (subgroup.empty())
    {
        queue = group + ":" + event;
    } else
    {
        queue = group + ":" + subgroup + ":" + event;
    }
    connection->BindQueue(queue, group);
    std::string queueName = connection->DeclareQueue(queue, false, true, false);
    std::string consumer_tag = connection->BasicConsume(queueName, "", false, false, false);
}

void AmqpProducer::publish(std::string event, std::string payload)
{

}