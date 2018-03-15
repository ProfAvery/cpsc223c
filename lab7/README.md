Lab 7
=====

In this lab, you will build a command-line phonebook that allows you look
up the office, phone number, and email address of any of the [full-time
faculty][1] in the Computer Science department.

You are given the following modules:

| Files                      | Purpose                               |
| -------------------------- | ------------------------------------- | 
| `main.c`                   | Main program                          |
| `commands.c`, `commands.h` | Command table and command definitions |
| `faculty.c`, `faculty.h`   | Contents of phonebook                 |

Complete the following:

1. Create a `Makefile` to build the program.
   * Use the example from Section 2 of [Unix Programming Tools][2] as a guide
   * Don't forget to use tabs instead of spaces in command lines
   * Name the executable program `phonebook`
   * Be careful with dependencies; only re-compile when necessary

2. Implement the find functions in `commands.c` to find entries in the
   `faculty` array
   * Use`qsort()` and `bsearch()`
   * Note that you will need to implement functions to compare two
     `professor` structs based on their fields

3. Modify `main.c` to:
   * Use `argc`, `argv`, and `bsearch()` to find the appropriate find
     command function pointer from the `commands` table
   * Use the pointer to call the appropriate find function from `commands.c`
     in order to search the `faculty` array for the given arguments
   * Print the matching record

  [1]: https://www.fullerton.edu/ecs/cs/faculty/
  [2]: http://cslibrary.stanford.edu/107/

Examples
-------

    $ ./phonebook
    Usage: phonebook <command> <string>

    $ ./phonebook email
    Usage: phonebook <command> <string>

    $ ./phonebook email kwortman@fullerton.edu
    Wortman, Kevin
    CS-538
    (657) 278-2968
    kwortman@fullerton.edu

    $ ./phonebook name 'Panangadan, Anand'
    Panangadan, Anand
    CS-538
    (657) 278-3998
    apanangadan@fullerton.edu

    $ ./phonebook phone '(657) 278-4822'
    Bein, Doina
    CS-542
    (657) 278-4822
    dbein@fullerton.edu
    
    $ ./phonebook office CS-540
    Shafae, Michael
    CS-540
    (657) 279-3291
    mshafae@fullerton.edu

    $ ./phonebook email kavery@fullerton.edu
    No match.

