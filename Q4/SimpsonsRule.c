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
//#include<conio.h>


// degree to radian conversion function
// float degtorad(float degang) {
   // return( (M_PI * degang)/180.0 );
// }

// For Q4 a)
//************************************
// For the Calculation of the area we are using the Simpson rule here 
// Defining the Simpson function here


// The Simpson's rule works by approximating the region under the graph of the function f(x) and calculating its area
/********************************************************

This function calculates the integral approximation of a function in our
case the function is "tan(x)". The function takes in input as number of 
intervals and returns the value as floating point area number. We are
also given the upper and lower limits as 0 and Pi.

*********************************************************/

// lower_limit -> lower limit (0 in our case)
// upper_limit -> upper limit (Pi(180 degrees) in our case)
// n -> number of intervals we need
// h -> the step defined as per the "n" given above
// integral - > the are under the curve f(x) according to the Trapezoidal rule

float Simpsons (int n, float lower_limit, float upper_limit){
  
  int i;
  float h,x,sum=0,integral;

  // Creating steps according to the interval given
  h=fabs(upper_limit-lower_limit)/n;
  
  //Applying Simpson's rule to the function given (tan(x))
  
  for(i=1;i<n-1;i++){
    
	x=lower_limit+i*h;
    
	if(i%2==0){
      sum=sum+2*tan(x);
    }
    else{
      sum=sum+4*tan(x);
    }
  
  }
  
  integral=(h/3)*(tan(lower_limit)+tan(upper_limit)+sum);
   
  // The final integral result
  return integral;
}


// Q) 4 b) and c)
// Calculating the area under the curve  y = tan(x) from 0 → Pi/3
// Checking for Check if it is odd or even (Should be odd)
// Empirically find the number of points needed to get the area within 1.0×10−5 of the actual result (ln(2))

// Main Code
int main()
{
	int n = 0;
	// a is the lower limit
	// b is the upper limit
	float integral = 0.0, actual_val = 0.0, error = 0.00001, a=0.0, b=M_PI/3;

	printf("\n Provide a odd value for the number of intervals\n\n");
	scanf("%d", &n);

	if (n % 2 == 0)
	{
		printf("\nPlease enter ODD value\n");
		return 0;
	}

    // Using the above defined function
	integral = Simpsons(n, a, b);
	
	// The acutal value of the definite integral
	actual_val = log(2);

    printf("\n Integral value according to Simpson's rule  is %.20f\r\n", integral);
	printf("\nActual Value of (y = tan(x); 0 <= x <= Pi/3) is  %.20f\r\n", actual_val); 
    
	
	// Q4 c) to check the number of points needed to reduce the error deviation from actual and calculated
        n = 0;

        do {
             
         n = n + 1;
      
         integral = Simpsons(n,a,b);

       } while(fabs(actual_val - integral) >= error);  

       printf("\n# Intervals needed are %d\r\n", n + 1);
       printf("\n# Points needed are %d\r\n", n + 2);
       
//	   getch();
       return 0;
}


// We can see that as we increase the number of points/ intervals we get the value of integral closer to log2



