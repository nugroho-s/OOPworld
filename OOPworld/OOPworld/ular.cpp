#include "ular.h"

ular::ular(int ID, char** bid, Point& p1, Point& p2, Point& p3, Point& p4) : karnivora(ID, bid, p1, p2, p3, p4) {
	// constructor 
	mlapar = maxlapar;
	power = 5;
	dt = 2;
	arah = 0;
	mengejar = 0;
}

ular::ular(ular& s) {
	// copy constructor
	mlapar = s.mlapar;
	power = s.power;
	dt = s.dt;
	arah = s.arah;
	mengejar = s.mengejar;
	P.set(s.getlok().getX(), s.getlok().getY());
}

ular& ular::operator= (ular& s) {
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

ular::~ular() {
	// destruktor
	cout << "destructor ular" << endl;
}

void ular::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}
