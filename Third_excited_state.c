// This is the Wigner,position and momentum distributions for the 3rd excited state of a simple QHO.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main() {

// Define pi

double pi;

pi=4.0*atan(1.0);
printf("pi = %0.2e\n",pi); // Checking we have the approximate number for pi


double p, x;
double Wigner3d(double x, double p) {
    return((pow(6,-1)*((-8*pow((pow(x,2)+pow(p,2)),3)+36*(pow((pow(x,2)+pow(p,2)),2))-36*(pow(x,2)+pow(p,2))+6)))*(-1/pi)*exp(-pow(x,2)-pow(p,2)));
}



// Now to create the loop that will give us the momentum, position and hence Wigner function data from -3 to 3.
double i, j, N, W;

FILE *data7;
data7 = fopen("Wigner_function_third_excited.dat","w");

p=0;
x=0;
W=0;
i=0;
j=0;
N=3;
for(j=-3; j<=N; j+=0.05) {
    p = j;
    for(i=-3; i<=N; i+=0.05) {
        x = i;                                     // Generating values for position.
        W = Wigner3d(x,p);                         // The value of the Wigner function.
        fprintf(data7, "%e\t %e\t %e\n", x, p, W); // Save data into file.
}
}
fclose(data7);



}
