Lab 3
=====

In this lab, you will create a version of the byte calculator from
[Lab 2][1] that will allow you to step through commands one at a time.

In order to do this, you will need to store commands in memory, rather
than reading them one at a time:

 * Create a `struct` to hold a command, its argument, and its line number
   (the first command is line 1, the second is line 2, and so on).

 * Create an array of `struct`s to hold several statements as a calculator
   program.

 * Use the C initializer syntax [Modern C, Level 1, Sections 2.3 and 6.3]
   [2] to hard-code the array of `struct`s to hold the calculator program
   from `lab2.input`, rather than reading commands with `scanf()`.

  [1]: https://github.com/ProfAvery/cpsc223c
  [2]: http://icube-icps.unistra.fr/img_auth.php/d/db/ModernC.pdf

Now, instead of using `scanf()` to read calculator commands, your program
should use `scanf()` to read commands describing what to do with the
calculator program you've created and stored:

| Command | Action                                            |
| ------- | ------------------------------------------------- |
| step    | Execute the next calculator command               |
| run     | Execute the rest of the calculator commands       |
| print   | Print the current byte value                      |
| list    | Print the current, previous, and next commands    |

Note that in order to keep track of which calculator command to execute
next, you will need to keep track of the current location in the array.

Example
-------

    $ ./debug-calculator
    list
     1 set 1
     2 shl 1
    step
    print
     1
    list
     1 set 1
     2 shl 1
     3 shl 1
    step
    print
    2
    list
     2 shl 1
     3 shl 1
     4 or 1
    run
    print
    e
    list
    12 set 1c
    13 shr 1

