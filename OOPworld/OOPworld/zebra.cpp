#include "zebra.h"

zebra::zebra() {
	// konstruktor
	mlapar = maxlapar;
	power = 3;
	dt = 2;
	arah = 0;
	umur = 30;
	id = 'z';
}

zebra::~zebra() {
	// destruktor
}

void zebra::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}

