//
// Created by Kris on 2023/4/25.
//

#ifndef UDP_OVER_TUNNEL_WSTUNNEL_H
#define UDP_OVER_TUNNEL_WSTUNNEL_H

#include "hv/WebSocketChannel.h"

#include "tunnel.h"

class WsTunnel : public Tunnel {
public:
    virtual int write(const char *, size_t) = 0;
    virtual State state() const = 0;
private:
    State m_state;
    WebSocketChannelPtr webSocketChannel;
};

#endif //UDP_OVER_TUNNEL_WSTUNNEL_H
