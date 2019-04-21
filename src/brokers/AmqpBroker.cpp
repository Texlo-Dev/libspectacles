//
// Created by texlo on 4/21/19.
//

#include "amqpcpp.h"
#include "amqpcpp/libev.h"
#include "brokers/AmqpBroker.h"

namespace spectacles
{
    namespace brokers
    {

        void AmqpBroker::consume(AmqpConsumeOptions opts, std::vector<std::string> events) {
            for (auto const &event: events) {
                consume(opts, event);
            }
        }

        void AmqpBroker::consume(AmqpConsumeOptions opts, std::string event) {
            auto *loop = EV_DEFAULT;
            AMQP::LibEvHandler handler(loop);
            AMQP::TcpConnection connection(&handler, AMQP::Address(opts.uri));
            AMQP::TcpChannel channel(&connection);
            std::string q;
            if (opts.subgroup.length() < 1) {
                q = opts.group + ":" + event;
            } else {
                q = opts.group + ":" + opts.subgroup + ":" + event;
            }
            channel.declareExchange(q, AMQP::direct, AMQP::durable);
            channel.bindQueue(opts.group, q, "");
            channel.declareQueue(q, AMQP::durable);
            channel.consume(q, "");
        }

        void AmqpBroker::publish(std::string g, std::string sg, char *buffer) {

        }

        void AmqpBroker::connect_consumer() {

        }

        void AmqpBroker::connect_producer() {

        }
    }
}

