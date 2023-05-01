//
// Created by Kris on 2023/4/25.
//

#ifndef UDP_OVER_TUNNEL_TRANSPORT_H
#define UDP_OVER_TUNNEL_TRANSPORT_H

#include <vector>
#include <memory>
#include "hv/hlog.h"

#include "../include/tunnel.h"

class Transport {
public:
    enum State {
        STATE_CLOSED = 0x0,
        STATE_ESTABLISHING = 0x1,
        STATE_ESTABLISHED = 0x2,
        STATE_CLOSE_WAIT = 0x3,
        STATE_CLOSING = 0x4
    };

    std::function<void()> onReady;
    std::function<void(const std::string&)> onRead;
    std::function<void()> onClose;

    int write(const char*,size_t);
    void close();
protected:
    std::vector<TunnelPtr> m_tunnels;
private:
    std::vector<TunnelPtr>::iterator currentTunnelIterator;

    TunnelPtr pickTunnel();
};

#endif //UDP_OVER_TUNNEL_TRANSPORT_H
