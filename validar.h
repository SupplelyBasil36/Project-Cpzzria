
static int longitud( const char * );
static bool comparar( const char *, const char * );
static void incorrecto( int );
static int numeroDigitos( int );
static int numeroDigitosTelefonicos( unsigned long long int );

/* Incluye el archivo de encabezado <stdio.h> si no esta incluido */
#ifndef _STDIO_H
	#include <stdio.h>
#endif

/* Incluye el archivo de encabezado <stdlib.h> para asignaci√≥n dinamica de memoria */
#ifndef _GLIBCXX_STDLIB_H
	#include <stdlib.h>
#endif

#ifdef linux
	#ifndef _TERMIOS_H
		#include <termios.h> // Incluye <termios.h>
	#endif

	#define ENTER 10
	#define BACKSPACE 127

	static struct termios old, current;

	/* Initialize new terminal i/o settings */
	void initTermios(int echo)
	{
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	current = old; /* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	if (echo) {
		current.c_lflag |= ECHO; /* set echo mode */
	} else {
		current.c_lflag &= ~ECHO; /* set no echo mode */
	}
	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
	}

	/* Restore old terminal i/o settings */
	void resetTermios(void)
	{
	tcsetattr(0, TCSANOW, &old);
	}

	/* Read 1 character - echo defines echo mode */
	char getch_(int echo)
	{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
	}

	/* Read 1 character without echo */
	char getch(void)
	{
	return getch_(0);
	}

	/* Read 1 character with echo */
	char getche(void)
	{
	return getch_(1);
	}
#elif defined(_WIN32)
	#include <conio.h>

	#define ENTER 13
	#define BACKSPACE 8
#endif

#ifndef VALIDAR_H
#define VALIDAR_H

bool validaAgrega(FILE *arch, int valor, repartidor *pR){
	repartidor dato;
	bool bandera= false;
	if(!(arch=fopen("estructura1.xls", "r"))){
		printf("Error al intentar abrir el archivo");
		exit(1); 
	}
	//printf("El valor de valor es %d", valor);
	while(!feof(arch)){
		fscanf(arch,"%d\n", &pR->id_repartidor);
		printf("El valor de valor es %d", valor);
		fscanf(arch,"%[^\t]\t", pR->r_naa.nombre);
		fscanf(arch,"%[^\t]\t", pR->r_naa.apellidoP);
		fscanf(arch,"%[^\t]\t",pR->r_naa.apellidoM);
		fscanf(arch,"%d\t",&dato.r_dg.direccion);
		fscanf(arch,"%lld\t",&dato.r_dg.telefono);
		fscanf(arch,"%[^\t]\n",pR->r_dg.email); 
		
		if(valor == pR->id_repartidor){
			printf("El Se encontrÛ coin %d", valor);
			bandera = true;
		}
	}
	fclose(arch);
	return bandera;
}

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
				printf("\a\tEl Id que ingresaste ya est· registrado, intenta de nuevo\n\t");
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

