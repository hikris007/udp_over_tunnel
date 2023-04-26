//
// Created by Kris on 2023/4/25.
//

#include "include/transport.h"

/**
 * Polling
 */
TunnelPtr Transport::pickTunnel() {
    std::vector<TunnelPtr>::iterator iterator;

    // If there's no tunnels then return a nullptr
    if(this->m_tunnels.empty()){
        hlogw("transport error: there is no tunnel.");
        return nullptr;
    }

    // If the currentTunnelIterator was null(default state)
    // Then return the first tunnel

    if(this->currentTunnelIterator == this->m_tunnels.end()){
        iterator = this->m_tunnels.begin();
    }

    // After return the iterator then move iterator to next
    return *iterator++;
}

int Transport::write(const char * data, int len) {
    TunnelPtr tunnelPtr = this->pickTunnel();
    if(tunnelPtr == nullptr){
        hloge("transport error: tunnel is nullptr");
        return 0;
    }

    return tunnelPtr->write(data,len);
}