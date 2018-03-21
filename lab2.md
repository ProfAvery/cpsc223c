Lab 2
=====

Create a calculator to work with hexadecimal numbers.

Begin with a byte value of type `uint8_t`.

Use `scanf()` to read one line at a time from standard input.

Each line consists of a command and an integer argument.  Each command
operates on the byte value. Arguments are in hexadecimal.

| Command | Action
| ------- | --------------------------------------------------------------|
| set     | Sets the current byte value to the argument                   |
| and     | Bitwise AND the current byte value with the argument          |
| or      | Bitwise OR the current byte value with the argument           |
| xor     | Bitwise Exclusive OR the current byte value with the argument |
| shr     | Shift the current byte value right by the argument            |
| shl     | Shift the current byte value left by the argument             |

After reading a line, your calculator should output the command and
argument followed by `"=>"` and the new byte value.

For example,

INPUT: `set 4`  
OUTPUT: `set 4 => 4`  
INPUT: `shr 1`  
OUTPUT: `shr 1 => 2`  

A longer example can be found in the files `lab2.input` and `lab2.output`.

Tips
----

1. You can automate your testing by redirecting input from a file,
   rather than typing it in one line at a time, e.g.

    ```
    $ ./calculator < lab2.input
    ```

2. You can save the output of your program by redirecting its output, e.g.

    ```
    $ ./calculator < lab2.input > lab2.test
    ```

3. The UNIX `diff` command can tell you if one file is different from
   another, e.g.

    ```
    $ diff lab2.output lab2.test
    2c2
    < shl 1 => 2
    ---
    > shl 1 => 3
    ```
