void inicializaArchivo(FILE *arch)
{
	struct repartidor *pR;
	int i = 0;
	setlocale(LC_CTYPE, "Spanish");
	if (!(arch = fopen("estructura1.xls", "r")))
	{ 
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	while (!feof(arch))
	{
		pR = (repartidor *)malloc(sizeof(repartidor));
		pR->r_naa.nombre = (char *)malloc(20 * sizeof(char));
		pR->r_naa.apellidoP = (char *)malloc(20 * sizeof(char));
		pR->r_naa.apellidoM = (char *)malloc(20 * sizeof(char));
		pR->r_dg.email = (char *)malloc(30 * sizeof(char));
		if (pR == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			fscanf(arch, "%d\t", &pR->id_repartidor);
			fscanf(arch, "%s\t", pR->r_naa.nombre);
			fscanf(arch, "%s\t", pR->r_naa.apellidoP);
			fflush(stdin);
			fscanf(arch, "%s\t", pR->r_naa.apellidoM);
			fscanf(arch, "%d\t", &pR->r_dg.direccion);
			fscanf(arch, "%lld\t", &pR->r_dg.telefono);
			fscanf(arch, "%s\t\n", pR->r_dg.email);
			fflush(stdin);
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
		}
	}
	fclose(arch);
}
void inicializaArchivoP(FILE *archP){
	struct pedidos *pP;
	setlocale(LC_CTYPE, "Spanish");
	if (!(archP = fopen("pedidos.xls", "r")))
	{
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	while (!feof(archP))
	{
		pP = (struct pedidos *)malloc(sizeof(pedidos));
		pP->descripcion = (char *)malloc(50 * sizeof(char));
		pP->p_cd.nombreC = (char *)malloc(20 * sizeof(char));
		if (pP == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			fscanf(archP, "%d\t", &pP->id_pedido);
			fflush(stdin);
			fscanf(archP, "%s\t", pP->p_cd.nombreC);
			fscanf(archP, "%d\t", &pP->p_cd.direccion);
			fscanf(archP, "%lld\t", &pP->p_cd.telefono);
			fscanf(archP, "%[^\t]", pP->descripcion);
			fscanf(archP, "%f\t\n", &pP->totalPago);
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
	fclose(archP);
	}
//Extraer del archivo datos, validar con if que sea el buscado almacenar en vector los valores que sean iguales al buscado
void inicializaArchivoA(FILE *archA){
	struct asig *pA;
	int contador = 0;
	char aux[50], aux2[50];
	int auxI, auxD;
	setlocale(LC_CTYPE, "Spanish");
	if (!(archA = fopen("asignaciones.xls", "r")))
	{
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	while (!feof(archA))
	{
		pA = (struct asig *)malloc(sizeof(asig));
		pA->nP = (char *)malloc(50 * sizeof(char));
		pA->nR = (char *)malloc(50 * sizeof(char));
		printf("while\n");
		if (pA == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			printf("else\n");
			fscanf(archA, "%d\t", &pA->id_Arepa);
			fscanf(archA, "%s\t", pA->nR);
			fscanf(archA, "%d\t", &pA->d1);
			fscanf(archA, "%d\t", &pA->id_Apedi);
			fscanf(archA, "%s\t", pA->nP);
			fscanf(archA, "%d\n", &pA->d2);
			
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
		contador += 1;
	}
	fclose(archA);
}
/*
void leeArchivo(FILE *arch){
	setlocale(LC_CTYPE, "Spanish");
	Pruebas dato;

	if(!(arch=fopen("estructura1.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1); 
	}
	printf("\n\n\t_________________________Pruebas_________________________\n\n");

	while(!feof(arch)){
		fscanf(arch,"%d\n", &dato.id_prueba);
		fscanf(arch,"%[^\t]\t", dato.prueba);
		fscanf(arch,"%[^\t]\t", dato.condiciones);
		fscanf(arch,"%f\t", &dato.precio);
		
		printf("\t%d\t", dato.id_prueba);
		printf("%s\t", dato.prueba);
		printf("%s\t", dato.condiciones);
		printf("%.f2\n", dato.precio);
	}
	fclose(arch);
}

void agregaEstructura1(FILE *arch, Pruebas *pEst1){
	bool bandera=true;
	int ent;
	
	if(!(arch=fopen("estructura1.xls", "a+"))){
		printf("Error al intentar crear el archivo");
		exit(1); 
	}
	do{
		ent = validaEntero("\tId_Prueba: ");
		bandera=validaAgrega(arch, ent);
	}while(bandera);  
	
	pEst1->id_prueba = ent;
	validaTexto(pEst1->prueba, "\tPrueba: ");
	validaTexto(pEst1->condiciones, "\tCondiciones: ");
	fflush(stdin);
	pEst1->precio = validaFlotante("\tPrecio: ");
		          
	fprintf(arch,"%d\t",pEst1->id_prueba);
	fprintf(arch,"%s\t",pEst1->prueba);
	fprintf(arch,"%s\t",pEst1->condiciones);
	fprintf(arch,"%f\n",pEst1->precio);
	
	fclose(arch);
}

bool validaAgrega(FILE *arch, int valor){
	setlocale(LC_CTYPE, "Spanish");
	Pruebas dato;
	int pedi[8];
	bool bandera= false;

	if(!(arch=fopen("estructura1.xls", "r"))){
		printf("Error al intentar crear el archivo");
		exit(1); 
	}
	
	while(!feof(arch)){
		fscanf(arch,"%d\t", &dato.id_prueba);
		fscanf(arch,"%[^\t]\t", dato.prueba);
		fscanf(arch,"%[^\t]\t", dato.condiciones);
		fscanf(arch,"%f\n", &dato.precio);
		
		if(valor == dato.id_prueba){
			bandera=true;
			int[8] = dato.idPedido;
		}
	}
	fclose(arch);
	kruskal(array);
	return bandera;
}





*/
