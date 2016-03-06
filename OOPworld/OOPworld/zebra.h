#include "herbivora.h"

// file: zebra.h 
// class zebra mewarisi sifat dari class herbivora
// class zebra mewarisi sifat dari class makhluk
// method yang dimiliki sendiri (tidak diturunkan dari herbivora dan makhluk) :
//		- NONE
// data yang dimiliki sendiri (tidak diturunkan dari herbivora dan makhluk) :
//		- const int maxlapar = 30 


class zebra : public herbivora {
public:
	// konstruktor
	zebra();
	
	// destruktor
	virtual ~zebra();
	
	// memakan objek lain. level kelaparannya menjadi maxlapar (sangat kenyang) 
	virtual void makan();
	
protected:
	// level kelaparan sebuah objek zebra 
	// maxlapar = 30 berarti objek sangat kenyang 
	// maxlapar = 0 berarti objek sangat lapar 
	// maxlapar < 30 berarti objek itu makin lapar
	const int maxlapar = 30;	
};