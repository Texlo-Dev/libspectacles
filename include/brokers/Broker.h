//
// Created by texlo on 4/21/19.
//

#include <iostream>
#include <vector>
#include <functional>

#ifndef SPECTACLES_BROKER_H
#define SPECTACLES_BROKER_H

namespace spectacles {
    namespace brokers {
        class Broker {
        public:
            virtual void onMessage(std::function<void(std::vector<uint8_t>)>);

            virtual void publish(std::string g, std::string sg, char *buffer);

            virtual void consume(std::string event);

            virtual void consume(std::vector<std::string> events);
        };
    }
}

#endif //SPECTACLES_BROKER_H
