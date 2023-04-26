//
// Created by Kris on 2023/4/26.
//

#ifndef UDP_OVER_TUNNEL_MAPPING_H
#include <functional>
#include <string>

class Mapping {
public:
    enum State {
        CLOSED = 0x00,
        WAITING_TO_BE_ESTABLISHED = 0x1,
        ESTABLISHED = 0x2,
        CLOSE_WAIT = 0x3,
        CLOSING = 0x4
    };

    std::function<void()> onReady;
    std::function<void(const std::string&)> onRead;
    std::function<void()> onClose;

    int write(const char*,int);
    void close();
protected:
private:
};

#define UDP_OVER_TUNNEL_MAPPING_H

#endif //UDP_OVER_TUNNEL_MAPPING_H
