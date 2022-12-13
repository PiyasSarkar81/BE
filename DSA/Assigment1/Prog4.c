#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
 
void main()
{
    int array[MAXSIZE];
    int i, num, power;
    float x, polySum;
 
    printf("Enter the order of the polynomial \n");
    scanf("%d", &num);
    printf("Enter the value of x \n");
    scanf("%f", &x);
    printf("Enter %d coefficients \n", num + 1);
    for (i = 0; i <= num; i++)
    {
        scanf("%d", &array[i]);
    }
    polySum = array[0];
    for (i = 1; i <= num; i++)
    {
        polySum = polySum * x + array[i];
    }
    power = num;
 
    printf("Given polynomial is: \n");
    for (i = 0; i <= num; i++)
    {
        if (power < 0)
        {
            break;
        }
        if (array[i] > 0)
            printf(" + ");
        else if (array[i] < 0)
            printf(" - ");
        else
            printf(" ");
        printf("%dx^%d  ", abs(array[i]), power--);
    }
    printf("\n Sum of the polynomial = %6.2f \n", polySum);
}
