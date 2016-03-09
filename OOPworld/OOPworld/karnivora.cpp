#include "karnivora.h"

karnivora::karnivora() {
	// default constructor
}

karnivora::karnivora(int ID, char** bid, Point& p1, Point& p2, Point& p3, Point& p4) : makhluk(ID, bid, 'k', p1, p2, p3, p4) {
	mlapar = 10;
}

karnivora::~karnivora() {
	std::cout << "destructor karnivora" << std::endl;
}

int karnivora::getmengejar() {
	return mengejar;
}

void karnivora::lihat() {
	dt += 1;
}

void karnivora::bergerak() {
	makhluk::bergerak();
	mlapar--;
}

void karnivora::printstatmakhluk() {
	makhluk::printstatmakhluk();
	printf("tingkat kelaparan = %d\n", mlapar);
}

int karnivora::getlapar() { 
	return mlapar; 
}