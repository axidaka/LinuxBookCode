#!/bin/sh

set -x

BUILD_TYPE=${BUILD_TYPE:-release}

cmake \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DMUDUO_PATH=../../build/${BUILD_TYPE}-install \
&& make $*
