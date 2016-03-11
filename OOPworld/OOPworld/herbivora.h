#include "makhluk.h"
#include "board2.h"

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
	// konstruktor
	herbivora();
	herbivora(Point&, Point&, Point&, Point&);
	
	// destruktor
	virtual ~herbivora();
	
	// mendapatkan objek yang mengejar 
	makhluk* getdikejar();
	
	// memakan objek lain - kelas turunannya harus mengimplementasikan ini 
	virtual void makan()=0;
	
	// membuat path ke target
	virtual void makepath(Point&) = 0;
	
	// objek turunan herbivora berpindah ke koordinat lain 
	virtual void bergerak();
	
	// mendapatkan level kelaparan sebuah objek turunan herbivora  
	virtual int getlapar();
	
protected:
	int mlapar;			// level kelaparan sebuah objek turunan herbivora 
	makhluk* dikejar;	// pointer terhadap objek yang mengejar
};
