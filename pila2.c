#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo * sgt;
    
    
}Pila;

void apila(Pila **, int); /* agrega un elemento . */

int desapila(Pila **); /* elimina y retorna el primer elemento . */

void vaciaPila(Pila **); /* vacia la pila ( pasa a tener tamaño 0) . */

int tamano(Pila *); /* da la cantidad de elementos que posee la pila . */

int estaVacia(Pila **); /* indica si la pila tiene o no elementos . */

int cima (Pila *); /* retorna el primer elemento pero no lo elimina . */

int main(){
    Pila *punta;
    punta = NULL;

    if (estaVacia(&punta) == 1){
printf(" La pila esta vacia \n");}else{
 printf(" La pila no esta vacia  \n");}


printf("agregamos el %d",1);
apila(&punta, 1);
printf("agregamos el %d",3);
apila(&punta, 3);
printf("agregamos el %d",13);
apila(&punta, 13);
printf("agregamos el %d",21);
apila(&punta, 21);

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
printf(" La pila esta vacia \n");}else{
 printf(" La pila no esta vacia  \n");} 


}



void apila(Pila ** pil , int d){
    if(estaVacia(pil)){
       * pil = (Pila*) malloc(sizeof(Pila));
       (*pil)->dato= d;
       (*pil)->sgt= NULL;
    }else{
        Pila *nuevo = (Pila*) malloc(sizeof(Pila));
        nuevo->dato= d;
        nuevo->sgt=*pil;
        *pil=nuevo;
    }

}


int desapila(Pila** pil){
      int n=0;
    if(!estaVacia(pil)){
       
         Pila *aux =NULL;
          aux=*pil;
        *pil=(*pil)->sgt;
         n = aux->dato;
        free(aux);
      
    }
 return n; 
}


void vaciaPila(Pila ** pil){
    if(!estaVacia(pil)){
Pila *aux = *pil;
*pil=(*pil)->sgt;
free(aux);
vaciaPila(pil);
}

}

int tamano(Pila * pil){
    int c=0;
    while(!estaVacia(&pil)){
        c++;
        pil=pil->sgt;
    }
    return c;
}

int estaVacia(Pila ** pil){
    return *pil== NULL;
}

int cima( Pila* pil){
    return pil->dato;
}