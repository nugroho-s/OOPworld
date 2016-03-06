#pragma once
#include <stdlib.h>
#include "Point.h"
#include "makhluk.h"

class karnivora : public makhluk {
public:
	karnivora();
	//~karnivora();
	virtual void makan() = 0;
	void lihat();
	void bergerak();
	int getlapar();
	void printstatmakhluk();
protected:
	int mlapar;
	int jenismakanan;
};