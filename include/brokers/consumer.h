//
// Created by texlo on 4/23/19.
//

#ifndef SPECTACLES_CONSUMER_H
#define SPECTACLES_CONSUMER_H


class Consumer
{
public:
    std::string group;
    std::string subgroup;
    std::set<std::string> events;

    explicit Consumer(std::string g, std::string sg)
    {
        group = g;
        subgroup = sg;
    }

    virtual void connect();

    virtual void consume(std::string event, std::function<void(std::string)> handler);
};


#endif //SPECTACLES_CONSUMER_H
