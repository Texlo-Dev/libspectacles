//
// Created by texlo on 4/21/19.
//

#include "amqpcpp.h"
#include "brokers/Broker.h"

namespace spectacles
{
    namespace brokers
    {
        void Broker::consume(std::string event) {
            std::cout << "No consume implementation detected.";
        }

        void Broker::consume(std::vector<std::string> events) {

            std::cout << "No consume implementation detected.";
        }

        void Broker::publish(std::string g, std::string sg, char *buffer) {
            std::cout << "No publish implementation found.";
        }

        void Broker::onMessage(std::function<void(std::vector<uint8_t>)>) {}
    }
}