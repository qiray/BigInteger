#ifndef BIGINTEGER_VERSION_HEADER
#define BIGINTEGER_VERSION_HEADER

#include <iostream>
#include <string>
#include <sstream>

//Singleton for version info
class BigIntegerVersionInfo {
public:
    static BigIntegerVersionInfo& Instance();
    int getMajor();
    int getMinor();
    int getBuild();
    std::string getCompleteInfo();
    void printCompleteInfo();

private:
    int major, minor, build;
    //copies, constructors and destructors are forbidden
    BigIntegerVersionInfo() {
        //init version data:
        major = 1;
        minor = 0;
        build = 1;
    }
    ~BigIntegerVersionInfo() {}
#if __cplusplus > 201100
    BigIntegerVersionInfo(BigIntegerVersionInfo const&) = delete;
    BigIntegerVersionInfo& operator= (BigIntegerVersionInfo const&) = delete;
#else
    BigIntegerVersionInfo(BigIntegerVersionInfo const&);
    BigIntegerVersionInfo& operator= (BigIntegerVersionInfo const&);
#endif
};

#endif
