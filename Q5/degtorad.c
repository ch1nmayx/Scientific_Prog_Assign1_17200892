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

float degtorad(float degang) {
   return( (M_PI * degang)/180.0 );
}


