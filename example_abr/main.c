#include <stdio.h>

typedef struct _noeud
{      int val ; // valeur stockee
       struct _noeud *  fg, * fd; // pointeurs vers les noeuds fils 
} NOEUD, * ABR ;




int main(int argc, char **argv)
{
	printf("TD 4 ABR: \n");
	
	ABR a=NULL; // equivalent:  struct _noeud * a = NULL;
	
	return 0;
}
