#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"complexe.h"

//determine le module
float complex_module(cplx z) 
{
	float somme;
	float r2 = (z.r)*(z.r);
	float i2 = (z.i)*(z.i);
	somme = r2 + i2;
	return sqrt(somme);
}

//determine l'argument
float complex_argument(cplx z) 
{
	float mod=complex_module(z);
	float r = z.r/mod;
	r = acos(r);
	return r;
}

//recherche de conjuger
cplx complex_conj(cplx z)
{
	 z.i = -(z.i);
	 return z;
}

//addition entre deux nombre complexe
cplx cplx_add(cplx z1, cplx z2) 
{
	cplx z;
	z.i = z1.i + z2.i;
	z.r = z1.r + z2.r;

	return z;
}

//multiplication entre deux nombre complexe
cplx cplx_mult(cplx z1, cplx z2) 
{
	cplx z;
	z.i = (z1.r)*(z2.i) + (z2.r)*(z1.i);
	z.r = (z1.r)*(z2.r) + (z1.i)*(z2.i);
}

//division entre deux nombre complexe
cplx cplx_div(cplx z1,cplx z2) 
{
	cplx z;
	double d = (z2.r)*(z2.r) + (z2.i)*(z2.i);
	z2 = complex_conj(z2);	//on prefere le conjuger de z2
	z = cplx_mult(z1,z2);
	z.i = (z.i)/d;
	z.r = (z.r)/d;

	return z;
}

cplx cplx_sous(cplx z1, cplx z2) 
{
	cplx z;
	z2.i = -(z2.i);
	z2.r = -(z2.r);

	z = cplx_add(z1,z2);
	return z;
}	
//l'operation entre complexe
cplx complex_ope(cplx z1, char s, cplx z2) 
{
	cplx z;
	if (s == '+') {
		z = cplx_add(z1,z2);
		return z;
	}
	else if (s == '-') {
		if ( (z2.i) == 0 && (z2.r) == 0) {
			printf("Erreur : dividant est nul\n");
			exit (-1);
		}
		z = cplx_sous(z1,z2);	
		return z;
	}
	else if (s == '*') {
		z = cplx_mult(z1,z2);	
		return z;
	}
	else if (s == '/') {
		z = cplx_div(z1,z2);	
		return z;
	}
	else { 
		printf("Erreur de signe d'opération\n");
	}
}

//inverse du nombre complexe
cplx complex_inv(cplx z1) 
{
	if (z1.r == 0 && z1.i == 0) {
		printf("On ne peut pas l'inverse d'un nombre nul");
		exit (-1);
	}
	cplx z;
	z.i = 0;
	z.r = 1;
	z = cplx_div(z,z1);

	return z;
}

cplx complex_puis(cplx z1, int n) 
{
	cplx  z;
	int i;

	if (n == 0) {
		z.r = 1;
		z.i = 0;
		return z;
	}
	else if ( n == 1) {
		return z1;
	}
	else if (n == -1) {
		z = complex_inv(z1);
		return z;
	}
	else if(n > 0) {
		z = z1;
		for(i = 0; i < n; i++){
			z = cplx_mult(z,z1);
		}
	}
	else if (n < 0) {
		z1 = complex_inv(z1);
		z = z1;
		for (i = 0; i < n; i++) {
			z = cplx_mult(z,z1);
		}
	}	
}

void complex_aff(cplx z) 
{
	printf("%.2f+i%.2f\n",z.r,z.i);
}

void oppc_affichage(cplx z1, char s, cplx z2, cplx z)
{
	printf("(%.2f+i%.2f)",z1.r,z1.i);
	printf(" %c ",s);
	printf("(%.2f+i%.2f)",z2.r,z2.i);
	printf(" = ");
	printf("(%.2f+i%.2f)\n",z.r,z.i);
}

