// This is the Wigner, position and momentum distributions for the ground state of a simple Quantum harmonic oscillator.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void main() {

// Define pi.

double pi;

pi=4.0*atan(1.0);          // The numerical definition of pi.
printf("pi = %0.2e\n",pi); // Checking we have the approximate number for pi.


// Define the momentum and position variables,
double p, x;

// Now, the function derived in section 4.1, W_0(X,P), is coded for, as follows,
double Wigner0th(double x, double p) {
    return(pow(pi,-1)*(exp(-pow(x,2)-pow(p,2))));
}

// Now to define the parameters used in a for-loop.
double i, j, N, W;

// Create .dat files that will save the data generated.
FILE *data9;
data9 = fopen("Wigner_function_ground.dat","w");

//Setting everything to zero before starting apart from the ending point N.
p=0;
x=0;
W=0;
i=0;
j=0;
N=3;    // This is the ending point, at which the loops stop.

// Now to create the double for-loop that will give us the momentum, position and hence Wigner function data from -3 to 3.

for(j=-3; j<=N; j+=0.05) {                            // The outer for-loop that will give the value of momentum used in the inner loop.
    p = j;                                            // Set those values equal to the variable that represents momentum.
    for(i=-3; i<=N; i+=0.05) {                        // The inner loop that gives all the values for the position from -3 to +3 in 0.05 increments.
        x = i;                                        // Generating values for position.
        W = Wigner0th(x,p);                           // The value of the Wigner function based on the values of position and momentum.
        fprintf(data9, "%e\t %e\t %e\n", x, p, W);    // Save the position, momentum and Wigner function values in to 3 columns, into the data file.
}
}
fclose(data9); // Wrap-up and close the file.

// Now, two function will be created, one for position and one for momentum to generate a plot for the distributions of both.

// The momentum distribution as derived in section 4.1
double momentum (double p) {
    return(exp(-pow(p,2))*(pow(sqrt(pi),-1)));
}

// The position distribution as derived in section 4.1
double position (double x) {
    return(exp(-pow(x,2))*(pow(sqrt(pi),-1)));
}

// Create .dat files that will save the data generated.
FILE *data10;
FILE *data11;
data10 = fopen("position0th.dat", "w"); // The name of the file that will store position values and position distribution.
data11 = fopen("momentum0th.dat", "w"); // The name of the file that will store momentum values and momentum distribution.

double Xd, Pd; // Setting position and momentum distribution to be represented by a single variable.

// Generating a single for-loop for both.
for(i=-3; i<=N; i+=0.05) {                       // The for-loop that generates values.
        x = i;                                   // Set the values generated equal to position.
        p = i;                                   // Set the same values equal to the momentum.
        Xd = position(x);                        // Generate the position distribution for each value.
        Pd = momentum(p);                        // Generate the momentum distribution for each value.
        fprintf(data10, "%e\t %e\n", x, Xd);     // Save the position value and position distribution into two columns into the respective file.
        fprintf(data11, "%e\t %e\n", p, Pd);     // Save the momentum value and momentum distribution into two columns into the respective file..
}

// Close the files.

fclose(data10);
fclose(data11);

}

// Gnuplot can now be used for the
