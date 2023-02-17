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
int tamano = 10;
int x = 10;
int y = 12;
int dir = 3;
int xb = 30;
int yb = 15;
char teclas;
int velocidad = 100;
int h = 1;
int puntuacion = 0;


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
	
void dibujar(){
	
	for(int i=1; i<tamano; i++){
		
		gotoxy(serpiente[i][0], serpiente[i][1]); printf("%c",15);
		
	}
	
}
	
void borrar(){
	
	for(int i=1; i<tamano; i++){
		
		gotoxy(serpiente[i][0], serpiente[i][1]); printf(" ");
		
	}
	
}

void movimiento(){
	
	if (kbhit()){
		
		teclas = getch();
		 switch(teclas){
			case ARRIBA:
			 if (dir != 2){
				 dir = 1;
			 }
			 break;
			 case ABAJO:
			 if (dir != 1){
				 dir = 2;
			 }
			 break;
			case DERECHA:
			 if (dir != 4){
				 dir = 3;
			 }
			 break;
			case IZQUIERDA:
			 if (dir != 3){
				 dir = 4;
			 }
			 break;
		 }
		
	}
	
}
	
void vel(){
	
	if(puntuacion == h*20){
		
		velocidad -= 10;
		h++;
		
	}
	
}
	
void bolitas(){
	
	if(x == xb && y == yb){
		
		xb = (rand() % 73 ) + 4;
		yb = (rand() % 19 ) + 4;
		tamano++;
		puntuacion += 10;
		gotoxy(xb, yb); printf("%c", 1);
		
	}
	
	vel();
	
}
	
bool choque(){
	
	if(x == 2 || x == 77 || y == 3 || y == 23){
		
		return false;
		
	}
	
	for (int j=tamano - 1; j<0; j--){
		
		if(serpiente [j][0] == x && serpiente [j][1] == y){
			
			return false;
		}
		
	}
	return true;
	
}
	
void score(){

	gotoxy(3,1);printf("score del jugador: %d", puntuacion);
	
}

using namespace std;

int main(int argc, char *argv[]) {
	
	tablero();
	gotoxy(xb, yb); printf("%c", 1);
	
	
	while(teclas != ESC && choque()){
		
		borrar();
		guardar();
		dibujar();
		bolitas();
		score();
		movimiento();
		movimiento();
		 if(dir == 1){y--;}
		 if(dir == 2){y++;}
		 if(dir == 3){x++;}
		 if(dir == 4){x--;}
		Sleep(velocidad);
		
	}
	
	system("pause>null");
	
	return 0;
}

