/***********************************************************************
Author - Chinmay Sinha
========================================================
S_iD    - 17200892
========================================================
Course - M.Sc Data and Computational Science
========================================================
***********************************************************************/

#include<stdio.h>

// Definition of Collatz Conjcture

int collatz_function(int curr_number)    {

    if ((curr_number % 2) == 0){
		
        return curr_number/2;
    }
	else{
		
        return (curr_number * 3) + 1;
	}
}


// Counting the number of digits in a an integer
// We will use this function in displaying the collatz sequence

int digit_len(int digits)

{
	int c = 0;
// Case for the number '0'
        if (digits == 0)
        {
           return c;
        }
// Case for other numbers
	while(digits != 0)
	{
		digits /= 10;
		c++;
	}

return c;
}

// Main function were we apply the Collatz conjecture
// We also terminate the program at 4,2,1 ending sequence 
// Check for a positive integer as input to the Collatz Conjecture
// Make sure that the print out does not exceed 40 characters per line

/***********************************************************
number -- > Number entered
n_number --> Next number in the collatz sequence
nn_number -- > Third number in the collatz sequence
d_num --> Dynamic variable to store the next number in the sequence
d_num_spaces --> Length of the variable d_num
************************************************************/
int main()  {
	
	int number, n_number = 0, nn_number = 0, d_num , d_num_spaces;

	printf("\n\nEnter a positive number\n\n");
	printf("\n***************************\n\n");
	scanf("%d", &number);
		
// Checking for a positive number
	if (number > 0 ){
		goto program;
	}
	else {	
	printf("\n\nError! Please enter a valid positive number > 0 \n\n");
	scanf("%d", &number);	
	}
	
	program : printf("\n\n\n");
	
	int line_length = 0;
	
	printf("%d, ",number);
	line_length = digit_len(number) + 2;
	
	while(number != 1) {

		n_number = collatz_function(number);
		nn_number = collatz_function(n_number);
// Terminating the program on the ending sequence of ...,4,2,1
		if (number == 4 && n_number == 2 && nn_number == 1 ){
			printf("%d, ",n_number);
			
			line_length = line_length + digit_len(n_number) + 2;
				
				if ( line_length  > 40)
				{
				/*If the line_length exceeds the 40 characters in the single line*/
				printf("\n");
				
				line_length = 0;
				}
			
			printf("%d\n",nn_number);
			break;
				}
				
				d_num = collatz_function(number);
				d_num_spaces  = digit_len(d_num);
				line_length = line_length + d_num_spaces + 2;
				// printf("line_length is %d,       ",line_length);
				if ( line_length  > 40 )
				{
					/*If the line_length exceeds the 40 characters in the single line*/
					printf("\n");
					line_length = 0;
				}
				
				printf("%d, ",d_num);
				number = collatz_function(number);
				}

return 0;

	}
