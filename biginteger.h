/*
    Copyright (C) 2012-2013, 2018 Yaroslav Zotov.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BIGINTEGER_H
#define BIGINTEGER_H


#include<string>
#include<vector>
#include<iostream>
#include "bigintegerexception.h"

typedef unsigned int digit;
typedef unsigned long long uLong;

/*TODO: 
add C++11 features
add comments
make refactoring
x86 and x64 support
*/

const digit Base2 = 1000000000U, BASE = 2147483648U, BaseMod = BASE - 1, BaseLog = 31, KaratsubaMin = 80, Base2Log = 9, Base3Log = Base2Log + 1;
const uLong Base3 = (uLong)Base2*10;
const int sizeOfDigit = sizeof(digit), sizeOfuLong = sizeof(uLong);

class BigInteger {
public:
    BigInteger();
    BigInteger(std::string);
    BigInteger(const char*);
    BigInteger(long);
    BigInteger(long long);
    BigInteger(int);
    BigInteger(digit);
    BigInteger(uLong);
    BigInteger(unsigned long);

    long getSize() const {return size;};

    BigInteger& operator=(const BigInteger&);

    BigInteger operator-() const;
    BigInteger operator+() const;
    
    BigInteger operator++();
    BigInteger operator++(int);
    BigInteger operator--();
    BigInteger operator--(int);

    friend BigInteger operator+(const BigInteger&, const BigInteger&);
    friend BigInteger operator-(const BigInteger&, const BigInteger&);
    friend BigInteger operator*(const BigInteger&, const BigInteger&);
    friend BigInteger operator/(const BigInteger&, const BigInteger&);
    friend BigInteger operator%(const BigInteger&, const BigInteger&);
    friend BigInteger operator>>(const BigInteger&, const BigInteger&);
    friend BigInteger operator<<(const BigInteger&, const BigInteger&);

    BigInteger operator+=(const BigInteger&);
    BigInteger operator-=(const BigInteger&);
    BigInteger operator*=(const BigInteger&);
    BigInteger operator/=(const BigInteger&);
    BigInteger operator%=(const BigInteger&);

    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator!=(const BigInteger&, const BigInteger&);
    friend bool operator>(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, const BigInteger&);

    friend std::istream& operator>>(std::istream&, BigInteger&);
    friend std::ostream& operator<<(std::ostream&, const BigInteger&);

    friend BigInteger pow(BigInteger, BigInteger);
    friend BigInteger gcd(const BigInteger&, const BigInteger&);
    friend BigInteger lcm(const BigInteger&, const BigInteger&);
    friend BigInteger fib(const BigInteger&);
    friend BigInteger fact(const BigInteger&);
    friend BigInteger abs(const BigInteger&);
    friend BigInteger log10(BigInteger);

    std::string toString(int, int);
    unsigned int toUint() const;
private:
    std::vector<digit> num;
    long size;
    bool sign;
    void fromDecimal(uLong*&, long&, digit&);
    void deleteLeadingZeroes();

    friend bool absCompare(const BigInteger&, const BigInteger&);
    friend void bigDivide(const BigInteger&, const BigInteger&, BigInteger&, BigInteger&);
    friend void tinyDivide(const BigInteger&, BigInteger&, digit, digit&);
    friend void tinyMul(const BigInteger&, digit, BigInteger&);
    friend void KaratsubaMul(const BigInteger&, const BigInteger&, BigInteger&);
    friend BigInteger tinyMul1(const BigInteger&, digit);
    friend void bigAdd(const BigInteger&, const BigInteger&, BigInteger&);
    friend void bigSub(const BigInteger&, const BigInteger&, BigInteger&);
};

#endif

