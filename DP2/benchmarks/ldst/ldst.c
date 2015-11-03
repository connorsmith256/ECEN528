#include <stdio.h>

main()  
{
  double x[100],y[100],z[100],r,b,g;
  int a,c;
  r = 1.034;
  g = r/r;
  b = 1.0;
  a = 1;
  for(c=0;c<10;c++) {
    x[c] = b/0.065;
    y[c] = b;
    z[c] = b;
    y[c+1] = r;
    z[c+1] = r;
    printf("x[%d] = %f,y[%d] = %f,z[%d] = %f\n",c,x[c],c,y[c],c,z[c]);
    
  }
}



