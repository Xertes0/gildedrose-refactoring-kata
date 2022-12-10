#!/bin/bash

: "${BUILD_DIR:=build}"

if [[ ! -d "$BUILD_DIR" ]]; then
    mkdir -p "$BUILD_DIR"
fi

cd "$BUILD_DIR"
cmake .. -DCMAKE_BUILD_TYPE:BOOL=Release && cmake --build . --parallel $(($(nproc)+1)) && ctest --output-on-failure
