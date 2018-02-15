
/***********************************************************************
Author - Chinmay Sinha
========================================================
S_iD    - 17200892
========================================================
Course - M.Sc Data and Computational Science
========================================================
***********************************************************************/


#include<stdio.h>
#include<math.h>
#include<integration_include.h>
#include<conio.h>

// Function to convert degree to radians 
// This function will take degree values as input and return a float radian value
// We will be using the output of this function in calculating the value of sin()

// float degtorad(float degang) {
   // return( (M_PI * degang)/180.0 );
// }


// The trapezoidal rule works by approximating the region under the graph of the function f(x) as a trapezoid and calculating its area
/********************************************************

This function calculates the integral approximation of a function in our
case the function is "sin(x)". The function takes in input as number of 
intervals and returns the value as floating point area number. We are
also given the upper and lower limits as 0 and Pi.

*********************************************************/

// lower_limit -> lower limit (0 in our case)
// upper_limit -> upper limit (Pi(180 degrees) in our case)
// n -> number of intervals we need
// h -> the step defined as per the "n" given above
// sum - > the are under the curve f(x) according to the Trapezoidal rule


float Trapezoidal (int n, float lower_limit, float upper_limit){

	float h,sum1=0,sum,y0,yn;
	int i;

	// defining a single step as h
	h=fabs(upper_limit-lower_limit)/n;
	
	
	y0=sin(degtorad((lower_limit+0*h)));
	yn=sin(degtorad((lower_limit+n*h)));
	
	// iterating for all the intervals
	for(i=1; i<n; i++){
		sum1 = sum1 + sin(degtorad((lower_limit+i*h)));
	}
	
	//final area of the curve
	sum =(h/2)*(y0 + yn + 2*sum1);

	return sum;
}

/*
//Testing of the above function

int main(void){
	printf("%.5f\n",Trapezoidal(12,0,180));

	getch();
	return 0;
}
*/


