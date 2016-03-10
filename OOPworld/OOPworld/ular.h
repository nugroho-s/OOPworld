#include "karnivora.h"
#include "list.h"
#include "board.h"

class ular : public karnivora {
public:
	// constructor
	ular();
	ular(int ID, char**, Point&, Point&, Point&, Point&);
	
	// copy constructor 
	ular(ular&);
	
	// operator= 
	ular& operator= (ular&);
	
	// destruktor
	virtual ~ular();
	
	// method
	virtual void makan();
	
protected:
	const int maxlapar = 35;
	
	list LOP;
};
