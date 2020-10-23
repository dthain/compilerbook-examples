/*
Example of generating GIMPLE intermediate representation.
gcc -fdump-tree-gimple test.c -c
*/

float f( int a, int b, float x ) {
	float y = a*x*x + b*x + 100;
	return y;
}

