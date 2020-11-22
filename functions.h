
void menuAdmin(FILE *arch)
{
	int eleccion = 0, repaOpc = 0, pediOpc=0, opc = 1, opcP = 1, asigOpc = 0, opcA=0 ;
	do
	{
		system("mode con: cols=40 lines=20");
		system("cls");
		printf("\n\n\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
		printf("   MENU ADMINISTRADOR   ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("\n\n\t1) Repartidores\n\t2) Pedidos\n\t3) Asignacion de pedidos\n\t4) Salir \n\n\tOpci�n: ");
	    eleccion = validarEntero1(1,4);
	    switch(eleccion)
	    {
	    	case 1:
	    		do{
	    			system("mode con: cols=50 lines=20"); 
		    		system("cls");
		    		printf("\n\n\n\t");
		    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
					printf("\t   REPARTIDORES           ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		    		printf("\n\n\t1) Ingresar repartidor\n");
		    		printf("\t2) Mostrar lista de repartidores\n");
		    		printf("\t3) Eliminar repartidor\n");
		    		printf("\t4) Modificar datos repartidor\n");
		    		printf("\t5) Salir \n\n\tOpci�n: ");
		    		repaOpc = validarEntero1(1,5);
		    		switch(repaOpc)
		    		{
		    			case 1:
		    				do{
		    					system("mode con: cols=80 lines=30"); 
		    					system("cls");
		    					printf("\n\n");
			    				ingresoRepartidores(arch);
			    				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			    				printf("\t�Desea registrar otro repartidor?       1)Si       2)No\n\tOpci�n: ");
								opc = validarEntero1(1,2);
							}while(opc == 1);
		    				break;
						case 2:
							system("cls"); 
							imprimirRepartidor();                      
							system("cls"); 
							break;
						case 3:
							eliminarRepartidor();
							break;
						case 4:
							modificarRepartidor();
							break;
						case 5:
							break;	
						default:
							printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
							getch(); 
							break;	
					}
				}while(repaOpc != 5);
				break;
	    		/******/
	    	case 2:
	    		do{
		    		system("mode con: cols=50 lines=20"); 
		    		system("cls");
		    		printf("\n\n\n\t");
		    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
					printf("\t      PEDIDOS\t\t  ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		    		printf("\n\n\t1) Ingresar pedidos\n");
		    		printf("\t2) Mostrar pedidos\n");
		    		printf("\t3) Eliminar pedidos\n");
		    		printf("\t4) Modificar datos pedidos\n");
		    		printf("\t5) Salir \n\n\tOpci�n: ");
		    		pediOpc = validarEntero1(1,5);
		    		switch(pediOpc)
		    		{
		    			case 1:
							do{
			    				ingresoPedidos();
			    				printf("Desea registrar otro pedido? 1)Si 2)No\n");
								scanf("%d", &opcP);
							}while(opcP == 1);
		    				break;
		    			case 2:
		    				imprimirPedidos();
		    				break;
		    			case 3:
		    				eliminarPedidos();
		    				break;
		    			case 4:
		    				modificarPedidos();
		    				break;
		    			case 5:
							break;
		    			default:
		    				printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
							getch(); 
		    				break;
		    		}
				}while(pediOpc != 5);
	    		break;
	    		/******/
	    	case 3:
	    		do{
		    		system("mode con: cols=53 lines=20"); 
		    		system("cls");
		    		printf("\n\n\n\t");
		    		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
					printf("\tASIGNACION DE PEDIDOS\t     ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		    		printf("\n\n\t1) Asignar pedidos\n");
		    		printf("\t2) Mostrar asignaciones de pedidos\n");
		    		printf("\t3) Eliminar asignaciones de pedidos\n");
		    		printf("\t4) Modificar asignaciones pedidos\n");
		    		printf("\t5) Salir \n\n\tOpci�n: ");
		    		asigOpc = validarEntero1(1,5);
		    		switch(asigOpc)
		    		{
		    			case 1:
							do{
			    				asignaciones();
			    				printf("Desea asignar otro pedido? 1)Si 2)No\n");
								scanf("%d", &opcA);
							}while(opcA == 1);
		    				break;
		    			case 2:
		    				//imprimirPedidos();
		    				break;
		    			case 3:
		    				//eliminarAsignaciones();
		    				break;
		    			case 4:
		    				//modificarAsignaciones();
		    				break;
		    			case 5:
							break;
		    			default:
		    				printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
							getch(); 
		    				break;
					}
			}while(asigOpc != 5);
			break;
			case 4:
				break;
	    	default:
	    		printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
				getch(); 
	    		break;
		}
	}while(eleccion != 4);
}
void usuario()
{
	printf("Hola");
}
