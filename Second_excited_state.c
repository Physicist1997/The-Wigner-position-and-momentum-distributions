// This is the Wigner, position and momentum distributions for the 2nd excited state of a simple QHO.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main() {

// Define pi

double pi;

pi=4.0*atan(1.0);
printf("pi = %0.2e\n",pi); // Checking we have the approximate number for pi


double p, x;
double Wigner2nd(double x, double p) {
    return((1/pi)*(2*pow((pow(x,2)+pow(p,2)),2)-4*(pow(x,2)+pow(p,2))+1)*exp(-pow(x,2)-pow(p,2)));
}

x=1;
p=1;
printf("w=%e\n", Wigner2nd(x,p));

// Now to create the loop that will give us the momentum, position and hence Wigner function data from -3 to 3.
double i, j, N, W;

FILE *data4;
data4 = fopen("Wigner_function_second_excited.dat","w");

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
        W = Wigner2nd(x,p);                           // The value of the Wigner function.
        fprintf(data4, "%e\t %e\t %e\n", x, p, W); // Save data into file.
}
}
fclose(data4);

// Position and momentum distributions

double Pd, Xd;
double momentum2nd(double p) {
    return(((1-4*pow(p,2)+4*pow(p,4))*exp(-pow(p,2)))/(2*sqrt(pi)));
}

double position2nd(double x) {
    return(((1-4*pow(x,2)+4*pow(x,4))*exp(-pow(x,2)))/(2*sqrt(pi)));
}

FILE *data5;
data5 = fopen("Position2nd.dat", "w");

FILE *data6;
data6 = fopen("Momentum2nd.dat", "w");

p=0;
x=0;
W=0;
i=0;
N=3;
for(i=-3; i<=N; i+=0.05) {
    x=i;
    p=i;
    Pd = momentum2nd(p);
    Xd = position2nd(x);
    fprintf(data5, "%e\t %e\n", x, Xd);
    fprintf(data6, "%e\t %e\n", p, Pd);
}

fclose(data5);
fclose(data6);

}
