#!/bin/bash

function build {
    [[ $1 == win ]] && OS=$(bash check_os.sh) || OS=win
    make clean && make release OS=$OS
    make clean && make release PLATFORM=x86 OS=$OS
    make clean && make release PLATFORM=x86 STD=c++03 OS=$OS
    make clean && make release STD=c++03 OS=$OS
}

make allclean
build
build win
