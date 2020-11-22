/***************************************************************************************************/
/***********************************REPARTIDORES****************************************************/
void ingresoRepartidores(FILE *arch)
{
	bool bandera= true;
	int num, foco = 0; 
	if(!(arch=fopen("estructura1.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1); 
	}
	
	system("cls");
	printf("\n\n\n\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
	printf("                   INGRESO DE REPARTIDORES                   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\n\n\n");
	struct repartidor *pR;
	pR = (repartidor *)malloc(sizeof(repartidor));
	if (pR == NULL)
	{
		printf("No hay espacio");
	}
	else
	{
		do{
			if(foco !=0){
				system("cls");
				printf("\n\n\n\t");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
				printf("                   INGRESO DE REPARTIDORES                   ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				printf("\n\n\n");
			}
			printf("\tId_Repartidor: \n\t");
			num = validarEntero1(1,500);
			bandera = validaRepartidor(num);        //validaAgrega(arch, num, pR);
			foco++;
		}while(bandera);
		pR->id_repartidor = num;
		printf("\tNombre: \n\t");
		validarCadena(&pR->r_naa.nombre,20);
		fflush(stdin);
		printf("\tApellido paterno: \n\t");
		validarCadena(&pR->r_naa.apellidoP,20);
		fflush(stdin);
		printf("\tApellido Materno: \n\t");
		validarCadena(&pR->r_naa.apellidoM,20);
		fflush(stdin);
		printf("\tDirección: (Número entre 1 y 200)\n\t");
		pR->r_dg.direccion  = validarEntero1(1,200);
		fflush(stdin);
		printf("\tTeléfono (10 Dígitos): \n\t");
		pR->r_dg.telefono  = validarTelefono(1000000000,9999999999);
		printf("\tE-mail: \n\t");
		validarCorreo1(&pR->r_dg.email,40);
		fflush(stdin);
		
		fprintf(arch,"%d\t",pR->id_repartidor);
		fprintf(arch,"%s\t",pR->r_naa.nombre);
		fprintf(arch,"%s\t",pR->r_naa.apellidoP);
		fprintf(arch,"%s\t",pR->r_naa.apellidoM);
		fprintf(arch,"%d\t",pR->r_dg.direccion);
		fprintf(arch,"%llu\t",pR->r_dg.telefono);
		fprintf(arch,"%s\n",pR->r_dg.email);
		
		if (primero == NULL)
		{
			primero = pR;
			primero->siguiente = primero;
			primero->anterior = ultimo;
			ultimo = pR;
		}
		else
		{
			ultimo->siguiente = pR;
			pR->siguiente = primero;
			pR->anterior = ultimo;
			ultimo = pR;
			primero->anterior = ultimo;
		}
		printf("\n\tProcesando...\n");
		Sleep(2000);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("\a\n\tLos datos del repartidor se han registrado con éxito\n\n");
	}
	fclose(arch);
}
void imprimirRepartidor()
{
	repartidor *actual;
	actual = (struct repartidor *)malloc(sizeof(struct repartidor));
	actual = primero;
	if (primero != NULL)
	{
		system("mode con: cols=150 lines=40"); 
		printf("\n\n\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
		printf("\t\t\t\t\t\t\t   LISTA DE REPARTIDORES   \t\t\t\t\t\t\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("\n\n\tId repartidor    Nombre\t     Apellidos\t\t\t Dirección  \tTeléfono\t\tE-mail");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\n\n\n");
		do
		{
			printf("%10d", actual->id_repartidor);
			printf("%20s", actual->r_naa.nombre);
			printf("%15s", actual->r_naa.apellidoP);
			printf("%15s", actual->r_naa.apellidoM);
			printf("%10d", actual->r_dg.direccion);
			printf("%20llu", actual->r_dg.telefono);
			printf("%30s\n\n", actual->r_dg.email);
			actual = actual->siguiente;
		} while (actual != primero);
		printf("\n\n\t");
		system("pause");
	}
	else
	{
		system("mode con: cols=80 lines=20");
		printf("\n\n\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
		printf("                  La lista se encuentra vacía                  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\n\n\t");
		system("pause");
	}
}
void eliminarRepartidor()
{
	system("mode con: cols=75 lines=15"); 
	printf("\n\n\n");
	struct repartidor *aux1, *aux2;
	aux1 = primero;
	aux2 = NULL;
	bool encontrar = false;
	int buscar = 0, opc = 0, opcRep = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("\a\t¡Advertencia! Has entrado a la opción ELIMINAR REPARTIDOR\n\t¿Estás seguro que deseas continuar?\n\n");
	printf("\t1)Continuar\t\t\t2)Regresar al menu anterior \n\n\tOpción: ");
	opc = validarEntero1(1,2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	switch(opc)
	{
		case 1:
			imprimirRepartidor();
			if (primero != NULL)
			{
				while (aux2 != ultimo && encontrar != true )
				{
					do{
						if(opcRep != 0){
							system("cls");
							imprimirRepartidor();
						} 
						printf("\tIngresa el Id que deseas eliminar: \n\t");
						buscar = validarEntero1(1,500);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
						printf("\a\tSe eliminará el repartidor %d\t¿Estás seguro que deseas continuar?\n\n", buscar);
						printf("\t1)Continuar\t\t\t\t2)Cancelar \n\n\tOpción: ");
						opcRep = validarEntero1(1,2);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					}while(opcRep == 2);
					if (aux1->id_repartidor == buscar)
					{
						if (aux1 == primero)
						{
							primero = primero->siguiente;
							primero->anterior = ultimo;
							ultimo->siguiente = primero;
							free(aux1);
						}
						else if (aux1 == ultimo)
						{
							ultimo = ultimo->anterior;
							ultimo->siguiente = primero;
							primero->anterior = ultimo;
							free(aux1);
						}
						else
						{
							aux2->siguiente = aux1->siguiente;
							aux1->siguiente->anterior = aux2;
							free(aux1);
						}
						encontrar = true;
					}
					aux2 = aux1; 
					aux1 = aux1->siguiente;
					(!encontrar) ? printf("No encontrado\n") : printf("");
					system("pause");
				}
			}
			break;
		case 2:
			break;
	}
}
void modificarRepartidor()
{
	struct repartidor *aux;
	aux = primero;
	bool encontrar = false;
	int busqueda = 0;
	if (primero != NULL)
	{
		while (aux != NULL && encontrar != true)
		{
			printf("\tIngresa el id a buscar: ");
			busqueda = validarEntero1(1,500);
			fflush(stdin);
			if (aux->id_repartidor == busqueda)
			{
				printf("\tNombre: \n\t");
				validarCadena(&aux->r_naa.nombre,20);
				fflush(stdin);
				printf("\tApellido paterno: \n\t");
				validarCadena(&aux->r_naa.apellidoP,20);
				fflush(stdin);
				printf("\tApellido Materno: \n\t");
				validarCadena(&aux->r_naa.apellidoM,20);
				fflush(stdin);
				printf("\tDirección: \n\t");
				aux->r_dg.direccion  = validarEntero1(1,50);
				fflush(stdin);
				printf("\tTeléfono (10 Dígitos): \n\t");
				aux->r_dg.telefono  = validarTelefono(1000000000,9999999999);
				printf("E-mail: \n\t");
				validarCorreo1(&aux->r_dg.email,40);
				fflush(stdin);
				encontrar = true;
			}
			aux = aux->siguiente;
			(!encontrar) ? printf("No encontrado\n") : printf("");
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
}
/***************************************************************************************************/
/**************************************PEDIDOS******************************************************/
void ingresoPedidos()
{
	system("cls");
	printf("Ingreso de pedidos\n");
	struct pedidos *pP;
	pP = (struct pedidos *)malloc(sizeof(struct pedidos));
	if (pP == NULL)
	{
		printf("No hay espacio");
	}
	else
	{
			printf("\tId_Pedido: \n\t");
			pP->id_pedido = validarEntero1(1,500); // validar si es entero // validar que no se repita
			fflush(stdin);
			printf("\tNombre cliente: \n\t");
			validarCadena(&pP->p_cd.nombreC,20);
			fflush(stdin);
			printf("\tDirección: \n\t");
			validarDireccion(&pP->p_cd.direccion,40);
			fflush(stdin);
			printf("\tTeléfono (10 Dígitos): \n\t");
			pP->p_cd.telefono = validarTelefono(1000000000,9999999999);
			fflush(stdin);
			printf("\tDescripción: \n\t");
			validarCadena(&pP->descripcion,20);
			fflush(stdin);
			printf("\tPrecio total: \n\t");
			pP->totalPago = validarFlotante(100,500);
			fflush(stdin);
			if (primeroP == NULL)
			{
				primeroP = pP;
				primeroP->siguiente = primeroP;
				primeroP->anterior = ultimoP;
				ultimoP = pP;
			}
			else
			{
				ultimoP->siguiente = pP;
				pP->siguiente = primeroP;
				pP->anterior = ultimoP;
				ultimoP = pP;
				primeroP->anterior = ultimoP;
			}
	}
}

void imprimirPedidos()
{
	system("cls");
	pedidos *actual;
	actual = (struct pedidos *)malloc(sizeof(struct pedidos));
	actual = primeroP;
	if (primeroP != NULL)
	{
		do
		{
			printf("\t%d\n\t", actual->id_pedido);
			printf("\t%s\n\t", actual->p_cd.nombreC);
			printf("\t%s\n\t", actual->p_cd.direccion);
			printf("\t%d\n\t", actual->p_cd.telefono);
			printf("\t%s\n\t", actual->descripcion);
			printf("\t%f\n\n", actual->totalPago);
			actual = actual->siguiente;
		} while (actual != primeroP);
	}
	else
	{
		printf("La lista se encuentra vacia");
	}
	system("pause");
}
void eliminarPedidos()
{
	imprimirPedidos();
	struct pedidos *aux1;
	struct pedidos *aux2;
	aux1 = primeroP;
	aux2 = NULL;
	bool encontrar = false;
	int buscar = 0;
	if (primeroP != NULL)
	{
		while (aux2 != ultimoP && encontrar != true)
		{
			printf("\tIngresa el Id a eliminar-> ");
			buscar = validarEntero1(1,500);
			if (aux1->id_pedido == buscar)
			{
				if (aux1 == primeroP)
				{
					primeroP = primeroP->siguiente;
					primeroP->anterior = ultimoP;
					ultimoP->siguiente = primeroP;
					free(aux1);
				}
				else if (aux1 == ultimoP)
				{
					ultimoP = ultimoP->anterior;
					ultimoP->siguiente = primeroP;
					primeroP->anterior = ultimoP;
					free(aux1);
				}
				else
				{
					aux2->siguiente = aux1->siguiente;
					aux1->siguiente->anterior = aux2;
					free(aux1);
				}

				encontrar = true;
			}
			aux2 = aux1;
			aux1 = aux1->siguiente;
			(!encontrar) ? printf("No encontrado\n") : printf("");
			system("pause");
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
}
void modificarPedidos()
{

	struct pedidos *aux;
	aux = primeroP;
	bool encontrar = false;
	int busqueda = 0;
	if (primeroP != NULL)
	{
		while (aux != NULL && encontrar != true)
		{
			printf("\tIngresa el Id a buscar-> ");
			busqueda = validarEntero1(1,500);
			fflush(stdin);
			if (aux->id_pedido == busqueda)
			{
				printf("Nombre cliente: \n");
				scanf("%[^\n]", aux->p_cd.nombreC);
				fflush(stdin);
				printf("Direccion: \n");
				scanf("%[^\n]", aux->p_cd.direccion);
				fflush(stdin);
				printf("Telefono: \n");
				scanf("%d", &aux->p_cd.telefono);
				fflush(stdin);
				printf("Descripcion: \n");
				scanf("%[^\n]", aux->descripcion);
				fflush(stdin);
				printf("Total pago: \n");
				scanf("%f", &aux->totalPago);
				fflush(stdin);
				encontrar = true;
			}
			aux = aux->siguiente;
			(!encontrar) ? printf("No encontrado\n") : printf("");
		}
	}
	else
	{
		printf("La lista se encuentra vacia\n");
	}
}
/***************************************************************************************************/
/**************************************GENERAL******************************************************/
void asignaciones()
{
	system("cls");
	printf("Asignaciones\n");
	struct asig *pA;
	pA = (asig * )malloc(sizeof(asig));
	if(pA == NULL)
	{
		printf("No hay espacio para asignar");
	}
	else{
		printf("\tId_Repartidor: \n");
		pA->id_Arepa = validarEntero1(1,500);
		printf("\tId_Pedido: \n");
		pA->id_Apedi = validarEntero1(1,500);
		if (primeroA == NULL)
		{
			primeroA = pA;
			primeroA->siguiente = primeroA;
			primeroA->anterior = ultimoA;
			ultimoA = pA;
		}
		else
		{
			ultimoA->siguiente = pA;
			pA->siguiente = primeroA;
			pA->anterior = ultimoA;
			ultimoA = pA;
			primeroA->anterior = ultimoA;
		}
	}
}

void ordenamiento()
{
	struct asig *aux, *sig;
	int x;
	aux = primeroA;
	while(aux->siguiente != primeroA){
        sig = aux->siguiente; 
        while(sig!=NULL){
            if(aux->id_Arepa > sig->id_Arepa){
                x = sig->id_Arepa;
                sig->id_Arepa = aux->id_Arepa;
                aux->id_Arepa = x;          
            }
            sig = sig->siguiente;                    
        } 
        aux = aux->siguiente;
        sig = aux->siguiente;          
    }
}
void bRepa(int x)
{

	struct repartidor *aux;
	aux = primero;
	bool encontrar = false;
	int busqueda = 0;
	if (primero != NULL)
	{
		while (aux != NULL && encontrar != true)
		{
			if (aux->id_repartidor == x)
			{
				printf("%s", aux->r_naa.nombre);
				encontrar = true;
			}
			aux = aux->siguiente;
			(!encontrar) ? printf("No encontrado\n") : printf("");
		}
	}
	else
	{
		printf("La lista se encuentra vacia\n");
	}
}
void bPedi(int x)
{

	struct pedidos *aux;
	aux = primeroP;
	bool encontrar = false;
	int busqueda = 0;
	if (primeroP != NULL)
	{
		while (aux != NULL && encontrar != true)
		{
			if (aux->id_pedido == x)
			{
				printf("%s", aux->p_cd.nombreC);
				encontrar = true;
			}
			aux = aux->siguiente;
			(!encontrar) ? printf("No encontrado\n") : printf("");
		}
	}
	else
	{
		printf("La lista se encuentra vacia\n");
	}
}
void mostrarAsignaciones()
{
	ordenamiento();
	system("cls");
	asig *actual;
	actual = (struct asig *)malloc(sizeof(struct asig));
	actual = primeroA;
	if (primeroA != NULL)
	{
		do
		{
			printf("%d ",actual->id_Arepa);
			bRepa(actual->id_Arepa);
			printf("\t");
			printf("%d", actual->id_Apedi);
			bPedi(actual->id_Apedi);
			printf("\n");
			actual = actual->siguiente;
		} while (actual != primeroA);
	}
	else
	{
		printf("La lista se encuentra vacia");
	}
	system("pause");
}
