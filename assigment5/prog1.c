
#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 3) - x * 9 + 1
#define f1(x) pow(x, 2) * 3 - 9

double epsilon = 0.01;

double bisectionMethod (double xL, double xR) {
    /* f(xL) < 0 and f(xR) > 0 */
    double xM = (xL + xR)/2, prevxM = (xL + xR)/2 + 1;
    double fL = f(xL), fM = f(xM), fR = f(xR);
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
        fM = f(xM);
        step++;
    } while (fabs(prevxM - xM) > epsilon);
    return xM;
}

double regulaFalsi (double xL, double xR) {
    double xM = (xL * f(xR) - xR * f(xL))/(f(xR) - f(xL)), prevxM = xM;
    double fL = f(xL), fM = f(xM), fR = f(xR);
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
        fM = f(xM);
        step++;
    } while (fabs(prevxM -xM) >= epsilon && fR != fL);
    return xM;
}

double newtonRaphson (double xN) {
    double prevxN = xN + 1; //dummy variable
    double fN = f(xN), f1xN = f1(xN);
    int step = 0;
    printf("Step\t\txN\t\tf(xN)\t\tf\'(xN)\t\tx(N+1)\n");
    while (fabs(xN - prevxN) >= epsilon && f1xN) {
        prevxN = xN;
        xN = xN - (fN/f1xN);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step, prevxN, fN, f1xN, xN);
        fN = f(xN), f1xN = f1(xN);
        step++;
    }
    return xN;
}

int main() {
    int choice; double guess1, guess2, f1, f2, xL, xR, root;
    do {
        printf ("SOLVING NON-LINEAR EQUATION::\n");
        printf ("1. Bisection method\n2. Regula Falsi method\n3. Newton Rhapson method\n4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        printf("\n");
        if (choice == 1) {
            printf("BISECTION METHOD\n");
            printf("Enter the initial guesses: ");
            scanf ("%lf%lf", &guess1, &guess2);
            f1 = f(guess1), f2 = f(guess2);
            while (f1 * f2 > 0) {
                printf ("Incorrect guesses! Guess again.\n");
                printf("Enter the initial guesses: ");
                scanf ("%lf%lf", &guess1, &guess2);
                f1 = f(guess1), f2 = f(guess2);
            }
            xR = (f1 > 0) ? guess1: guess2;
            xL = (f1 < 0) ? guess1: guess2;
            root = bisectionMethod(xL, xR);
        
        }
        else if (choice == 2) {
            printf("REGULA FALSI METHOD\n");
            printf("Enter the initial guesses: ");
            scanf ("%lf%lf", &guess1, &guess2);
            f1 = f(guess1), f2 = f(guess2);
            while (f1 * f2 > 0) {
                printf ("Incorrect guesses! Guess again.\n");
                printf("Enter the initial guesses: ");
                scanf ("%lf%lf", &guess1, &guess2);
                f1 = f(guess1), f2 = f(guess2);
            }
            xR = (f1 > 0) ? guess1: guess2;
            xL = (f1 < 0) ? guess1: guess2;
            root = regulaFalsi(xL, xR);
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
            root = newtonRaphson(xL);
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
