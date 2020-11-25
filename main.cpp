#include "libraries.h"
//PROYECTO PROGRAMACION II
int main()
{
	FILE *arch = NULL;
	FILE *archP = NULL;
	FILE *archA = NULL;
	system("mode con: cols=73 lines=43");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	portada();
	datos();
	system("cls");
	setlocale(LC_CTYPE, "Spanish");
	int opcPrincipal = 0;
	inicializaArchivo(arch);
	inicializaArchivoP(archP);
	printf("787897987987979798789PITOCOMELUCIO\n");
	inicializaArchivoA(archA);

	while (opcPrincipal != 3)
	{
		fflush(stdin);
		menuGeneral();
		opcPrincipal = validarEntero1(1, 3);
		fflush(stdin);
		switch (opcPrincipal)
		{
		case 1:
			menuAdmin(arch, archP, archA);
			break;
		case 2:
			usuario();
			break;
		case 3:
			printf("\n\tLa sesión ha terminado!!! \n");
			exit(0);
			break;
		default:
			printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
			getch();
			break;
		}
		printf("\n\n");
	}
	return 0;
}
