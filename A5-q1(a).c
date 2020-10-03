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




/*
*********************************************************OUTPUT**********************************************************
Given equation is :
        log (x) - sin (x) = 0

Please enter the value of a : 1.5

Please enter the value of b : 2.5
Root already exists in the guessed interval
Using Bisection method:-
It.No.          a                       b                       c                       f(c)                    Error
 1              1.500000                2.500000                2.000000                -0.216150               0.250000
 2              2.000000                2.500000                2.250000                0.032857                0.125000
 3              2.000000                2.250000                2.125000                -0.096548               0.062500
 4              2.125000                2.250000                2.187500                -0.033030               0.031250
 5              2.187500                2.250000                2.218750                -0.000377               0.015625
 6              2.218750                2.250000                2.234375                0.016169                0.007813
 7              2.218750                2.234375                2.226563                0.007878                0.003906
 8              2.218750                2.226563                2.222656                0.003746                0.001953
 9              2.218750                2.222656                2.220703                0.001684                0.000977
 10             2.218750                2.220703                2.219727                0.000653                0.000488
 11             2.218750                2.219727                2.219238                0.000138                0.000244
 12             2.218750                2.219238                2.218994                -0.000119               0.000122
 13             2.218994                2.219238                2.219116                0.000010                0.000061
 14             2.218994                2.219116                2.219055                -0.000055               0.000031
 15             2.219055                2.219116                2.219086                -0.000023               0.000015
 16             2.219086                2.219116                2.219101                -0.000007               0.000008
 17             2.219101                2.219116                2.219109                0.000002                0.000004
 18             2.219101                2.219109                2.219105                -0.000003               0.000002
 19             2.219105                2.219109                2.219107                -0.000001               0.000001
 20             2.219107                2.219109                2.219108                0.000001                0.000000

The value of root is : 2.219107

Using Regula Falsi method:-
It.No.          a                       b                       c                       f(c)                    Error
 1              1.500000                2.500000                2.150691                -0.070732               0.063588
 2              2.150691                2.500000                2.214279                -0.005084               0.004499
 3              2.214279                2.500000                2.218778                -0.000347               0.000307
 4              2.218778                2.500000                2.219085                -0.000024               0.000021
 5              2.219085                2.500000                2.219106                -0.000002               0.000001
 6              2.219106                2.500000                2.219107                -0.000000               0.000000

The root, using Regula Falsi method, is: 2.219107

For using Newton-Raphson method:-
Please enter the value of a : 1.5

Iter.No.        a               f(a)            c               Error
1               1.500000        -0.592030       2.493456        0.258682
2               2.493456        0.309968        2.234774        0.015599
3               2.234774        0.016593        2.219175        0.000068

Root is: 2.219107
**************************************************************************************************************************
*/
