Example Code for Introduction to Compilers and Language Design
--------------------------------------------------------------

This repository contains example code and test cases
for the [Introduction to Compilers and Language Design] (http://compilerbook.org)
online textbook.

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

- bminor contains the starter code for the B-Minor project.
This incorporates the header files defined in the text book,
and gives a simple structure that will help to avoid some
common software engineering pitfalls.

- tests contains some sample test cases that demonstrate how
to automate testing for each stage of the project.  Note that
the test cases are not necessarily comprehensive: both students
and instructors are advised to carefully study the language,
write new test cases, and discuss any areas of ambiguity.
 


