#include "karnivora.h"
#include "list.h"
#include "board.h"

class elang : public karnivora {
public:
	// constructor
	elang();
	elang(int ID, char**, Point&, Point&, Point&, Point&);
	
	// copy constructor 
	elang(elang&);
	
	// operator= 
	elang& operator= (elang&);
	
	// destruktor
	virtual ~elang();
	
	// method
	virtual void makan();

	
protected:
	const int maxlapar = 25;
	
	list LOP;
};
