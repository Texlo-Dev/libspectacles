//
// Created by texlo on 4/23/19.
//

#include "spectacles.h"
#include <SimpleAmqpClient/SimpleAmqpClient.h>

#ifndef SPECTACLES_INCLUDE_AMQP_H
#define SPECTACLES_INCLUDE_AMQP_H


class AmqpConsumer : Consumer
{
private:
    AmqpClient::Channel::ptr_t connection;
public:
    std::string amqp_uri;

    explicit AmqpConsumer(std::string uri, std::string g, std::string sg) : Consumer(g, sg)
    {
        amqp_uri = uri;
    }

    void consume(std::string event, std::function<void(std::string)> handler) override;
};

class AmqpProducer : Producer
{
private:
    AmqpClient::Channel::ptr_t connection;
public:
    std::string amqp_uri;

    explicit AmqpProducer(std::string uri, std::string g, std::string sg) : Producer(g, sg)
    {
        amqp_uri = uri;
    }

    void publish(std::string event, std::string data) override;
};


#endif //SPECTACLES_INCLUDE_AMQP_H
