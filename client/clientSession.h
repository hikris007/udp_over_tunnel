//
// Created by Kris on 2023/4/28.
//

#ifndef UDP_OVER_TUNNEL_CLIENTSESSION_H
#define UDP_OVER_TUNNEL_CLIENTSESSION_H

#include <string>
#include <unordered_map>

#include "hv/UdpServer.h"

#include "../include/session.h"
#include "../include/mapping.h"

typedef std::unordered_map<std::string, MappingPtr> MappingTable;

class ClientSession : public Session {
public:
    ClientSession(hv::EventLoopPtr, int listenPort, std::string);
    ClientSession(int listenPort,std::string);

protected:
private:
    std::string listenAddress = "";
    int listenPort = -1;
    std::shared_ptr<hv::UdpServer> udpServerPtr;

    MappingTable mappingTable;

    MappingTable::iterator createMapping(const std::string&);
    bool isMappingExist(const std::string&) const;
};

#endif //UDP_OVER_TUNNEL_CLIENTSESSION_H
