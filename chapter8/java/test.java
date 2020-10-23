/*
Example of generating JVM intermediate representation.
javac test.java
javap -c test.class
*/

class test {

float f( int a, int b, float x ) {
	float y = a*x*x + b*x + 100;
	return y;
}

}

