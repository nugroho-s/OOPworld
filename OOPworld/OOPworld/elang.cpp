#include "elang.h"

elang::elang(int ID, char** bid, Point& p1, Point& p2, Point& p3, Point& p4) : karnivora(ID, bid, p1, p2, p3, p4) {
	// constructor 
	mlapar = maxlapar;
	power = 4;
	dt = 2;
	arah = 0;
	mengejar = 0;
}

elang::elang(elang& s) {
	// copy constructor
	mlapar = s.mlapar;
	power = s.power;
	dt = s.dt;
	arah = s.arah;
	mengejar = s.mengejar;
	P.set(s.getlok().getX(), s.getlok().getY());
}

elang& elang::operator= (elang& s) {
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

elang::~elang() {
	// destruktor
	cout << "destructor elang" << endl;
}

void elang::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}

	
