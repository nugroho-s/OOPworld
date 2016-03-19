#include "board2.h"

int sizex;
int sizey;
Point min_h_vertical, min_k_vertical;
Point max_h_vertical, max_k_vertical;
Point min_h_horizontal, min_k_horizontal;
Point max_h_horizontal, max_k_horizontal;
char** isi;
Point pintu_u;	// pintu benteng utara 
Point pintu_s;	// pintu benteng selatan 

void board() {
	
	// struktur input board dari file
	//---sizex sizey 
	//---!!!!!!!!!!
	//---!hhhhhhhh!
	//---!!!!!x!!!!
	//---kkkkkkkkkk
	//---k!!!kk!!!k
	//---k!tqkkqt!k
	//---k!!!kk!!!k 
	//---kkkkkkkkkk 
	//---!!!!!y!!!!
	//---!!!!!!!!!!
	//
	// h = wilayah herbivora (kura2[a], kelinci[k], zebra[z])
	// k = wilayah karnivora (singa[s], elang[e], ular[u])
	// ! = dinding benteng
	// x = pintu masuk/keluar benteng utara
	// y = pintu masuk/keluar benteng selatan
	// t = saved area
	// q = pintu masuk/keluar benteng perlindungan
	
	ifstream myfile;
	myfile.open("board.txt");
	char c;
	int counter = 0;
	
	string line;
	string token;
	if (myfile.is_open()) {
		getline(myfile, line);
		stringstream lineStream(line);
		
		while (lineStream >> token) {
			if (counter == 0) {
				sizex = stoi(token);
			} else if(counter == 1) {
				sizey = stoi(token);
			}
			counter++;
		}
		std::cout << "ukuran board (x-y): " << sizex << " " << sizey << std::endl;
		// alokasi array of char 
		isi = new char*[sizey];
		for(int i = 0; i < sizey; ++i) {
			isi[i] = new char[sizex];
		}
		
		// mengisi array dengan input board 
		// sekaligus inisiasi posisi pintu masuk/keluar benteng 
		int c_pjg = 0;	
		while (getline(myfile, line)) {
			stringstream lineStream(line);
			while (lineStream >> token) {
				for (int i = 0; i < token.length(); i++) {
					isi[c_pjg][i] = token[i];
					if (token[i] == 'x') { // lokasi pintu_u 
						pintu_u.set(i, c_pjg);
					} else if (token[i] == 'y') { // lokasi pintu_s 
						pintu_s.set(i, c_pjg);
					} 
				}
				c_pjg++;
			}
		}
		
		// inisiasi nilai min_h dan max_h utk herbivora 
		int px, py;
		min_h_ver('h', &px, &py);
		min_h_vertical.set(px, py);
		max_h_ver('h', &px, &py);
		max_h_vertical.set(px, py);
		min_h_hor('h', &px, &py);
		min_h_horizontal.set(px, py);
		max_h_hor('h', &px, &py);
		max_h_horizontal.set(px, py);
		
		// inisiasi nilai min_h dan max_h utk karnivora 
		min_h_ver('k', &px, &py);
		min_k_vertical.set(px, py);
		max_h_ver('k', &px, &py);
		max_k_vertical.set(px, py);
		min_h_hor('k', &px, &py);
		min_k_horizontal.set(px, py);
		max_h_hor('k', &px, &py);
		max_k_horizontal.set(px, py);
		
		// tutup file 
		myfile.close();
	} else {
		std::cout << "gagal membuka file board.txt" << std::endl;
	}
	
}

void min_h_ver(char jns_obj, int* x, int* y) {
	int i, j, found = 0;
	for (i = 0; i < sizex; i++) {
		for (j = 0; j < sizey; j++) {
			if (isi[j][i] == jns_obj) {
				found = 1;
				break;
			}
		}
		if (found == 1) {
			break;
		}
	}
	*x = j;
	*y = i;
}

void max_h_ver(char jns_obj, int* x, int* y) {
	int i, j, found = 0;
	for (i = sizex-1; i >= 0; i--) {
		for (j = 0; j < sizey; j++) {
			if (isi[j][i] == jns_obj) {
				found = 1;
				break;
			}
		}
		if (found == 1) {
			break;
		}
	}
	*x = j;
	*y = i;
}

void min_h_hor(char jns_obj, int* x, int* y) {
	int i, j, found = 0;
	for (i = 0; i < sizey; i++) {
		for (j = 0; j < sizex; j++) {
			if (isi[i][j] == jns_obj) {
				found = 1;
				break;
			}
		}
		if (found == 1) {
			break;
		}
	}
	*x = i;
	*y = j;
}

void max_h_hor(char jns_obj, int* x, int* y) {
	int i, j, found = 0;
	for (i = sizey-1; i >= 0; i--) {
		for (j = 0; j < sizex; j++) {
			if (isi[i][j] == jns_obj) {
				found = 1;
				break;
			}
		}
		if (found == 1) {
			break;
		}
	}
	*x = i;
	*y = j;
}

void printboard() {
	printf(" ");
	for (int i = 0; i < sizex; i++)
		printf("%d", i % 10);
	printf("\n");
	for (int i = 0; i < sizey; i++) {
		printf("%d", i % 10);
		for (int j = 0; j < sizex; j++) {
			printf("%c", isi[i][j]);
		}
		printf("\n");
	}
}

void tambah(makhluk& m, char ch) {
	Point P = m.getlok();
	isi[P.getY()][P.getX()] = ch;
	m.printstatmakhluk();
}

void move(makhluk& m, char ch) {
	
	// list of makhluk (LOM) = {zebra1, singa1}
	// untuk karnivora:
	//--- jika di LOM ada herbivora, maka menjalankan prosedur mengejar
	//--- jika tidak ada, jalankan prosedur move biasa 
	
	Point P = m.getlok();
	isi[P.getY()][P.getX()] = '.';
	m.bergerak();
	P = m.getlok();
	isi[P.getY()][P.getX()] = ch;
}

void hapus(makhluk& m) {
	Point P = m.getlok();
	isi[P.getX()][P.getY()] = '.';
}

void deallocate_board() {
	// dealokasi array board 
	for (int i = 0; i < sizey; i++) {
        delete[] isi[i];
    }
    delete[] isi;
	isi = 0;
	std::cout << "dealokasi board" << std::endl;
}
