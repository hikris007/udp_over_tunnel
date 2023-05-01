//
// Created by Kris on 2023/4/25.
//

#ifndef UDP_OVER_TUNNEL_TUNNEL_H
#define UDP_OVER_TUNNEL_TUNNEL_H

#include <functional>
#include <memory>
#include <string>

/**
 * CLOSED That means the connection is not connected or in the default state
 * ESTABLISHED That means the connection is ready to send or receive data.
 * CLOSING That means the peer has no more data to send, but self still has data that needs to be sent. After all data has been sent, the connection will close.
 * CLOSE_WAIT That means no more data to send also can't write data,waiting for peer close
 */

class Tunnel {

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

    virtual int write(const char*,size_t) = 0;
    virtual void close() = 0;
    virtual enum State state() const = 0;

private:
};

typedef std::shared_ptr<Tunnel> TunnelPtr;


#endif //UDP_OVER_TUNNEL_TUNNEL_H
