// This is the Wigner, position and momentum distributions for the 4th excited state of a simple QHO.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main() {

// Define pi

double pi;

pi=4.0*atan(1.0);
printf("pi = %0.2e\n",pi); // Checking we have the approximate number for pi


double p, x;
double Wigner4d(double x, double p) {
    return(pow((24*pi),-1)*(16*pow((pow(x,2)+pow(p,2)),4)-128*pow((pow(x,2)+pow(p,2)),3)+288*pow((pow(x,2)+pow(p,2)),2)-192*(pow(x,2)+pow(p,2))+24)*exp(-pow(x,2)-pow(p,2)));
}

// Now to create the loop that will give us the momentum, position and hence Wigner function data from -3 to 3.
double i, j, N, W;

FILE *data8;
data8 = fopen("Wigner_function_fourth_excited.dat","w");

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
        W = Wigner4d(x,p);                         // The value of the Wigner function.
        fprintf(data8, "%e\t %e\t %e\n", x, p, W); // Save data into file.
}
}
fclose(data8);


}
