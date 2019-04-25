//
// Created by texlo on 4/21/19.
//

#include "../spectacles.h"
#include "Shard.h"

#ifndef SPECTACLES_MANAGER_H
#define SPECTACLES_MANAGER_H

class Manager
{
private:
    std::string ws_uri;
public:
    int shard_count;
    std::vector<Shard> shards;
};
#endif //SPECTACLES_MANAGER_H
