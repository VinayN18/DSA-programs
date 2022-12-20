#include <stdio.h>

int main()
{
	printf("Today I am %d years old and next year I'm going to be %d years old\n", 20, 21);
	
	// Using an "Integer" format specifier with a "floating point" value
	printf("My average grade: %d\n", 93.7); // Dangerous! 

	// Using a "Floating Point" format specifier
	printf("My average grade: %f\n", 93.7);

	// Using only 1 digit after the decimal point
	printf("My average grade: %.1f\n", 93.7);
	return 0;
}