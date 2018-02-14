#!/bin/sh

if [ -z "$1" ]; then
    echo "Usage: $0 file.c" 1>&2
    exit 1
fi

executable=$(basename "$1" '.c')

if [ "$1" = "$executable" ]; then
    echo "Usage: $0 file.c" 1>&2
    exit 2
fi

cc -std=c11 -g -Og \
    -Wall -Wextra -Wpedantic -Werror \
    -fno-diagnostics-show-option "$1" -o "$executable" \
|| exit $?

"./$executable"

trap 'rm "$executable"' EXIT
