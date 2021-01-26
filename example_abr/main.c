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
ABR createABRNode(int valeur){
	ABR newNode = NULL;
	
	newNode = (ABR) malloc(sizeof(struct _noeud));
	
	newNode -> val = valeur;
	newNode -> fg = NULL;
	newNode -> fd = NULL;
	return newNode;
	
}
//Exo 3
ABR insertInABR(int value, ABR currentNode){
	
	//printf("Inserting value:\n");
	if(currentNode == NULL){
		//printf("Creating node\n");
		return createABRNode(value);
	}else{
		if(currentNode-> val > value){
			currentNode -> fg =  insertInABR(value, currentNode -> fg);
			}
		else{
			currentNode -> fd =   insertInABR(value, currentNode -> fd);
		}
		return currentNode;
		}
	
}
//Exo 4
void afficherABR(ABR currentNode){
	if(currentNode != NULL){
			afficherABR(currentNode->fg);
			printf("value %d\n", currentNode -> val);
			afficherABR(currentNode->fd);
		}
	}
// exo  5

int main(int argc, char **argv)
{
	printf("TD 4 ABR: \n");
	
	ABR a=NULL; // equivalent:  struct _noeud * a = NULL;
	///  exo 1: {4,2,1,8,6,7,3,9,5}
	a = insertInABR(4, a);
	a = insertInABR(2, a);
	a = insertInABR(1, a);
	a = insertInABR(8, a);
	a = insertInABR(6, a);
	a = insertInABR(7, a);
	a = insertInABR(3, a);
	a = insertInABR(9, a);
	a = insertInABR(5, a);
	printf("printing ABR:\n");
	afficherABR(a);
	
	return 0;
}
