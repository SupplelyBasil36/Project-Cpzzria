//****************************************************************VALIDACIONES PARA QUE NO EXISTAN REPETIDOS***************************************************
bool validaRepartidor(int valor)
{
	struct repartidor *aux1, *aux2;
	aux1 = primero;
	aux2 = NULL;
	bool encontrar = false;
	int busqueda = 0;
	if (primero != NULL)
	{
		while (aux2 != ultimo && encontrar != true)
		{
			if (aux1->id_repartidor == valor)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				printf("\a\tEl Id que ingresaste ya estï¿½ registrado, intenta de nuevo\n\t");
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				encontrar = true;
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
	return encontrar;
}
bool validaPedido(int valor)
{
	struct pedidos *aux1, *aux2;
	aux1 = primeroP;
	aux2 = NULL;
	bool encontrar = false;
	int busqueda = 0;
	if (primeroP != NULL)
	{
		while (aux2 != ultimoP && encontrar != true)
		{
			if (aux1->id_pedido == valor)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				printf("\a\tEl id de pedido que ingresaste ya está registrado, intenta de nuevo\n\t");
				system("pause");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				encontrar = true;
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
			//(!encontrar) ? printf("No encontrado\n") : printf("");
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
	return encontrar;
}
//***********************************************************VALIDACION DE EXISTENCIA DE ID PEDIDO Y REPARTIDORES**********************************************
bool validaExistenciaPedido(int valor)
{
	struct pedidos *aux1, *aux2;
	aux1 = primeroP;
	aux2 = NULL;
	bool encontrar = false;
	if (primeroP != NULL)
	{
		while (aux2 != ultimoP && encontrar != true)
		{
			if (aux1->id_pedido == valor)
			{
				encontrar = true;
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
	return encontrar;
}
bool validaExistenciaRepartidor(int valor)
{
	struct repartidor *aux1, *aux2;
	aux1 = primero;
	aux2 = NULL;
	bool encontrar = false;
	if (primero != NULL)
	{
		while (aux2 != ultimo && encontrar != true)
		{
			if (aux1->id_repartidor == valor)
			{
				encontrar = true;
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
		}
	}else{
		printf("La lista se encuentra vacia\n");
		system("pause");
	}
	return encontrar;
}
bool validaRpedido_asignado(int pedido)
{
	//Funcionando
	struct asig *aux1,*aux2;
	aux1 = primeroA;
	aux2 = NULL;
	bool encontrar = true;
	if(primeroA != NULL)
	{
		while(aux2 != ultimoA && encontrar != false)
		{
			if(aux1->id_Apedi == pedido)
			{
				printf("Este pedido ya ha sido asignado \n");
				encontrar = false;
			}
			aux2 = aux1; 
			aux1 = aux1->siguiente;
		}
	}
	system("pause");
	return encontrar;
}
/*******************************************************BUSCADORES PARA IMPRESION EN EL ARCHIVO ASIGNACIONES****************************************************/
void bARepa(FILE *archA, int x, asig *pA)
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
				fprintf(archA, "%s\t", aux->r_naa.nombre);
				fprintf(archA, "%d\t", aux->r_dg.direccion);
				pA->nR = aux->r_naa.nombre;
				encontrar = true;
			}
			aux = aux->siguiente;
		}
		(!encontrar) ? printf("No encontrado\n") : printf("");
	}
	else
	{
		printf("La lista repartidores se encuentra vacia\n");
	}
}
void bAPedi(FILE *archA, int x, asig *pA)
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
				fprintf(archA, "%s\t", aux->p_cd.nombreC);
				fprintf(archA, "%d\n", aux->p_cd.direccion);
				pA->nP = aux->p_cd.nombreC;
				encontrar = true;
			}
			aux = aux->siguiente;
		}
		(!encontrar) ? printf("No encontrado\n") : printf("");
	}
	else
	{
		printf("La lista pedidos se encuentra vacia\n");
	}
}


