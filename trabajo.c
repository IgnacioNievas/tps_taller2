#include "trabajo_TDA.h"


int main(void){
    politico *chicosBuenos, *chicosMalos;
    chicosBuenos = NULL;
    chicosMalos = NULL;

    elegirLista('f', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "jose", &chicosBuenos, &chicosMalos);
    elegirLista('f', "alejandro", &chicosBuenos, &chicosMalos);
    elegirLista('f', "juan", &chicosBuenos, &chicosMalos);
     printf("\n");
    printf("Lista de buenos:\n");
    mostrar(chicosBuenos);
     printf("\n");
    elegirLista('d', "nahuel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "adrian", &chicosBuenos, &chicosMalos);
    elegirLista('d', "yair", &chicosBuenos, &chicosMalos);
     printf("\n");
    printf("Lista de malos:\n");
    mostrar(chicosMalos);
     printf("\n");
    elegirLista('d', "daniel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "joel", &chicosBuenos, &chicosMalos);
    elegirLista('f', "nahuel", &chicosBuenos, &chicosMalos);
    elegirLista('d', "juan", &chicosBuenos, &chicosMalos);
   elegirLista('d', "yair", &chicosBuenos, &chicosMalos);
    elegirLista('e', "roberto", &chicosBuenos, &chicosMalos);
    
    printf("\n");
    printf("Lista de buenos:\n");
    mostrar(chicosBuenos);
    
    printf("\n");
    printf("Lista de malos:\n");
    mostrar(chicosMalos);
}   



void insertar(char nombre[], politico **lista){
    if(*lista == NULL){
        *lista = (politico*)malloc(sizeof(politico));
        strcpy((*lista)->nombre, nombre);
        (*lista)->sgte = NULL;
        
    }else if(miembro(nombre, *lista)){
            printf("- %s se mantiene en su lista.\n", nombre);
        }else  if((*lista)->sgte != NULL){
            politico *nuevo = (politico*)malloc(sizeof(politico));
            strcpy(nuevo->nombre, nombre);
            nuevo->sgte = (*lista)->sgte;
            (*lista)->sgte = nuevo;
           
        }else{
            insertar(nombre, &(*lista)->sgte);
        }
        
    
}

void suprimir(char nombre[], politico **lista){
    if(*lista == NULL){
       printf("- No hay politico para eliminar\n");
    }else if(miembro(nombre, *lista)){
            politico *fuera = (*lista);
            (*lista) = (*lista)->sgte;
            printf("- Se elimino a %s\n",fuera->nombre);
            free(fuera);
        }else{
            suprimir(nombre, &(*lista)->sgte);
        }
    
}

void mostrar(politico *lista){
    politico *temp;
    temp = lista;
    if(lista != NULL){
        while(temp != NULL){
            printf("%s\n", temp->nombre);
            temp = temp->sgte;
        }
    }else{
        printf("Lista vacia.\n");
    }
}

int miembro(char nombre[], politico *lista){
    politico *temp = NULL;
    temp = lista;
    if(lista != NULL){
        while(temp != NULL){
            if(strcmp((temp)->nombre, nombre) == 0){
                return 1;
            }
                temp = temp->sgte;
            
        }
    }
    return 0;  
}

void elegirLista(char voto,char nombre[],politico **buenos,politico **malos){
    if(voto == 'f'){
        if(miembro(nombre, *malos)){
            suprimir(nombre, malos);
            insertar(nombre, buenos);
            printf("- %s se pasa a los Chicos Buenos\n", nombre);
        }else {
            insertar(nombre, buenos);
            printf(" - %s se une a los Chicos Buenos\n", nombre);
        }
    }else if(voto == 'd'){
        if( miembro(nombre, *buenos)){
            suprimir(nombre, buenos);
            insertar(nombre, malos);
            printf("- %s se pasa a los Chicos Malos\n", nombre);
        }else{
            insertar(nombre, malos);
            printf("- %s se une a los Chicos Malos\n", nombre);
        }
    }else if(voto == 'e'){
        printf("- %s se adstubo en la votacion\n", nombre);
    }
    
}