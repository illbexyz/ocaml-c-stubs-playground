#!/bin/bash

# Directory of this file
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Tell the linked where to find the playground library
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DIR/libplayground/build
DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$DIR/libplayground/build
export LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH

exec_arg () {
    if [ "$1" == "test" ]; then
        echo "Test:"
        dune runtest
        echo ""
    fi;
    if [ "$1" == "main" ]; then
        echo "Main:"
        dune exec src/main.exe
        echo ""
    fi;
}

echo ""

if [ "$1" = "" ]; then
    dune exec src/main.exe
else
    exec_arg $1
    exec_arg $2
fi;