#include <stdio.h>

/// Exo 1

struct _cell{
	int valeur;
	struct _cell * suiv;
};

// Redefinition of type: now we call 'CELL' to 'struct _cell'
typedef struct _cell CELL;
// Equivalent: 
//typedef struct _cell{
//	int valeur;
//	struct _cell * suiv;
//} CELL;


typedef CELL * LIST;









int main(int argc, char **argv)
{
	printf("hello world TD 2 Liste Simple\n");
	return 0;
}