/* Valida que el dato ingresado sea un numero de punto flotante */
double validarFlotante( float min, float max )
{
	char *ptrNumero = NULL; // Se almacenara el numero en caracteres
	int i = 0; // Contador para cada caracter del arreglo
	int dig = 0; // Contador de digitos permitidos
	int digitos = 0; // Numero de digitos permitidos
	char remplazo = 0; // Caracter de remplazo, antes de almacenar un caracter en el arreglo
	bool esNumero = true; // Si es numero se sale de las validaciones de lo contrario continua
	bool esPunto = false; // Si el caracter es un punto

	if( numeroDigitos( max ) > numeroDigitos( min ) ) // Toma la longitud del parametro mas grande en digitos
		digitos = numeroDigitos( max );
	else
		digitos = numeroDigitos( min );

	digitos += 4; // Permite almacenar cuatro digitos mas para el signo menos o mas, un punto y tres decimas

	ptrNumero = ( char * ) calloc( digitos + 1, sizeof( char ) ); // Asigna la memoria

	do {

		if( !(esNumero) )
		incorrecto( dig );

		dig = 0;

		do {

			remplazo = getch();

			if( ( remplazo == '+' || remplazo == '-' ) && dig == 0 ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			/* Si el caracter es un digito y aun el numero de digitos no esta en el limite */
			else if( remplazo >= '0' && remplazo <= '9' && dig < digitos ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			else if( remplazo == '.' && !esPunto && dig < digitos ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				esPunto = true;

				++dig;
			}

			else if( remplazo == BACKSPACE && dig > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--dig;

				if( *( ptrNumero + dig ) == '.' )
					esPunto = false;
			}

		} while( remplazo != ENTER );

		*( ptrNumero + dig ) = '\0';

		esPunto = false;

		atof(ptrNumero) < min || atof(ptrNumero) > max || dig == 0 || ( *(ptrNumero + 0) == '+' && *(ptrNumero + 1) == '\0' ) || ( *(ptrNumero + 0) == '-' && *(ptrNumero + 1) == '\0' )
		? esNumero = false : esNumero = true;
	}
	while( !(esNumero) );

	putchar( '\n' );

	return atof(ptrNumero);
}

/* Valida que el dato ingresado sea entero */
int validarEntero1( int min, int max )
{
	char *ptrNumero = NULL; // Se almacenara el numero en caracteres
	int i = 0; // Contador para cada caracter del arreglo
	int dig = 0; // Contador de digitos permitidos
	int digitos = 0; // Numero de digitos permitidos
	char remplazo = 0; // Caracter de remplazo, antes de almacenar un caracter en el arreglo
	bool esNumero = true; // Si es numero se sale de las validaciones de lo contrario continua

	if( numeroDigitos( max ) > numeroDigitos( min ) ) // Toma la longitud del parametro mas grande en digitos
		digitos = numeroDigitos( max );
	else
		digitos = numeroDigitos( min );

	++digitos; // Permite almacenar un digito mas para el signo menos o mas

	ptrNumero = ( char * ) calloc( digitos + 1, sizeof( char ) ); // Asigna la memoria

	do {

		if( !(esNumero) )
		incorrecto( dig );

		dig = 0;

		do {

			remplazo = getch();

			if( ( remplazo == '+' || remplazo == '-' ) && dig == 0 ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			/* Si el caracter es un digito y aun el numero de digitos no esta en el limite */
			else if( remplazo >= '0' && remplazo <= '9' && dig < digitos ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			else if( remplazo == BACKSPACE && dig > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--dig;
			}

		} while( remplazo != ENTER );

		*( ptrNumero + dig ) = '\0';

		atoi(ptrNumero) < min || atoi(ptrNumero) > max || dig == 0 || ( *(ptrNumero + 0) == '+' && *(ptrNumero + 1) == '\0' ) || ( *(ptrNumero + 0) == '-' && *(ptrNumero + 1) == '\0' )
		? esNumero = false : esNumero = true;
	}
	while( !(esNumero) );

	putchar( '\n' );

	return atoi(ptrNumero);
}


/* Valida que el dato ingresado sea entero */
unsigned long long int validarTelefono( unsigned long long int min, unsigned long long int max )
{
	char *ptrNumero = NULL; // Se almacenara el numero en caracteres
	int i = 0; // Contador para cada caracter del arreglo
	int dig = 0; // Contador de digitos permitidos
	int digitos = 0; // Numero de digitos permitidos
	char remplazo = 0; // Caracter de remplazo, antes de almacenar un caracter en el arreglo
	bool esNumero = true; // Si es numero se sale de las validaciones de lo contrario continua

	if( numeroDigitosTelefonicos( max ) > numeroDigitosTelefonicos( min ) ) // Toma la longitud del parametro mas grande en digitos
		digitos = numeroDigitos( max );
	else
		digitos = numeroDigitos( min );

	++digitos; // Permite almacenar un digito mas para el signo menos o mas

	ptrNumero = ( char * ) calloc( digitos + 1, sizeof( char ) ); // Asigna la memoria

	do {

		if( !(esNumero) )
		incorrecto( dig );

		dig = 0;

		do {

			remplazo = getch();

			if( ( remplazo == '+' || remplazo == '-' ) && dig == 0 ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			/* Si el caracter es un digito y aun el numero de digitos no esta en el limite */
			else if( remplazo >= '0' && remplazo <= '9' && dig < digitos ) {

				printf( "%c", remplazo );
				*( ptrNumero + dig ) = remplazo;

				++dig;
			}

			else if( remplazo == BACKSPACE && dig > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--dig;
			}

		} while( remplazo != ENTER );

		*( ptrNumero + dig ) = '\0';

		atoll(ptrNumero) < min || atoll(ptrNumero) > max || dig == 0 || ( *(ptrNumero + 0) == '+' && *(ptrNumero + 1) == '\0' ) || ( *(ptrNumero + 0) == '-' && *(ptrNumero + 1) == '\0' )
		? esNumero = false : esNumero = true;
	}
	while( !(esNumero) );

	putchar( '\n' );

	return atoll(ptrNumero);
}

/* Comprueba que el dato ingresado sea un caracter */
char validarCaracter( void )
{
	char caracter = 0;
	char remplazo = 0;
	int digitos = 0;

	do {

		if( remplazo == ENTER )
		incorrecto( 0 );

		remplazo = getch();

		if( ( ( remplazo >= 'a' && remplazo <= 'z' ) || ( remplazo >= 'A' && remplazo <= 'Z' ) ) && digitos < 1 ) {

			printf( "%c", remplazo );
			caracter = remplazo;

			++digitos;
		}

		if( remplazo == BACKSPACE && digitos > 0 ) {

			printf( "\b \b" ); // Retrocede, borra, retrocede
			--digitos;
		}

	} while( remplazo != ENTER || digitos == 0 );

	putchar( '\n' );

	return caracter;
}

/* Comprueba que el dato ingresado sea una cadena */
void validarCadena( char **ptrCadena, int tamanio )
{
	int caracter = 0;
	char remplazo = 0;
	bool esCadena = true;

	*( ptrCadena ) = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		remplazo = getch();

		if( ( ( remplazo >= 'a' && remplazo <= 'z' ) || ( remplazo >= 'A' && remplazo <= 'Z' ) ) && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;
		}

		else if( remplazo == ' ' && caracter != 0 && *( *( ptrCadena ) + caracter - 1 ) != ' ' && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;

		} else if( remplazo == BACKSPACE && caracter > 0 ) {

			printf( "\b \b" ); // Retrocede, borra, retrocede
			--caracter;
		}

	} while( remplazo != ENTER || caracter == 0 );

	*( *( ptrCadena ) + caracter ) = '\0';

	putchar( '\n' );
}

void validarDireccion( char **ptrCadena, int tamanio )
{
	int caracter = 0;
	char remplazo = 0;
	bool esCadena = true;

	*( ptrCadena ) = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		remplazo = getch();

		if( ( ( remplazo >= 'a' && remplazo <= 'z' ) || ( remplazo >= 'A' && remplazo <= 'Z' || ( remplazo >= '0' && remplazo <= '9' )) ) && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;
		}

		else if( remplazo == ' ' && caracter != 0 && *( *( ptrCadena ) + caracter - 1 ) != ' ' && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;

		} else if( remplazo == BACKSPACE && caracter > 0 ) {

			printf( "\b \b" ); // Retrocede, borra, retrocede
			--caracter;
		}

	} while( remplazo != ENTER || caracter == 0 );

	*( *( ptrCadena ) + caracter ) = '\0';

	putchar( '\n' );
}

void validarCorreo1( char **ptrCadena, int tamanio )
{
	int caracter = 0;
	char remplazo = 0;
	bool esCadena = true;

	*( ptrCadena ) = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		remplazo = getch();

		if( ( ( remplazo >= 'a' && remplazo <= 'z' ) || ( remplazo >= 'A' && remplazo <= 'Z') || ( remplazo >= '0' && remplazo <= '9' ) || remplazo == '@' || remplazo == '.') && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;
		}

		else if( remplazo == ' ' && caracter != 0 && *( *( ptrCadena ) + caracter - 1 ) != ' ' && caracter < tamanio ) {

			printf( "%c", remplazo );
			*( *( ptrCadena ) + caracter ) = remplazo;

			++caracter;

		} else if( remplazo == BACKSPACE && caracter > 0 ) {

			printf( "\b \b" ); // Retrocede, borra, retrocede
			--caracter;
		}

	} while( remplazo != ENTER || caracter == 0 );

	*( *( ptrCadena ) + caracter ) = '\0';

	putchar( '\n' );
}

/* Comprueba que la cadena ingresada sea un correo */
bool validarCorreo( const char *ptrCorreo )
{
	static char *ptrCadena = NULL;
	int caracter = 0;
	int tamanio = 0;
	int esUsuario = 0;
	char remplazo = 0;
	bool esArroba = false;

	tamanio = longitud( ptrCorreo );

	ptrCadena = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		if( !esUsuario )
		incorrecto( caracter );

		caracter = 0;

		do {

			remplazo = getch();

			if( remplazo == '@' ) {

				if( !esArroba ) {
					esArroba = true;

					printf( "%c", remplazo );
					*( ptrCadena + caracter ) = remplazo;

					++caracter;
				}

			} else if( remplazo != BACKSPACE && remplazo != ENTER && remplazo != 32 && caracter < tamanio ) {

				printf( "%c", remplazo );
				*( ptrCadena + caracter ) = remplazo;

				if( remplazo == '@' )
				esArroba = true;

				++caracter;
			} else if( remplazo == BACKSPACE && caracter > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--caracter;

				if( *( ptrCadena + caracter ) == '@' )
				esArroba = false;
			}

		} while( remplazo != ENTER );

		*( ptrCadena + caracter ) = '\0';

		esUsuario = comparar( ptrCadena, ptrCorreo );
	}
	while( !esUsuario );

	putchar( '\n' );

	return true;
}

bool validarUsuario( const char *ptrUsuario )
{
	static char *ptrCadena = NULL;
	int caracter = 0;
	int tamanio = 0;
	int esUsuario = 0;
	char remplazo = 0;

	tamanio = longitud( ptrUsuario );

	ptrCadena = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		if( !esUsuario )
		incorrecto( caracter );

		caracter = 0;

		do {

			remplazo = getch();

			if( remplazo != BACKSPACE && remplazo != ENTER && caracter < tamanio ) {

				printf( "%c", remplazo );
				*( ptrCadena + caracter ) = remplazo;

				++caracter;
			}

			else if( remplazo == BACKSPACE && caracter > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--caracter;
			}

		} while( remplazo != ENTER );

		*( ptrCadena + caracter ) = '\0';

		esUsuario = comparar( ptrCadena, ptrUsuario );
	}
	while( !esUsuario );

	putchar( '\n' );

	return true;
}

