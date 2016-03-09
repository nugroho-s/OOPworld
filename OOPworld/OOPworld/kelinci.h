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
	
	//!bersembunyi di benteng kecil
	void sembunyi();
	
	//!berpindah ke koordinat lain 
	void bergerak();
	
private:
	const int maxlapar = 30;
}
