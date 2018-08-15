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

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<sstream>
#include <climits>
using namespace std;

typedef unsigned int digit;
typedef unsigned long long uLong;

/*TODO: 
remove warnings
remove using namespace stt
add C++11 features
move some public functions to private
add comments
make refactoring
add unit tests
x86 and x64 support
*/

const digit Base2 = 1000000000U, BASE = 2147483648U, BaseMod = BASE - 1, BaseLog = 31, KaratsubaMin = 80, Base2Log = 9, Base3Log = Base2Log + 1;
const uLong Base3 = (uLong)Base2*10;
const int sizeOfDigit = sizeof(digit), sizeOfuLong = sizeof(uLong);

class BigInteger {
    vector<digit> num;
    long size;
    bool sign;
    void fromDecimal(uLong*&, long&, digit&);
    void deleteLeadingZeroes();
public:
    long getSize() const {return size;};
    BigInteger();
    BigInteger(string);
    BigInteger(const char*);
    BigInteger(long);
    BigInteger(long long);
    BigInteger(int);
    BigInteger(digit);
    BigInteger(uLong);
    BigInteger(unsigned long);
    BigInteger& operator=(const BigInteger&);
    friend BigInteger abs(const BigInteger&);
    BigInteger operator-() const;
    friend BigInteger operator+(const BigInteger&, const BigInteger&);
    BigInteger operator+=(const BigInteger&);
    BigInteger operator++();
    BigInteger operator++(int);
    friend BigInteger operator-(const BigInteger&, const BigInteger&);
    BigInteger operator-=(const BigInteger&);
    BigInteger operator--();
    BigInteger operator--(int);
    friend BigInteger operator*(const BigInteger&, const BigInteger&);
    BigInteger operator*=(const BigInteger&);
    friend BigInteger operator/(const BigInteger&, const BigInteger&);
    BigInteger operator/=(const BigInteger&);
    friend BigInteger operator%(const BigInteger&, const BigInteger&);
    BigInteger operator%=(const BigInteger&); 
    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator!=(const BigInteger&, const BigInteger&);
    friend bool operator> (const BigInteger&, const BigInteger&);
    friend bool operator< (const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, const BigInteger&); 
    friend bool absCompare(const BigInteger&, const BigInteger&);
    friend istream& operator>>(istream&, BigInteger&);
    friend ostream& operator<<(ostream&, const BigInteger&);
    friend BigInteger operator>>(const BigInteger&, const BigInteger&);
    friend BigInteger operator<<(const BigInteger&, const BigInteger&);     
    friend BigInteger pow(BigInteger, BigInteger);
    friend void bigDivide(const BigInteger&, const BigInteger&, BigInteger&, BigInteger&);
    friend void tinyDivide(const BigInteger&, BigInteger&, digit, digit&);
    friend void tinyMul(const BigInteger&, digit, BigInteger&);
    friend void KaratsubaMul(const BigInteger&, const BigInteger&, BigInteger&);
    friend BigInteger tinyMul1(const BigInteger&, digit);
    friend void bigAdd(const BigInteger&, const BigInteger&, BigInteger&);
    friend void bigSub(const BigInteger&, const BigInteger&, BigInteger&);
    friend BigInteger gcd(const BigInteger&, const BigInteger&);
    friend BigInteger lcm(const BigInteger&, const BigInteger&);
    friend BigInteger fib(const BigInteger&);
    unsigned int toUint() const;
    string toString(int, int);
};

BigInteger log10(BigInteger);

#endif

