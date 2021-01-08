#include <stdio.h>



void minMaxMoyenne(
    // Parametre d'Entrée
	int n[], 
	// Parametre d'Entrée, et a la fois, sorti
	int *pmin, int *pmax, float *pmoy
){
	
	*pmin = n[0];
    *pmax = n[0]; 
	 
	 int sum = 0;
	 
	for(int i= 0; i< 5; i++ ){
		if(*pmin > n[i]) {
			*pmin = n[i];
			}
		if(*pmax < n[i]) {
			*pmax = n[i];
		}
		sum = sum + n[i];
	}
	
	*pmoy = sum / 5; //TODO: create a constant
	
	printf("Min %d", *pmin);
	printf("Max %d", *pmax);
}


int main(int argc, char **argv)
{
	printf("TD 1\n");
	int n[]  = {5,6,7,8,3}; 
	
	int resultMax = 0;
	int resultMin = 0;
	float resultMoy = 0.0;
	
	//Ap
	minMaxMoyenne(n, &resultMin,  &resultMax, &resultMoy);
	
	printf("Min %d Max %d Moy %f", resultMin, resultMax, resultMoy);
	
	printf("End");
	return 0;
}
