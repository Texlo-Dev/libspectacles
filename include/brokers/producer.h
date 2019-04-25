//
// Created by texlo on 4/23/19.
//

#ifndef SPECTACLES_PRODUCER_H
#define SPECTACLES_PRODUCER_H


class Producer
{
public:
    std::string group;
    std::string subgroup;

    explicit Producer(std::string g, std::string sg)
    {
        group = g;
        subgroup = sg;
    }

    virtual void connect(std::string uri);
    virtual void publish(std::string event, std::string payload);
};


#endif //SPECTACLES_PRODUCER_H
