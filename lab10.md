# Lab 10

Use [GLib][1] to write a command-line utility to count the frequency of
words in a text file.

A word is any substring separated by whitespace. Before counting the
words, strip [punctuation][2] and convert the string to lowercase.

Output should contain each word in the text file followed by the number
of times the word occurs, sorted in alphabetical order:

    $ cat > file.txt <<EOF
    > Output should contain each word in the text file followed by the
    > number of times the word occurs, sorted in alphabetical order:
    >
    > The quick brown fox jumped over the lazy dog.
    > EOF

    $ ./freq file.txt
    alphabetical    1
    brown           1
    by              1
    contain         1
    dog             1
    each            1
    file            1
    followed        1
    fox             1
    in              2
    jumped          1
    lazy            1
    number          1
    occurs          1
    of              1
    order           1
    output          1
    over            1
    quick           1
    should          1
    sorted          1
    text            1
    the             5
    times           1
    word            2

Consider using at least the following GLib features:
 * [I/O Channels][3] (to read the text file)
 * [Balanced Binary Trees][4] (to store the words and their counts)
 * [String Utility Functions][5]

*Hint*: other features may be useful as well; the [GLib documentation][1]
repays close study.

Provide a `Makefile` to link your program with GLib.

[1]: https://developer.gnome.org/glib/2.48/
[2]: http://en.cppreference.com/w/c/string/byte/ispunct 
[3]: https://developer.gnome.org/glib/2.48/glib-IO-Channels.html
[4]: https://developer.gnome.org/glib/2.48/glib-Balanced-Binary-Trees.html
[5]: https://developer.gnome.org/glib/2.48/glib-String-Utility-Functions.html

