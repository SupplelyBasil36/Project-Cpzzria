int tamEntero = 11;	//tamaño de la cadena para funcion validaEntero
int tamCadena = 20;	//tamaño de la cadena para funcion validaCadena
int tamFloat = 10; //tamaño de la cadena para funcion validaFlotante
int tamText = 50;
 
void validaTexto(char nom[], const char *mensaje){
	char cadena[50]="";
	bool bandera = true;
	char espacio;
	
	espacio = ("%c",165);
	
	do{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena)<50){
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

int validaEntero(const char *mensaje){ //envia char
	char cadena[tamEntero]="";
	bool bandera = true;
	int entero = 0;
	do{	
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",cadena);
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

float validaFlotante(const char *mensaje){
	char cadena[50]="";
	bool bandera = true;
	float flotante = 0;
	char punto;
	
	punto = ("%c",46);
	
	do{	
		int cont = 0;
		printf("%s",mensaje);
		scanf("%[^\n]",cadena);
		if(strlen(cadena)<50){
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
