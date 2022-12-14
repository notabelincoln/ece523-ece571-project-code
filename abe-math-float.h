/* Abe Jordan
 * ECE 523 / ECE 571
 * Project
 * abe-math-float.h
 */

#ifndef ABE_MATH_FLOAT_H
#define ABE_MATH_FLOAT_H
/* compute rectangle area */
float area_rect(float delta_x, float y);

/* compute trapezoid area */
float area_trap(float delta_x, float y1, float y2);

/* approximate a sin value using taylor series */
float sin_taylor(float x);

/* compute the value of a polynomial (lowest degree coefficient first) evaluated at x */
float poly_eval(const float *coefs, int power, float x);

/* compute simpsons method of a general function */
float sim(float (*f)(float f_x), float x_a, float x_b);
#endif
