#include <stdio.h>
#include <math.h>

#define M 10

double epsilon = 0.001;

void augmentMatrix (double A[][M + 1], const double B[], const int r, const int c) {
    //A is a r x c matrix, B is a r x 1 matrix
    //contents of B will be inserted in the (c + 1)th column of A
    int i;
    if (c > 10) {
        printf ("Exceeded maximum capacity! Exiting...\n");
        return;
    }
    for (i = 0; i < r; i++) 
        A[i][c] = B[i];
}

// function to reduce matrix to reduced
// row echelon form.
int performOperation(double A[][M + 1], int r, int c)
{
	int i, j, k = 0, ctr, flag = 0;
	double pro = 0, swapVar;
	
	// Performing elementary operations
	for (i = 0; i < r; i++)
	{
		if (A[i][i] == 0)
		{
			ctr = 1;
			while ((i + ctr) < r && A[i + ctr][i] == 0)
				ctr++;		
			if ((i + ctr) == r) {
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= c; k++) {
                swapVar = A[j][k];
                A[j][k] = A[j + ctr][k];
                A[j + ctr][k] = swapVar;
            }
		}

		for (j = 0; j < c; j++) {
			
			// Excluding all i == j
			if (i != j) {
				
				// Converting Matrix to reduced row
				// echelon form(diagonal matrix)
				pro = A[j][i] / A[i][i];

				for (k = 0; k <= c; k++)				
					A[j][k] = A[j][k] - (A[i][k])*pro;			
			}
		}
	}
	return flag;
}

// To check whether infinite solutions
// exists or no solution exists
int checkConsistency(double A[][M + 1], int r, int c, int flag)
{
	int i, j;
	double sum;
	
	// flag == 2 for infinite solution
	// flag == 3 for No solution
	flag = 3;
	for (i = 0; i < r; i++)
	{
		sum = 0;
		for (j = 0; j < c; j++)	
			sum = sum + A[i][j];
		if (sum == A[i][j])
			flag = 2;	
	}
	return flag;
}

// Function to print the desired result
// if unique solutions exists, otherwise
// prints no solution or infinite solutions
// depending upon the input given.
void printResult(double A[][M + 1], double X[], int r, int c, int flag)
{
    int i;
	printf ("Solution is : ");

	if (flag == 2)	
	printf ("Infinite Solutions Exists.\n");
	else if (flag == 3)	
	printf ("No Solution Exists.\n");
	
	// Printing the solution by dividing constants by
	// their respective diagonal elements
	else {
        for (i = 0; i < r; i++)  X[i] = A[i][c] / A[i][i];
		printf ("x = %.4lf, y = %.4lf, z = %.4lf\n", X[0], X[1], X[2]);	
	}
}

void GaussJordanElim (double A[][M + 1], double B[], double X[], int r, int c) {
    int flag = 0;
    //Augmenting constant matrix(B[]) to coefficient matrix (A[][])
    augmentMatrix (A, B, r, c);
    // Performing Matrix transformation
	flag = performOperation(A, r, c);
	
	if (flag == 1)	
		flag = checkConsistency(A, r, c, flag);
    printResult (A, X, r, c, flag);
}

/*************************************************************/

// function for elementary operation of swapping two rows
void swap_row(double A[][M + 1], int r, int c, int i, int j)
{
	//printf("Swapped rows %d and %d\n", i, j);
    double swapVar;  int k;
	for (k = 0; k <= c; k++)
	{
		swapVar = A[i][k];
		A[i][k] = A[j][k];
		A[j][k] = swapVar;
	}
}

// function to reduce matrix to r.e.f. Returns a value to
// indicate whether matrix is singular or not
int forwardElim(double A[][M + 1], int r, int c)
{
    int k, i_max, i, j; 
    double v_max, f;
	for (k = 0; k < c; k++)
	{
		// Initialize maximum value and index for pivot
		i_max = k;
		v_max = A[i_max][k];

		/* find greater amplitude for pivot if any */
		for (i = k + 1; i < r; i++)
			if (fabs(A[i][k]) > v_max)
				v_max = A[i][k], i_max = i;

		/* if a principal diagonal element is zero,
		* it denotes that matrix is singular, and
		* will lead to a division-by-zero later. */
		if (!A[k][i_max])
			return k; // Matrix is singular

		/* Swap the greatest value row with current row */
		if (i_max != k)
			swap_row(A, r, c, k, i_max);


		for (i = k + 1; i < r; i++)
		{
			/* factor f to set current row kth element to 0,
			* and subsequently remaining kth column to 0 */
			f = A[i][k]/A[k][k];

			/* subtract fth multiple of corresponding kth
			row element*/
			for (j= k+1; j <= c; j++)
				A[i][j] -= A[k][j]*f;

			/* filling lower triangular matrix with zeros*/
			A[i][k] = 0;
		}
	}
	return -1;
}

// function to calculate the values of the unknowns
void backSub(double A[][M + 1], double X[], int r, int c)
{
    int i, j;
	/* Start calculating from last equation up to the
	first */
	for (i = r - 1; i >= 0; i--)
	{
		/* start with the RHS of the equation */
		X[i] = A[i][c];

		/* Initialize j to i+1 since matrix is upper
		triangular*/
		for (j = i + 1; j < c; j++)
		{
			/* subtract all the lhs values
			* except the coefficient of the variable
			* whose value is being calculated */
			X[i] -= A[i][j] * X[j];
		}

		/* divide the RHS by the coefficient of the
		unknown being calculated */
		X[i] = X[i]/A[i][i];
	}

	printf("\nSolution is : ");
	printf ("x = %.4lf, y = %.4lf, z = %.4lf\n", X[0], X[1], X[2]);
}

