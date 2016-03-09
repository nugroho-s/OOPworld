#include "makhluk.h"
#include "herbivora.h"

class kelinci : public herbivora {
public:
	//! konstruktor
	kelinci();
	
	//! destruktor
	~kelinci();
	
	//!memakan objek lain 
	void makan();
	
	//!bersembunyi di cangkang utk kasus kura2
	void sembunyi();
	
	//!berpindah ke koordinat lain 
	void bergerak();
	
private:
	const int maxlapar = 30;
}
