//
// Created by Kris on 2023/5/1.
//

#ifndef UDP_OVER_TUNNEL_UTILS_H
#define UDP_OVER_TUNNEL_UTILS_H

#include "memory"

class Utils {
public:
    static int Uint32ToBytes(uint32_t,char*);
    static int BytesToUint32(const char*,uint32_t*);
};


#endif //UDP_OVER_TUNNEL_UTILS_H
