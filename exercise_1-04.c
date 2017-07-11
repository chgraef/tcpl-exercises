// Exercise 1-3.
// Modify the temperature conversion program to print a heading above the
// table.

#include <stdio.h>

/*
 * print Celsius-Fahrenheit table
 * for celsius = 0, 20, ..., 300; floating-point version
 */
int main()
{
	float lower = -20;    /* lower limit of temperature scale */
	float upper = 150;    /* upper limit */
	float step  =  10;    /* step size */

	printf("  °C     °F\n"
	       "====  =====\n");

	for (float celsius = lower; celsius <= upper; celsius += step) {
		float fahr = 9.0 / 5.0 * celsius + 32.0;
		printf("%4.0f  %5.1f\n", celsius, fahr);
	}
}
