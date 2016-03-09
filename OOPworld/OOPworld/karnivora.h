#pragma once
#include <stdlib.h>
#include "Point.h"
#include "makhluk.h"

class karnivora : public makhluk {
public:
	karnivora();
	karnivora(int ID, char**, Point&, Point&, Point&, Point&);
	~karnivora();
	int getmengejar();
	virtual void makan() = 0;
	virtual void makepath() = 0;
	void lihat();
	void bergerak();
	int getlapar();
	void printstatmakhluk();
protected:
	int mlapar;
	int jenismakanan;
	int mengejar;		// return 1 jika sedang mengejar herbivora
	Point target;		// lokasi target yang dituju 
};