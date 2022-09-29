#include <stdio.h>
#include <stdlib.h>

 typedef struct {
 int numerador , denominador ;
 } fraccion ;

 int mcd ( fraccion * pfr) ; // calcula el minimo comun divisor y lo retorna

 fraccion reduce ( fraccion * pfr ) ; // retorna la fraccion reducida

 void muestraFraccion ( fraccion  auxi ) ; // imprime por pantalla los valores

 int main () {
 fraccion f1 = {140 , 26};
 fraccion f2 = {380 , 44};
 fraccion f3 = {830 , 675};
muestraFraccion ( reduce (&f1) ) ;
 muestraFraccion ( reduce (&f2) ) ;
 muestraFraccion ( reduce (&f3) ) ;

 return 0;
 }

 int mcd(fraccion * pfr){
	int a,b,q,aux;//denominador, numerador ,el cociente y auxiliar
	div_t cociente ; //una variable de tipo div_t que es un struct  que a su vez tiene dos variables: el residuo y el cociente que viene de la libreria stdlib.h 
	a = pfr->numerador;//Sea a el mayor es numerador. 
	b = pfr->denominador;//y b el menor es denominador.
	
	while (b!=0) {
		aux = b; //asigno denominador a  una auxiliar para no perder el valor
		cociente = div(a,b); //Divıdase a entre b (utilizo la funcion div para dividir a y b , que seria como si usara el / , esa funcion proviene de dicha librería  stdlib.h)
		q = cociente.quot;//y sea q el cociente ( el nombre de la struct es cociente que contiene al cociente que seria .quot)
		b = cociente.rem; // Hagase  b = r( el nombre de la struct es cociente que contiene al cociente que seria .rem)
		a = aux; //Hagase a = b 
		
	}
	return a; //Repıtase desde el paso 2 hasta que b sea 0.
};


fraccion reduce(fraccion * pfr){ 
	fraccion auxi;

	// Divıdase numerador y denominador entre a.
	auxi.numerador = (pfr->numerador) / mcd(pfr);
	auxi.denominador = (pfr->denominador) / mcd(pfr);

	return auxi;
}	
	
void muestraFraccion (fraccion auxi) {
	printf("La fracion reducida  es : %d/%d\n\n", auxi.numerador, auxi.denominador);
}
