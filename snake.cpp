#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESC 27

int serpiente[200][2];
int s = 1;
int tamano = 5;
int x = 10;
int y = 12;
char teclas;

void gotoxy(int x, int y){
	
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
	
}
	
void tablero(){
	
	for(int i=2; i<78; i++){
		
		gotoxy(i , 3); printf ("%c", 205);
		gotoxy(i , 23); printf ("%c", 205);
		
	}
	for(int i=4; i<23; i++){
		
		gotoxy(2 , i); printf ("%c", 186);
		gotoxy(77 , i); printf ("%c", 186);
		
	}
	gotoxy(2, 3); printf ("%c", 201);
	gotoxy(77, 3); printf ("%c", 187);
	gotoxy(77, 23); printf ("%c", 188);
	gotoxy(2, 23); printf ("%c", 200);
	
}
	
void guardar(){
	
	serpiente[s][0] = x;
	serpiente [s][1] = y;
	s++;
	if(s == tamano){
		
		s = 1;
		
	}
}

using namespace std;

int main(int argc, char *argv[]) {
	
	tablero();
	
	while(teclas != ESC){
		
	}
	
	system("pause>null");
	
	return 0;
}

