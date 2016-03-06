#include "Point.h"

Point::Point() { 
	// inisialisasi koordinat awal objek di (0, 0)
	x=0; 
	y=0; 
}

Point::Point (int _X, int _Y) { 
	// inisialisasi koordinat awal objek di (_X, _Y)
    x = _X; 
	y = _Y;
 }

// mendapatkan koordinat absis (x) dan ordinat (y) objek di bidang
int Point::getX () { return x;}
int Point::getY () { return y;}

// mengubah posisi (x, y) objek di bidang menjadi _x dan _y 
void Point::set(int _x, int _y) {
	x = _x;
	y = _y;
}

// memindahkan objek ke koordinat (x+dx, y+dy)
void Point::move (int dx, int dy) {
	x = x + dx;
	y = y + dy;
}