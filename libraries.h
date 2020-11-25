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
    int direccion;
    unsigned long long int telefono;
} pedidoCliente;

struct pedidos
{
    int id_pedido;
    pedidoCliente p_cd;
    char *descripcion;
    float totalPago;
    pedidos *siguiente;
    pedidos *anterior;
} *primeroP, *ultimoP;
/*-------------------------------------------------------*/
/*---------------REGISTRO DE LOS EMPLEADOS---------------*/
/*Tener el registro de los repartidores, nombre, apellidos, direcci?n, tel?fono,
email, cada repartidor tendr? asignado un n?mero de empleado.*/
typedef struct
{
    char *nombre;
    char *apellidoP;
    char *apellidoM;
} repartidorNAA;

typedef struct
{
    int direccion;
    unsigned long long int telefono;
    char *email;
} repartidorG;

struct repartidor
{
    int id_repartidor;
    repartidorNAA r_naa;
    repartidorG r_dg;
    repartidor *siguiente;
    repartidor *anterior;
} *primero, *ultimo;
/*---------------------------------ASIGNACIONES----------------------*/
struct asig
{
    char *nP;
    char *nR;
    int d1;
    int d2;
    int id_Arepa;
    int id_Apedi;
    asig *siguiente;
    asig *anterior;
} *primeroA, *ultimoA;

#include "validar.h"
#include "validations.h"
#include "buscadores.h"
#include "style.h"
#include "functionsAdmin.h"
#include "functions.h"
#include "decorar.h"
#include "archivos.h"
