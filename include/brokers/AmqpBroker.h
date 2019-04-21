//
// Created by texlo on 4/21/19.
//

#include "brokers/Broker.h"
#include "amqpcpp.h"

#ifndef SPECTACLES_AMQPBROKER_H
#define SPECTACLES_AMQPBROKER_H

struct AmqpConsumeOptions {
    std::string uri;
    std::string group;
    std::string subgroup;
};

namespace spectacles {
    namespace brokers {
        class AmqpBroker {
        public:
            AMQP::Address address;
            std::string group;
            std::string subgroup;

            void consume(AmqpConsumeOptions opts, std::string event);

            void consume(AmqpConsumeOptions opts, std::vector<std::string>);

            void connect_consumer();

            void connect_producer();

            void onMessage(std::function<void(std::vector<uint8_t>)>);

            void publish(std::string g, std::string sg, char *buffer);

        private:
            AMQP::Connection prod_conn;
            AMQP::Connection consumer_conn;
        };
    }
}

#endif //SPECTACLES_AMQPBROKER_H
