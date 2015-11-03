#include<stdio.h>

#define N 8
int verbose = 0;
int numSolutions = 0;
int board[N];

void PrintSolution()
{
    int i,j;
    for (i = 0; i < N; i++)
    {
	printf("\t(");	 
	for (j = 0; j < board[i]; j++)
	    printf("0");
	printf("1");
	for (j = board[i] + 1; j < N; j++)
	    printf("0");
	printf(")\n");
    }
}

solve(row)
int row;
{
    int column, right,left,i,safe;
    for (column = 0; column < N; column++)
    {
	safe = 1;	 
	if (row == 0)
	    for (i = 0; i < N; i++)
		board[i] = N;
	else 
	    for (i = row - 1, right = column+1, left = column-1; 
		 i >= 0; i--, right++, left--) 
		if (board[i] == column || board[i] == right || board[i] == left)
		{
		    safe=0;
		    break;
		}
	if (safe)
	{
	    board[row] = column;
	    if(row == (N-1))
	    {
		numSolutions++;
		if (verbose)
		{
		    printf("Solution #%d:\n", numSolutions);
		    PrintSolution();
		}
	    }
	    else solve(row+1);
	}	    
    }   
}

main()
{
    int i, iterations;
    printf("***SOLUTION FOR %d QUEENS***\n",N);
    solve(0);
    printf("Found %d solutions\n", numSolutions);
}

