#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo * stg;
    
}Cola;

void encola(Cola**, Cola**, int); /* añade un elemento al final de la cola. */

int desencola(Cola**, Cola **); /* elimina y retorna el primer elemento de la cola.  */

void vaciaCola(Cola **, Cola **); /* vacia la cola, el tamaño pasa a ser cero.  */

int tamano(Cola *); /* retorna el tamaño de la cola, el número de elementos.  */

int estaVacia(Cola **); /* retorna verdadero si esta vacía. */

int inicio(Cola *); /* retorna pero no elimina al primer elemento. */

int main(){

Cola *frente, *final;
frente=NULL;
final=NULL;
printf("Encolo el 14 \n");
	encola (&frente, &final, 14);
	printf("Encolo el 7 \n");
	encola (&frente, &final, 7);
	printf("Encolo el 26 \n");
	encola (&frente, &final, 26);
	printf("Encolo el 13 \n");
	encola (&frente, &final, 13);
	
	printf("\n El tamano de la cola es %d. \n", tamano(frente));	

   printf(" \n  Su frente es %d. \n", inicio(frente));

	printf(" \n Desencolo el %d \n", desencola(&frente, &final));

	printf(" Desencolo el %d \n", desencola(&frente, &final));
	
	printf(" \n Ahora su tamano de la cola es %d. \n", tamano(frente));	

	printf(" \n  Ahora su frente es %d. \n", inicio(frente));
	
	printf("\nEncolo el 20 \n");
	encola (&frente, &final, 20);
	printf("Encolo el 30 \n");
	encola (&frente, &final, 30);
	printf("Encolo el 40 \n");
	encola (&frente, &final, 40);

	printf(" \n Desencolo el %d \n", desencola(&frente, &final));

	printf("\n Ahora su  tamano de la cola es %d. \n", tamano(frente));
	
    printf(" \n Ahora su  frente es %d. \n", inicio(frente));
	
	printf("\n Vacio la cola  \n");
	vaciaCola(&frente, &final);

	printf("\n  En verdad la cola esta vacia? \n");
	vaciaCola(&frente, &final);

	return 0;

}




void encola(Cola** ini, Cola** fin, int i){ 
	if(estaVacia(ini)){  
		*ini = (Cola*) malloc (sizeof(Cola));
		(*ini)->dato = i; 
		(*ini)->stg = NULL;
		// Igualo inicio y final. Al momento de encolar, si es el primer elemento que se ingresa, el puntero frente y final referencia a este primer nodo. 
		*fin = *ini; 
	} else {
        Cola *nuevo=(Cola*) malloc (sizeof(Cola));
		(*fin)->stg = nuevo;
		*fin=(*fin)->stg; // Si lo hago antes de inicializar "fin.sgte", "final" queda apuntando a NULL y pierdo la referencia 
		(*fin)->dato = i;
		(*fin)->stg = NULL;		
	}
} /* añade un elemento al final de la cola. */

int desencola(Cola**frente, Cola **final){
    Cola * temp = *frente;
    int i ;
  	if(estaVacia(frente)){ 
	printf("\n La cola esta vacia\n");
	} else {
		if (*frente == *final) 
			*final = NULL;// igualo a fin a nada osea null
		 i = (*frente)->dato;
		 //  utilizo un temporal para luego poder liberar el nodo desencolado sin perder la referencia 
		*frente = (*frente)->stg; // me muevo  al siguiente 
		free(temp);	//libero la memoria 
		
		
	}
    return i;
}; /* elimina y retorna el primer elemento de la cola.  */

void vaciaCola(Cola **frente, Cola **final){
   if(estaVacia(frente)){ 
		printf("\n Si la cola ya  esta vacia. \n");        
    }else if (*frente==*final) { 
   	    free(*frente); // Puedo liberar asi nomas porque no necesito sacar ningun dato,al liberar frente estoy liberando fin
    *frente=NULL; 
    *final=NULL;// me quedaba el último elemento en la cola. 
	}else {
        Cola * tmp = *frente; // Creo un temporal para no peorder referencia al que estoy eliminando 
        *frente = (*frente)->stg; // Apunto frentecio al siguiente elemento de la cola
        free(tmp); // Libero la memoria ocupada por el elemento que elimine 
        vaciaCola(frente, final); // Llamo a la funcion recursivamente para que elimine nodos hasta que quede el ultimo elemento 
    }   
}; /* vacia la cola, el tamaño pasa a ser cero.  */

int tamano(Cola *frente){
    int c =0;
while(!estaVacia(&frente)){
c++;
frente=frente->stg;
}
return c;
} /* retorna el tamaño de la cola, el número de elementos.  */

int estaVacia(Cola **frente){
    return *frente==NULL;
}; /* retorna verdadero si esta vacía. */

int inicio(Cola *frente){
    return frente->dato;
}; /* retorna pero no elimina al primer elemento. */