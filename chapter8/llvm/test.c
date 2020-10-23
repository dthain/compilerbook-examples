/*
Example of generating LLVM intermediate representation.
clang -S -emit-llvm test.c -o test.llvm
*/

float f( int a, int b, float x ) {
	float y = a*x*x + b*x + 100;
	return y;
}

