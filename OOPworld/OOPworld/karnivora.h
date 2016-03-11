#include "makhluk.h"
#include "board2.h"

class karnivora : public makhluk {
public:
	// konstruktor
	karnivora();
	karnivora(Point&, Point&, Point&, Point&);
	// destruktor
	~karnivora();
	// mendapatkan objek yang dikejar 
	makhluk* getmengejar();
	// memakan objek lain - kelas turunannya harus mengimplementasikan ini 
	virtual void makan() = 0;
	// membuat path ke target
	virtual void makepath(Point&) = 0;
	// mendeteksi apakah di daerah sepanjang arah gerak karnivora terdapat herbivora
	void lihat(Point&);
	// objek turunan karnivora berpindah ke koordinat lain 
	void bergerak();
	// mendapatkan level kelaparan karnivora 
	int getlapar();
	// menampilkan status karnivora 
	void printstatmakhluk();
	
protected:
	int mlapar;			// level kelaparan sebuah objek turunan herbivora 
	int jenismakanan;
	makhluk* mengejar;	// pointer terhadap objek yang dikejar
};

void point_in_while(Point&, int, int, int);