#include "makhluk.h"

// file: herbivora.h 
// class herbivora mewarisi sifat dari makhluk 
// method yang dimiliki sendiri (tidak diturunkan dari makhluk) :
//		- herbivora()
//		- virtual ~herbivora()
//		- virtual void sembunyi()
// data yang dimiliki sendiri (tidak diturunkan dari makhluk) :
//		- int mlapar 


class herbivora: public makhluk {
public:
	//! konstruktor
	herbivora();
	
	//!destruktor
	virtual ~herbivora();
	
	//!memakan objek lain - kelas turunannya harus mengimplementasikan ini 
	virtual void makan()=0;
	
	//!bersembunyi di benteng kecil ATAU di cangkang utk kasus kura2
	virtual void sembunyi();
	
	//!objek turunan herbivora berpindah ke koordinat lain 
	virtual void bergerak();
	
	//!mendapatkan level kelaparan sebuah objek turunan herbivora  
	virtual int getlapar();
	
protected:
	int mlapar;		//!level kelaparan sebuah objek turunan herbivora 
};
