
void inicializaArchivo(FILE *arch)
{
	struct repartidor *pR;
	pR = (repartidor *)malloc(sizeof(repartidor));
	int i = 0;
	char nombre[30], apellidoP[30], apellidoM[30], email[30];
	setlocale(LC_CTYPE, "Spanish");
	if (!(arch = fopen("estructura1.xls", "r")))
	{ //Primero se crea el archivo
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
			printf("%d\t", pR->id_repartidor);
			fscanf(arch, "%s\t", pR->r_naa.nombre);
			printf("%s", pR->r_naa.nombre);
			fscanf(arch, "%s\t", pR->r_naa.apellidoP);
			printf("\t%s", pR->r_naa.apellidoP);
			fflush(stdin);
			fscanf(arch, "%s\t", pR->r_naa.apellidoM);
			printf("\t%s", pR->r_naa.apellidoM);
			fscanf(arch, "%d\t", &pR->r_dg.direccion);
			fscanf(arch, "%lld\t", &pR->r_dg.telefono);
			fscanf(arch, "%s\t\n", pR->r_dg.email);
			fflush(stdin);
			//	printf("\t%s", &pR->r_dg.email);
			system("pause");
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
	pP = (struct pedidos *)malloc(sizeof(pedidos));
	char nombreC[50], direccion[50], descripcion[50];
	setlocale(LC_CTYPE, "Spanish");
	if (!(arch = fopen("pedidos.xls", "r")))
	{
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	while (!feof(archP))
	{
		pP->descripcion = (char *)malloc(50 * sizeof(char));
		pP->p_cd.nombreC = (char *)malloc(50 * sizeof(char));
		pP->p_cd.direccion = (char *)malloc(50 * sizeof(char));
		if (pP == NULL)
		{
			printf("No hay espacio");
		}
		else
		{
			fscanf(archP, "%d\t", &pP->id_pedido);
			fscanf(archP, "%s\t", pP->p_cd.nombreC);
			fscanf(archP, "%s\t", pP->p_cd.direccion);
			fscanf(archP, "%lld\t", &pP->p_cd.telefono);
			fscanf(archP, "%s\t", pP->descripcion);
			fscanf(archP, "%f\t\n", &pP->totalPago);
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
		}
	}
	fclose(arch);
	return bandera;
}





*/
