#pragma once
#include <stdlib.h>
#include "Point.h"
#include "makhluk.h"

class karnivora : public makhluk {
public:
	karnivora();
	//! konstruktor
	virtual ~karnivora();
	//! destruktor
	virtual void makan() = 0;
	//! mengisi mlapar
	void lihat();
	//! jika melihat mangsa, akan menambah kecepatan
	void bergerak();
	//! berpindah tempat
	int getlapar();
	//! mengembalikan mlapar
	void printstatmakhluk();
	//! print status makhluk karnivora
protected:
	int mlapar;
	int jenismakanan;
};