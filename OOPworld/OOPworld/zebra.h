#include "herbivora.h"
#include "list.h"
#include "board.h"
#include "pathtree.h"

// file: zebra.h 
// class zebra mewarisi sifat dari class herbivora
// class zebra mewarisi sifat dari class makhluk
// method yang dimiliki sendiri (tidak diturunkan dari herbivora dan makhluk) :
//		- NONE
// data yang dimiliki sendiri (tidak diturunkan dari herbivora dan makhluk) :
//		- const int maxlapar = 30 


extern Point** prevs;

class zebra : public herbivora {
public:
	// constructor
	zebra();
	zebra(int ID, char**, Point&, Point&, Point&, Point&);

	// copy constructor
	zebra(zebra&);

	// operator= 
	zebra& operator= (zebra&);

	// destruktor
	virtual ~zebra();

	// memakan objek lain. level kelaparannya menjadi maxlapar (sangat kenyang) 
	virtual void makan();

	// membuat path ke target
	virtual void makepath();

protected:
	// level kelaparan sebuah objek zebra 
	// maxlapar = 30 berarti objek sangat kenyang 
	// maxlapar = 0 berarti objek sangat lapar 
	// maxlapar < 30 berarti objek itu makin lapar
	const int maxlapar = 30;

	// list dengan elemen Point (x,y) yang menyatakan sel-sel mana saja 
	// yang termasuk ke dalam path si zebra menuju posisi target 
	list LOP;
};