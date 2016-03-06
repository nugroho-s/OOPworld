#include "list.h"

list::list() {
	// inisialisasi list kosong 
	head = NULL;
	tail = NULL;
}

list::~list() {
	// mendealokasi semua elemen list 
	node *current, *temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

int list::isEmpty() {
	if (head == NULL && tail == NULL) { 
		return 1; 
	} else {
		return 0;
	}
}
	
int list::isOneElmt() {
	if (head != NULL && head->next == NULL) {
		return 1;
	} else {
		return 0;
	}
}

struct list::node* list::searchMakhluk(struct list::node* ptr, string name) {
    while(name != ptr->nama_makhluk) {    
       ptr = ptr->next;                          
       if(ptr == NULL) {                          
          break;          
	   }		  
    }
    return ptr; 	
}

void list::addNode(string s, int i) {
	// inisialisasi node baru utk ditambahkan
	struct node* ptr = new node;
	
	if (ptr == NULL) { // alokasi gagal
		cout << "alokasi gagal" << endl;
	} else { // alokasi berhasil 
		ptr->nama_makhluk = s;
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

void list::printList(struct list::node* ptr) {
	if (isEmpty()) {
		cout << "menampilkan list kosong" << endl;
	} else {
		while (ptr != NULL) {
			cout << ptr->nama_makhluk << endl;
			ptr = ptr->next;
		}
	}
}