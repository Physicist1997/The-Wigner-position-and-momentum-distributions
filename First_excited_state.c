// This is the Wigner function and the position and momentum distributions, for the 1st excited state of a simple QHO.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main() {

double pi;

// Define pi

pi=4.0*atan(1.0);
printf("pi = %0.2e\n",pi); // Checking we have the approximate number for pi

// Starting from the unnormalised state of our choice (No physical meaning).

double Wx, x;

Wx = x*exp(-(pow(x,2)/2)); // An unnormalized state.

// Now establishing the wavefunction for a QHO at ground state.
// The Hermite polynomial for ground state is equal to 1.

double psi(double x) {
    return((sqrt(2)*x*exp(-(pow(x,2)/2)))/pow(pi,0.25));  // Wx is expanded in the function for functionality reasons.
}

// Now, establishing the density operator for x = x-(s/2) and x = x+(s/2).

double rho, s, A, B;

A = psi(x+(s/2)); // s = displacement
B = psi(x-(s/2)); // s = displacement
rho = A*B; // The density operator

// Now taking the inverse Fourier transform of the density operator we end up with the Wigner function, which in this case is,

double p;
double Wigner(double x, double p) {
    return(((-1+2*pow(p,2)+2*pow(x,2))*exp(-pow(x,2)-pow(p,2)))/pi);
}


// Now, following the process of obtaining the position and momentum distributions we have,

// For the momentum distribution,


double momentum(double p) {
    return((exp(-pow(p,2))*(-1+2*pow(p,2))+exp(-pow(p,2)))/sqrt(pi));
}


// For the position distribution,

double position(double x) {
    return((exp(-pow(x,2))*(-1+2*pow(x,2))+exp(-pow(x,2)))/sqrt(pi));
}


// Now we will use different values for position and momentum distributions in order to create a 2D graph for them.
//Set everything to zero.

x=0;
p=0;
s=0;

FILE *data1;   // Pointer
data1 = fopen("Position.dat","w"); //.dat File name

FILE *data2;   // Pointer
data2 = fopen("Momentum.dat","w"); //.dat File name


// Now the values for the position and momentum from -3 to 3 with 0.05 increments.

double Pd, Xd, i, N;

N=3;
i=0;
for(i=-3; i<=N; i+=0.05) {
    p = i;                              // Generating values for momentum.
    Pd = momentum(p);                   // The respective momentum distribution.
    x = i;                              // Generating values for position.
    Xd = position(x);                   // The respective position distribution.
    fprintf(data1, "%e\t %e\n", x, Xd); // Save the data into file.
    fprintf(data2, "%e\t %e\n", p, Pd); // Save data into file.
}

fclose(data1);
fclose(data2);


// Now we will create the 3-D plot of the Wigner function for the respective positions and momenta.

//Set everything to zero.

x=0;
p=0;
s=0;

FILE *data3;   // Pointer
data3 = fopen("Wigner_function_first_excited.dat","w"); //.dat File name

double W, j;  // The Wigner function.

N=3;
i=0;
j=0;
for(j=-3; j<=N; j+=0.05) {
    p = j;
    for(i=-3; i<=N; i+=0.05) {
        Pd = momentum(p);                          // The respective momentum distribution.
        x = i;                                     // Generating values for position.
        Xd = position(x);                          // The respective position distribution.
        W = Wigner(x,p);                           // The value of the Wigner function.
        fprintf(data3, "%e\t %e\t %e\n", x, p, W); // Save data into file.
}
}


fclose(data3);


}
