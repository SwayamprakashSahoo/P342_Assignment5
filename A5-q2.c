//Solve a polynomial using Laguerre's method and Synthetic Division of the polynomials

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <math.h>

void main()
{
    int n;
    printf("Solving polynomial using the laguerre method and synthetic division:-\n\n");
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







/*
*********************************************OUTPUT****************************************************
Solving polynomial using the laguerre method and synthetic division:-

Please enter the order of the polynomial:       4

Please enter the coefficients of the polynomial in decreasing power of x:
1
-3
-7
27
-18

Given polynomial is:
P(x) = (1.000000 x^4) + (-3.000000 x^3) + (-7.000000 x^2) + (27.000000 x^1) + (-18.000000 x^0)

Using Laguerre method:
The initial guess of root: 5.5
1st Root is:3.000000
Root 2 is : 2.000000
Root 3 is : 1.000000
Root 4 is : -3.000000
**********************************************************************************************************
*/
