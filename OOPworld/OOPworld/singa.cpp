#include "singa.h"

singa::singa() {
	// constructor 
	mlapar = maxlapar;
	power = 3;
	dt = 2;
	arah = 0;
	umur = 30;
	id = 's';
}

singa::singa(singa& s) {
	// copy constructor
	mlapar = s.mlapar;
	power = s.power;
	dt = s.dt;
	arah = s.arah;
	umur = s.umur;
	P.set(s.getlok().getX(), s.getlok().getY());
}

singa& singa::operator= (singa& s) {
	// operator=
	if (this == &s) { // jika melakukan assignment trhdp diri sendiri
		return *this; 
	} else { // jika bukan
		mlapar = s.mlapar;
		power = s.power;
		dt = s.dt;
		arah = s.arah;
		umur = s.umur;
		P.set(s.getlok().getX(), s.getlok().getY());
		return *this;
	}
}

singa::~singa() {
	// destruktor
	cout << "destructor singa" << endl;
}

void singa::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}

