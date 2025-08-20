#include"srco.h"
#include<stdio.h>
#include<string.h>

cds** list(int *n) {
	cds** l = malloc(3*sizeof(cds));

	strcpy(l[0][0].u,"mery");
	strcpy(l[0][0].c,"mery");

	strcpy(l[0][1].u,"mery");
	strcpy(l[0][1].c,"mery");

	*n = 2;
	return l;


}

listcode(cds id) 
{
	int n = 0;
	cds** ref = list(n);

	for (i = 0; i < n; i++) {
		if (strcmp(id.u,ref[0][i].ui) == 0) {
			if (strcmp(id.c,ref[0][i].c) == 0) {
					free(ref);
					return 1;
			}
		}
	}
	printf("Erreur, le code ou username est incorrect\n");
	free(ref);
	return (-1);
}
