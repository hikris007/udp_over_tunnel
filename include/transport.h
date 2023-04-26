//
// Created by Kris on 2023/4/25.
//

#ifndef UDP_OVER_TUNNEL_TRANSPORT_H
#include <vector>
#include <memory>
#include "hv/hlog.h"

#include "../include/tunnel.h"

class Transport {
public:
    enum State {
        STATE_CLOSED = 0x0,
        STATE_ESTABLISHED = 0x1,
        STATE_CLOSE_WAIT = 0x2,
        STATE_CLOSING = 0x3
    };

    std::function<void()> onReady;
    std::function<void(const std::string&)> onRead;
    std::function<void()> onClose;

    int write(const char*,int);
    void close();
protected:
    std::vector<TunnelPtr> m_tunnels;
private:
    std::vector<TunnelPtr>::iterator currentTunnelIterator;

    TunnelPtr pickTunnel();
};

#define UDP_OVER_TUNNEL_TRANSPORT_H

#endif //UDP_OVER_TUNNEL_TRANSPORT_H