bool validarContrasena( const char *ptrContrasena )
{
	static char *ptrCadena = NULL;
	int caracter = 0;
	int tamanio = 0;
	int esContrasena = 0;
	char remplazo = 0;

	tamanio = longitud( ptrContrasena );

	ptrCadena = ( char * ) calloc( tamanio + 1, sizeof( char ) );

	do {

		if( !esContrasena )
		incorrecto( caracter );

		caracter = 0;

		do {

			remplazo = getch();

			if( remplazo != BACKSPACE && remplazo != ENTER && caracter < tamanio ) {

				printf( "*", remplazo );
				*( ptrCadena + caracter ) = remplazo;

				++caracter;
			}

			else if( remplazo == BACKSPACE && caracter > 0 ) {

				printf( "\b \b" ); // Retrocede, borra, retrocede
				--caracter;
			}

		} while( remplazo != ENTER );

		*( ptrCadena + caracter ) = '\0';

		esContrasena = comparar( ptrCadena, ptrContrasena );
	}
	while( !esContrasena );

	putchar( '\n' );

	return true;
}

/* Calcula la longitud de una cadena */
static int longitud( const char *ptrCadena )
{
	int i = 0;

	while( *(ptrCadena + i) != '\0' ) {
		i++;
	}

	return i;
}

