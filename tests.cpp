
#include <iostream>
#include <assert.h>
#include "biginteger.h"

#define test(EXPRESSION, MESSAGE)\
    if (!(EXPRESSION)) {\
        std::cerr << MESSAGE << ": " << "Test '" << #EXPRESSION << "' failed in file " << __FILE__ << " line " << __LINE__ << std::endl;\
        errorCount++;\
    }

int main() {
    int errorCount = 0;
    try {
        BigInteger a(1), b(2), c(3), num;
        BigInteger a1("1"), fromString("21474836471234567890"), fromStdString(std::string("21474836471234567890"));
        BigInteger fromString1("-21474836471234567890"), fromStdString1(std::string("-21474836471234567890"));
        BigInteger fromLong(-2147483648l), fromLongLong(2147483648ll), fromUnsignedLong(2147483648ul);
        BigInteger fromString2("2147483648");

        test(a == a1, "1st equality test failed");
        test(fromString == fromStdString, "2st equality test failed");
        test(fromString == "21474836471234567890", "3rd equality test failed");
        test(a == 1, "Integer equality test failed");
        test(a == "1", "String equality test failed");
        test(fromUnsignedLong == fromLongLong, "Equality test failed");
        test(fromString2 == fromLongLong, "Equality test failed");
        test(fromStdString1 == fromStdString1, "Equality test failed");
        test(num == 0, "Equality test failed");

        test(a != b, "1st non-equality test failed");
        test(a != 100, "2nd non-equality test failed");
        test(fromString != fromString1, "3rd non-equality test failed");
        test(fromStdString != "21474836471234567891", "4th non-equality test failed");
        test(fromLongLong != fromLong, "Non-equality test failed");
        test(num != fromLong, "Non-equality test failed");

        test(a < b, "Less than test failed");
        test(b < c, "Less than test failed");
        test(fromStdString1 < fromString, "Less than test failed");
        test(fromLong < fromString2, "Less than test failed");
        test(a < fromLongLong, "Less than test failed");
        test(num < a, "Less than test failed");

        test(c > a, "Greater than test failed");
        test(b > a, "Greater than test failed");
        test(fromString > fromString2, "Greater than test failed");
        test(fromString2 > fromLong, "Greater than test failed");
        test(fromLongLong > c, "Greater than test failed");

        test(fromLongLong >= c, "Greater or equal test failed");
        test(fromLongLong >= fromUnsignedLong, "Greater or equal test failed");
        test(fromString >= fromStdString, "Greater or equal test failed");
        test(fromString1 >= fromStdString1, "Greater or equal test failed");
        test(c >= c, "Greater or equal test failed");

        test(b <= c, "Less or equal test failed");
        test(fromString2 <= fromLongLong, "Less or equal test failed");
        test(fromString1 <= fromStdString, "Less or equal test failed");
        test(fromStdString1 <= fromString, "Less or equal test failed");
        test(a <= a, "Less or equal test failed");

        test(a + b == c, "Sum test failed");
        test(a1 + a == b, "Sum test failed");
        test(fromString1 + fromString == num, "Sum test failed");
        test(fromString1 + num == fromStdString1, "Sum test failed");
        test(fromString + fromStdString == "42949672942469135780", "Sum test failed");
        test(fromString + fromLong + fromStdString + fromLongLong == "42949672942469135780", "Sum test failed");

        //+ - * / % 
        // ++ --
        // + -
        //>> <<


        //gcd, lcm, fib, abs, pow, fact, log10
        //tostring, toUint()
    } catch(...) {
        std::cerr << "Some unhandled errors " << std::endl;
        errorCount = 1;
    }
    if (errorCount > 0) 
        std::cerr << "Tests ended with " << errorCount << (errorCount > 1 ? " errors" : " error") << std::endl;
    else
        std::cout << "Tests ended successfully" << std:: endl;
    return errorCount;
}
