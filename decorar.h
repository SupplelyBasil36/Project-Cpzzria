void gotoxy(int x,int y){                                //funcion que habilita el uso de gotoxy dentro del main
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

void portada(){                                //funcion que habilita el uso de gotoxy dentro del main
	int aux;
	FILE *archivo = fopen("portada.txt", "r");
	
	for(int i=0; i<42; i++){
		for(int j=0; j<72; j++){
			fscanf(archivo,"%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),aux);
			printf("%c",219);
		}
		printf("\n");
	}
	
	fclose(archivo);
 } 
 
 void datos(){
 	setlocale(LC_CTYPE, "Spanish");
 	gotoxy(25,5);
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
 	printf("Universidad Politécnica de San Luis Potosí");
 	gotoxy(25,7);
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
 	printf("Programación I Lenguaje C");
 	gotoxy(25,9);
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
 	printf("Lucio López Aquino");
 	gotoxy(25,11);
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
 	printf("Cualquier tecla para iniciar...");
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
 	getch();	
 	
 }

