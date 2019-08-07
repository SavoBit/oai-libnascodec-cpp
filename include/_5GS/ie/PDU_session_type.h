#pragma once

#include <iostream>
#include <vector>
#include <information_element.h>

namespace _5GS
{

namespace IE
{

class PDU_session_type : public InformationElement
{

public:
    // TS 24.501- 9.11.4.11

    static const std::string name;

    enum class Value : uint8_t
    {
        IPv4 = 1,
        IPv6,
        IPv4v6,
        Unstructured,
        Ethernet,
        reserved = 7
    };

    PDU_session_type();
    PDU_session_type(const Value value);

    void set(Value id);
    Value get() const;

    std::string to_string() const;

    static std::string value_to_string(const Value value);

protected:
    int code_TV(std::vector<uint8_t> &data, const uint8_t iei) const;
    int decode_TV(const std::vector<uint8_t> &data, const uint8_t iei);

private:
    Value value;
};

} // namespace IE

} // namespace _5GS
