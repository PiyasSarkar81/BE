#include <stdio.h>
#include <math.h>

#define f(x, c) x * tan(x) - c
#define f1(x) tan(x) + x / (pow (cos(x), 2))

double epsilon = 0.01;

double bisectionMethod (double xL, double xR, double c) {
	double xM = (xL + xR)/2, prevxM = (xL + xR)/2 + 1;
	double fL = f(xL, c), fM = f(xM, c), fR = f(xR, c);
	int step = 0;
	printf("Step\t\txL\t\txR\t\txM\t\tf(xM)\n");
	do {
	        prevxM = xM;
	        printf("%d\t\t%f\t%f\t%f\t%f\n",step, xL, xR, xM, fM);
	        if (fL == 0) return xL;
	        else if (fR == 0) return xR;
	        else if (fM == 0) return xM;
	        else if ((fM * fL > 0)) {
	                xL = xM;
	                fL = fM;
	        }
	        else {
	                xR = xM;
	                fR = fM;
	        }
	        xM = (xL + xR)/2.0;
	        fM = f(xM, c);
	        step++;
	} while (fabs(prevxM - xM) > epsilon);
	return xM;
}

double regulaFalsi (double xL, double xR, double c) {
    double xM = (xL * f(xR, c) - xR * f(xL, c))/(f(xR, c) - f(xL, c)), prevxM = xM;
    double fL = f(xL, c), fM = f(xM, c), fR = f(xR, c);
    int step = 0;
    printf("Step\t\txL\t\txR\t\txM\t\tf(xM)\n");
    do {
        prevxM = xM;
        printf("%d\t\t%f\t%f\t%f\t%f\n",step, xL, xR, xM, fM);
        if (fL == 0) return xL;
        else if (fR == 0) return xR;
        else if (fM == 0) return xM;
        else if ((fM * fL > 0)) {
            xL = xM;
            fL = fM;
        } 
        else {
            xR = xM;
            fR = fM;
        }
        xM = (xL * fR - xR * fL)/(fR - fL);
        fM = f(xM, c);
        step++;
    } while (fabs(prevxM -xM) >= epsilon && fR != fL);
    return xM;
}

double newtonRhapson (double xN, double c) {
    double prevxN = xN + 1; //dummy variable
    double fN = f(xN, c), f1xN = f1(xN);
    int step = 0;
    printf("Step\t\txN\t\tf(xN)\t\tf\'(xN)\t\tx(N+1)\n");
    while (fabs(xN - prevxN) >= epsilon && f1xN) {
        prevxN = xN;
        xN = xN - (fN/f1xN);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step, prevxN, fN, f1xN, xN);
        fN = f(xN, c), f1xN = f1(xN);
        step++;
    }
    return xN;
}

int main() {
    int choice; double c, guess1, guess2, f1, f2, xL, xR, root;
    printf ("SOLVING NON-LINEAR EQUATION::\n");
    printf ("x * tanx = c.\nEnter the value of c (a constant): ");
    scanf ("%lf", &c);
    do {
        printf ("\nMethod of solving:\n");
        printf ("1. Bisection method\n2. Regula Falsi method\n3. Newton Rhapson method\n4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        printf("\n");
        if (choice == 1) {
            printf("BISECTION METHOD\n");
            printf("Enter the initial guesses: ");
            scanf ("%lf%lf", &guess1, &guess2);
            f1 = f(guess1, c), f2 = f(guess2, c);
            printf ("f(%lf) = %lf, f(%lf) = %lf\n", guess1, f1, guess2, f2);
            while (f1 * f2 > 0) {
                printf ("Incorrect guesses! Guess again.\n");
                printf("Enter the initial guesses: ");
                scanf ("%lf%lf", &guess1, &guess2);
                f1 = f(guess1, c), f2 = f(guess2, c);
                printf ("f(%lf) = %lf, f(%lf) = %lf\n", guess1, f1, guess2, f2);
            }
            xR = (f1 > 0) ? guess1: guess2;
            xL = (f1 < 0) ? guess1: guess2;
            root = bisectionMethod(xL, xR, c);
        }
        else if (choice == 2) {
            printf("REGULA FALSI METHOD\n");
            printf("Enter the initial guesses: ");
            scanf ("%lf%lf", &guess1, &guess2);
            f1 = f(guess1, c), f2 = f(guess2, c);
            printf ("f(%lf) = %lf, f(%lf) = %lf\n", guess1, f1, guess2, f2);
            while (f1 * f2 > 0) {
                    printf ("Incorrect guesses! Guess again.\n");
                    printf("Enter the initial guesses: ");
                    scanf ("%lf%lf", &guess1, &guess2);
                    f1 = f(guess1, c), f2 = f(guess2, c);
                    printf ("f(%lf) = %lf, f(%lf) = %lf\n", guess1, f1, guess2, f2);
            }
            xR = (f1 > 0) ? guess1: guess2;
            xL = (f1 < 0) ? guess1: guess2;
            root = regulaFalsi(xL, xR, c);
        }
        else if (choice == 3) {
            printf("NEWTON RAPHSON METHOD\n");
            printf("Enter the initial guess: ");
            scanf ("%lf", &guess1);
            f1 = f1(guess1);
            while (f1 == 0) {
                    printf ("f\'(%lf) is not defined! Guess again.\n", guess1);
                    printf("Enter the initial guess: ");
                    scanf ("%lf", &guess1);
                    f1 = f1(guess1);
            }
            xL = guess1;
            root = newtonRhapson(xL, c);
        }
        else if (choice == 4) {
            printf ("Exiting...\n");
            return 0;
        }
        else {
            printf ("Wrong choice! Try again!\n\n");
            continue;
        } 
        printf ("The root is %lf.\n\n", root);
    }while (choice != 4);
    return 0;
}

