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

rm -f core
ulimit -c unlimited
cc -std=c11 -g \
    -Wall -Wextra -Wpedantic -Werror \
    -Wfloat-equal -Wlogical-op -Wshadow -Wswitch-default \
    -Wbad-function-cast -Wcast-qual -Waggregate-return \
    -fno-diagnostics-show-option "$1" -o "$executable" \
|| exit $?

shift
"./$executable" "$@"

trap 'test -f core || rm "$executable"' EXIT
