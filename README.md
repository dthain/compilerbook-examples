Example Code for Compilers Course
---------------------------------

This repository contains example code and test cases
for the CSE 40243 compilers course at the University of Notre Dame.

- calc0 contains an *incorrect* example that attempts to
parse arithmetic expressions using bison, but is full
of shift-reduce conflits.

- calc1 contains a *correct* example of using bison and flex
together to parse and evaluate simple arithmetic expressions,
by computing results as they are parsed.

- calc2 contains a more complex example of using bison and
flex to parse arithmetic expressions and convert them into
a simple abstract syntax tree of expressions. This 
would be a good place to start as you design your compiler.

- cminor contains the starter code for the CMinor project,
starting with the AST for the parser assignment.

- tests contains the hidden instructors' tests that
were used to evaluate each programming assignment.

