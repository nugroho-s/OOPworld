#include "karnivora.h"
#include "list.h"
#include "board.h"

class singa : public karnivora {
public:
	// constructor
	singa();
	singa(Point&, Point&, Point&, Point&);
	
	// copy constructor 
	singa(singa&);
	
	// operator= 
	singa& operator= (singa&);
	
	// destruktor
	virtual ~singa();
	
	// method
	virtual void makan();
	virtual void makepath(Point&);
	
protected:
	const int maxlapar = 30;
	
	list LOP;
};