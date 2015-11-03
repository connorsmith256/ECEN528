/******************************************************************************
		Gauss-Jordan Method - Algorithm 6.1C1
*******************************************************************************

To solve the n x n linear system

	E1:   a(1,1)*X1 + a(1,2)*X2 + ... a(1,n)*Xn = a(1,n+1)
	E2:   a(2,1)*X1 + a(2,2)*X2 + ... a(2,n)*Xn = a(2,n+1)
	.        .           .               .           .
	.        .           .               .           .
	.        .           .               .           .
	En:   a(n,1)*X1 + a(n,2)*X2 + ... a(n,n)*Xn = a(n,n+1):

INPUT number of equations and unknowns n; augmented matrix A = (a(i,j)) where
1 <= i <= n and 1 <= j <= n+1.

OUTPUT solution x1,x2,...,xn or message that linear system has no unique
solution.

*******************************************************************************
*	Written by:  Harold A. Toomey, BYU, Summer 1989, v4.11		      *
******************************************************************************/
double A[5][6] ={{7,-3,-2,0,-1,-6},{-3,12,-1,-5,-3,5},{-2,-1,12,-5,0,22},{0,-5,-5,20,-4,11},
		  {-1,-3,0,-4,10,-5}};

print_matrix(n)	/* Prints out a matrix. */
int n;
{
    int i, j;

    for (i=0;i<n;i++) 
    {
	printf("[ ");
	for (j=0;j<n;j++)
	    printf("% 3g ", A[i][j]);
	printf(" | % 3g ", A[i][n]);
	printf("]\n    ");
    }
    printf("\n");

}

main()
{

    double m[5][6], X[5], temp; 
         
    int i, j, k, n=5, p, FLAG;

  
    /* STEP #1 */
    for (i=0;i<n;i++) 
    {				/* Do Steps 2-4.  Elimination process. */
	/* Modified from Algorithm 6.1. */
	printf("At row %d:\n", i);
	printf("A = ");
	print_matrix(n);	/* Show intermediate results for looks. */

	/* STEP #2 */
	for (p=i;p<n;p++) 
	{			/* Let p be the smallest integer with */
	    if (A[p][i] != 0.0) 
	    {			/* i <= p <= n and a(pi) != 0. */
		FLAG = 1;
		break;
	    }
	    FLAG = 0;		/* FLAG = 0 indicates an all zero row. */
	}

	if (i == p)
	    printf("No rows need swapping.\n\n"); /* For looks. */
	else
	    printf("Need to swap row %d with row %d.\n\n", i, p);

	if (FLAG == 0) 
	{
	    printf("No unique solution exists (1).\n");
	    exit (-1);
	}

	/* STEP #3 */
	if (p != i)		/* Swap Ep with Ei. */
	    for (k=0;k<n;k++) 
	    {
		temp = A[p][k];
		A[p][k] = A[i][k];
		A[i][k] = temp;
	    }

	/* STEP #4 */
	for (j=0;j<n;j++)	/* Do Steps 5-6. */
	    /* Modified from Algorithm 6.1. */
	    if (j != i) 
	    {			/* Modified from Algorithm 6.1. */

		/* STEP #5 */
		m[j][i] = A[j][i] / A[i][i];

		/* STEP #6 */
		for (k=0;k<=n;k++)
		    A[j][k] -= m[j][i] * A[i][k];
	    }
    }
    /* STEP #7 
       
       if (A[n-1][n-1] == 0.0) 
       {
       printf("No unique solution exists (2).\n");
       exit (-1);
       } 
       */
    printf("At row %d:\n", n);
    printf("A = ");
    print_matrix(n);		/* Show intermediate results for looks. */

    /* STEPS #8-#9 */
    for (i=0;i<n;i++)		/* Obtain solution. */
	X[i] = A[i][n] / A[i][i];

    /* STEP #10 */
    printf("\nX = [ ");		/* Procedure completed successfully. */
    for (i=0;i<n;i++)
	printf("% .8g ", X[i]);
    printf("]\n");

} /* STOP */













