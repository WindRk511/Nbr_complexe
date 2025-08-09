#include<stdlib.h>
#include<math.h>
#include"complexe.h"


float complex_module(cplx z) {
	float somme;
	float r2 = (z.r)*(z.r);
	float i2 = (z.i)*(z.i);
	somme = r2 + i2;
	return sqrt(somme);
}

float complex_argument(cplx z) {
	float mod=complex_module(z);
	float r = z.r/mod;
	r = acos(r);
	return r;
}

cplx complex_conj(cplx z){
	 z.i = -(z.i);
	 return z;
}
