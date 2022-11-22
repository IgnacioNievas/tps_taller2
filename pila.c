#include <stdio.h>

#define CAPACIDAD 8

int elementos[CAPACIDAD];

int punta = -1;

void apila (int); /* agrega un elemento */

int desapila (); /* elimina y retorna el primer elemento */

void vaciaPila (); /* vacia la pila (pasa a tener tamano 0) */

int tamao  ();  /* da la cantidad de elementos que posee la pila */

_Bool estaVacia (); /* indica si la pila tiene o no elementos */

int cima (); /* retorna el primer elemento pero no lo elimina */



int main(){
for(int i = 0 ; i < CAPACIDAD; i++){
    printf("Apilamos %d \n", i+8);
    apila(i+8);
}
printf("\n apilo el %d\n",2);
apila(2);
printf("\n Desapilamos el %d \n", desapila());
printf("\n La punta es %d. Y el fondo seria %d \n", punta+1 , cima());
printf("\n La pila tiene %d elementos. \n", tamao ());

	//  la vaciamos 
	vaciaPila();
	if (estaVacia()) printf(" \n La pila esta vacia. \n");
	
	//probando desapilar con pila vacia

	printf("\n Desapilamos %d \n", desapila()); 

}

void apila(int e){
    if(tamao()== CAPACIDAD){
       printf("\n No se puede apilar %d, la pila ha alcanzado su capacidad maxima de %d elementos. \n", e, CAPACIDAD);
    }
    punta+=1;
    elementos[punta]= e;
    }


int desapila (){
  if(estaVacia()){
        printf("la pila esta vacia");
    }
    punta-=1;
    return elementos[punta +1];
    
    }

int tamao (){
return(punta+1);
}

_Bool estaVacia (){
    return (punta ==-1 );
}

void vaciaPila (){
  punta = -1;
}

int cima(){
    return elementos[punta] ;
}