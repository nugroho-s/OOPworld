#include "karnivora.h"

class singa : public karnivora {
public:
	// constructor
	singa();
	
	// copy constructor 
	singa(singa&);
	
	// operator= 
	singa& operator= (singa&);
	
	// destruktor
	virtual ~singa();
	
	// method
	virtual void makan();
	
protected:
	const int maxlapar = 30;
};