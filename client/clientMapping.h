//
// Created by Kris on 2023/4/29.
//

#ifndef UDP_OVER_TUNNEL_CLIENTMAPPING_H
#define UDP_OVER_TUNNEL_CLIENTMAPPING_H

#include "../include/mapping.h"

class ClientMapping : public Mapping {
public:
    int write(const char*,size_t);
    int close();

protected:
private:
    std::string peerAddress;

    std::function<int (const char*,size_t)> handleWrite;
};

#endif //UDP_OVER_TUNNEL_CLIENTMAPPING_H
