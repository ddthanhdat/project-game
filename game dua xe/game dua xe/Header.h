#include <iostream>
#include <math.h>
#include "console.h"
#include "console.cpp"
using namespace std;
//////////////////////// CLASS XE
class xe{   
	int x;
	int y;
	
	int diem;
public:
	xe(int a, int b){ x = a; y = b; diem = 0; }
	char hinhdang[3][3];
	xe(){ diem = 0; }
	int getdiem() { return diem; }
	int getX(){ return x; }
	int getY(){ return y; }
	void setdiem(int d){ diem += d; }
	void setX(int ax){ x = ax; }
	void setY(int ay){ y = ay; }
	void updateX(char tam, int so){
		if (tam == '+')
			x += so;
		else if (tam == '-')
			x -= so;
	}
	void updateY(char tam, int so){
		if (tam == '+')
			y += so;
		else if (tam == '-')
			y -= so;
	}
	void in(int, int);
};
void xe::in(int x, int y){
	int y1, x1;
	if (y > 0)
		TextColor(4);
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			x1 = x + j;
			y1 = y + i;
			gotoXY(x1, y1); cout << hinhdang[i + 1][j + 1];
		}
	}
}


//////////////////////////	CLASS VAT CAN...
class vatcan{
	int x, y;
	
public:
	char hinhdang[3][3];
	vatcan(int a = 5, int b = 1){
		 x = a;   y = b;
		 hinhdang[0][0] = hinhdang[0][2] = hinhdang[2][0] = hinhdang[2][2] = 'O';
		 hinhdang[0][1] = hinhdang[2][1] = '.';
		 hinhdang[1][0] = hinhdang[1][2] = ':';
		 hinhdang[1][1] = '0';
	}
	int getX(){ return x; }
	int getY(){ return y; }
	void setX(int ax){ x = ax; }
	void setY(int ay){ y = ay; }
	void updateX(char tam, int so){
		if (tam == '+')
			x += so;
		else if (tam == '-')
			x -= so;
	}
	void updateY(char tam, int so){
		if (tam == '+')
			y += so;
		else if (tam == '-')
			y -= so;
	}
	void in(int, int);
};
// in vat can
void vatcan::in(int x, int y){
	int y1, x1;
	if (y > 0)
		
		TextColor(14);
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			x1 = x + j;
			y1 = y + i;
			gotoXY(x1, y1); cout << hinhdang[i + 1][j + 1];
		}
	}
}




