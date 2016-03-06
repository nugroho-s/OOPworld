#include "herbivora.h"

herbivora::herbivora() {
	// konstruktor
	// inisialisasi nilai mlapar = 10;
	mlapar = 10;
}

herbivora::~herbivora() {
	// destruktor 
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