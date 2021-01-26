#include <stdio.h>

typedef struct _noeud
{      int val ; // valeur stockee
       struct _noeud *  fg, * fd; // pointeurs vers les noeuds fils 
} NOEUD, * ABR ;

void exo1(){
	// Donner le schéma de l’arbre obtenu en insérant la suite de valeurs 
	//{2,1,8,6,7,3,9,5} dans cet ordre dans l’arbre a.
	

}
//Exo 2
ABR createNode(int valeur){
	ABR newNode = NULL;
	
	newNode = (ABR) malloc(sizeof(struct _noeud));
	
	newNode -> val = valeur;
	
	return newNode;
	
}
//Exo 3
ABR insert(int value, ABR currentNode){
	if(currentNode == NULL){
		return createNode(value);
	}else{
		if(currentNode-> val > value){
			return insert(value, currentNode -> fg);
			}
		else{
			return insert(value, currentNode -> fd);
		}
		}
	
}


int main(int argc, char **argv)
{
	printf("TD 4 ABR: \n");
	
	ABR a=NULL; // equivalent:  struct _noeud * a = NULL;
	
	return 0;
}
