#include "convertlogic.h"
#include <cstring>
#include <iomanip>

ConvertLogic::ConvertLogic() {}

uint32_t ConvertLogic::floatToBits(float f) {
    uint32_t bits;
    std::memcpy(&bits, &f, sizeof(f)); // 安全复制位模式
    return bits;
}

uint64_t ConvertLogic::doubleToBits(double d) {
    uint64_t bits;
    std::memcpy(&bits, &d, sizeof(d)); // 安全复制位模式
    return bits;
}

ConvertLogic::Float32Parts ConvertLogic::parseFloat32(uint32_t bits) {
    Float32Parts parts;
    parts.sign = (bits >> 31) & 1;
    parts.exponent = (bits >> 23) & 0xFF;
    parts.mantissa = bits & 0x7FFFFF;

    return parts;
}

ConvertLogic::Float64Parts ConvertLogic::parseFloat64(uint64_t bits) {
    Float64Parts parts;
    parts.sign = (bits >> 63) & 1;
    parts.exponent = (bits >> 52) & 0x7FF;
    parts.mantissa = bits & 0xFFFFFFFFFFFFF;

    return parts;
}

// 格式化函数
std::string ConvertLogic::formatBinary32(uint32_t bits) {
    std::string result;
    for (int i = 31; i >= 0; i--) {
        result.append(((bits >> i) & 1) ? "1" : "0");
        if (i == 31) result.append(" ");
        if (i == 23) result.append(" ");
        if (i == 19) result.append(" ");
        if (i == 15) result.append(" ");
        if (i == 11) result.append(" ");
        if (i == 7) result.append(" ");
        if (i == 3) result.append(" ");
    }
    return result;
}

std::string ConvertLogic::formatBinary64(uint64_t bits) {
    std::string result;
    for (int i = 63; i >= 0; i--) {
        result.append(((bits >> i) & 1) ? "1" : "0");
        if (i == 63) result.append(" ");
        if (i == 52) result.append(" ");
    }
    return result;
}

std::string ConvertLogic::formatHex32(uint32_t bits) {
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << bits;
    return ss.str();
}

std::string ConvertLogic::formatHex64(uint64_t bits) {
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(16) << bits;
    return ss.str();
}
