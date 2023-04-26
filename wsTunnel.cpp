//
// Created by Kris on 2023/4/25.
//

#include "include/wsTunnel.h"

int WsTunnel::write(const char * data, int len) {
    return this->webSocketChannel->write(data,len);
}

Tunnel::State WsTunnel::state() const {
    return this->m_state;
}