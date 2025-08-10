#include"complexe.h"
#include<stdio.h>

void complex_recu(cplx* z1)
{
	float d;
	 printf("nombre complexe sous forme : a+ib\n");
	 printf("a=");
	 scanf("%f",&d);
	 z1->r = d;
	 printf("b=");
	 scanf("%f",&d);
	 z1->i = d;
}

void exe_menu(int c)
{
	cplx z1,z2,z;
	float a,m;
	int n;
	char s;
	char* ps = &s;
	switch (c) {
		case 1: printf("Entre le nombre complexe:\n");
			complex_recu(&z);
			a = complex_argument(z);
			m = complex_module(z);
			printf(" Argument : %.2f ; Module : %.2frad\n",a,m);
			break;
		case 2: printf("Entre les nombres complexes :\n");
			printf("Le premier :\n");
			complex_recu(&z1);
			printf("\nLe second :\n");
			complex_recu(&z2);
			printf("L'operade (+,-,*,/) :  ");
			scanf(" %c",ps);
			z = complex_ope(z1,s,z2);
			oppc_affichage(z1,s,z2,z);
			break;
		case 3:	printf("Entre le nombre complexe:\n");
			complex_recu(&z);
			printf("Entre l'exposant : ");
			scanf("%d",&n);
			z = complex_puis(z,n);
			complex_aff(z1);
			printf(" puissance %d est ",n);
			complex_aff(z);
		default:
			printf("Aucun correspondant!\n");
			break;
	}
}

void complex_menu() 
{
	int a,t;
	char tc;

	printf("_________________________MENU :_______________________\n");
	printf("1. Recherche d'argument et module \n");
	printf("2. Operation arithmetique entre deux nombres complexes\n");
	printf("3. Trouve la puissance d'un nombre complexe");

	printf("\nChoisir l'un à ces menu :\n");
	scanf("%d",&a);

	exe_menu(a);

}

