#include<math.h>
#include<stdio.h>
#include<integration_include.h>
#include<conio.h>

// Function to convert degree to radians 
// This function will take degree values as input and return a float radian value
// We will be using the output of this function in calculating the value of sin()

// float degtorad(float degang) {
   // return( (M_PI * degang)/180.0 );
// }


// The Simpson's rule works by approximating the region under the graph of the function f(x) and calculating its area
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
// integral - > the are under the curve f(x) according to the Trapezoidal rule

float Simpsons(int n, float lower_limit, float upper_limit){
  
  int i;
  float h,x,sum=0,integral;

  // Creating steps according to the interval given
  h=fabs(upper_limit-lower_limit)/n;
  
  //Applying Simpson's rule to the function given (Sin(x))
  
  for(i=1;i<n-1;i++){
    
	x=lower_limit+i*h;
    
	if(i%2==0){
      sum=sum+2*sin(degtorad(x));
    }
    else{
      sum=sum+4*sin(degtorad(x));
    }
  
  }
  
  integral=(h/3)*(sin(degtorad(lower_limit))+sin(degtorad(upper_limit))+sum);
   
  // The final integral result
  return integral;
}

/*
//Testing of the above function

int main(void){
	printf("%.5f\n",Simpsons(12,0,180));

	getch();
	return 0;
}
*/



