#include "zebra.h"

Point** prevs;

zebra::zebra(int ID, char** bid, Point& p1, Point& p2, Point& p3, Point& p4) : herbivora(ID, bid, p1, p2, p3, p4) {
	// constructor
	mlapar = maxlapar;
	power = 3;
	dt = 2;
	arah = 0;
	dikejar = 0;
	target.set(pintu_s.getX(), pintu_s.getY());
	// inisiasi list of path kosong
	LOP.headp = NULL;
	LOP.tailp = NULL;
}

zebra::zebra(zebra& z) {
	// copy constructor
	mlapar = z.mlapar;
	power = z.power;
	dt = z.dt;
	arah = z.arah;
	dikejar = z.dikejar;
	P.set(z.getlok().getX(), z.getlok().getY());
}

zebra& zebra::operator= (zebra& z) {
	// operator= 
	if (this == &z) { // jika melakukan assignment trhdp diri sendiri
		return *this;
	} else { // jika bukan 
		mlapar = z.mlapar;
		power = z.power;
		dt = z.dt;
		arah = z.arah;
		dikejar = z.dikejar;
		P.set(z.getlok().getX(), z.getlok().getY());
		return *this;
	}
}
	
zebra::~zebra() {
	// destruktor
	std::cout << "destructor zebra" << std::endl;
}

void zebra::makan() {
	// jika memakan objek lain, maka level kelaparannya menjadi sangat kenyang (30)
	mlapar = maxlapar;
}

void zebra::makepath() { 
	// membuat path ke pintu_s dan menyimpannya ke dalam list of path (LOP)
	
	// inisiasi status setiap sel board = 0 (belum pernah dialokasikan sebagai node pada tree)
	stat = new int*[sizey];
	for(int i = 0; i < sizey; ++i) {
		stat[i] = new int[sizex];
	}
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			stat[i][j] = 0;
		}
	}
	
	std::cout << "searching path for zebra at: " << P.getX() << ", " << P.getY() << std::endl;
	
	//alokasi ptree 
	ptree = new Point[sizex*sizey*8];
	//alokasi address proot ke NULL (pohon kosong)
	proot = NULL;
	//inisiasi isi ptree 
	for (int i = 0; i < sizex*sizey*8; i++) {
		ptree[i].set(-1, -1);
	}
	
	//memasukkan posisi awal sebuah zebra di board (yang nilainya random) ke dalam ptree sebagai elemen ke-0
	ptree[0].set(P.getX(), P.getY());
	//argumen ke-1 bernilai 1 berarti melakukan pemanggilaan prosedur MakeTree pertama kali 
	MakeTree(1, 0, 0);
	
	std::cout << "PATH ZEBRA KE TUJUAN" << std::endl;
	
	/*
	for (int i = 0; i < sizex*sizey*8; i++) {
		std::cout << ptree[i].getX() << ", " << ptree[i].getY() << std::endl;
		getchar();
	}
	*/
	
	Node* ptarget = SearchNode(proot, ptree[found_target]);
	Node* curr = ptarget;
	if (curr == NULL) {std::cout<<"null"<<std::endl;}
	while (curr != NULL) { //selama belum sampai di proot 
		std::cout << "point: " << Akar(curr).getX() << ", " << Akar(curr).getY() << std::endl;
		curr = Parent(curr);
	}
	
	//dealokasi ptree dan node teratas dari PathTree
	delete[] ptree;
	delete proot;
	delete curr;
	delete ptarget;
}
	
