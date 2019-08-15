Starter Code for BMinor Project
-------------------------------

This directory contains the starter code for the BMinor compiler.
Students in CSE 40243 are *required* to use these header files as the basis for your work.
Trust us, it will get you started on the right track, and make it
much easier for the instructors to help you with any difficulties.

Of course, to complete the project, you will have to add quite a bit
to what is here.  You are free to add new files, add items to the
structures, implement new functions, and so forth.  But stick to
the basic structure that `decl` represents a declaration,
`expr` represents an expression, and so forth.

For your sanity and ours, you *must* adhere to the following style:
- Every function must be prefixed with the name of the structure that it manipulates.
- Function prototypes go in the `.h` file of the corresponding name.
- Function implementations go in the `.c` file of the corresponding name.

For example, the function `decl_print` prints out a declaration.
Its prototype is found in `decl.h` and the implementation is found in `decl.c`.

For the parsing assignment:

The include files `decl.h stmt.h expr.h type.h param_list.h`
comprise the abstract syntax tree (AST) for CMinor.
A CMinor program is a list of declarations (`decl`) of either global
variables or global functions.  A global function declaration
is a list of statements (`stmt`) such as if-else, while-loops,
and return statements.  Most statements contain expressions (`expr`)
which are trees of operators and values.  A type structure (`type`)
is used to represent abstract types like `integer`, `string`,
and `array of boolean`.

For the typechecking assignment:

The module `hash_table` implements a string-based hash table,
which will come in handy in the typechecking assignment.
The hash table will point to objects of type `symbol` so
as to match variables names (`x`) with their definitions,
like "parameter 3" or "global integer x".

For the code generation assignment:

The module 'library.c' contains the "standard library" for bminor,
which is needed to implement the print statement and the exponentiation
operator.  You are welcome to add items to the library if you find
it helpful.  Set up your Makefile carefully: library.c should be
linked against a compiled bminor program, not against the compiler itself.


