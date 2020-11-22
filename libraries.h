#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>  
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <unistd.h>
#include <cstdio>
/*---------------REGISTRO DE LOS PEDIDOS---------------*/
/*a) N?mero de pedido
b) Nombre del cliente.
b) Direcci?n
c) Tel?fono
d) Descripci?n del producto solicitado.
e) Total a pagar.*/

typedef struct
{
    char *nombreC;
    char *direccion;
    unsigned long long int telefono;
}pedidoCliente;

struct pedidos
{
    int id_pedido;
    pedidoCliente p_cd;
    char *descripcion;
    float totalPago;
    pedidos *siguiente;
    pedidos *anterior;
}*primeroP, *ultimoP;
/*-------------------------------------------------------*/
/*---------------REGISTRO DE LOS EMPLEADOS---------------*/
/*Tener el registro de los repartidores, nombre, apellidos, direcci?n, tel?fono,
email, cada repartidor tendr? asignado un n?mero de empleado.*/
typedef struct
{
    char *nombre;
    char *apellidoP;
    char *apellidoM;
}repartidorNAA;

typedef struct
{
    int direccion;
    unsigned long long int telefono;
    char *email;
}repartidorG;

struct repartidor
{
	int pedi[8];
    int id_repartidor;
    repartidorNAA r_naa;
    repartidorG r_dg;
    
    repartidor *siguiente;
    repartidor *anterior;
}*primero, *ultimo;
/*-------------------------------------------------------*/
struct asig
{
	int id_Arepa;
	int id_Apedi;
	asig *siguiente;
	asig *anterior;
}*primeroA,*ultimoA;

struct base
{
	int id_repartidor;
	char nombre[50];
    char apellidoP[50];
    char apellidoM[50];
    int direccion;
    int telefono;
    char email[50];
};


#include "validar.h"
#include "validations.h"
#include "functionsAdmin.h"
#include "functions.h"
#include "decorar.h"
#include "archivos.h"
