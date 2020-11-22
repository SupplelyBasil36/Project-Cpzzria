#include "libraries.h"

int main()
{
	FILE *arch = NULL;
	system("mode con: cols=73 lines=43");        
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	portada();
	datos();
	system("cls");  
	setlocale(LC_CTYPE, "Spanish"); 
    int opcPrincipal = 0;
    repartidor *pR;
	pR = (repartidor *)malloc(sizeof(repartidor));
    inicializaArchivo(arch, pR);
    	
	while(opcPrincipal != 3){
		fflush(stdin);
		system("mode con: cols=40 lines=20");
		system("cls");
		printf("\n\n\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
		printf("     MENU PRINCIPAL     ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\n\n\t1) Administrador\n\t2) Usuario\n\t3) Salir\n\n\tOpción: ");
    	opcPrincipal = validarEntero1(1,3);
    	fflush(stdin);
    	switch(opcPrincipal)
    	{
    		case 1:
	    		menuAdmin(arch);
	    		break;
	    	case 2:
	    		usuario();
	    		break;
	    	case 3:
				printf("\n\tLa sesión ha terminado!!! \n");
				exit (0);
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
