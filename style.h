void menuAdminGeneral()
{
    system("mode con: cols=40 lines=20");
    system("cls");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 225);
    printf("   MENU ADMINISTRADOR   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\t1) Repartidores\n\t2) Pedidos\n\t3) Asignacion de pedidos\n\t4) Salir \n\n\tOpci�n: ");
}
void menuAdminGenera_Repartidor()
{
    system("mode con: cols=50 lines=20");
    system("cls");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 225);
    printf("\t   REPARTIDORES           ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\t1) Ingresar repartidor\n");
    printf("\t2) Mostrar lista de repartidores\n");
    printf("\t3) Eliminar repartidor\n");
    printf("\t4) Modificar datos repartidor\n");
    printf("\t5) Salir \n\n\tOpci�n: ");
}
void menuAdminGenera_Pedidos()
{
    system("mode con: cols=50 lines=20");
    system("cls");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 225);
    printf("\t      PEDIDOS\t\t  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\t1) Ingresar pedidos\n");
    printf("\t2) Mostrar pedidos\n");
    printf("\t3) Eliminar pedidos\n");
    printf("\t4) Modificar datos pedidos\n");
    printf("\t5) Salir \n\n\tOpci�n: ");
}
void presentacionRepar()
{
    //PRESENTACION INGRESO DE REPARTIDORES
    system("cls");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
    printf("                   INGRESO DE REPARTIDORES                   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n");
}

void imprimirRepar(){
    //IMPRESION DE REPARTIDORES
    system("mode con: cols=150 lines=40");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
    printf("\t\t\t\t\t\t\t   LISTA DE REPARTIDORES   \t\t\t\t\t\t\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n\n\tId repartidor    Nombre\t     Apellidos\t\t\t Direcci�n  \tTel�fono\t\tE-mail");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n");
}
void immprimirReparNull()
{
    //IMPRESION DE REPARTIDORES SI ES NULL
    system("mode con: cols=80 lines=20");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
    printf("                  La lista se encuentra vac�a                  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\t");
    system("pause");
}

void presentacionPedi()
{
    system("cls");
    printf("\n\n\n\t");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
    printf("                   INGRESO DE PEDIDOS                   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n\n\n");
}