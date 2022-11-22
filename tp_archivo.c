#include "archivo.h"

int main(void){
    FILE *person, *persons;
    person = fopen("persona.txt", "r");
    persons = fopen("personas.txt", "w");
    char nombre[100];
    char apellido[100];
    char sexo[100];
    int *edad = (int*)malloc(sizeof(int));
    assert(edad != NULL);
    int *meses = (int*)malloc(sizeof(int));
    assert(meses != NULL);
    char *planPe = (char*)malloc(sizeof(char));
    assert(planPe != NULL);
    float* monto = (float*)malloc(sizeof(float));
    assert(monto != NULL);

    assert(person != NULL);
    while (!feof(person)){
        fscanf(person, "%s %s %d %s %d %c", nombre, apellido, edad, sexo, meses, planPe);
        monto = calcularPago(planPe, meses, edad);
        printf("%s %s %d %s %d %c %.2f\n", nombre, apellido, *edad, sexo, *meses, *planPe, *monto);
        fprintf(persons, "%s %s %d %s %d %c %.2f\n", nombre, apellido, *edad, sexo, *meses, *planPe, *monto);
    }
    fclose(person);
    fclose(persons);
    free(edad);
    free(meses);
    free(planPe);
    free(monto);
    return 0;
}


float* calcularPago(char *planPe, int *meses, int *edad){
    FILE *pl;
    pl = fopen("plan.txt", "r");
    assert(pl != NULL);
    char *planPl = (char*)malloc(sizeof(char));
    assert(planPl != NULL);
    int *montoPl = (int*)malloc(sizeof(int));
    assert(montoPl != NULL);
    float *monto = (float*)malloc(sizeof(float));
    assert(monto != NULL);
    while(*planPl != *planPe){
        fscanf(pl, "%c %d", planPl, montoPl);
        if(feof(pl)){
            break;
        }
    }
    if(*edad > 65 || *edad < 12){
        if(*meses > 24){
            *monto = *montoPl -((50.0/100.0) * (*montoPl));
        }else{
            *monto = *montoPl -((5.0/100.0) * (*montoPl));
        }
    }else if(*meses > 24){
            *monto = *montoPl -((45.0/100.0) * (*montoPl));
        }else{
            *monto = *montoPl;
        }
    


    return monto;

    
}