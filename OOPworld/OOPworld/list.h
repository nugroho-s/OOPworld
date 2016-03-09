//
// file: list.h 
//---merepresentasikan kumpulan makhluk dalam list of makhluk (LOM)
//

#include "makhluk.h"

#ifndef list_h
#define list_h 

class list
{
public:
	// struktur sebuah node list 
	// LOM menyimpan pointer to address dari objek turunan makhluk 
	struct node {			
		//char nama_makhluk;
		makhluk* mptr;
		struct node *next;
	} *head, *tail;		// ---head menunjuk address node pertama
						// ---tail menunjuk address node terakhir 

	// struktur sebuah path list 
	// LOP menyimpan koordinat path objek 
	struct path {
		Point P;
		struct path *nextp;
	} *headp, *tailp;
	
	// constructor	
	list();
	list(string);
	// destructor
	~list();			
	
	// operator= 
	list& operator=(list& l);
	
	// return 1 jika list kosong, 0 jika sebaliknya
	int isEmpty();
	
	// return 1 jika list berisi 1 elemen, 0 jika sebaliknya 
	int isOneElmt();
	
	// mencari elemen list dengan nama tertentu
	//struct list::node* searchMakhluk(struct list::node*, char);	
	
	// menambahkan sebuah node ke list 
	void addNode(makhluk* m);
	void addPath(Point&);
	
	// menghapus sebuah node dari list 
	void deleteNode(struct list::node*);
	void deletePath(struct list::path*);
	
	// menampilkan seluruh isi list 
	void printList(struct list::node*);
	void printListPath(struct list::path*);
	
protected:
	string nama_list;		// misal: lom = list of makhluk, dll 
};

#endif 