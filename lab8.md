Lab 8
=====

In this lab, you will expose the functionality of [Lab 6][1] both as an
interpreter and as an interactive debugger for the byte command language
of [Lab 2][2].

*Note*: Unlike Lab 6, you are welcome to use the solutions posted for
previous labs at no penalty.

Your program should accept any number of command line arguments. Each
argument should be the name of a file containing byte
instructions. Execute these instructions in order, and print the value
of the byte at the end.

Use the C Standard File I/O functions from `<stdio.h>` to read each file.

In addition to the command-line arguments, your program should also
accept the following command-line options:

| Option | Meaning                                           |
| -------| ------------------------------------------------- |
| -v     | verbose - print each byte command and its result  |
| -d     | debug - Accept debug commands from standard input |

Use `getopt()` to parse the command-line options, as described in Chapter
2 of [UNIX Systems Programming for SVR4][3].

*Note*: In order to use `getopt()` you will need to:
1. Include `<unistd.h>`
2. Modify `CFLAGS` to include `-D_POSIX_C_SOURCE=200801L`

[1]: https://github.com/ProfAvery/cpsc223c/blob/master/lab6/Makefile
[2]: https://github.com/ProfAvery/cpsc223c/blob/master/lab2.md
[3]: http://bitsinthewind.com/about-dac/publications/unix-systems-programming

Examples
-------

    $ ./calculator lab2.input 
    e

    $ cat > extra.input <<EOF
    > set 42
    > EOF

    $ ./calculator lab2.input extra.input
    42

    $ ./calculator -v lab2.input extra.input
    set 1 => 1
    shl 1 => 2
    shl 1 => 4
    or 1 => 5
    or 2 => 7
    shl 2 => 1c
    xor 10 => c
    xor 10 => 1c
    and 4 => 4
    set 1c => 1c
    and 3 => 0
    set 1c => 1c
    shr 1 => e
    set 42 => 42

    $ ./calculator -d lab2.input extra.input
    list
     1 set 1
     2 shl 1
    continue
    list
    13 shr 1
    14 set 42
    quit

    $ ./calculator -d -v lab2.input extra.input
    list
     1 set 1
     2 shl 1
    step
    set 1 => 1
    list
     1 set 1
     2 shl 1
     3 shl 1
    continue
    shl 1 => 2
    shl 1 => 4
    or 1 => 5
    or 2 => 7
    shl 2 => 1c
    xor 10 => c
    xor 10 => 1c
    and 4 => 4
    set 1c => 1c
    and 3 => 0
    set 1c => 1c
    shr 1 => e
    set 42 => 42
    quit
