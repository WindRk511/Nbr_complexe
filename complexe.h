struct complexe {
        float r;
        float i;
};
typedef struct complexe cplx;
float complex_module(cplx z);
float complex_argument(cplx z);
cplx complex_conj(cplx z);
cplx cplx_add(z1,z2);
cplx cplx_add(cplx z1, cplx z2);
cplx cplx_mult(cplx z1, cplx z2);
cplx cplx_mult(cplx z1, cplx z2);
cplx complex_ope(cplx z1, char* s, cplx z2);
cplx complex_inv(cplx z1);
cplx complex_puis(cplx z1, int n);
void complex_aff(cplx z);
void oppc_affichage(cplx z1, char s, cplx z2, cplx z);




