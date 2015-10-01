Broken Calculator Example
-------------------------

This is an example of an *incorrect* use of Bison.
The grammar given in the parser is ambiguous,
because the rules defining expr are recursive
on both the left and right sides.  The resulting
grammar is not LALR(1) and will not work correctly.

Bison tells you this explicity when you run it:

```
make
...
yacc -d -bparser -v calc.bison
yacc: 20 shift/reduce conflicts.

```

Because we run bison with the -v option,
it produces a file called parser.output, which
contains the entire LR automaton, and lists the
itemsets and actions for each state.
For example:

```
6: shift/reduce conflict (shift 9, reduce 6) on TOKEN_ADD
6: shift/reduce conflict (shift 10, reduce 6) on TOKEN_SUBTRACT
6: shift/reduce conflict (shift 11, reduce 6) on TOKEN_MULTIPLY
6: shift/reduce conflict (shift 12, reduce 6) on TOKEN_DIVIDE
state 6
        expr : expr . TOKEN_ADD expr  (2)
        expr : expr . TOKEN_SUBTRACT expr  (3)
        expr : expr . TOKEN_MULTIPLY expr  (4)
        expr : expr . TOKEN_DIVIDE expr  (5)
        expr : TOKEN_SUBTRACT expr .  (6)

        TOKEN_ADD  shift 9
        TOKEN_SUBTRACT  shift 10
        TOKEN_MULTIPLY  shift 11
        TOKEN_DIVIDE  shift 12
        TOKEN_SEMI  reduce 6
        TOKEN_RPAREN  reduce 6
```

For a correct example, see calc1.
