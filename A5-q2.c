//Solve a polynomial using Laguerre's method

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <math.h>

void main()
{
    int n;
    printf("Solving polynomial using the laguerre method:-\n\n");
    printf("Please enter the order of the polynomial:\t");
    scanf("%d", &n);

    double* array = malloc((n + 1) * sizeof(double));
    double coeff;
    printf("\nPlease enter the coefficients of the polynomial in decreasing power of x:\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%lf", &coeff);
        array[i] = coeff;
    }

    printf("\nGiven polynomial is:\n");
    printf("P(x) = (%lf x^%d) + ", array[0], n);
    for (int i = 1; i < n; i++)
    {
        printf("(%lf x^%d) + ", array[i], (n - i));
    }
    printf("(%lf x^0)\n", array[n]);
    double x;
    printf("\nUsing Laguerre method:\n");
    printf("The initial guess of root: 5.5\n");
  
    double b = 0;
    b = laguerre(&array[0], 5.5, n);
    printf("1st Root is:%lf\n", b);
    double* temp = synDiv(&array[0], b, n);

    for (int i = 1; i < n - 1; i++)
    {
        b = laguerre(temp, 5.5, n - i);
        printf("Root %d is : %lf\n",i + 1, b);
        temp = synDiv(temp, b, n);
    }

    double c = 0 - temp[1];

    printf("Root %d is : %lf\n", n, c);
}