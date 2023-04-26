//
// Created by Kris on 2023/4/25.
//

#ifndef UDP_OVER_TUNNEL_TEST_H
#include <vector>
#include <memory>
#include "../include/tunnel.h"

class WSTunnel:public Tunnel {
//    void write(const char *, int) override {
//
//    }
};
class BBB {

};

typedef std::vector<std::shared_ptr<Tunnel>> Tunnels;
void main2(){
    Tunnels tunnels;
    std::shared_ptr<WSTunnel> wsTunnel;
    TunnelPtr a = wsTunnel;
    BBB b;

    tunnels.push_back(wsTunnel);
//    tunnels.push_back(&b);
}

#define UDP_OVER_TUNNEL_TEST_H

#endif //UDP_OVER_TUNNEL_TEST_H
