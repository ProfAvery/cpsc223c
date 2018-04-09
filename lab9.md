# Lab 9

In [Lab 7][1]'s `phonebook` utility, you may have noticed that it wasn't
very efficient to call `qsort()` on each invocation in order to re-sort
the `faculty` array. In this lab we will correct that deficiency and build
some command-line tools for working with phonebooks in binary format.

Create the following command-line tools:

## `mkphone`

Takes no command-line arguments. Calls `qsort()` four times on the
`faculty` array, sorting by each of `name`, `office`, `phone`, and
`email`. Uses the `open()`, `write()`, and `close()` system calls to
write the sorted array to binary files named `name.bin`, `office.bin`,
`phone.bin`, and `email.bin`.

    $ ls
    mkphone

    $ ./mkphone

    $ ls
    email.bin mkphone name.bin office.bin phone.bin


## `lsphone`

Takes one command-line argument: the name of a sorted array binary
file. Uses the `open()`, `read()`, and `close()` system calls to dump
the contents of the file to `stdout`.

    $ ./lsphone name.bin
    Barua, Susamma
    CS-502
    (657) 278-3362
    sbarua@fullerton.edu

    ...

    Wortman, Kevin
    CS-538
    (657) 278-2968
    kwortman@fullerton.edu

    $ ./lsphone email.bin
    Cong, Bin
    CS-417
    (657) 278-2031
    bcong@fullerton.edu

    Tian, Yun
    CS-538
    (657) 278-2041
    ytian@fullerton.edu

*Tip*: whenever you work with binary files, it's a good idea to write a
small utility to dump a file's contents just to make sure that you
understand the format.


## `phone`

Takes two command-line arguments: the name of a sorted array binary
file and a key to search for. Uses `open()`, `read()`, and `close()`
to load the sorted array and `bsearch()` to search it.

    $ ./phone
    Usage: phone <file> <string>

    $ ./phone email.bin
    Usage: phone <file> <string>

    $ ./phone email.bin kwortman@fullerton.edu
    Wortman, Kevin
    CS-538
    (657) 278-2968
    kwortman@fullerton.edu

    $ ./phone name.bin 'Panangadan, Anand'
    Panangadan, Anand
    CS-538
    (657) 278-3998
    apanangadan@fullerton.edu

    ...

    $ ./phone email.bin kavery@fullerton.edu
    No match.


### Notes

 * As with [Lab 8][2], you may use any of the code from previous labs.

 * This lab has several moving parts; use a `Makefile`.
 
 * Consider creating a `test` target for `make` to automate your work.

 * Don't forget to include `CFLAGS` with all the switches from [Lab 6][3].


[1]: https://github.com/ProfAvery/cpsc223c/blob/master/lab7/
[2]: https://github.com/ProfAvery/cpsc223c/blob/master/lab8.md
[3]: https://github.com/ProfAvery/cpsc223c/blob/master/lab6/Makefile

