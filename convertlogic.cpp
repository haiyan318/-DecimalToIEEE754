#include "convertlogic.h"
#include <cstring>
#include <iomanip>
#include <sstream>

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
        if (i == 48) result.append(" ");
        if (i == 44) result.append(" ");
        if (i == 40) result.append(" ");
        if (i == 36) result.append(" ");
        if (i == 32) result.append(" ");
        if (i == 28) result.append(" ");
        if (i == 24) result.append(" ");
        if (i == 20) result.append(" ");
        if (i == 16) result.append(" ");
        if (i == 12) result.append(" ");
        if (i == 8) result.append(" ");
        if (i == 4) result.append(" ");
    }
    return result;
}

std::string ConvertLogic::formatHex32(uint32_t bits) {
    std::stringstream ss;
    // ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << bits;
    // return ss.str();
    // 先生成8位补0的纯十六进制字符串（无0x、无分隔）
    ss << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << bits;
    std::string hexStr = ss.str();
    std::string result = "0x"; // 前缀

    // 每两位插入一个空格，末尾不加空格
    for (int i = 0; i < hexStr.size(); i += 2) {
        result += hexStr.substr(i, 2);
        // 最后一组（7-8位）后不加分隔符
        if (i != hexStr.size() - 2) {
            result += " ";
        }
    }
    return result;
}

std::string ConvertLogic::formatHex64(uint64_t bits) {
    std::stringstream ss;
    // ss << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(16) << bits;
    // return ss.str();
    // 先生成16位补0的纯十六进制字符串（无0x、无分隔）
    ss << std::hex << std::uppercase << std::setfill('0') << std::setw(16) << bits;
    std::string hexStr = ss.str();
    std::string result = "0x"; // 前缀

    // 每两位插入一个空格，末尾不加空格
    for (int i = 0; i < hexStr.size(); i += 2) {
        result += hexStr.substr(i, 2);
        // 最后一组（15-16位）后不加分隔符
        if (i != hexStr.size() - 2) {
            result += " ";
        }
    }
    return result;
}
