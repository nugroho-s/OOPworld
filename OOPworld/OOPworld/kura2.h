#pragma once
#include "makhluk.h"
#include "herbivora.h"

class kura2: public herbivora{
public:
	//! konstruktor
	kura2();
	
	//! destruktor
	~kura2();
	
	//!memakan objek lain 
	void makan();
	
	//!bersembunyi di cangkang utk kasus kura2
	void sembunyi();
	
	//!berpindah ke koordinat lain 
	void bergerak();
	
private:
	const int maxlapar = 30;

};
