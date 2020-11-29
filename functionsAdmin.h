/***************************************************************************************************/
/***********************************REPARTIDORES****************************************************/
void ingresoRepartidores(FILE *arch)
{
	bool bandera = true;
	int num, foco = 0;
	if (!(arch = fopen("estructura1.xls", "a+")))
	{
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	else
	{
		presentacionRepar();
		struct repartidor *pR;
		pR = (repartidor *)malloc(sizeof(repartidor));
		if (pR == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			do
			{
				if (foco != 0)
				{
					presentacionRepar();
				}
				printf("\tId_Repartidor: \n\t");
				num = validarEntero1(1, 500);
				bandera = validaRepartidor(num); //validaAgrega(arch, num, pR);
				foco++;
			} while (bandera);
			pR->id_repartidor = num;
			printf("\tNombre: \n\t");
			validarCadena(&pR->r_naa.nombre, 20);
			fflush(stdin);
			printf("\tApellido paterno: \n\t");
			validarCadena(&pR->r_naa.apellidoP, 20);
			fflush(stdin);
			printf("\tApellido Materno: \n\t");
			validarCadena(&pR->r_naa.apellidoM, 20);
			fflush(stdin);
			printf("\tDireccion: (N�mero entre 1 y 200)\n\t");
			pR->r_dg.direccion = validarEntero1(1, 200);
			fflush(stdin);
			printf("\tTel�fono (10 D�gitos): \n\t");
			pR->r_dg.telefono = validarTelefono(1000000000, 9999999999);
			printf("\tE-mail: \n\t");
			validarCorreo1(&pR->r_dg.email, 40);
			fflush(stdin);

			fprintf(arch, "%d\t", pR->id_repartidor);
			fprintf(arch, "%s\t", pR->r_naa.nombre);
			fprintf(arch, "%s\t", pR->r_naa.apellidoP);
			fprintf(arch, "%s\t", pR->r_naa.apellidoM);
			fprintf(arch, "%d\t", pR->r_dg.direccion);
			fprintf(arch, "%llu\t", pR->r_dg.telefono);
			fprintf(arch, "%s\n", pR->r_dg.email);

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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\a\n\tLos datos del repartidor se han registrado con �xito\n\n");
		}
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
		imprimirRepar();
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
		immprimirReparNull();
	}
}
void eliminarRepartidor()
{
	system("mode con: cols=75 lines=15");
	printf("\n\n\n");
	struct repartidor *aux1;
	struct repartidor *aux2;
	aux1 = primero;
	aux2 = NULL;
	bool encontrar = false;
	int buscar = 0, opc = 0, opcRep = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\a\tAdvertencia! Has entrado a la opci�n ELIMINAR REPARTIDOR\n\tEst�s seguro que deseas continuar?\n\n");
	printf("\t1)Continuar\t\t\t2)Regresar al menu anterior \n\n\tOpci�n: ");
	opc = validarEntero1(1, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	switch (opc)
	{
	case 1:
		imprimirRepartidor();
		do
		{
			if (opcRep != 0)
			{
				system("cls");
				imprimirRepartidor();
			}
			printf("\tIngresa el Id que deseas eliminar: \n\t");
			buscar = validarEntero1(1, 500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("\a\tSe eliminar� el repartidor \n\tEst�s seguro que deseas continuar?\n\n", buscar);
			printf("\t1)Continuar\t\t\t\t2)Cancelar \n\n\tOpci�n: ");
			opcRep = validarEntero1(1, 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		} while (opcRep == 2);
		if (primero != NULL)
		{
			while (aux2 != ultimo && encontrar != true)
			{
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
					printf("\n\tProcesando...\n");
					Sleep(2000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					printf("\a\n\tRepartidor %d eliminado con �xito\n\n\t", aux1->id_repartidor);
				}
				aux2 = aux1;
				aux1 = aux1->siguiente;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			(!encontrar) ? printf("\a\tRegistro no encontrado\n\t") : printf("");
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		}
		break;
	default:
		break;
	}
}
void modificarRepartidor()
{
	system("mode con: cols=75 lines=15"); 
	printf("\n\n\n");
	struct repartidor *aux1, *aux2;
	aux1 = primero;
	aux2 = NULL;
	bool encontrar = false;
	int busqueda = 0, opcMod =0, opcModi = 0;
	imprimirRepartidor();
	if (primero != NULL)
	{
		do{
			if(opcMod != 0){
				system("cls");
				imprimirRepartidor();
			} 
			printf("\tIngresa el Id que deseas modificar: \n\t");
			busqueda = validarEntero1(1,500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			printf("\a\tSe modificar�n los datos del repartidor %d\t�Est�s seguro que deseas continuar?\n\n", busqueda);
			printf("\t1)Continuar\t\t\t\t2)Cancelar \n\n\tOpci�n: ");
			opcMod = validarEntero1(1,2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		}while(opcMod == 2);

		while (aux2 != ultimo && encontrar != true )
		{
		
			if (aux1->id_repartidor == busqueda)
			{
				system("cls");
				repartidorModificacionMenu();
				opcModi = validarEntero1(1,4);
				switch (opcModi)
				{
				case 1:
					printf("\tNombre: \n\t");
					validarCadena(&aux1->r_naa.nombre, 20);
					fflush(stdin);
					printf("\tApellido paterno: \n\t");
					validarCadena(&aux1->r_naa.apellidoP, 20);
					fflush(stdin);
					printf("\tApellido Materno: \n\t");
					validarCadena(&aux1->r_naa.apellidoM, 20);
					fflush(stdin);
					encontrar = true;
					printf("\n\tProcesando...\n");
					Sleep(2000);
					break;
				case 2:
					printf("\tDirecci�n: (N�mero entre 1 y 200)\n\t");
					aux1->r_dg.direccion = validarEntero1(1, 200);
					fflush(stdin);
					encontrar = true;
					printf("\n\tProcesando...\n");
					Sleep(2000);
					break;
				case 3:
					printf("\tTel�fono: (10 D�gitos) \n\t");
					aux1->r_dg.telefono = validarTelefono(1000000000, 9999999999);
					encontrar = true;
					printf("\n\tProcesando...\n");
					Sleep(2000);
					break;
				case 4:
					printf("\tE-mail: \n\t");
					validarCorreo1(&aux1->r_dg.email, 40);
					fflush(stdin);
					encontrar = true;
					printf("\n\tProcesando...\n");
					Sleep(2000);
				default:
					printf("\aOpcion invalida\n\n");
					break;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				printf("\a\n\tRepartidor %d modificado con �xito\n\n", aux1->id_repartidor);
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		(!encontrar) ? printf("\a\tRegistro no encontrado\n\t") : printf("");
		system("pause");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
} 
/***************************************************************************************************/
/**************************************PEDIDOS******************************************************/
void ingresoPedidos(FILE *archP)
{
	bool bandera = true;
	int num = 0, foco = 0;
	if (!(archP = fopen("pedidos.xls", "a+")))
	{
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	else
	{
		presentacionPedi();
		struct pedidos *pP;
		pP = (struct pedidos *)malloc(sizeof(struct pedidos));
		if (pP == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			do
			{
				if (foco != 0)
				{
					presentacionPedi();
				}
				printf("\tId_Pedido: \n\t");
				num = validarEntero1(1, 500);
				bandera = validaPedido(num); //validaAgrega(arch, num, pR);
				foco++;
			} while (bandera);
			pP->id_pedido = num;
			fflush(stdin);
			printf("\tNombre cliente: \n\t");
			validarCadena(&pP->p_cd.nombreC, 20);
			fflush(stdin);
			printf("\tDireccion: (N�mero entre 1 y 200)\n\t");
			pP->p_cd.direccion = validarEntero1(1, 200);
			fflush(stdin);
			printf("\tTel�fono (10 D�gitos): \n\t");
			pP->p_cd.telefono = validarTelefono(1000000000, 9999999999);
			fflush(stdin);
			printf("\tDescripci�n: \n\t");
			validarCadena(&pP->descripcion, 20);
			fflush(stdin);
			printf("\tPrecio total: \n\t");
			pP->totalPago = validarFlotante(100, 500);
			fflush(stdin);

			fprintf(archP, "%d\t", pP->id_pedido);
			fprintf(archP, "%s\t", pP->p_cd.nombreC);
			fprintf(archP, "%d\t", pP->p_cd.direccion);
			fprintf(archP, "%llu\t", pP->p_cd.telefono);
			fprintf(archP, "%\t", pP->descripcion);
			fprintf(archP, "%.2f\n", pP->totalPago);

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
	fclose(archP);
}
void imprimirPedidos()
{
	system("cls");
	pedidos *actual;
	actual = (struct pedidos *)malloc(sizeof(struct pedidos));
	actual = primeroP;
	if (primeroP != NULL)
	{
		imprimirPedi();
		do
		{
			printf("%10d", actual->id_pedido);
			printf("%15s", actual->p_cd.nombreC);
			printf("%10d", actual->p_cd.direccion);
			printf("%15llu\t", actual->p_cd.telefono);
			printf("%20s\t\t", actual->descripcion);
			printf("%30.2f\n", actual->totalPago);
			actual = actual->siguiente;
		} while (actual != primeroP);
		printf("\n\n\t");
		system("pause");
	}
	else
	{
		printf("La lista se encuentra vacia");
	}
	system("pause");
}
void eliminarPedidos()
{
	system("mode con: cols=75 lines=15");
	printf("\n\n\n");
	struct pedidos *aux1;
	struct pedidos *aux2;
	aux1 = primeroP;
	aux2 = NULL;
	bool encontrar = false;
	int buscar = 0, opc = 0, opcRep = 0;
	if(primeroP != NULL){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\a\tAdvertencia! Has entrado a la opci�n ELIMINAR PEDIDO\n\tEst�s seguro que deseas continuar?\n\n");
		printf("\t1)Continuar\t\t\t2)Regresar al menu anterior \n\n\tOpci�n: ");
		opc = validarEntero1(1, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		switch (opc)
		{
		case 1:
			imprimirPedidos();
			do
			{
				if (opcRep != 0)
				{
					system("cls");
					imprimirPedidos();
				}
				printf("\tIngresa el Id que deseas eliminar: \n\t");
				buscar = validarEntero1(1, 500);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("\a\tSe eliminar� el pedido %d\tEst�s seguro que deseas continuar?\n\n", buscar);
				printf("\t1)Continuar\t\t\t\t2)Cancelar \n\n\tOpci�n: ");
				opcRep = validarEntero1(1, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			} while (opcRep == 2);
			if (primeroP != NULL)
			{
				while (aux2 != ultimoP && encontrar != true)
				{
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
				}
				(!encontrar) ? printf("No encontrado\n") : printf("");
			}
			break;
		default:
			break;	
		}
	}else{
		printf("La lista se encuentra vacia\n");
	}
}
void modificarPedidos()
{

	struct pedidos *aux;
	aux = primeroP;
	bool encontrar = false;
	int busqueda = 0, opcModi=0;
	if (primeroP != NULL)
	{
		while (aux != NULL && encontrar != true)
		{
			printf("\tIngresa el Id a buscar-> ");
			busqueda = validarEntero1(1, 500);
			fflush(stdin);
			if (aux->id_pedido == busqueda)
			{
				system("cls");
				pedidoModificacionMenu();
				opcModi = validarEntero1(1,5);
				switch(opcModi)
				{
					case 1:
						printf("\tNombre cliente: \n\t");
						validarCadena(&aux->p_cd.nombreC, 20);
						fflush(stdin);
						encontrar = true;
						printf("\n\tProcesando...\n");
						Sleep(2000);
						break;
					case 2:
						printf("\tDireccion: (N�mero entre 1 y 200)\n\t");
						aux->p_cd.direccion = validarEntero1(1, 200);
						fflush(stdin);
						encontrar = true;
						printf("\n\tProcesando...\n");
						Sleep(2000);
						break;
					case 3:
						printf("\tTel�fono (10 D�gitos): \n\t");
						aux->p_cd.telefono = validarTelefono(1000000000, 9999999999);
						fflush(stdin);
						encontrar = true;
						printf("\n\tProcesando...\n");
						Sleep(2000);
						break;
					case 4:
						printf("\tDescripci�n: \n\t");
						validarCadena(&aux->descripcion, 40);
						fflush(stdin);
						encontrar = true;
						printf("\n\tProcesando...\n");
						Sleep(2000);
						break;
					case 5:
						printf("\tPrecio total: \n\t");
						aux->totalPago = validarEntero1(100, 500);
						fflush(stdin);
						encontrar = true;
						printf("\n\tProcesando...\n");
						Sleep(2000);
						break;
					default:
						printf("\a Opcion incorrecta \t\n");
						break;
				}
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
/**************************************ASIGNACIONES******************************************************/
void asignaciones(FILE *archA)
{
	if (!(archA = fopen("asignaciones.xls", "a+")))
	{
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	else
	{
		system("cls");
		printf("Asignaciones\n");
		struct asig *pA;
		pA = (asig *)malloc(sizeof(asig));
		bool bandera = false, bandera1 = false;
		int num, foco = 0;
		if (pA == NULL)
		{
			printf("No hay espacio para asignar");
		}
		else
		{
			imprimirRepartidor();
			do
			{
				if (foco != 0)
				{
					imprimirRepartidor();
				}
				printf("\tId_Repartidor: \n\t");
				num = validarEntero1(1, 500);
				bandera = validaExistenciaRepartidor(num);
				foco++;
			} while (bandera == false);
			pA->id_Arepa = num;
			system("cls");
			bandera = false;
			num = 0; 
			foco = 0;
			imprimirPedidos();
			do
			{
				bandera = false;
				do
				{
					if (foco != 0)
					{
						imprimirPedidos();
					}
					printf("\tId_Pedido: \n\t");
					num = validarEntero1(1, 500);
					bandera = validaExistenciaPedido(num);
					foco++;
				} while (bandera == false);
				bandera1 = validaRpedido_asignado(num);
			}while(bandera1 == false);
			
			pA->id_Apedi = num;
			
			fprintf(archA, "%d\t", pA->id_Arepa);
			bARepa(archA, pA->id_Arepa, pA);
			fprintf(archA, "%d\t", pA->id_Apedi, pA);
			bAPedi(archA, pA->id_Apedi, pA);			
			
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
	fclose(archA);
}
void mostrarAsignaciones()
{
	system("cls");
	struct asig *actual;
	actual = (struct asig *)malloc(sizeof(struct asig));
	actual = primeroA;
	if (primeroA != NULL)
	{
		do
		{
			printf("%d\t", actual->id_Arepa);
			printf("%s\t", actual->nR);
			printf("%d\t", actual->d1);
			printf("%d\t", actual->id_Apedi);
			printf("%s\t", actual->nP);
			printf("%d\t", actual->d2);
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
void eliminarAsignaciones()
{
	system("mode con: cols=75 lines=15");
	printf("\n\n\n");
	struct asig *aux1;
	struct asig *aux2;
	aux1 = primeroA;
	aux2 = NULL;
	bool encontrar = false;
	int buscar = 0, opc = 0, opcRep = 0;
	if(primeroA != NULL){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\a\tAdvertencia! Has entrado a la opci�n ELIMINAR PEDIDO\n\tEst�s seguro que deseas continuar?\n\n");
		printf("\t1)Continuar\t\t\t2)Regresar al menu anterior \n\n\tOpci�n: ");
		opc = validarEntero1(1, 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		switch (opc)
		{
		case 1:
			mostrarAsignaciones();
			do
			{
				if (opcRep != 0)
				{
					system("cls");
					mostrarAsignaciones();
				}
				printf("\tIngresa el Id de pedido que deseas eliminar: \n\t");
				buscar = validarEntero1(1, 500);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("\a\tSe eliminar� el pedido %d\tEst�s seguro que deseas continuar?\n\n", buscar);
				printf("\t1)Continuar\t\t\t\t2)Cancelar \n\n\tOpci�n: ");
				opcRep = validarEntero1(1, 2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			} while (opcRep == 2);
			if (primeroA != NULL)
			{
				while (aux2 != ultimoA && encontrar != true)
				{
					if (aux1->id_Apedi == buscar)
					{
						if (aux1 == primeroA)
						{
							primeroA = primeroA->siguiente;
							primeroA->anterior = ultimoA;
							ultimoA->siguiente = primeroA;
							free(aux1);
						}
						else if (aux1 == ultimoA)
						{
							ultimoA = ultimoA->anterior;
							ultimoA->siguiente = primeroA;
							primeroA->anterior = ultimoA;
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
				}
				(!encontrar) ? printf("No encontrado\n") : printf("");
			}
			break;
		default:
			break;	
		}
	}else{
		printf("La lista se encuentra vacia\n");
	}
}
