#include <stdio.h>

typedef struct { int a; float b,c;} S;

int main(int argc, char **argv)
{
	printf("Quizz 2: question 6. Algo 4: ------\n");
	// 3 instuctions: 2 declaration, 1 affectation.
	//S mon_s, * p=&mon_s;
	
	//Equivalent
	S mon_s; // Decl variable
	S * p; // Decl pointer
    p = & mon_s; // initialisation pointer: address de Mon_s.
	
	//mon_s : -->pas initialisation: reservation de la memoire dans la declaration.
	printf("\n address mon_s: %p", &mon_s);
	//Affiche la valeur a l'interieur de la variable pointer.
	printf("\n valuer pointer p %p", p); //init avec address de mon_s
	
	// Ca marche, mais on n outilise pas des address de pointers.
	printf("\n address pointer p %p", &p); 
	
	printf("\n mon_s.a: %p", &mon_s.a);
	printf("\n mon_s.b: %p", &mon_s.b);
	printf("\n mon_s.c: %p", &mon_s.c);
	
	printf("\n (avant init)valuer  de mon_s.a : %d", mon_s.a);
	
	//Initialisation des champs
	mon_s.a = 10;
	mon_s.b = 1.0;
	mon_s.c = 2.4;
	
	printf("\n (apres init) valuer  de mon_s.a : %d", mon_s.a);
	
	printf("\n (apres init) valuer  de mon_s.a avec pointer : %d", p->a);
	
	S mon_s_2; // -->pas initialisation: reservation de la memoire dans la declaration.
	
	printf("\n mon_s2: %p", &mon_s_2);

	printf("\n mon_s2.a: %p", &mon_s_2.a);
	printf("\n mon_s2.b: %p", &mon_s_2.b);
	printf("\n mon_s2.c: %p", &mon_s_2.c);
	
	//
	
	
	
	
	
	
	
	
	//S allMyS[10000000];
	
	
	
	
	
	
	
	
	printf("\nEnd--");
	return 0;
}
