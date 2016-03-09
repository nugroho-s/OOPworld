#include "Point.h"
#include "stdafx.h" 

// Abstract Class - tidak bisa dibuat objeknya
#ifndef makhluk_h
#define makhluk_h

class makhluk {
public:
	// konstruktor
	makhluk();
	makhluk(int ID, char**, char jenis_obj, Point min_h_v, Point max_h_v, Point min_h_h, Point max_h_h);

	// destruktor 
	virtual ~makhluk();
	
	// METHOD
	//---objek turunan makhluk berpindah ke koordinat lain 
	virtual void bergerak();
	//---memakan objek lain - kelas turunannya harus mengimplementasikan ini 
	virtual void makan() = 0;
	//---membuat path ke target
	virtual void makepath() = 0;
	
	//
	// GETTER 
	//

	// mendapatkan level kelaparan sebuah objek turunan makhluk 
	virtual int getlapar() = 0;
	Point getlok();
	int getid();
	int getdt();
	int getpower();
	int getarah();
	
	// menampilkan lokasi (x, y) sebuah objek turunan makhluk di bidang 
	void printlok();
	// menampilkan semua status makhluk
	virtual void printstatmakhluk();

protected:
	int id;		// id objek turunan makhluk hidup (unik)
	int dt;		// selang waktu gerak sebuah objek turunan makhluk 
	int power;	// kekuatan sebuah objek turunan makhluk (berguna saat sebuah sel board ditempati lebih dari 1 makhluk) 
	int arah;	// arah gerak sebuah objek turunan makhluk 
	Point P;	// koordinat sebuah objek turunan makhluk di bidang 
};

#endif 