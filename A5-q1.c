//Solving equations using Bisection, Regula Falsi and Newton-Raphson methods.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylib.h"


int main()
{
	int x = 1;
	double a, b, n, arr[2];
	printf("Given equation is :\n\tlog (x) - sin (x) = 0");

	printf("\n\nPlease enter the value of a : ");
	scanf_s("%lf", &arr[0]);
	printf("\nPlease enter the value of b : ");
	scanf_s("%lf", &arr[1]);
	if (func(arr[0], x) * func(arr[1], x) >= 0)
		printf("You have not assumed proper value for a and b");
	
	bracket(arr, x);
	a = arr[0];
	b = arr[1];
	printf("\nUsing Bisection method:-");
	bisection(a, b, x);

	printf("\n\nUsing Regula Falsi method:-");
	regulaFalsi(a, b, x);

	printf("\n\nFor using Newton-Raphson method:-");
	printf("\nPlease enter the value of a : ");
	scanf_s("%lf", &n);
	newtonRaphson(n, x);
}
