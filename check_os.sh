#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    echo linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo darwin
elif [[ "$OSTYPE" == "cygwin" ]]; then
    echo cygwin
elif [[ "$OSTYPE" == "msys" ]]; then
    echo msys
elif [[ "$OSTYPE" == "win32" ]]; then
    echo win
elif [[ "$OSTYPE" == "freebsd"* ]]; then
    echo freebsd
else
    echo unknown
fi
