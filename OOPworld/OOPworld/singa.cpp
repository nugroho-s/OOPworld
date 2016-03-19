#include "singa.h"

singa::singa(Point& p1, Point& p2, Point& p3, Point& p4) : karnivora(p1, p2, p3, p4) {
	// constructor 
	mlapar = maxlapar;
	power = 5;
	dt = 2;
	arah = 0;
	mengejar = NULL;		// belum ada objek yang sedang dikejar
	target.set(-1, -1);	
	printf("selesai alokasi s\n");
}

singa::singa(singa& s) {
	// copy constructor
	mlapar = s.mlapar;
	power = s.power;
	dt = s.dt;
	arah = s.arah;
	mengejar = s.mengejar;
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
		mengejar = s.mengejar;
		P.set(s.getlok().getX(), s.getlok().getY());
		return *this;
	}
}

singa::~singa() {
	// destruktor
	std::cout << "destructor singa" << std::endl;
}

void singa::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}

void singa::makepath(Point& _target) { 

}
	
