#include <stdio.h>
#include <math.h>

#define MAXN 100
#define ORDER 4

float epsilon = 0.001;

// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    int i;
    float temp = u;
    for (i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

// Calculation of u mentioned in formula
float v_cal(float v, int n)
{
    int i;
    float temp = v;
    for ( i = 1; i < n; i++)
        temp = temp * (v + i);
    return temp;
}
 
// calculating factorial of given number n
int fact(int n)
{
    int f = 1,i;
    for ( i = 2; i <= n; i++)
        f *= i;
    return f;
}

float LagrangeInterpolation (float x[], float y[], int n, float xp) {
    int i, j;
    float yp = 0, p;
    /* Implementing Lagrange Interpolation */
    for(i = 0; i < n; i++)
    {
    	p = 1;
    	for(j = 0; j < n; j++)
    	{
    	   if(i != j)
    	   {
    	    	p = p * (xp - x[j])/(x[i] - x[j]);
    	   }
    	}
    	yp = yp + p * y[i];
    }
    return yp;
}

float NewtonForward (float x[], float y[], int n, float xp) {
    float diff[MAXN+1][ORDER+1], u, yp;
    int i, j;
    for (i = 0; i < n; i++) 
        diff[i][0] = y[i];

    //calculating the forward difference table
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++)
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];
    }

    //displaying the forward difference table
    printf ("\nForward difference table: \n");
    for (i = 0; i < n; i++) {
        printf ("%4.4f\t", x[i]);
        for (j = 0; j < n - i; j++)
            printf ("%4.3f\t", diff[i][j]);
        printf ("\n");
    }
    printf ("\n");
    
    // initializing u and yp
    yp = diff[0][0];
    u = (xp - x[0]) / (x[1] - x[0]);
    for (i = 1; i < n; i++) {
        yp = yp + (u_cal(u, i) * diff[0][i]) /
                                 fact(i);
    }

    return yp;
}

float NewtonBackward (float x[], float y[], int n, float xp) {
    float diff[MAXN+1][ORDER+1], v, yp;
    int i, j;
    for (i = 0; i < n; i++) 
        diff[i][0] = y[i];

    //calculating the backward difference table
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--)
            diff[j][i] = diff[j][i - 1] - diff[j - 1][i - 1];
    }
    //displaying the backward difference table
    printf ("\nBackward difference table: \n");
    for (i = 0; i < n; i++) {
        printf ("%4.4f\t", x[i]);
        for (j = 0; j < n - i; j++)
            printf ("%4.3f\t", diff[i][j]);
        printf ("\n");
    }
    printf ("\n");

    // initializing v and yp
    yp = diff[n - 1][0];
    v = (xp - x[n - 1]) / (x[1] - x[0]);
    for (i = 1; i < n; i++) {
        yp = yp + (v_cal(v, i) * diff[n - 1][i]) /
                                 fact(i);
    }
    return yp;
}

int main() {
    int choice, i, n; 
    float x[100], y[100], xp, yp = 0;

    printf ("INTERPOLATION METHODS::\n");
    printf("Enter the number of points: ");
	scanf("%d", &n);
	printf("Enter the respective values of the variables x and y: \n");
    for( i = 0; i < n; i++)
    {
        scanf ("%f",&x[i]);
        scanf("%f",&y[i]);
    }

    printf ("\nThe given data values are:\n");
    printf ("x:\t");
    for (i = 0; i < n; i++)   printf ("%.4f\t", x[i]);
    printf ("\ny:\t");
    for (i = 0; i < n; i++)  printf ("%.4f\t", y[i]);
	printf("\n\nEnter interpolation point: ");
	scanf("%f", &xp);

    do {
        printf ("\nChoose the method of solving this system of equations:\n");
        printf ("1. Lagrange's Interpolation method\n"); 
        printf("2. Newton's Forward Interpolation method\n");
        printf("3. Newton's Backward Interpolation method\n"), 
        printf("4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        printf("\n");
        if (choice == 1) {
            printf("LAGRANGE'S INTERPOLATION METHOD\n");
            yp = LagrangeInterpolation (x, y, n, xp);
        }
        else if (choice == 2) {
            printf("NEWTON'S FORWARD INTERPOLATION METHOD\n");
            yp = NewtonForward (x, y, n, xp);
                
        }
        else if (choice == 3) {
            printf("NEWTON'S BACKWARD INTEPOLATION METHOD\n");
            yp = NewtonBackward (x, y, n, xp);
        }
        else if (choice == 4) {
            printf ("Exiting...\n");
            return 0;
        }
        else {
            printf ("Wrong choice! Try again!\n\n");
            continue;
        } 
        printf ("The interpolated value of the function at %.4f is %.4f\n", xp, yp);
    }while (choice != 4);
    return 0;
}
