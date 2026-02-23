#ifndef CONVERTLOGIC_H
#define CONVERTLOGIC_H

#include <cstdint>
#include <string>
class ConvertLogic
{
public:
    struct Float32Parts {
        bool sign;
        uint8_t exponent;
        uint32_t mantissa;
        std::string type;
        int32_t actualExponent;
    };

    struct Float64Parts {
        bool sign;
        uint16_t exponent;
        uint64_t mantissa;
        std::string type;
        int64_t actualExponent;
    };

    ConvertLogic();

    // 转换函数
    static uint32_t floatToBits(float f);
    static uint64_t doubleToBits(double d);

    // 解析函数
    static Float32Parts parseFloat32(uint32_t bits);
    static Float64Parts parseFloat64(uint64_t bits);

    // 格式化函数
    static std::string formatBinary32(uint32_t bits);
    static std::string formatBinary64(uint64_t bits);
    static std::string formatHex32(uint32_t bits);
    static std::string formatHex64(uint64_t bits);
};

#endif // CONVERTLOGIC_H
