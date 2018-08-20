# BigInteger
Arbitrary-precision integer library in C++

## Build

For building library run
```bash
make
```

There are some extra flags and arguments:
    notest - build library only (without tests)
    OS=win - build for Windows
    NO_DEBUG=true - disable exceptions log

For example to build library for Windows with tests and without exceptions' logging:

```bash
make OS=win NO_DEBUG=true
```

## Usage

This library provides BigInteger class with simple interface - BigInteger can be used as standard integer types:

```c++
#include <iostream>

int main() {
    BigInteger a(1000), b("340282366920938463463374607431768211456");
    BigInteger c = fact(a);
    std::cout << a + b << std::endl;
    std::cout << c - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << a % b << std::endl;
    return 0;
}
```

For more information see [tests.cpp](https://github.com/qiray/BigInteger/blob/master/tests.cpp) file.

## Testing

To compile and the tests, you need to execute

```
make tests
```

It will produce tests.exe or tests.out file. Run this file. If there is no error there should be the text:

```
Tests ended successfully
```

## Projects using BigInteger

[Xlife](https://sourceforge.net/projects/xlife-cal/) - a popular freeware program for the simulation of cellular automata.

## Contact

You are welcome to open [new issue](https://github.com/qiray/BigInteger/issues/new) if you have any questions or bugs. Please also mention the version of the library you are using and the version of your compiler and operating system.

If your project uses BigInteger library please let me know and leave a link to this repo in your project.

## License

The library is licensed under the GNU GPL 3. For more information see the [LICENSE](https://github.com/qiray/BigInteger/blob/master/LICENSE) file.
