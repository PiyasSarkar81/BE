#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a = 0, b = 1;
float epsilon = 0.001;

float f (float x, float y, int func_Val) {
	if (func_Val == 0) return (2 * x * y);
    else if (func_Val == 1) return (x*x  + y*y);
    else return 0;
}

void RungeKutta2ndOrder (float h, float x[], float y_rk[][10], float y0, int func_Val) {
	float k1, k2, k;
	int i, n;
	n = (b - a)/h;
    y_rk[func_Val][0] = y0;
    for (i = 1; i <= n; i++) {
        k1 = h * f(x[i - 1], y_rk[func_Val][i -1], func_Val);
        k2 = h * f((x[i - 1] + h), (y_rk[func_Val][i -1] + k1), func_Val);
        k = (k1 + k2)/2;
        y_rk[func_Val][i] = y_rk[func_Val][i - 1] + k;
    }
    printf ("From Runge-Kutta method of 2nd order:\nx:\t");
    for(i = 0; i <= n; i++)
        printf ("%4.4f\t", x[i]);
    printf ("\ny:\t");
	for(i = 0; i <= n; i++)
        printf ("%4.4f\t", y_rk[func_Val][i]);
	printf ("\n");
}

void EulersMethod (float h, float x[], float y_euler[][10], float y0, int func_Val) {
	float k;
	int i, n;
	n = (b - a)/h;
    y_euler[func_Val][0] = y0;
    for (i = 1; i <= n; i++) {
        k = h * f(x[i - 1], y_euler[func_Val][i -1], func_Val);
        y_euler[func_Val][i] = y_euler[func_Val][i - 1] + k;
    }
    printf ("From Euler's method:\nx:\t");
    for(i = 0; i <= n; i++)
        printf ("%4.4f\t", x[i]);
    printf ("\ny:\t");
	for(i = 0; i <= n; i++)
        printf ("%4.4f\t", y_euler[func_Val][i]);
	printf ("\n");
}

int main() {
	float x[10], y_euler[2][10], y_rk[2][10], h = 0.25;
    int func_Val = 0, i, n;
    printf ("SOLVING DIFFERENTIAL EQUATIONS::\n");
    printf ("1. Differential equation: f'(x, y) = 2xy, y(0) = 0.5\n");
    printf ("2. Differential equation: f'(x, y) = x^2 + y^2, y(0) = 1\n");
    printf ("Choose which equation to solve: ");
    scanf ("%d", &func_Val);
    x[0] = a;  n = (b - a)/h;
    x[n] = b;
    for (i = 1; i < n; i++) {
        x[i] = x[i - 1] + h;
    }
    if (func_Val == 1) {
        RungeKutta2ndOrder(h, x, y_rk, 0.5, 0);
        EulersMethod(h, x, y_euler, 0.5, 0);
        printf ("\n");
    }
    else if (func_Val == 2) {
        RungeKutta2ndOrder(h, x, y_rk, 1, 1);
        EulersMethod(h, x, y_euler, 1, 1);
        printf ("\n");
    }
	return 0;
}
