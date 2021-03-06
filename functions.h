void menuAdmin(FILE *arch, FILE *archP, FILE *archA)
{
	int eleccion = 0, repaOpc = 0, pediOpc = 0, opc = 1, opcP = 1, asigOpc = 0, opcA = 0, q = 0;
	do
	{
		menuAdminGeneral();
		eleccion = validarEntero1(1, 4);
		switch (eleccion)
		{
		case 1:
			do
			{
				menuAdminGenera_Repartidor();
				repaOpc = validarEntero1(1, 5);
				switch (repaOpc)
				{
				case 1:
					do
					{
						system("mode con: cols=80 lines=30");
						system("cls");
						printf("\n\n");
						ingresoRepartidores(arch);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						printf("\tDesea registrar otro repartidor?       1)Si       2)No\n\tOpcion: ");
						opc = validarEntero1(1, 2);
					} while (opc == 1);
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
			} while (repaOpc != 5);
			break;
		case 2:
			do
			{
				menuAdminGenera_Pedidos();
				pediOpc = validarEntero1(1, 5);
				switch (pediOpc)
				{
				case 1:
					do
					{
						ingresoPedidos(archP);
						printf("Desea registrar otro pedido? 1)Si 2)No\n");
						scanf("%d", &opcP);
					} while (opcP == 1);
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
			} while (pediOpc != 5);
			break;
		case 3:
			do
			{
				menuAsignaciones_General();
				asigOpc = validarEntero1(1, 5);
				switch (asigOpc)
				{
				case 1:
					do
					{
						asignaciones(archA);
						printf("Desea asignar otro pedido? 1)Si 2)No\n");
						scanf("%d", &opcA);
					} while (opcA == 1);
					break;
				case 2:
					mostrarAsignaciones();
					break;
				case 3://Eliminar basandose en pedido
					eliminarAsignaciones();
					break;
				case 4://Modificar basandose en pedido pero modificar repartidor
					//modificarAsignaciones();
					break;
				case 5:
					break;
				default:
					printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
					getch();
					break;
				}
			} while (asigOpc != 5);
			break;
		case 4:
			break;
		default:
			printf("\n\tError, intenta de nuevo:\n\tPresione cualquier tecla");
			getch();
			break;
		}
	} while (eleccion != 4);
}
void usuario()
{
	printf("Hola");
}
