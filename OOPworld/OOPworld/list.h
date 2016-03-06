//
// file: list.h 
//---merepresentasikan kumpulan makhluk dalam list of makhluk (LOM)
//

#include "stdafx.h"

#ifndef list_h
#define list_h 

class list
{
public:
	//! struktur sebuah node list 
	struct node {			
		string nama_makhluk;
		struct node *next;
	} *head, *tail;		//! ---head menunjuk address node pertama
						//! ---tail menunjuk address node terakhir 

	//! constructor	
	list();
	//! destructor
	~list();			

	// return 1 jika list kosong, 0 jika sebaliknya
	int isEmpty();
	
	// return 1 jika list berisi 1 elemen, 0 jika sebaliknya 
	int isOneElmt();
	
	// mencari elemen list dengan nama tertentu
	struct list::node* searchMakhluk(struct list::node*, string);	
	
	// menambahkan sebuah node ke list 
	void addNode(string s, int i);
	
	// menghapus sebuah node dari list 
	void deleteNode(struct list::node*);
	
	// menampilkan seluruh isi list 
	void printList(struct list::node*);
};

#endif 