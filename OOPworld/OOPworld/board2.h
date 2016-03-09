#include "makhluk.h"
#include "Point.h"

extern int sizex;
extern int sizey;
extern int sizepintu_p;
extern Point min_h_vertical, min_k_vertical;
extern Point max_h_vertical, max_k_vertical;
extern Point min_h_horizontal, min_k_horizontal;
extern Point max_h_horizontal, max_k_horizontal;
extern char** isi;
extern Point pintu_u;
extern Point pintu_s;
extern Point* pintu_p;
		
void board();
	// make board dari file eksternal 
void min_h_ver(char, int*, int*);
void max_h_ver(char, int*, int*);
void min_h_hor(char, int*, int*);
void max_h_hor(char, int*, int*);
void printboard();
	//print kondisi dunia saat ini
void tambah(makhluk&, char);
	//tambahkan makhluk ke papan
void move(makhluk&, char);
	//gerakkan makhluk, parameter makhluk yang diminta parameter
	//adalah sebelum digerakkan
	//setelah move, makhluk akan berpindah
void hapus(makhluk&);
	//hapus makhluk dari papan
void deallocate_board();
	//dealokasi array board
