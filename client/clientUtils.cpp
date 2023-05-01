//
// Created by Kris on 2023/5/1.
//

#include <cstring>

#include "clientUtils.h"
#include "../Utils.h"

int ClientUtils::BuildMappingRequestWithPayload(
        char * result, size_t* resultLen,
        Mapping::OpCode opCode,
        MappingID tempID,
        const char * data, size_t len
    ) {
    *resultLen = MAPPING_REQUEST_HEADER_SIZE + len;
    int errCode = 0;

    // OpCode
    result[0] = opCode;

    // TempID
    errCode = Utils::Uint32ToBytes(tempID,result+1);
    if(errCode != 0)
        return errCode;

    // Data
    if(data != nullptr && len > 0){
        std::memcpy(result+5,data,len);
    }

    return errCode;
}

int ClientUtils::BuildMappingResponseWithPayload(
        char * result, size_t* resultLen,
        Mapping::OpCode opCode,
        MappingID tempID,
        MappingID mappingID,
        const char * data, size_t len
    ) {

    *resultLen = MAPPING_REQUEST_HEADER_SIZE + len;
    int errCode = 0;

    // OpCode
    result[0] = opCode;

    // TempID
    errCode = Utils::Uint32ToBytes(tempID,result+1);
    if(errCode != 0)
        return errCode;

    // MappingID
    errCode = Utils::Uint32ToBytes(mappingID,result+5);

    // Data
    if(data != nullptr && len > 0){
        std::memcpy(result+9,data,len);
    }

    return errCode;
}

int ClientUtils::BuildMappingData(
        char * result, size_t* resultLen,
        Mapping::OpCode opCode,
        MappingID mappingID,
        const char * data, size_t len
) {
    *resultLen = MAPPING_REQUEST_HEADER_SIZE + len;
    int errCode = 0;

    // OpCode
    result[0] = opCode;

    // MappingID
    errCode = Utils::Uint32ToBytes(mappingID,result+1);
    if(errCode != 0)
        return errCode;

    // Data
    if(data != nullptr && len > 0){
        std::memcpy(result+5,data,len);
    }

    return errCode;
}