# Lab 12

Use [GObject][1] to create two classes:
 * `Person`, with a member variable `name`
 * `Student`, a subclass of `Person`

Create a virtual function `person_greet()` for each class.

When `person_greet()` is called with a `Person` object, print the string
`"Hello"`, followed by the `name`.

When `person_greet()` is called with a `Student` object, print the string
`"Welcome to CSUF"`, followed by the `name`.

Create an object of each class and demonstrate that `person_greet()`
produces the correct output for each object.

Create a `Makefile` for the project, calling `pkg-config`
as appropriate. To avoid warnings from GObject, omit `-Wbad-function-cast`
from `CFLAGS`.

*Note*: in order to complete this lab successfully, you will probably
need both the readings from the [Schedule][2] and some of the code from
this [object template][3].

[1]: https://developer.gnome.org/gobject/2.48/
[2]: https://docs.google.com/spreadsheets/d/1rGLFf0ALZhnWrwHa8RM41e4gtwJarFtnqLr5OhqfLl4/edit?usp=sharing
[3]: https://gist.github.com/ProfAvery/505e01eb41b12a38db23511333ab2b43

