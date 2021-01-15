#include <stdio.h>

struct _date{
	int jour;
	int mois;
	int annee;
	struct _date * suiv;
};

// Redefinition of type
typedef struct _date DATE;
typedef DATE * LIST;


int main(int argc, char **argv)
{
	printf("TD 2: Exo 2\n");
	return 0;
}
