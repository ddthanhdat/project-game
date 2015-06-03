#include <iostream>
#include <math.h>
#include "Header.h"
#include "console.h"
#include "console.cpp"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
const int lephaiROAD = 22;
const int leduoiRoad = 23;
int vachke = 0;
int diem = 0;

void hienthi(vatcan &);
inline void dieukhien(xe &, xe &);
int xuly(xe &, xe &, vatcan &);
inline void khoitao(xe &, xe &);
inline void hienthiroad(xe &, xe &);

int main(){
	xe xe1(5,20);
	xe xe2(8, 20);
	vatcan vc[10];
	khoitao(xe1, xe2);
	int soluong = 0;
	int time = 0;
	int thoat = 0;
	int speed = 300;
	while (1)
	{
		clrscr();
		// hien thi //
		hienthiroad(xe1, xe2);
		// hien thi vat can
		hienthi(vc[0]);
		
		if (time >= 19){
			hienthi(vc[1]);
			if(time==19) soluong++;
		}
		
		if (time >= 29){
			hienthi(vc[2]); 
			if (time == 29) soluong++;
		}
		if (time >= 35){
			hienthi(vc[3]); 
			if (time == 35) soluong++;
		}
		if (time >= 55){
			hienthi(vc[4]);
			if (time == 55) soluong++;
		}
		if (time >= 75){
			hienthi(vc[5]);
			if (time == 75) soluong++;
		}
		if (time >= 100){
			hienthi(vc[6]);
			if (time == 100) soluong++;
		}
		if (time >= 125){
			hienthi(vc[7]);
			if (time == 125) soluong++;
		}
		time++;
		// hien thi xe


		// dieu khien//
		dieukhien(xe1, xe2);
		// xu ly
		for (int i = 0; i <= soluong; i++)
		if (-1 == xuly(xe1, xe2, vc[i]))thoat = 1;
	
		if (thoat == 1){
			TextColor(7);
			gotoXY(35, 15); cout << " game over !";
			break;
		}
		
		if (speed < 0) speed = 0;
		else speed -= diem * 5;
		Sleep(speed);
	}
	system("pause");
	return 0;
}

inline void khoitao(xe &xe1,xe &xe2){
	//khoi tao hinh dang xe1//
	xe1.hinhdang[0][0] = xe1.hinhdang[0][2] = xe1.hinhdang[2][0] = xe1.hinhdang[2][2] = 'O';
	xe1.hinhdang[0][1] = xe1.hinhdang[2][1] = '-';
	xe1.hinhdang[1][0] = xe1.hinhdang[1][2] = '|';
	xe1.hinhdang[1][1] = '1';
	xe2.hinhdang[0][0] = xe2.hinhdang[0][2] = xe2.hinhdang[2][0] = xe2.hinhdang[2][2] = 'O';
	xe2.hinhdang[0][1] = xe2.hinhdang[2][1] = '-';
	xe2.hinhdang[1][0] = xe2.hinhdang[1][2] = '|';
	xe2.hinhdang[1][1] = '2';
	// khoai tao vatcan
	
}

int xuly(xe &xe1,xe &xe2, vatcan &vc){
	
	// va cham xe
	int khoangcachX = abs(xe1.getX() - vc.getX());
	int khoangcachY = abs(xe1.getY() - vc.getY());
	int khoangcachX2= abs(xe2.getX() - vc.getX());
	int khoangcachY2= abs(xe2.getY() - vc.getY());
	if ((khoangcachX < 3 && khoangcachY < 3) || (khoangcachX2 < 3 && khoangcachY2 <3)) return -1;
	
	// chay xuong va cong diem
	vc.updateY('+', 1);
	if (vc.getY() == leduoiRoad) {
		diem++;
		vc.setY(1);
		int tam = 2 + rand() % (lephaiROAD-3);
		vc.setX(tam);
	}
	return 1;
}
inline void dieukhien(xe &xe1,xe &xe2){
	char key;
	if (_kbhit()){
		key = _getch();
		if ((key == 'A' || key == 'a') && xe1.getX() > 2)
			xe1.updateX('-', 3);
		else if ((key == 'D' || key == 'd') && xe1.getX() <lephaiROAD - 2)
			xe1.updateX('+', 3);
		else if (key == 'W' || key == 'w')
			xe1.updateY('-', 1);
		else if ((key == 'S' || key == 's') && xe1.getY() < leduoiRoad - 1)
			xe1.updateY('+', 1);

		if ((key == 'J' || key == 'j') && xe2.getX() > 2)
			xe2.updateX('-', 3);
		else if ((key == 'L' || key == 'l') && xe2.getX() <lephaiROAD - 2)
			xe2.updateX('+', 3);
		else if (key == 'I' || key == 'i')
			xe2.updateY('-', 1);
		else if ((key == 'K' || key == 'k') && xe2.getY() < leduoiRoad - 1)
			xe2.updateY('+', 1);
	}
}
inline void hienthiroad(xe &xe1, xe &xe2){
	TextColor(7); 														// begin Road
	for (int i = 0; i <= leduoiRoad; i++){
		gotoXY(0, i); cout << "|";
		gotoXY(lephaiROAD, i); cout << "|";
	}

	if (vachke % 3 == 0)
	for (int j = 0; j <= leduoiRoad; j++){
		if (j % 3 != 2){
			gotoXY(lephaiROAD / 2, j); cout << "|";
		}
	}
	else if (vachke % 3 == 1)
	for (int j = 0; j <= leduoiRoad; j++){
		if (j % 3 != 0){ gotoXY(lephaiROAD / 2, j); cout << "|"; }
	}
	else if (vachke % 3 == 2)
	for (int j = 0; j <= leduoiRoad; j++){
		if (j % 3 != 1){ gotoXY(lephaiROAD / 2, j); cout << "|"; }
	}
	vachke++;
	//hien thi xe
	xe1.in(xe1.getX(), xe1.getY());
	xe2.in(xe2.getX(), xe2.getY());
	// hien thi thong tin
	TextColor(7);
	gotoXY(30, 2); cout << "diem = " << diem;
}
void hienthi(vatcan &vc){
	// in vat can
	vc.in(vc.getX(), vc.getY());
}