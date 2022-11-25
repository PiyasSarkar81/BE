#include <stdio.h>
#include <math.h>

#define MAXN 100
#define ORDER 4

float epsilon = 0.001;

void LeastSquaresFit (float x[], float y[], int n, float *a, float *b) {
    float sumx = 0, sumy = 0, sumx2 = 0, sum_xy = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        sumx += x[i];
        sumx2 += x[i]*x[i];
        sumy += y[i];
        sum_xy += y[i]*x[i];
    }

    /* y = ax + b */
    *b=(sumx2*sumy - sum_xy*sumx)/(n*sumx2-sumx*sumx);
    *a=(n*sum_xy - sumx*sumy)/(n*sumx2-sumx*sumx);
}

int main() {
    int i, n; 
    float x[100], y[100], a, b;

    printf ("LEAST SQUARES FIT::\n");
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
    printf("\n");
    LeastSquaresFit (x, y, n, &a, &b);

    printf("\nThe required equation is y = %.4fx + (%.4f)\n\n",a,b);
    return 0;
}
