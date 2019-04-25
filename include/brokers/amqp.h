//
// Created by texlo on 4/23/19.
//

#include <string.h>

#include "SimpleAmqpClient/SimpleAmqpClient.h"
#include "../spectacles.h"

#ifndef SPECTACLES_INCLUDE_AMQP_H
#define SPECTACLES_INCLUDE_AMQP_H

namespace spectacles
{
    namespace brokers
    {
        class AmqpConsumer : Consumer
        {
        private:
            AmqpClient::Channel::ptr_t connection;
            std::function<void(std::string, AmqpClient::BasicMessage::ptr_t)> eventHandler;
        public:
            explicit AmqpConsumer(std::string g, std::string sg) : Consumer(g, sg)
            {}

            void connect(std::string uri, std::vector<std::string> events) override;

            void onMessage(std::function<void(std::string, AmqpClient::BasicMessage::ptr_t)> handler);
        };

        class AmqpProducer : Producer
        {
        private:
            AmqpClient::Channel::ptr_t connection;
        public:
            explicit AmqpProducer(std::string g, std::string sg) : Producer(g, sg)
            {}

            void connect(std::string uri) override;

            void publish(std::string event, AmqpClient::BasicMessage::ptr_t message);
        };
    }
}


#endif //SPECTACLES_INCLUDE_AMQP_H
