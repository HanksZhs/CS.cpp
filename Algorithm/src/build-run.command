#! /bin/bash

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd ${CUR_DIR}

on_error_msg() {
    local retv=$?
    if [ $retv -gt 0 ]; then
        echo $1
        exit 1
    fi
}

cd ../


if [ "$1" = "r" ]; then
    # check build dir.
    if [ -d "build" ] ; then
        echo "removing old build dir..."
        rm -rf ./build
        echo "done"
    fi

    echo "create build dir..."
    mkdir build

    cd ./build

    cmake ../
    on_error_msg "cmake failed"
    echo "cmake finish"

    cd ../
fi


if [ -d "build" ]; then
    cd build
else
    mkdir "build"
    cd build
fi

make 

on_error_msg "make failed"

echo "make finish"

cd ../../build/

./algorithm/bin/algorithm

exit 0;


