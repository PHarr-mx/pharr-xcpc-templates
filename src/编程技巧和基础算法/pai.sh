#!/bin/bash
while true; do
    ./data > data.in
    ./std <data.in >std.out
    ./code <data.in >code.out
    if diff std.out code.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        exit 0
    fi
done