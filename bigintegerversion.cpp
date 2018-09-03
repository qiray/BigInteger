#include <iostream>
#include <sstream>

#include "biginteger.h"

BigIntegerVersionInfo& BigIntegerVersionInfo::Instance() {
    static BigIntegerVersionInfo s;
    return s;
}
int BigIntegerVersionInfo::getMajor() {
    return major;
}
int BigIntegerVersionInfo::getMinor() {
    return minor;
}
int BigIntegerVersionInfo::getBuild() {
    return build;
}
std::string BigIntegerVersionInfo::getCompleteInfo() {
    std::ostringstream s;
    s << "BigInteger library version " << major << "." << minor << "." << build << ".\n";
    #ifdef BUILD
        s << "Target " << BUILD << std::endl;
    #endif
    s << "Build at " << __DATE__ << " " << __TIME__ << std::endl << std::endl;
    return s.str();
}
void BigIntegerVersionInfo::printCompleteInfo() {
    std::cout << getCompleteInfo();
}