static bool comparar( const char *ptrCadena1, const char *ptrCadena2 )
{
	for( ; *ptrCadena1 != '\0' || *ptrCadena2 != '\0'; ptrCadena1++, ptrCadena2++ ) {
		if( *ptrCadena1 != *ptrCadena2 )
			return false;
	}

	return true;
}

static int numeroDigitos( int numero )
{
	int notacion = 1; // Representa la notacion 10 a la potencia "n"
	int longitud = 0;

	while( numero / notacion != 0 ) {

		++longitud;

		notacion *= 10;
	}

	return longitud;
}

static int numeroDigitosTelefonicos( unsigned long long int numero )
{
	int notacion = 1; // Representa la notacion 10 a la potencia "n"
	int longitud = 0;

	while( numero / notacion != 0 ) {

		++longitud;

		notacion *= 10;
	}

	return longitud;
}

static void incorrecto( int longitud )
{
	int i = 0;

	for( i = 1; i <= longitud; i++ ) {
		putchar( '\b' );
	}

	if( longitud != 0 )
	printf( "%*c", longitud, ' ' );

	for( i = 1; i <= longitud; i++ ) {
		putchar( '\b' );
	}

	printf( "INCORRECTO" );

	getch();

	for( i = 1; i <= 10; i++ ) {
		putchar( '\b' );
	}

	printf( "%*c", 10, ' ' );

	for( i = 1; i <= 10; i++ ) {
		putchar( '\b' );
	}
}

#endif
