
#ifndef BIGINTEGER_EXCEPTION_HEADER
#define BIGINTEGER_EXCEPTION_HEADER

#include <exception>
#include <string>
#include <sstream>
#include <iostream>

// Exception class for bignumbers
class BigIntegerException : public std::exception {
public:
    // Log error before throwing
    void LogError(bool show) {
        if (show)
            std::cerr << report << std::endl;
    }

    // Construct an a exception
    BigIntegerException(const char* message, const char* file, int line)
        : file(file)
        , line(line)
        , message(message) {
        std::ostringstream outputStream;
        std::string messageString = message;

        if (!messageString.empty()) {
            outputStream << messageString;
        } else {
            outputStream << "Unknown exception";
        }
        outputStream << " in file '" << file << "' line " << line;
        report = outputStream.str();

        LogError(show);
    }

    // The assertion message
    virtual const char* what() const throw() {
        return report.c_str();
    }

    // Source file
    const char* File() const throw() {
        return file;
    }

    // Source line
    int Line() const throw() {
        return line;
    }

    // Description of failure
    const char* Message() const throw() {
        return message;
    }
private:
    const char* message;
    const char* file;
    int line;
    std::string report;
    static const bool show = true; //TODO: use #define or something similar
};

#endif
