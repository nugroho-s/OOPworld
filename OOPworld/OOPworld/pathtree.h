#include "board2.h"
#include "Point.h"

#ifndef paththree_h
#define paththree_h 

extern int** stat;
	//menyimpan nilai 1 atau 0 yang menyatakan apakah sebuah point di board sudah pernah 
	//dialokasikan sebagai node pada tree 
extern Point* ptree;
	//menyimpan semua point di board yang sudah pernah dialokasikan sebagai node pada tree 
extern int found_target;
	//menyimpan nilai 1 atau 0 yang menyatakan apakah pembentukan tree sudah mencapai target tujuan objek atau belum

/** Definisi Type Pohon Path **/
typedef struct tNode *AddressTree;
typedef struct tNode {
	AddressTree timur;
	AddressTree tenggara;
	AddressTree selatan;
	AddressTree baratdaya;
	AddressTree barat;
	AddressTree baratlaut;
	AddressTree utara;
	AddressTree timurlaut;
	AddressTree parent;
	Point P;
} Node;
typedef AddressTree PathTree;

/*
	DEFINISI Pohon Path (PathTree):
		- PathTree merupakan sebuah pohon dengan jumlah child node maksimal
		  sebanyak 8 buah (timur, tenggara, selatan, dst)
		- Urutan child node yang dimiliki sebuah parent node dari kiri ke kanan 
		  dapat dilihat pada bagian Selektor di bawah
*/

extern Node* proot;
	//menyimpan address dari node paling atas sebuah PathTree 
	
/** Selektor **/
// mengambil nilai point dari node di address P 
#define Akar(Q) (Q)->P 
// mengirimkan address dari node timur 
#define Timur(Q) (Q)->timur 
// mengirimkan address dari node tenggara 
#define Tenggara(Q) (Q)->tenggara 
// mengirimkan address dari node selatan 
#define Selatan(Q) (Q)->selatan
// mengirimkan address dari node baratdaya
#define BaratDaya(Q) (Q)->baratdaya 
// mengirimkan address dari node barat 
#define Barat(Q) (Q)->barat
// mengirimkan address dari node baratlaut 
#define BaratLaut(Q) (Q)->baratlaut
// mengirimkan address dari node utara  
#define Utara(Q) (Q)->utara
// mengirimkan address dari node timurlaut 
#define TimurLaut(Q) (Q)->timurlaut
//mengirimkan node parent dari sebuah child node 
#define Parent(Q) (Q)->parent 

bool isOneElmt(Node*);
	//return value 1 jika sebuah node tidak memiliki child node sama sekali; 0 jika sebaliknya 
bool isnotinptree(int, int);
	//return value 1 jika sebuah point yang MAU dialokasi sbg node BELUM pernah dialokasi sebagai 
	//node sebelumnya (nilai stat = 0)
Node* SearchNode(Node*, Point&);
	//mencari address node yang punya nilai Point sama dengan ptree ke idx_ptree
Node* Tree(int, int*, int*);
	//menghasilkan PathTree dengan child dan parent node sudah dialokasikan 
void MakeTree(int, int, int, Point&);
	//men-generate semua child node untuk sebuah node (yang nanti akan menjadi parent node) 

#endif
