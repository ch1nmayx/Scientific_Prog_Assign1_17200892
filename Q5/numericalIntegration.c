
/***********************************************************************
Author - Chinmay Sinha
========================================================
S_iD    - 17200892
========================================================
Course - M.Sc Data and Computational Science
========================================================
***********************************************************************/


#include<stdio.h>
#include<integration_include.h>
#include<math.h>
#include<conio.h>

// defining cases for various integration methods
#define Trapez 1
#define SimpsonsFunction 2
#define Gaussian_Quad 3
#define lower_limit 0.0
#define upper_limit 180.0


int main()
{
  int  i=0, n = 0, integ_case = 0;
  float area = 0.0;

  printf("  1) Trapezoidal Rule\n");
  printf("  2) Simpson's Rule\n");
  printf("  3) Gauss Quadrature\n\n");
  
  // Taking the integration method choice as input
  scanf("%d", &integ_case);

  if (integ_case < 1 || integ_case > 3)
  {
     printf("Return a value between 1 and 3\n");
     return 0;
  }

  // TRAPEZOIDAL_RULE as the first case
  switch(integ_case)
  {
    case Trapez:
         printf("\nEnter the value for Number of Intervals  ");

         scanf("%d", &n);
         area = Trapezoidal(n,0.0,180.0);       
         printf("\nArea using Trapezodial Rule for interval[ %d ] is %.10f\n", n, area);
    break;

	// SIMPSON'S RULE as the first case
    case SimpsonsFunction:
         printf("\nEnter the value for Number of Intervals  ");

         scanf("%d", &n);

         if (n % 2 != 0)
         {
            printf("Please Enter the Even number of intervals\r\n");
            return 0;
         }

         area = Simpsons(n,0.0,180.0);
         printf("\nArea using Simpson Rule for interval[ %d ] is %.10f\n", n, area);
    break;
	
	// GAUSS_QUAD as the third case
    case Gaussian_Quad:
         area = gauss(n,0.0,180.0);
         printf("\nArea using Gauss Quadrature for the interval[ %d ] is %.10f\n", 2, area);
    break;

    default:
    
    break;
  }

  //Tabulate the results of all methods for the following interval values: n = {2,8,16,64}.
  // We can see that the intervals are pow(2,i), where i = {1,3,4,6}

  for (i = 1; i < 7; i++)
  {
      if (i == 2 || i == 5)
      {
         continue;
      }

      n = pow(2,i);

      printf("\nArea of sin(x) for various intervals %d \r\n\n", n);
      printf("Trapezodial Rule    %.5f\r\n",Trapezoidal(n,0.0,180.0));
      printf("Simpson Rule        %.5f\r\n",Simpsons(n,0.0,180.0));
      printf("Gauss Quadrature    %.5f\r\n", gauss(n,0.0,180.0)); 
  }

  getch();
  return 0;
}

