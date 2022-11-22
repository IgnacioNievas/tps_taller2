#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo
{
    int anterior, posterior; 
	int * elementos; 
	int capacidad;
	int vacia;
}circular;


circular * inicializaCola(int);

int suma_uno(int, int); 
void vaciar(circular **); 
int estaVacia(circular *); 
int estaLlena(circular *); 
int frente(circular *); 
void encolar(circular **, int); 
int desencolar(circular **); 

int main(){

	circular * aro = inicializaCola(10);

	for(int i=0; i<aro->capacidad; i++){
		encolar(&aro, (i+20));
		printf("Encolo %d en elementos[%d]. \n", i+20, aro->posterior-1);
		printf("Posterior %d y anterior %d.  \n", aro->posterior, aro->anterior);
	}

	printf("\n Con la cola llena, intento encolar 30.\n");	
	encolar(&aro, 30);


	for(int i=0; i<(aro->capacidad); i++){
		printf("\n Desencolo %d de la posicion %d del array \n", desencolar(&aro), aro->anterior-1);
		printf("Posterior %d y anterior %d  \n", aro->posterior, aro->anterior);
	}

	if (estaVacia(aro) == 1){
	printf("\n La cola esta vacia \n");}
	else {printf("\n La cola  no esta vacia \n"); }

	for(int i=0; i<aro->capacidad-8; i++){
		encolar(&aro, (i+40));
		printf(" \n Encolo %d en elementos[%d]. \n", i+40, aro->posterior-1);
		printf("Posterior %d y anterior %d  \n", aro->posterior, aro->anterior);
	}
if (estaVacia(aro) == 1){
	printf("\n La cola esta vacia \n");}
	else {printf("\n La cola  no esta vacia \n"); }

	printf("\n  El frente es: %d \n", frente(aro));

	printf("\n Vacio la cola  \n");	
	vaciar(&aro);

		if (estaVacia(aro) == 1){
	printf("\n La cola esta vacia \n");}
	else {printf("\n La cola  no esta vacia \n"); }

	printf(" \n El frente es: %d \n", frente(aro));

	return 0;
}

circular * inicializaCola(int cap){
	circular * cola = (circular*) malloc (sizeof(circular));
	cola->anterior = 1;
	cola->posterior = cap;
	cola->elementos = (int*) malloc (cap * sizeof(int));
	cola->capacidad = cap;
	cola->vacia = 1;
}

 // suma uno con modulo para que al llegar a la capacidad máxima "vuelva" al inicio de la cola 
int suma_uno(int posicion, int capacidad) {
	return ((posicion % capacidad) + 1);
} 

// vacia la cola 
void vaciar(circular ** cola){ 
	(*cola)->anterior = 1;
	(*cola)->posterior = (*cola)->capacidad;
	(*cola)->vacia = 1;
} 

// devuelve 1 si esta vacia y 0 si no esta vacia 
int estaVacia(circular * cola){ 
	return (cola->vacia);
} 
// devuelve 1 si la cola esta llena y 0 si queda espacio
int estaLlena(circular * cola){
	return ((suma_uno(cola->posterior, cola->capacidad) == cola->anterior) & !estaVacia(cola)); 
}

void encolar(circular ** cola, int elem){ 
	if(estaLlena(*cola)){

		printf(" \n No se puede encolar %d, la cola esta llena.\n", elem);}

	else {
		
		(*cola)->posterior = suma_uno((*cola)->posterior, (*cola)->capacidad);
		if ((*cola)->posterior-1 >= (*cola)->capacidad){
				printf(" \n Pasaste de la capacidad max!\n"); 
				return;
			}

		(*cola)->elementos[(*cola)->posterior-1] = elem; 

		if (estaVacia(*cola)){
			(*cola)->vacia = 0;	}
	}
}

int desencolar(circular ** cola){ 
	
	if (estaVacia(*cola))
		printf("\n La cola esta vacia.\n");
	else {
		int i = *((*cola)->elementos + (*cola)->anterior-1);		
		(*cola)->anterior = suma_uno((*cola)->anterior, (*cola)->capacidad);
		
		return i;
	}
}
// muestra el elemento que saldria primero, el "frente"
int frente(circular * cola){ 
	if (estaVacia(cola)){

		printf("Una cola vacia no tiene frente.\n");
		

	} 
	else
		
		return *((cola->elementos + cola->anterior) - 1);

}