// function to get matrix content
void GaussianElim(double A[][M + 1], double B[], double X[], int r, int c)
{
    int singular_flag;
    //Augmenting constant matrix(B[]) to coefficient matrix (A[][])
    augmentMatrix (A, B, r, c);

	/* reduction into r.e.f. */
	singular_flag = forwardElim(A, r, c);

	/* if matrix is singular */
	if (singular_flag != -1)
	{
		printf("Singular Matrix.\n");

		/* if the RHS of equation corresponding to
		zero row is 0, * system has infinitely
		many solutions, else inconsistent*/
		if (A[singular_flag][c])
			printf("Inconsistent System.");
		else
			printf("May have infinitely many solutions.");
		return;
	}

	/* get solution to system and print it using
	backward substitution */
	backSub (A, X, r, c);
}

/************************************************************/

/************************** JACOBI *********************************/

// check the given matrix is Diagonally
// Dominant Matrix or not.
int isDDM (double A[][M + 1], int r, int c)
{
    int i, j;     double sum;
    // for each row
    for (i = 0; i < r; i++)
   {       
        // for each column, finding sum of each row.
        sum = 0;
        for (j = 0; j < c; j++)            
            sum += fabs(A[i][j]);       
 
        // removing the diagonal element.
        sum -= fabs(A[i][i]);
 
        // checking if diagonal element is less
        // than sum of non-diagonal element.
        if (fabs(A[i][i]) < sum)
            return 0;  //equation which does not satify criterion
    }
    return 1;   
}

void makeSystemDDM (double A[][M + 1], int r, int c) {
    int l = 1, swaps = 0;
    while (!isDDM(A, r, c) && swaps < 5) {
        swap_row (A, r, c , l, (l + 1) % 3);
        swaps++;
        l = (l + 1) % 3;
    };
}

void Jacobi (double A[][M + 1], double B[], double X[], int r, int c) {
    double x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
    int step = 0, i;

    //Augmenting constant matrix(B[]) to coefficient matrix (A[][])
    augmentMatrix (A, B, r, c);

    //make sure system is diagonally dominant
    makeSystemDDM (A, r, c);

    if (!isDDM(A, r, c)) {
        printf ("System cannot be made diagonally dominant.\n");
        return;
    }

    printf ("\nThe given system of equations (in diagonally dominant form) is:\n");
        for (i = 0; i < r; i++)
            printf ("%.4lfx + (%.4lf)y + (%.4lf)z = %.4lf\n", A[i][0], A[i][1], A[i][2], A[i][3]);

    printf("\nStep\tx\ty\tz\n");
    printf("%d\t%0.4lf\t%0.4lf\t%0.4lf\n",step, x0,y0,z0);
    do {
        /* Calculation */
        x1 = (A[0][3] - (A[0][1]*y0 + A[0][2]*z0))/A[0][0];
        y1 = (A[1][3] - (A[1][2]*z0 + A[1][0]*x0))/A[1][1];
        z1 = (A[2][3] - (A[2][0]*x0 + A[2][1]*y0))/A[2][2];
        printf("%d\t%0.4lf\t%0.4lf\t%0.4lf\n",step, x1, y1, z1);

        /* Err */
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        step++;

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while(e1 > epsilon && e2 > epsilon && e3 > epsilon);

    X[0] = x1, X[1] = y1, X[2] = z1;
    printf("\nSolution is : ");
	printf ("x = %.4lf, y = %.4lf, z = %.4lf\n", X[0], X[1], X[2]);
}

/**********************************************************/

void reinitializeMatrix (double A[][M + 1], double A1[][M + 1], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) 
            A[i][j] = A1[i][j];
    }
}

int main() {
    int choice, i, j, r = 3, c = 3; 
    double A[M][M + 1], A1[M][M + 1], X[M], B[M];   //max size is a 10 x 10 system of eqns.

    printf ("SOLVING A 3x3 SYSTEM OF LINEAR EQUATIONS::\n");
    printf ("Enter the system of equations (in matrix form):\n");
    printf ("Enter the coefficient matrix (%d x %d):\n", r, c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf ("%lf", &A[i][j]);
            A1[i][j] = A[i][j];
        }
    }
    printf ("Enter the constants (%d x 1):\n", r);
    for (i = 0; i < r; i++) scanf ("%lf", &B[i]);
    printf ("\nThe given system of equations is:\n");
    for (i = 0; i < r; i++)
        printf ("%.4lfx + (%.4lf)y + (%.4lf)z = %.4lf\n", A[i][0], A[i][1], A[i][2], B[i]);

    do {
        printf ("\nChoose the method of solving this system of equations:\n");
        printf ("1. Gauss Jordan Elimination method\n"); 
        printf("2. Gauss Elimination method\n");
        printf("3. Jacobi's method\n"), 
        printf("4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        printf("\n");
        if (choice == 1) {
            printf("GAUSS JORDAN ELIMINATION METHOD\n");
            GaussJordanElim (A, B, X, r, c);
            reinitializeMatrix (A, A1, r, c);
        }
        else if (choice == 2) {
            printf("GAUSS ELIMINATION METHOD\n");
            GaussianElim (A, B, X, r, c);
            reinitializeMatrix (A, A1, r, c);
        }
        else if (choice == 3) {
            printf("JACOBI'S METHOD\n");
            Jacobi (A, B, X, r, c);
        }
        else if (choice == 4) {
            printf ("Exiting...\n");
            return 0;
        }
		else {
            printf ("Wrong choice! Try again!\n\n");
            continue;
        } 
    }while (choice != 4);
    return 0;
}
