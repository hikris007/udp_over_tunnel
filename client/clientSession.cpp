//
// Created by Kris on 2023/4/28.
//

#include "clientSession.h"

ClientSession::ClientSession(hv::EventLoopPtr eventLoopPtr, int listenPort, std::string listenAddress) {
    hv::UdpServer *udpServer = eventLoopPtr == nullptr ? new hv::UdpServer:new hv::UdpServer(eventLoopPtr);

    int fd = udpServer->createsocket(listenPort, listenAddress.c_str());
    if (fd < 0) {
        hloge("failed to create socket, fd:%d", fd);
        return;
    }

    udpServer->onMessage = [this](const hv::SocketChannelPtr &channelPtr, hv::Buffer *buffer) {
        std::string peerAddress = channelPtr->peeraddr();

        // If the mapping does not exist
        // Then create one
        MappingTable::iterator iterator = this->isMappingExist(peerAddress) ?
                                          this->mappingTable.find(peerAddress)
                                                                            :
                                          this->createMapping(peerAddress);

        return iterator->second->write((char*)buffer->data(),buffer->size());
    };
}

ClientSession::ClientSession(int listenPort, std::string listenAddress = "0.0.0.0") {
    ClientSession(nullptr,listenPort,listenAddress);
}

MappingTable::iterator ClientSession::createMapping(const std::string& peerAddress) {
    // TODO:Create mapping
    MappingPtr mappingPtr;

    // Store to mapping table after created
    this->mappingTable.insert(std::pair<std::string,MappingPtr>(peerAddress,mappingPtr));

    MappingTable::iterator iterator = this->mappingTable.find(peerAddress);
    if(iterator == this->mappingTable.end()){
        hloge("failed to create mapping");
    }

    return iterator;
}

bool ClientSession::isMappingExist(const std::string& peerAddress) const {
    return this->mappingTable.find(peerAddress) != this->mappingTable.end();
}