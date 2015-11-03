/* Travelling Salesman problem using the Dynamic Programming method
   Written by Chris Bodily and David Butler
   Modified for UNIX by Jeff Penfold
*/

#include <stdio.h>

#define NUM_CITIES          13
#define NUM_CITIES_MINUS_1  12
#define NUM_SUBSETS         4095   /* 2^(NUM_CITIES - 1) - 1 */

unsigned int table[NUM_CITIES_MINUS_1][NUM_SUBSETS+1];
unsigned int temp;
unsigned int min_distance;
unsigned int dist[NUM_CITIES][NUM_CITIES]={
{0, 491, 765, 509, 848, 459, 358, 715, 646, 270, 392, 527, 575},
{491, 0, 662, 516, 951, 150, 313, 924, 543, 319, 611, 1018, 1016},
{765, 662, 0, 256, 1613, 812, 975, 1480, 137, 981, 373, 862, 554},
{509, 516, 256, 0, 1357, 556, 719, 1224, 191, 725, 117, 606, 500},
{848, 951, 1613, 1357, 0, 801, 668, 133, 1494, 632, 1240, 751, 1423},
{459, 150, 812, 556, 801, 0, 163, 892, 693, 189, 579, 986, 984},
{358, 313, 975, 719, 668, 163, 0, 791, 856, 88, 602, 885, 883},
{715, 924, 1480, 1224, 133, 892, 791, 0, 1361, 703, 1107, 618, 1290},
{646, 543, 137, 191, 1494, 693, 856, 1361, 0, 862, 286, 743, 691},
{270, 319, 981, 725, 632, 189, 88, 703, 862, 0, 608, 797, 795},
{392, 611, 373, 117, 1240, 579, 602, 1107, 286, 608, 0, 489, 405},
{527, 1018, 862, 606, 751, 986, 885, 618, 743, 797, 489, 0, 672},
{575, 1016, 554, 500, 1423, 984, 883, 1290, 691, 795, 405, 672, 0}};

int main()
{
  register unsigned int j;
  register unsigned int x;
  register unsigned int y;
  register unsigned int z;
  
/* fill in the zero set */
  for (x = 0; x < NUM_CITIES_MINUS_1; x++)
    table[x][0] = dist[x+1][0];

/* now fill the 'table' */
  for (x=1; x < NUM_SUBSETS; x++)
    for (y=0; y < NUM_CITIES_MINUS_1; y++)
      if ( !( 1 & (x>>y) ) ) 
      {
	min_distance = 0xFFFF;
	for (z = 0; z < NUM_CITIES_MINUS_1; z++)
          if ( 1 & (x >> z) )
	  {
	    j = x ^ (1 << z);
	    temp = table[z][j] + dist[z+1][y+1];
	    if (min_distance > temp)
              min_distance = temp;
	  }
	table[y][x] = min_distance;
      }

/* now get the min distance */
  x = NUM_SUBSETS;
  min_distance = 0xFFFF;
  for (z = 0; z < NUM_CITIES_MINUS_1; z++)
  {
    j = x ^ (1 << z);
    temp = table[z][j] + dist[z+1][0];
    if (min_distance > temp)
      min_distance = temp;
  }

  printf("Optimal Distance: %u\n", min_distance);

  return 0;
}
