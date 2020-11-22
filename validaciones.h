int tamEntero = 11;	//tamaño de la cadena para funcion validaEntero
int tamCadena = 20;	//tamaño de la cadena para funcion validaCadena
int tamFloat = 10; //tamaño de la cadena para funcion validaFlotante
int tamText = 50;

bool validaAgrega(FILE *arch, int valor){
	setlocale(LC_CTYPE,"Spanish");
	PRUEBAS dato;
	bool bandera = false;
	
	if(!(arch=fopen("Pruebas.xls","r"))){
		printf("Error al intentar leer archivo");
		exit(1);
	}
	
	while(!feof(arch)){
		fscanf(arch,"%d\t",&dato.id_prueba);
		fscanf(arch,"%[^\t]\t", dato.prueba);
		fscanf(arch,"%[^\t]\t", dato.condiciones);
		fscanf(arch,"%f\n",&dato.precio);
		
		if(valor == dato.id_prueba){
			bandera = true;
		}
	}
	fclose(arch);
	return bandera;
}

int validaEntero(const char *mensaje){ //envia char
	char cadena[tamEntero]="";
	bool bandera = true;
	int entero = 0;
	
	do{	
		printf("%s",mensaje);
		fflush(stdin);
		gets(cadena);
		if(strlen(cadena)<tamEntero){
			for(int i = 0; i < strlen(cadena); i++){
				if(isdigit(cadena[i])){
					if(i==(strlen(cadena)-1)){
						entero = atoi(cadena);
						bandera = false;	
					}
				}
			}	
		}else {
			printf("Valor demasiado grande\n");
			continue;	
		}
	}while(bandera);
	
	return entero;	
}

float validaFloat(const char *mensaje){
	char cadena[tamFloat]="";
	bool bandera = true;
	float flotante = 0;
	char punto;
	
	punto = ("%c",46);
	
	do{	
		int cont = 0;
		printf("%s",mensaje);
		gets(cadena);
		if(strlen(cadena)<tamFloat){
			for(int i = 0; i < strlen(cadena); i++){
				if(isdigit(cadena[i]) || (cadena[i] == punto)){
					if((cadena[i]) == punto) cont++;
					if(cont < 2) {
						if(i==(strlen(cadena)-1)){
							flotante = atof(cadena);
							bandera = false;
						}
					}else {
						printf("No valido\n");
					}
				}else{
					printf("No es un digito\n");
				}
			}	
		}else {
			printf("Valor demasiado grande\n");
			continue;	
		}
	}while(bandera);
	
	return flotante;
}

void validaCadena(char nom[], const char *mensaje){
	char cadena[tamCadena]="";
	bool bandera = true;
	
	while(bandera){
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena) > (tamCadena-1)){
			continue;
		}else{
			for(int i = 0; i < strlen(cadena); i++){
				if(isalpha(cadena[i])){
					if(i==(strlen(cadena)-1)){
						strcpy(nom, cadena);
						bandera = false;
					}
				}else{
					break;
				}
			}
		}
	}
}

float validaTexto(char nom[], const char *mensaje){
	char cadena[tamFloat]="";
	bool bandera = true;
	char espacio;
	
	espacio = ("%c",165);
	
	do{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena)<tamText){
			for(int i = 0; i < strlen(cadena); i++){
				if(isalpha(cadena[i]) || (cadena[i] == espacio)){
					if(i==(strlen(cadena)-1)){
						strcpy(nom, cadena);
						bandera = false;
					}
				}
			}	
		}
	}while(bandera);
}
