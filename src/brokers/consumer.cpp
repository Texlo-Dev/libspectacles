//
// Created by texlo on 4/24/19.
//

#include "../../include/spectacles.h"

void Consumer::connect(std::string uri, std::set<std::string> events)
{
    fprintf(stderr, "Abstract class base detected, doing nothing");
}

void Consumer::onMessage(std::function<void(std::string)> handler)
{
    fprintf(stderr, "Abstract class base detected, doing nothing");
}
