#pragma once
#include "makhluk.h"

/*
	DEFINISI:
	Tumbuhan hanya akan berada di spawn karnivora
*/

class tumbuhan : public makhluk {
public:
	//konstruktor
	tumbuhan();
	
	//copy constructor
	tumbuhan(tumbuhan&);
	
	//operator= 
	tumbuhan& operator= (tumbuhan&);
	
	//destruktor
	~tumbuhan();

private:
	//Nilainya 0 atau 1. 
	//Nilai 0 berarti tumbuhan belum dimakan herbivora
	//sehingga masih ada di board. 
	//Nilai 1 berarti tumbuhan sudah dimakan herbivora 
	//sehingga dihilangkan dari board
	int dimakan;	
	
	//posisi sebuah tumbuhan di board 
	Point P;
};