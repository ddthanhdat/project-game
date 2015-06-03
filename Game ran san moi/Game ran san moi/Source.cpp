#include <iostream>
#include "Header.h"
#include "console.h"
#include "console.cpp"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int xuly(diem &);
inline void dieukhien(char &);
//void hienthi(diem &);
int i = 2;
int soluong = 3;

int main(){
	char trangthai = 'd';
	diem ran[100];
	diem food;
	int speed=300;
	
	// khoi tao ban dau:
	ran[0].SetX(4);
	ran[0].SetY(4);
	ran[1].SetX(5);
	ran[1].SetY(4);
	ran[2].SetX(6);
	ran[2].SetY(4);
	food.SetX(1 + rand() % 20);
	food.SetY(1 + rand() % 20);
	
	//gotoXY(1, 1); cout << trangthai;
	//xu ly
	while (1){
		//xuly(ran);
		//dieu khien
		//dieukhien(trangthai);
		char key;
		if (_kbhit()){
			key = _getch();
			if ((key == 'A' || key == 'a') && ( ran[i - 1].GetY() != ran[i].GetY() ))
				trangthai = 'a';
			else if ((key == 'D' || key == 'd') && (ran[i - 1].GetY() != ran[i].GetY()))
				trangthai = 'd';
			else if ((key == 'W' || key == 'w') && (ran[i - 1].GetX() != ran[i].GetX()))
				trangthai = 'w';
			else if ((key == 'S' || key == 's') && (ran[i - 1].GetX() != ran[i].GetX()))
				trangthai = 's';
		}
		//
		clrscr();
		if ((trangthai == 'a') ){
			i++;
			ran[i].SetX(ran[i - 1].GetX() - 1);
			ran[i].SetY(ran[i - 1].GetY());
		}
		else if (trangthai == 'w'){
			i++;
			ran[i].SetX(ran[i - 1].GetX());
			ran[i].SetY(ran[i - 1].GetY()-1);
		}
		else if (trangthai == 'd'){
			i++;
			ran[i].SetX(ran[i - 1].GetX()+1);
			ran[i].SetY(ran[i - 1].GetY());
		}
		else if (trangthai == 's'){
			i++;
			ran[i].SetX(ran[i - 1].GetX());
			ran[i].SetY(ran[i - 1].GetY() + 1);
		}
		//xuly food
		if (ran[i].GetX() == food.GetX() && ran[i].GetY() == food.GetY()){
			food.SetX(1 + rand() % 20);
			food.SetY(1 + rand() % 20);
			soluong++;
		}
		// xu ly full 100 mang;
		if (i == 99){
			int k = soluong - 1;
			for (int j = i; j >= i - soluong + 1; j--){
				ran[k].SetX(ran[j].GetX());
				ran[k].SetY(ran[j].GetY());
				k--;
			}
			i = soluong - 1;
		}
		
		// hien thi: text
		gotoXY(5, 1); cout << "Demo game: ITUS-GAME CLUB";
		// hien thi ran:
		for (int j = i; j >= i - soluong + 1; j--){
			gotoXY(ran[j].GetX(), ran[j].GetY()); cout << "O";
		}
		
		//
		gotoXY(food.GetX(), food.GetY()); cout << "F";
		
		if (speed <= 0) speed = 0;
		else speed = 300 - soluong * 15;
		Sleep(speed);
		
	}
	
	system("pause");
	return 0;
}
inline void dieukhien(char &trangthai){
	
}
	
int xuly(diem ran[]);