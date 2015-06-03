#include <iostream>
using namespace std;

class diem{
	int x; int y;
public:
	diem(int a = 0, int b = 0){ x = a; y = b; }
	void SetX(int a){ x = a; }
	void SetY(int a){ y = a; }
	int GetX(){ return x; }
	int GetY(){ return y; }
};