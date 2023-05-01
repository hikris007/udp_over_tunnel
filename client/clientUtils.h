//
// Created by Kris on 2023/5/1.
//

#ifndef UDP_OVER_TUNNEL_CLIENTUTILS_H
#define UDP_OVER_TUNNEL_CLIENTUTILS_H

#include "../include/mapping.h"

class ClientUtils {
    static int BuildMappingRequestWithPayload(char*,size_t*,Mapping::OpCode,MappingID ,const char*,size_t);
    static int BuildMappingResponseWithPayload(char*,size_t*,Mapping::OpCode,MappingID ,MappingID ,const char*,size_t);
    static int BuildMappingData(char*,size_t*,Mapping::OpCode,MappingID ,const char*,size_t);
};


#endif //UDP_OVER_TUNNEL_CLIENTUTILS_H
