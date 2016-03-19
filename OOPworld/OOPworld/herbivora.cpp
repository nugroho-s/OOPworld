#include "herbivora.h"

herbivora::herbivora() {
}

herbivora::herbivora(Point& p1, Point& p2, Point& p3, Point& p4) : makhluk(isi, 'h', p1, p2, p3, p4) {
	mlapar = 10;
}

herbivora::~herbivora() {
	std::cout << "destructor herbivora" << std::endl;
}

makhluk* herbivora::getdikejar() {
	return dikejar;
}

void herbivora::bergerak() {
	// level kelaparan berkurang menjadi semakin lapar
	makhluk::bergerak();
	mlapar--;
}

int herbivora::getlapar() {
	// mengembalikan level kelaparan sebuah objek herbivora 
	return mlapar;
}

void herbivora::printstatmakhluk() {
	makhluk::printstatmakhluk();
	printf("tingkat kelaparan = %d\n", mlapar);
}
