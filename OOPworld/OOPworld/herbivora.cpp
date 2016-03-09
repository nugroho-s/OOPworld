#include "herbivora.h"

herbivora::herbivora() {
	// default constructor
}

herbivora::herbivora(int ID, char** bid, Point& p1, Point& p2, Point& p3, Point& p4) : makhluk(ID, bid, 'h', p1, p2, p3, p4) {
	// konstruktor
	// inisialisasi nilai mlapar = 10;
	mlapar = 10;
}

herbivora::~herbivora() {
	// destruktor 
	std::cout << "destructor herbivora" << std::endl;
}

int herbivora::getdikejar() {
	return dikejar;
}

void herbivora::sembunyi()
{}

void herbivora::bergerak() {
	// level kelaparan berkurang menjadi semakin lapar
	makhluk::bergerak();
	mlapar--;
}

int herbivora::getlapar() {
	// mengembalikan level kelaparan sebuah objek herbivora 
	return mlapar;
}