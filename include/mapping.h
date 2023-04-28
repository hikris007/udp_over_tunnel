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
#define INVALID_MAPPING_ID 0;

class Mapping {
public:
    enum OpCode {
        OP_CODE_ESTABLISHED = 0x1,
        OP_CODE_DATA = 0x2,
        OP_CODE_CLOSE = 0x3
    };
    enum State {
        STATE_CLOSED = 0x0,
        STATE_WAITING_TO_BE_ESTABLISHED = 0x1,
        STATE_ESTABLISHED = 0x2,
        STATE_CLOSE_WAIT = 0x3,
        STATE_CLOSING = 0x4
    };

    std::function<void()> onReady;
    std::function<void(const std::string&)> onRead;
    std::function<void()> onClose;

    int write(const char*,size_t);
    void close();
protected:
private:
};

typedef std::shared_ptr<Mapping> MappingPtr;

#endif //UDP_OVER_TUNNEL_MAPPING_H
