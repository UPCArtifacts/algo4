#include <stdio.h>

/// Exo 1

struct Client{
	int nrClient;
	int identifier;
	};

struct _cell{
	int valeur;
	//Si je veux une liste de Client, je change la valeur de la cellule i.e., du champ 'valeur' 
	//struct Client valeur;
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

// Exo 2 TD 2. Create cell
CELL* createCell(int valueDeLaCellule){
	
	CELL* newCell;
	newCell = (CELL*) malloc(sizeof(CELL));
	//Affectation -init-
	newCell->valeur = valueDeLaCellule;
	// return l addresse òu nous avons stocké la nouvelle cellule.
	return newCell;
}

// Avec Client: 
//CELL* createCell(struct Client valueOfClient){
//....
///}

//CELL* createCell(int nrClient, int identifier){
//...
//}



int main(int argc, char **argv)
{
	printf("hello world TD 2 Liste Simple\n");
	
	printf("Exo 2: \n");
	
	int valueOfNewElement = 10;
	CELL * createdCellDix = createCell(valueOfNewElement);
	
	printf("La valeur à l'interieur de la cellule est: %d", createdCellDix->valeur);
	//equivalent:
	//printf("La valeur à l'interieur de la cellule est: %d", (*createdCellDix).valeur);
	
	return 0;
}
