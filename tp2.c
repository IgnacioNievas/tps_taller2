#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* sgte;
}pila;

void apila(pila**, int); /* agrega un elemento . */

int desapila(pila **); /* elimina y retorna el primer elemento . */

void vaciaPila(pila **); /* vacia la pila ( pasa a tener tamaño 0) . */

int tamano(pila *); /* da la cantidad de elementos que posee la pila . */

int estaVacia(pila **); /* indica si la pila tiene o no elementos . */

int cima (pila *); /* retorna el primer elemento pero no lo elimina . */


int main ()
{

pila * punta; /* creo la pila */

punta = NULL ; /* la seteo en NULL porque está vacía */

// pruebo que este vacia
if (estaVacia(&punta) == 1){
printf(" La pila esta vacia \n");}
else{ printf(" La pila no esta vacia  \n", estaVacia(&punta));} 

// creo la pila

printf("\n Apilo 26\n");
apila(&punta, 26); 
printf(" \n Apilo 7\n");
apila (&punta, 7); 
printf(" \n Apilo 17\n");
apila (&punta, 17); 

// verifico el tamaño
printf("\n El tamano de la pila es %d.\n", tamano (punta)); 

// saco un dato tendria que ser el 17
printf("\n Saco el dato: %d. \n", desapila(&punta)); 
printf("\n El dato que quedo en la cima es el %d. \n",cima(punta)); 
// verifico el  nuevo tamaño
printf("\n El tamano de la pila es %d.\n", tamano (punta)); 

// agrego mas elementos
printf("\n Apilo 126\n");
apila (&punta, 126);
printf("\n Apilo 35\n");
apila (&punta, 35);
printf("\n Apilo 123\n");
apila (&punta, 123);
printf("\n Apilo 14\n");
apila (&punta, 14);

// verifico el  nuevo tamaño
printf("\n El tamano de la pila es %d.\n", tamano (punta)); 


// saco  otro dato tendria que ser el 14
printf("\n Desapilo el dato: %d. \n", desapila(&punta)); 
// verifico el  nuevo tamaño
printf("\n El tamano de la pila es %d.\n", tamano (punta)); 
// me fijo que quede 123 como cima para verificar que funciona 
printf("\n El dato que quedo en la cima es el %d. \n",cima(punta)); 

// repito con mas datos 
printf("\n Saco el dato: %d. \n", desapila(&punta));
printf("\n Saco el dato: %d. \n", desapila(&punta));
printf("\n El tamano de la pila es %d.\n", tamano (punta));
printf("\n El dato que quedo en la cima es el %d. \n",cima(punta));

// pruebo la funcion para ver si anda correctarmente la de limpieza
vaciaPila(&punta);

if (estaVacia(&punta) == 1){
printf(" La pila esta vacia \n");}
else{ printf(" La pila no esta vacia  \n", estaVacia(&punta));} 


return 0; 

}

/* agrega un elemento . */
void apila (pila** pil, int i){
	// funciona  si esta vacia , luego reserva memoria para la nueva cima de la pila, ingresa el dato de la cima, digo que el nodo siguiente no existe
	//si la pila tiene mas elementos hago lo mismo pero Le asigno el dato pasado por parámetro al  nuevo nodo yEstoy apilando, los nuevos nodos van "arriba", la cima queda "abajo" del nuevo nodo.
		if (estaVacia(pil)){
		*pil = (pila*) malloc(sizeof(pila)); 
		(*pil)->dato = i;   
		(*pil)->sgte =NULL; 
	} else {
		pila * nuevo = (pila*) malloc(sizeof(pila)); 
		nuevo->dato = i; 
		nuevo->sgte = *pil; 
		*pil = nuevo; 		
	}

}

/* elimina y retorna el primer elemento . */
int desapila(pila ** pil){
// funciona guardando el dato que voy a retornar  i, y crea un temporal para mantener el puntero al que estoy desapilando para no perder la referencia y poder liberarlo
// luego apunta hacia la cima al siguiente elemento de la pila , libera memoria ocupada por el elemento que acabo de desapilar , por ulitmo devuelvo el dato guardado en el elemento desapilado
	if (!estaVacia(pil)){
	
		int i = (*pil)->dato; 
		pila * tempo = *pil; 
		*pil = ((*pil)->sgte); 
		free(tempo); 
		return i; 
	}

}
 /* vacia la pila ( pasa a tener tamaño 0) . */
void vaciaPila(pila ** pil){ 
	//esta funcion vacie la pila, no que retorne el dato , como ??
//creo un temporal para mantener el puntero al que estoy eliminando para no perder la referencia y poder liberarlo , apuntando cima al siguiente elemento de la pila y llamo a la funcion recursivamente para que elimine nodos hasta que la pila este vacia 

	if(!estaVacia(pil)){ 
		pila * tempo= *pil; 
		*pil= (*pil)->sgte; 
		free(tempo); 
		vaciaPila(pil); 
	}

}
/* da la cantidad de elementos que posee la pila . */
int tamano(pila * pil){

	int i = 0; 
//Mientras la pila no esté vacía , recorro la pila hasta que esté vacía 
	while(!estaVacia(&pil)){ 
		i++; 
		pil =pil->sgte; 
	}

	return i;
}

 
/* indica si la pila tiene o no elementos . */
int estaVacia(pila ** pil) { 
	return (*pil==NULL); 
}


/* retorna el primer elemento pero no lo elimina . */
int cima (pila * pil){
	return pil->dato; 
}