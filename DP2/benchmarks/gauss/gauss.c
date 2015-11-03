/*  This program uses Gaussian elimination to find the matrix x given matrix
    A and B for Ax=B
    written by Darrin Stokes
    ECEn 425, Lab 1 solution
    last updated 9/4/96 */

#include <stdio.h>

void main(void)
{

  int i,j,k;
  float matrix[4][5];
  float divrow,addrow,total;
  
  matrix[1][1]=4; matrix[1][2]=3; matrix[1][3]=4; matrix[1][4]=6;
  matrix[2][1]=1; matrix[2][2]=2; matrix[2][3]=6; matrix[2][4]=-1;
  matrix[3][1]=8; matrix[3][2]=7; matrix[3][3]=5; matrix[3][4]=17;

  for (k=1;k<=3;k++){
     divrow = matrix[k][k]; 
       for (j=k;j<=4;j++)
         matrix[k][j] = matrix[k][j]/divrow;
       for (i=1;i<=3;i++)
         if (i!=k){
           addrow = -matrix[i][k];
            for (j=1;j<=4;j++)
               matrix[i][j]=matrix[k][j]*addrow + matrix[i][j];
         }
  }

  total = matrix[1][4] + matrix[2][4] + matrix[3][4];
  printf("%f\n",total);
}
