/***********************************************************************
Author - Chinmay Sinha
========================================================
S_iD    - 17200892
========================================================
Course - M.Sc Data and Computational Science
========================================================
***********************************************************************/
#include <stdio.h>
#include <conio.h>

#define HILBERT_ROWS 4
#define HILBERT_COLS 4
#define MR 3
#define MC 3

// Writing a function that calculates the determinant of a 3x3 matrix
// Q4 a)


double Determinant(float A[3][3])
{
    // Defining a 3x3 matrix
    int a, b, c, d, e, f, g, h, i;
    double det;

     // * |           | 
     // * | a  b  c |
     // * | d  e  f  |
     // * | g  h  i  |
     // * |           |
     
    a = A[0][0]; b = A[0][1]; c = A[0][2];
    
	d = A[1][0]; e = A[1][1]; f = A[1][2];
    
	g = A[2][0]; h = A[2][1]; i = A[2][2];

    /*
     * det(A) = a(ei - fh) - b(di - fg) + c(dh - eg)
     */
    // Calculation according to the rule stated above
	det = (a*(e*i - f*h)) - (b*(d*i - f*g)) + (c*(d*h - e*g));

    return det;
}


// Defining Hilbert Function 
// "H" denotes the array containing the Hilbert Matrix
// Q 4 b)
// void Hilbert(double H[HILBERT_ROWS][HILBERT_COLS]){
    // int i=0 , j = 0;
	
    // for(i=0; i < HILBERT_ROWS; i++){
		
        // for(j=0 ; j<HILBERT_COLS; j++){
			
            // H[i][j] = (double)1.0/((i+1)+(j+1)-1.0);
        // }
    // }
// }


// Cramers rule to calculate the determinant of a 4x4 matrix
// s --> Size of the matrix 
// H -- > the matrix to be calculated
// This function is used to minors from a 4X4 hilbert matrix

void cramer_minor(
		float H[HILBERT_ROWS][HILBERT_COLS], float D[MR][MC], int dummy)
{
	int s = 0, t = 0, i= 0, j =0;

	for (s= 1; s < HILBERT_ROWS; s++)
	{
		for (t = 0; t < HILBERT_COLS; t++)
		{
			if (dummy == t)
			{
				continue;
			}

			D[i][j] = H[s][t];
			j++;
		}

		i++;
		j = 0;
	}

	// return;
}


// Defining the cramers rule for calculating the determinant

float cramers(float H[HILBERT_ROWS][HILBERT_COLS])
{

	float da = 0.0, db = 0.0, dc= 0.0, dd = 0.0, D[MR][MC], det = 0.0;
	int r = 0, c = 0, i= 0, j =0;

     cramer_minor(H, D, 0);

	/*Compute Determinant of minors of Matrix*/
	da = Determinant(D);cramer_minor(H, D, 1);

	db = Determinant(D);cramer_minor(H, D, 2);

	dc = Determinant(D);cramer_minor(H, D, 3);

	dd = Determinant(D);


	det = H[0][0]*da - H[0][1]*db + H[0][2]*dc - H[0][3]*dd;

	return det;
}


// Defining a function to print the matrix described as general m x n matrix
// Q4 d)

void MatrixPrint(int m, int n, float matrix[m][n]){
	
    int i , j ;
    
	for(i=0;i<m;i++){
    
		for(j=0;j<n;j++){

			printf("%lf\t",matrix[i][j]);
		}
		
        printf("\n");
    }

}


// Q4 c) - Using Cramer’s rule to find the determinant of the Hilbert Matrix above
// Main Program to display the HIlber Matrix defined above

int main( ) {
    float H[HILBERT_ROWS][HILBERT_COLS];
    float determinant_value;
	
	int i=0 , j = 0;
	
    for(i=0; i < HILBERT_ROWS; i++){
		
        for(j=0 ; j<HILBERT_COLS; j++){
			
            H[i][j] = (float)1.0/((i+1)+(j+1)-1.0);
        }
    }

    // Displaying the Hilbert Matrix generated above
	printf("\nThe required Hilbert matrix is:\n");
    printf("\n*************************\n");
    
	MatrixPrint(HILBERT_ROWS,HILBERT_COLS,H);
	printf("\n*************************\n");
	
	determinant_value = cramers(H);
	printf("\nThe determinan according to cramers rule is %.5f\r\n",determinant_value);
	
	getch();
return 0;
	
}

