#include <stdio.h>
#include "validar.h"

int main(){

    int numero = 0;
    float flotante = 0.0;
    char caracter = 0;
    char *ptrCadena = NULL;

    printf( "Numero: " );
    numero = validarEntero(1,10);

    printf( "Flotante: " );
    flotante = validarFlotante(1,99.9);

    printf( "Caracter: " );
    caracter = validarCaracter();

    printf( "Cadena: " );
    validarCadena(&ptrCadena, 20);

    printf( "Cadena ingresada: %s\n", ptrCadena );

    printf( "Usuario: " );
    validarUsuario( "Hola" );

    printf( "Contraseña: " );
    validarContrasena( "Adios" );

    return 0;
}