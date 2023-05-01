//
// Created by Kris on 2023/4/26.
//

#ifndef UDP_OVER_TUNNEL_MAPPING_H
#define UDP_OVER_TUNNEL_MAPPING_H

#include <functional>
#include <memory>
#include <string>

/**
 * Package struct
 * OpCode|MappingID|Data(Optional)
 *
 * OpCode:
 *      0x1 -> Establish Mapping
 *      0x2 -> Data
 *      0x3 -> Close Mapping
 */

typedef uint32_t MappingID;

#define INVALID_MAPPING_ID 0

class Mapping {
public:
    enum OpCode: uint8_t {
        OP_CODE_REQUEST = 0x1,
        OP_CODE_RESPONSE = 0x2,
        OP_CODE_DATA = 0x3,
        OP_CODE_CLOSE = 0x4
    };
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

    virtual int write(const char*,size_t);
    virtual int close();
protected:
private:
};

typedef std::shared_ptr<Mapping> MappingPtr;

#define MAPPING_ID_SIZE sizeof(MappingID)
#define MAPPING_REQUEST_HEADER_SIZE (sizeof(Mapping::OpCode) + MAPPING_ID_SIZE * 2)
#define MAPPING_RESPONSE_HEADER_SIZE (sizeof(Mapping::OpCode) + MAPPING_ID_SIZE * 2)
#define MAPPING_HEADER_SIZE (sizeof(Mapping::OpCode) + MAPPING_ID_SIZE)

#endif //UDP_OVER_TUNNEL_MAPPING_H
