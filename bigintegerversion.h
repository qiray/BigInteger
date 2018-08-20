#ifndef BIGINTEGER_VERSION_HEADER
#define BIGINTEGER_VERSION_HEADER

#include <iostream>
#include <string>
#include <sstream>

//Singleton for version info
class BigIntegerVersionInfo {
public:
    static BigIntegerVersionInfo& Instance() {
        static BigIntegerVersionInfo s;
        return s;
    }
    int getMajor() {
        return major;
    }
    int getMinor() {
        return minor;
    }
    int getBuild() {
        return build;
    }
    std::string getCompleteInfo() {
        std::ostringstream s;
        s << "BigInteger library version " << major << "." << minor << "." << build << 
            ". Build at " << __DATE__ << " " << __TIME__ << std::endl << std::endl;
        return s.str();
    }
    void printCompleteInfo() {
        std::cout << getCompleteInfo();
    }

private:
    int major, minor, build;
    //copies, constructors and destructors are forbidden
    BigIntegerVersionInfo() {
        //init version data:
        major = 1;
        minor = 0;
        build = 0;
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
