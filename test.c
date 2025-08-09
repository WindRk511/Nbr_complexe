#include<stdio.h>
#include<stdlib.h>
#include"complexe.h"

void affmod_arg(cplx z);

int main () {
	cplx a;
	affmod_arg(a);
}

void affmod_arg(cplx z) {
	float mod,arg;
	z.r=1;
	z.i=1;

	mod = complex_module(z);
	arg = complex_argument(z);

	printf("Module : %.2f\nArgument : %.2f\n",mod,arg);
}	
