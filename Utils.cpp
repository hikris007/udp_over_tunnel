//
// Created by Kris on 2023/5/1.
//

#include "Utils.h"

int Utils::BytesToUint32(const char * bytes, uint32_t *result) {
    if(result == nullptr)
        return -1;

    *result = 0;
    *result += (uint32_t)((bytes[0] & 0xFF) << 24);
    *result += (uint32_t)((bytes[1] & 0xFF) << 16);
    *result += (uint32_t)((bytes[2] & 0xFF) << 8);
    *result += (uint32_t)(bytes[3] & 0xFF);

    return 0;
}

int Utils::Uint32ToBytes(uint32_t number, char *bytes) {
    if(bytes == nullptr)
        return -1;

    bytes[0] = (char) (number >> 24 & 0xFF);
    bytes[1] = (char) (number >> 16 & 0xFF);
    bytes[2] = (char) (number >> 8 & 0xFF);
    bytes[3] = (char) (number & 0xFF);

    return 0;
}