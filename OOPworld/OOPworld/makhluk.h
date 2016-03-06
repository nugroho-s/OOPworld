#pragma once

#include "Point.h"
#include "stdafx.h" 

//! Abstract Class - tidak bisa dibuat objeknya
class makhluk {
public:
	//! konstruktor
	makhluk();

	//! destruktor 
	virtual ~makhluk();

	//! objek turunan makhluk berpindah ke koordinat lain 
	virtual void bergerak();

	//! memakan objek lain - kelas turunannya harus mengimplementasikan ini 
	virtual void makan() = 0;

	//
	// GETTER 
	//

	//! mendapatkan level kelaparan sebuah objek turunan makhluk 
	virtual int getlapar() = 0;
	//! mendapatkan lokasi (x, y) sebuah objek turunan makhluk di bidang 
	Point getlok();

	//! menampilkan lokasi (x, y) sebuah objek turunan makhluk di bidang 
	void printlok();

	//! menampilkan semua status makhluk
	virtual void printstatmakhluk();

	virtual char getid();
	//! mengirimkan id

protected:
	char id;
	int dt;		//! selang waktu gerak sebuah objek turunan makhluk 
	int umur;	//
	int power;	//! kekuatan sebuah objek turunan makhluk 
	int arah;	//! arah gerak sebuah objek turunan makhluk 
	Point P;	//! koordinat sebuah objek turunan makhluk di bidang 
};