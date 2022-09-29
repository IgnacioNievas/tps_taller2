#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* sgte;
}cola;

void encola(cola**, cola**, int); /* añade un elemento al final de la cola. */

int desencola(cola**, cola **); /* elimina y retorna el primer elemento de la cola.  */

void vaciaCola(cola **, cola **); /* vacia la cola, el tamaño pasa a ser cero.  */

int tamano(cola *); /* retorna el tamaño de la cola, el número de elementos.  */

int estaVacia(cola **); /* retorna verdadero si esta vacía. */

int frente(cola *); /* retorna pero no elimina al primer elemento. */



int main ()
{
	cola *inicio , *final; 
	inicio = NULL;

	final = NULL;
	
	printf("Encolo el 14 \n");
	encola (&inicio, &final, 14);
	printf("Encolo el 7 \n");
	encola (&inicio, &final, 7);
	printf("Encolo el 26 \n");
	encola (&inicio, &final, 26);
	printf("Encolo el 13 \n");
	encola (&inicio, &final, 13);
	
	printf("\n El tamano de la cola es %d. \n", tamano(inicio));	

   printf(" \n  Su frente es %d. \n", frente(inicio));

	printf(" \n Desencolo el %d \n", desencola(&inicio, &final));

	printf(" Desencolo el %d \n", desencola(&inicio, &final));
	
	printf(" \n Ahora su tamano de la cola es %d. \n", tamano(inicio));	

	printf(" \n  Ahora su frente es %d. \n", frente(inicio));
	
	printf("\nEncolo el 20 \n");
	encola (&inicio, &final, 20);
	printf("Encolo el 30 \n");
	encola (&inicio, &final, 30);
	printf("Encolo el 40 \n");
	encola (&inicio, &final, 40);

	printf(" \n Desencolo el %d \n", desencola(&inicio, &final));

	printf("\n Ahora su  tamano de la cola es %d. \n", tamano(inicio));
	
    printf(" \n Ahora su  frente es %d. \n", frente(inicio));
	
	printf("\n Vacio la cola  \n");
	vaciaCola(&inicio, &final);

	printf("\n  En verdad la cola esta vacia? \n");
	vaciaCola(&inicio, &final);

	return 0;
}

/* añade un elemento al final de la cola. */	
void encola(cola** ini, cola** fin, int i){ 
	if(estaVacia(ini)){  
		*ini = (cola*) malloc (sizeof(cola));
		(*ini)->dato = i; 
		(*ini)->sgte = NULL;
		// Igualo inicio y final. Al momento de encolar, si es el primer elemento que se ingresa, el puntero frente y final referencia a este primer nodo. 
		*fin = *ini; 
	} else {
		(*fin)->sgte = (cola*) malloc (sizeof(cola)); 
		*fin=(*fin)->sgte; // Si lo hago antes de inicializar "fin.sgte", "final" queda apuntando a NULL y pierdo la referencia 
		(*fin)->dato = i;
		(*fin)->sgte = NULL;		
	}
}
/* elimina y retorna el primer elemento de la cola.  */
int desencola(cola** ini, cola ** fin){

	if(estaVacia(ini)){ 
	printf("\n La cola esta vacia\n");
	} else {
		if (*ini == *fin) 
			*fin = NULL;// igualo a fin a nada osea null
		int i = (*ini)->dato;
		cola * temp = *ini; //  utilizo un temporal para luego poder liberar el nodo desencolado sin perder la referencia 
		*ini = (*ini)->sgte; // me muevo  al siguiente 
		free(temp);	//libero la memoria 
		return i;
		
	}

} 

/* vacia la cola, el tamaño pasa a ser cero.  */
void vaciaCola(cola ** ini, cola ** fin) {

    if(estaVacia(ini)){ 
		printf("\n Si la cola ya  esta vacia. \n");        
    }else if (*ini==*fin) { 
   	    free(*ini); // Puedo liberar asi nomas porque no necesito sacar ningun dato,al liberar ini estoy liberando fin
   	    *fin=*ini=NULL; // me quedaba el último elemento en la cola. 
	}else {
        cola * tmp = *ini; // Creo un temporal para no peorder referencia al que estoy eliminando 
        *ini = (*ini)->sgte; // Apunto inicio al siguiente elemento de la cola
        free(tmp); // Libero la memoria ocupada por el elemento que elimine 
        vaciaCola(ini, fin); // Llamo a la funcion recursivamente para que elimine nodos hasta que quede el ultimo elemento 
    }

}

/* retorna el tamaño de la cola, el número de elementos.  */
int tamano(cola * cola){

		int i = 0; 

	while(cola!=NULL){
		i++; 
		cola = cola->sgte; 	
	}

	return i;

}
/* retorna verdadero si esta vacía. */
int estaVacia(cola ** c){
	return (*c==NULL); 
}


/* retorna pero no elimina al primer elemento. */
int frente(cola * c){
	return c->dato;
}