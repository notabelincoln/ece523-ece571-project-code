/* Abe Jordan
 * ECE 523 / ECE 571
 * Project
 * abe-math-float.c
 */

#ifndef SIN_TAYLOR_N
#define SIN_TAYLOR_N 4
#endif

#include <math.h>
/* compute rectangle area */
float area_rect(float delta_x, float y)
{
	return delta_x * y;
}

/* compute trapezoid area */
float area_trap(float delta_x, float y1, float y2)
{
	return (delta_x * (y1 + y2) / 2);
}

/* approximate a sin value using taylor series */
float sin_taylor(float x)
{
	if (x > M_PI / 2)
		return -1 * sin_taylor(x - (M_PI));
	else if (x < M_PI / -2)
		return sin_taylor(x + 2 * M_PI);
	int i;
	float ret;
	float tmp;

	ret = x;
	tmp = x;

	for (i = 1; i < SIN_TAYLOR_N; i++) {
		tmp = tmp * x * x / (-2.0 * i * (2 * i + 1));
		ret += tmp;
	}

	return ret;
}

/* compute the value of a polynomial (lowest degree coefficient first) evaluated at x */
float poly_eval(const float *coefs, int power, float x)
{
	int i;
	int j;
	
	float tmp;
	float ret;

	ret = coefs[0];

	for (i = 1; i <= power; i++) {
		tmp = x * coefs[i];
		
		for (j = 1; j < i; j++)
			tmp = tmp * x;

		ret += tmp;
	}

	return ret;
}

/* compute simpsons method of a general function */
float sim(float (*f)(float f_x), float x_a, float x_b)
{
	float tmp;
	float ret;

	tmp = (x_b - x_a) / 6.0;
	ret = tmp * (f(x_a) + 4.0 * f((x_a + x_b) / 2) + f(x_b));

	return ret;
}

