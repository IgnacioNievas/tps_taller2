#include <stdio.h>

#define CAPACIDAD 7

int elementos[CAPACIDAD];

int punta = -1;

void apila (int); /* agrega un elemento */

int desapila (); /* elimina y retorna el primer elemento */

void vaciaPila (); /* vacia la pila (pasa a tener tamano 0) */

int tamao  ();  /* da la cantidad de elementos que posee la pila */

_Bool estaVacia (); /* indica si la pila tiene o no elementos */

int cima (); /* retorna el primer elemento pero no lo elimina */



int main ()
{
	//  llenamos la pila. 
	for (int i=0; i<CAPACIDAD; i++){
		printf("Apilamos %d \n", i+7);
		apila(i+7);
	}
	printf("\n Apilamos el %d \n", 2);
	apila(2);
	printf("\n Desapilamos el %d \n", desapila());
	printf("\n La punta es %d. Y el fondo seria %d \n", punta +1, cima());
	printf("\n La pila tiene %d elementos. \n", tamao ()+1);

	//  la vaciamos 
	vaciaPila();
	if (estaVacia()) printf(" \n La pila esta vacia. \n");
	
	//probando desapilar con pila vacia

	printf("\n Desapilamos %d \n", desapila()); 
		
	return 0;
}

void apila (int e){
	if (tamao () == CAPACIDAD){
		printf("\n No se puede apilar %d, la pila ha alcanzado su capacidad maxima de %d elementos. \n", e, CAPACIDAD);
	} else {
		punta += 1;
		elementos[punta] = e;
	}
}

int desapila (){
	if (estaVacia()) {
		printf("\n No hay elementos en una pila vacia.\n");
	
	} else {
		// solo mueve el valor porque no elimino elementos anteriores ni los verifico en null, si no que los sobreescribo podría acceder a valores antiguos
		punta-=1 ; 
		return elementos[punta + 1];  
	}
	
} 

void vaciaPila(){ 
	// solo digo que si es -1 esta vacia
punta = -1;
}

int tamao  (){
	//  es +1 porque no contiene elementos
	return (punta + 1); 
}

_Bool estaVacia (){
	// si me devuelve -1 esta vacia la pila
	return (punta == -1); 
}

int cima (){
	//  veo que hay en la cima 
	return elementos[punta]; 
}