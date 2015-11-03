#include <stdio.h>

/* surface[][] represents the potential of a surface with the
   specified boundary values held fixed.  Intermediate values are
   calculated iteratively as the average of the four adjacent values
   until they converge.  (See discussion page 145 of Neff's "Basic
   Electromagnetic Fields".)  */

#define LEDGE 0.0		/* potential on left edge */
#define REDGE 0.0		/* potential on right edge */
#define TEDGE 100.0		/* potential on top edge */
#define BEDGE 0.0		/* potential on bottom edge */

#define SSIZE 6

float surface[SSIZE][SSIZE];

init()
{    /* initialize array first.  Note that corners of array are never
       used in nearest neighbor calculations since potential on edges
       is assumed to be fixed, so they are flagged with a unique value 
       to make printing the array simpler. */

    int i, j;
    for (i = 1; i < SSIZE; i++)
    {
	surface[i][0] = LEDGE;	surface[i][SSIZE-1] = REDGE;
	surface[0][i] = TEDGE;	surface[SSIZE-1][i] = BEDGE;
    }
    for (i = 1; i < SSIZE-1; i++)
	for (j = 1; j < SSIZE-1; j++)
	    surface[i][j] = 0.0;
    surface[0][0] = surface[SSIZE-1][0] = -1.0;
    surface[0][SSIZE-1] = surface[SSIZE-1][SSIZE-1] = -1.0;
}

printres()
{
    int i, j;
    for (i = 0; i < SSIZE; i++)
    {
	for (j = 0; j < SSIZE; j++)
	    if (surface[i][j] >= 0)
		printf("%6.2f ", surface[i][j]);
	    else
		printf("       ");
	printf("\n");
    }
    printf("\n");
}

main()
{
    int i,j,converged, cnt;
    float new;

    init();

    /* the iteration proceeds in a simplistic order.  A better order
       would lead to faster convergence, but simplicity is the goal
       here. */
    cnt = 0;
    do 
    {
	converged = 1;
	for (i = 1; i < SSIZE-1; i++)
	{
	    for (j = 1; j < SSIZE-1; j++)
	    {
		new = (surface[i-1][j] + surface[i+1][j] +
		    surface[i][j+1] + surface[i][j-1]) / 4.0;
		if (new - surface[i][j] > 0.01 || new - surface[i][j] < -0.01)
		    converged = 0;
		surface[i][j] = new;
	    }
	}
	cnt++;
    } while (!converged);
    printres();
    printf("Took %d iterations\n", cnt);
}
