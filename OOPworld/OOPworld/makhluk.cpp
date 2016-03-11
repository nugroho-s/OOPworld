//
// File: makhluk.cpp
//
// IMPLEMENTASI abstract class makhluk.h
//

#include "makhluk.h"

makhluk::makhluk() {
	// default constructor 
}

makhluk::makhluk(char** bid, char jenis_obj, Point min_h_v, Point max_h_v, Point min_h_h, Point max_h_h) {
	// konstruktor
	// inisiasi nilai koordinat awal objek (x, y) dengan nilai random 
	int found = 0, x, y;
	while (found == 0) {
		// random nilai (x,y) dan cek apakah lokasi objek sudah tepat di spawn nya  
		x = rand() % (max_h_v.getX()+1-min_h_v.getX()) + min_h_v.getX(); 
		y = rand() % (max_h_h.getY()+1-min_h_h.getY()) + min_h_h.getY();
		if (bid[x][y] == jenis_obj) {
			found = 1;
		}
	}
	P.set(x, y);
	
	// inisiasi atribut id 
	id = jenis_obj;
	// inisiasi nilai arah gerak awal objek dengan nilai random (0 - 7)
	arah = rand() % 8;
}

makhluk::~makhluk() {
	// destruktor
	std::cout << "destructor makhluk" << std::endl;
}

void makhluk::bergerak() {
	// memindahkan objek ke posisi lain di bidang 
	
	/*
	ketentuan: 
	0 : timur
	1 : tenggara
	2 : seltan
	3 : barat daya
	4 : barat 
	5 : barat laut
	6 : utara
	7 : timur laut
	*/
	
	if (arah == 0) {
		P.move(power,0);
	} else if (arah == 1) {
		P.move(power,-power);
	} else if (arah == 2) {
		P.move(0,-power);
	} else if (arah == 3) {
		P.move(-power,-power);
	} else if (arah == 4) {
		P.move(-power,0);
	} else if (arah == 5) {
		P.move(-power,power);
	} else if (arah == 6) {
		P.move(0,power);
	} else if (arah == 7) {
		P.move(power,power);
	}

	//jika keluar dari bidang, bagaimana?
}

Point makhluk::getlok() { 
	// mengembalikan posisi (x, y) objek di bidang 
	return P; 
}

Point makhluk::gettarget() {
	// mengembalikan posisi target (x, y) di bidang 
	return target;
}

int makhluk::getid() {
	return id;
}
int makhluk::getdt() {
	return dt;
}
int makhluk::getpower() {
	return power;
}
int makhluk::getarah() {
	return arah;
}

void makhluk::printlok() {
	printf("lokasi = (%d,%d)\n", P.getX(), P.getY());
}

void makhluk::printstatmakhluk() {
	makhluk::printlok();
}