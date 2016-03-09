#include "list.h"

list::list() {
	// inisialisasi list kosong - LOP
	nama_list = "lop";
	headp = NULL;
	tailp = NULL;
}

list::list(string _nama_list) {
	// inisialisasi list kosong - LOM
	nama_list = _nama_list;
	head = NULL;
	tail = NULL;
}

list::~list() {
	// mendealokasi semua elemen list 
	cout << "destructor list" << endl;
	if (nama_list == "lom") {
		node *current, *temp;
		current = head;
		temp = head;
		while(current != NULL) {
			current = current->next;
			delete temp;
			temp = current;
		}
	} else {
		path *current, *temp;
		current = headp;
		temp = headp;
		while(current != NULL) {
			current = current->nextp;
			delete temp;
			temp = current;
		}
	}
}

list& list::operator=(list& l) {
	if (this == &l) {
		return *this;
	} else {
		nama_list = l.nama_list;
		if (nama_list == "lom") {
			head = NULL;
			tail = NULL;
			node* current;
			current = l.head;
			while (current != NULL) {
				addNode(current->mptr);
				current = current->next;
			}
		} else {
			headp = NULL;
			tailp = NULL;
			path* current;
			current = l.headp;
			while (current != NULL) {
				addPath(current->P);
				current = current->nextp;
			}
		}
		return *this;
	}
}

int list::isEmpty() {
	if (nama_list == "lom") {
		if (head == NULL && tail == NULL) { 
			return 1; 
		} else {
			return 0;
		}
	} else {
		if (headp == NULL && tailp == NULL) { 
			return 1; 
		} else {
			return 0;
		}
	}
}
	
int list::isOneElmt() {
	if (nama_list == "lom") {
		if (head != NULL && head->next == NULL) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if (headp != NULL && headp->nextp == NULL) {
			return 1;
		} else {
			return 0;
		}
	}
}

/*
struct list::node* list::searchMakhluk(struct list::node* ptr, char name) {
    while(name != ptr->mptr) {    
       ptr = ptr->next;                          
       if(ptr == NULL) {                          
          break;          
	   }		  
    }
    return ptr; 	
}
*/

void list::addNode(makhluk* m) {
	// inisialisasi node baru utk ditambahkan
	struct node* ptr = new node;
	if (ptr == NULL) { // alokasi gagal
		cout << "alokasi node gagal" << endl;
	} else { // alokasi berhasil 
		ptr->mptr = m;
	}
	
	// menambahkan ke dalam list sbg elemen terakhir
	if (head == NULL) { // jika list kosong, firstElmt = addedElmt
		head = ptr;
		tail = ptr;
	} else { // list berisi
		tail->next = ptr;
		ptr->next = NULL;
		tail = ptr;
	}
}

void list::addPath(Point& p) {
	// inisialisasi path baru utk ditambahkan
	struct path* ptr = new path;
	int px, py;
	if (ptr == NULL) { // alokasi gagal
		cout << "alokasi path gagal" << endl;
	} else { // alokasi berhasil 
		px = p.getX();
		py = p.getY();
		ptr->P.set(px, py);
	}
	
	// menambahkan ke dalam list sbg elemen terakhir
	if (headp == NULL) { // jika list kosong, firstElmt = addedElmt
		headp = ptr;
		tailp = ptr;
	} else { // list berisi
		tailp->nextp = ptr;
		ptr->nextp = NULL;
		tailp = ptr;
	}
}

void list::deleteNode(struct list::node* ptr) {
	node* temp = ptr;
	node* prev = head;
	if (isEmpty()) {
		cout << "list kosong tidak bisa dihapus" << endl;
	} else {
		if (temp == prev) {
			head = head->next;
			if (tail == temp) {
				tail = tail->next;
			}
			delete temp;
		} else {
			while (prev->next != ptr) {
				prev = prev->next;
			}
			prev->next = temp->next;
			if (tail == temp) {
				tail = prev;
			}
			delete temp;
		}
	}
}

void list::deletePath(struct list::path* ptr) {
	path* temp = ptr;
	path* prev = headp;
	if (isEmpty()) {
		cout << "list kosong tidak bisa dihapus" << endl;
	} else {
		if (temp == prev) {
			headp = headp->nextp;
			if (tailp == temp) {
				tailp = tailp->nextp;
			}
			delete temp;
		} else {
			while (prev->nextp != ptr) {
				prev = prev->nextp;
			}
			prev->nextp = temp->nextp;
			if (tailp == temp) {
				tailp = prev;
			}
			delete temp;
		}
	}
}

void list::printList(struct list::node* ptr) {
	cout << "isi list node" << endl;
	if (isEmpty()) {
		cout << "menampilkan list kosong" << endl;
	} else {
		while (ptr != NULL) {
			cout << ptr->mptr->getpower() << endl;
			ptr = ptr->next;
		}
	}
}

void list::printListPath(struct list::path* ptr) {
	cout << "isi list path" << endl;
	if (isEmpty()) {
		cout << "menampilkan list kosong" << endl;
	} else {
		while (ptr != NULL) {
			cout << ptr->P.getX() << ", " << ptr->P.getY() << endl;
			ptr = ptr->nextp;
		}
	}
}