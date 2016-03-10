#include "pathtree.h"

int** status;
Point* ptree;
int found_target = -1;
Node* proot;

bool isOneElmt(Node* par) {
	if (Timur(par) == NULL && Tenggara(par) == NULL && Selatan(par) == NULL && BaratDaya(par) == NULL && Barat(par) == NULL && BaratLaut(par) == NULL && Utara(par) == NULL && TimurLaut(par) == NULL) {
		return true;
	} else {
		return false;
	}
}

bool isnotinptree(int _posx, int _posy) {
	if (status[_posy][_posx] == 0) { //belum pnya child 
		return true;
	} else {
		return false;
	}
}

Node* SearchNode(Node* par, Point& pp) {
	Node* cek_timur = NULL;
	Node* cek_tenggara = NULL;
	Node* cek_selatan = NULL;
	Node* cek_baratdaya = NULL;
	Node* cek_barat = NULL;
	Node* cek_baratlaut = NULL;
	Node* cek_utara = NULL;
	Node* cek_timurlaut = NULL;

	if (par == NULL) {

	}
	
	else if (isOneElmt(par)) {
		if (Akar(par).getX() == pp.getX() && Akar(par).getY() == pp.getY()) {
			//node berhasil ditemukan di address par 
			//std::cout << "Node found" << std::endl;
			return par;
		}
	} else {
		if (Timur(par) != NULL) {
			//std::cout << "search timur " << Akar(Timur(par)).getX() << ", " << Akar(Timur(par)).getY() << std::endl;
			cek_timur = SearchNode(Timur(par), pp);
			if (cek_timur != NULL) {
				return cek_timur;
			}
		} 
		if (Tenggara(par) != NULL && cek_timur == NULL) {
			//std::cout << "search tenggara" << std::endl;
			cek_tenggara = SearchNode(Tenggara(par), pp);
			if (cek_tenggara != NULL) {
				return cek_tenggara;
			}
		} 
		if (Selatan(par) != NULL && cek_timur == NULL && cek_tenggara == NULL) {
			//std::cout << "search selatan" << std::endl;
			cek_selatan = SearchNode(Selatan(par), pp);
			if (cek_selatan != NULL) {
				return cek_selatan;
			}
		} 
		if (BaratDaya(par) != NULL && cek_timur == NULL && cek_tenggara == NULL && cek_selatan == NULL) {
			//std::cout << "search baratdaya" << std::endl;	
			cek_baratdaya = SearchNode(BaratDaya(par), pp);
			if (cek_baratdaya != NULL) {
				return cek_baratdaya;
			}
		} 
		if (Barat(par) != NULL && cek_timur == NULL && cek_tenggara == NULL && cek_selatan == NULL && cek_baratdaya == NULL) {
			//std::cout << "search barat" << std::endl;	
			cek_barat = SearchNode(Barat(par), pp);
			if (cek_barat != NULL) {
				return cek_barat;
			}
		} 
		if (BaratLaut(par) != NULL && cek_timur == NULL && cek_tenggara == NULL && cek_selatan == NULL && cek_baratdaya == NULL && cek_barat == NULL) {
			//std::cout << "search baratlaut" << std::endl;	
			cek_baratlaut = SearchNode(BaratLaut(par), pp);
			if (cek_baratlaut != NULL) {
				return cek_baratlaut;
			}
		} 
		if (Utara(par) != NULL && cek_timur == NULL && cek_tenggara == NULL && cek_selatan == NULL && cek_baratdaya == NULL && cek_barat == NULL && cek_baratlaut == NULL) { 
			//std::cout << "search utara" << std::endl;	
			cek_utara = SearchNode(Utara(par), pp);
			if (cek_utara != NULL) {
				return cek_utara;
			}
		} 
		if (TimurLaut(par) != NULL && cek_timur == NULL && cek_tenggara == NULL && cek_selatan == NULL && cek_baratdaya == NULL && cek_barat == NULL && cek_baratlaut == NULL && cek_utara == NULL) {
			//std::cout << "search timurlaut" << std::endl;	
			cek_timurlaut = SearchNode(TimurLaut(par), pp);
			if (cek_timurlaut != NULL) {
				return cek_timurlaut;
			}
		}
	}
}

Node* Tree(int idx_ptree, int* passhead, int* passtail) {
	int pos_x, pos_y;
	Node* pparent;
	Node* ptimur;
	Node* ptenggara;
	Node* pselatan;
	Node* pbaratdaya;
	Node* pbarat;
	Node* pbaratlaut;
	Node* putara;
	Node* ptimurlaut;

	//mendapatkan posisi elemen terakhir di ptree 
	int ii;
	for (ii = 0; ii < sizex*sizey*8; ii++) {
		if (ptree[ii].getX() == -1 && ptree[ii].getY() == -1) {
			break; 
		}
	}
		*passhead = ii;
		int temp_passhead = ii;
		
		pos_x = ptree[idx_ptree].getX();
		pos_y = ptree[idx_ptree].getY();
		
		//timur
		if (pos_x+1 < sizex) {
			if (isi[pos_y][pos_x+1] != '!' && isi[pos_y][pos_x+1] != 'q' && isnotinptree(pos_x+1, pos_y) == true) {
				ptimur = new Node;
				Akar(ptimur).set(pos_x+1, pos_y);
				Timur(ptimur) = Tenggara(ptimur) = Selatan(ptimur) = BaratDaya(ptimur) = NULL;
				Barat(ptimur) = BaratLaut(ptimur) = Utara(ptimur) = TimurLaut(ptimur) = NULL;
			
				ptree[temp_passhead].set(pos_x+1, pos_y);
				temp_passhead++;
			
				//std::cout << "timur is OK" << std::endl;
				//std::cout << Akar(ptimur).getX() << ", " << Akar(ptimur).getY() << std::endl;
			} else { ptimur = NULL; }
		} else { ptimur = NULL; }
		//tenggara
		if (pos_x+1 < sizex && pos_y+1 < sizey) {
			if (isi[pos_y+1][pos_x+1] != '!' && isi[pos_y+1][pos_x+1] != 'q' && isnotinptree(pos_x+1, pos_y+1) == true) {
				ptenggara = new Node;
				Akar(ptenggara).set(pos_x+1, pos_y+1);
				Timur(ptenggara) = Tenggara(ptenggara) = Selatan(ptenggara) = BaratDaya(ptenggara) = NULL;
				Barat(ptenggara) = BaratLaut(ptenggara) = Utara(ptenggara) = TimurLaut(ptenggara) = NULL;
			
				ptree[temp_passhead].set(pos_x+1, pos_y+1);
				temp_passhead++;
			
				//std::cout << "tenggara is OK" << std::endl;
				//std::cout << Akar(ptenggara).getX() << ", " << Akar(ptenggara).getY() << std::endl;
			} else { ptenggara = NULL; }
		} else { ptenggara = NULL; }
		//selatan
		if (pos_y+1 < sizey) {
			if (isi[pos_y+1][pos_x] != '!' && isi[pos_y+1][pos_x] != 'q' && isnotinptree(pos_x, pos_y+1) == true) {
				pselatan = new Node;
				Akar(pselatan).set(pos_x, pos_y+1);
				Timur(pselatan) = Tenggara(pselatan) = Selatan(pselatan) = BaratDaya(pselatan) = NULL;
				Barat(pselatan) = BaratLaut(pselatan) = Utara(pselatan) = TimurLaut(pselatan) = NULL;
			
				ptree[temp_passhead].set(pos_x, pos_y+1);
				temp_passhead++;
			
				//std::cout << "selatan is OK" << std::endl;
				//std::cout << Akar(pselatan).getX() << ", " << Akar(pselatan).getY() << std::endl;
			} else { pselatan = NULL; }
		} else { pselatan = NULL; }
		//barat daya
		if (pos_y+1 < sizey && pos_x-1 >= 0) {
			if (isi[pos_y+1][pos_x-1] != '!' && isi[pos_y+1][pos_x-1] != 'q' && isnotinptree(pos_x-1, pos_y+1) == true) {
				pbaratdaya = new Node;
				Akar(pbaratdaya).set(pos_x-1, pos_y+1);
				Timur(pbaratdaya) = Tenggara(pbaratdaya) = Selatan(pbaratdaya) = BaratDaya(pbaratdaya) = NULL;
				Barat(pbaratdaya) = BaratLaut(pbaratdaya) = Utara(pbaratdaya) = TimurLaut(pbaratdaya) = NULL;
			
				ptree[temp_passhead].set(pos_x-1, pos_y+1);
				temp_passhead++;
			
				//std::cout << "baratdaya is OK" << std::endl;
				//std::cout << Akar(pbaratdaya).getX() << ", " << Akar(pbaratdaya).getY() << std::endl;
			} else { pbaratdaya = NULL; }
		} else { pbaratdaya = NULL; }
		//barat
		if (pos_x-1 >= 0) {
			if (isi[pos_y][pos_x-1] != '!' && isi[pos_y][pos_x-1] != 'q' && isnotinptree(pos_x-1, pos_y) == true) {
				pbarat = new Node;
				Akar(pbarat).set(pos_x-1, pos_y);
				Timur(pbarat) = Tenggara(pbarat) = Selatan(pbarat) = BaratDaya(pbarat) = NULL;
				Barat(pbarat) = BaratLaut(pbarat) = Utara(pbarat) = TimurLaut(pbarat) = NULL;
		
				ptree[temp_passhead].set(pos_x-1, pos_y);
				temp_passhead++;
			
				//std::cout << "barat is OK" << std::endl;
				//std::cout << Akar(pbarat).getX() << ", " << Akar(pbarat).getY() << std::endl;
			} else { pbarat = NULL; }
		} else { pbarat = NULL; }
		//barat laut
		if (pos_y-1 >= 0 && pos_x-1 >= 0) {
			if (isi[pos_y-1][pos_x-1] != '!' && isi[pos_y-1][pos_x-1] != 'q' && isnotinptree(pos_x-1, pos_y-1) == true) {
				pbaratlaut = new Node;
				Akar(pbaratlaut).set(pos_x-1, pos_y-1);
				Timur(pbaratlaut) = Tenggara(pbaratlaut) = Selatan(pbaratlaut) = BaratDaya(pbaratlaut) = NULL;
				Barat(pbaratlaut) = BaratLaut(pbaratlaut) = Utara(pbaratlaut) = TimurLaut(pbaratlaut) = NULL;
			
				ptree[temp_passhead].set(pos_x-1, pos_y-1);
				temp_passhead++;
			
				//std::cout << "baratlaut is OK" << std::endl;
				//std::cout << Akar(pbaratlaut).getX() << ", " << Akar(pbaratlaut).getY() << std::endl;
			} else { pbaratlaut = NULL; }
		} else { pbaratlaut = NULL; }
		//utara
		if (pos_y-1 >= 0) {
			if (isi[pos_y-1][pos_x] != '!' && isi[pos_y-1][pos_x] != 'q' && isnotinptree(pos_x, pos_y-1) == true) {
				putara = new Node;
				Akar(putara).set(pos_x, pos_y-1);
				Timur(putara) = Tenggara(putara) = Selatan(putara) = BaratDaya(putara) = NULL;
				Barat(putara) = BaratLaut(putara) = Utara(putara) = TimurLaut(putara) = NULL;
			
				ptree[temp_passhead].set(pos_x, pos_y-1);
				temp_passhead++;
			
				//std::cout << "utara is OK" << std::endl;
				//std::cout << Akar(putara).getX() << ", " << Akar(putara).getY() << std::endl;
			} else { putara = NULL; } 
		} else { putara = NULL; }
		//timur laut 
		if (pos_y-1 >= 0 && pos_x+1 < sizex) {
			if (isi[pos_y-1][pos_x+1] != '!' && isi[pos_y-1][pos_x+1] != 'q' && isnotinptree(pos_x+1, pos_y-1) == true) {
				ptimurlaut = new Node;
				Akar(ptimurlaut).set(pos_x+1, pos_y-1);
				Timur(ptimurlaut) = Tenggara(ptimurlaut) = Selatan(ptimurlaut) = BaratDaya(ptimurlaut) = NULL;
				Barat(ptimurlaut) = BaratLaut(ptimurlaut) = Utara(ptimurlaut) = TimurLaut(ptimurlaut) = NULL;
			
				ptree[temp_passhead].set(pos_x+1, pos_y-1);
				temp_passhead++;
			
				//std::cout << "timur laut is OK" << std::endl;
				//std::cout << Akar(ptimurlaut).getX() << ", " << Akar(ptimurlaut).getY() << std::endl;
			
			} else { ptimurlaut = NULL; }
		} else { ptimurlaut = NULL; }
		
		// membentuk node parent dari kumpulan child node di atas 
		if (proot == NULL) { // tree masih kosong 
			pparent = new Node;
		} else {
			// search node yang punya nilai Point sama dengan ptree ke idx_ptree
			pparent = SearchNode(proot, ptree[idx_ptree]);
		}
		
		Akar(pparent).set(pos_x, pos_y);
		status[pos_y][pos_x] = 1;		// sudah pnya child 
		
		//menghubungkan parent node dengan child node untuk membentuk sebuah PathTree 
		Timur(pparent) = ptimur;
		if (ptimur != NULL) {
			Parent(ptimur) = pparent;
			std::cout << "timur pparent: " << Akar(ptimur).getX() << ", " << Akar(ptimur).getY() << std::endl;
		} 
		
		Tenggara(pparent) = ptenggara;
		if (ptenggara != NULL) {
			Parent(ptenggara) = pparent;
			std::cout << "tenggara pparent: " << Akar(ptenggara).getX() << ", " << Akar(ptenggara).getY() << std::endl;
		}
		
		Selatan(pparent) = pselatan;
		if (pselatan != NULL) {
			Parent(pselatan) = pparent;
			std::cout << "selatan pparent: " << Akar(pselatan).getX() << ", " << Akar(pselatan).getY() << std::endl;
		}
		
		BaratDaya(pparent) = pbaratdaya;
		if (pbaratdaya != NULL) {
			Parent(pbaratdaya) = pparent;
			std::cout << "bd pparent: " << Akar(pbaratdaya).getX() << ", " << Akar(pbaratdaya).getY() << std::endl;
		}
		
		Barat(pparent) = pbarat;
		if (pbarat != NULL) {
			Parent(pbarat) = pparent;
			std::cout << "barat pparent: " << Akar(pbarat).getX() << ", " << Akar(pbarat).getY() << std::endl;
		}
		
		BaratLaut(pparent) = pbaratlaut;
		if (pbaratlaut != NULL) {
			Parent(pbaratlaut) = pparent;
			std::cout << "bl pparent: " << Akar(pbaratlaut).getX() << ", " << Akar(pbaratlaut).getY() << std::endl;
		}
		
		Utara(pparent) = putara;
		if (putara != NULL) {
			Parent(putara) = pparent;
			std::cout << "utara pparent: " << Akar(putara).getX() << ", " << Akar(putara).getY() << std::endl;
		}
		
		TimurLaut(pparent) = ptimurlaut;
		if (ptimurlaut != NULL) {
			Parent(ptimurlaut) = pparent;
			std::cout << "tl pparent: " << Akar(ptimurlaut).getX() << ", " << Akar(ptimurlaut).getY() << std::endl;
		}
	
		//pembentukan sebuah PathTree berhasil 
		std::cout << "TREE IS OK" << std::endl;
	
	//mengembalikan nilai tail yang baru (disimpan di passtail)
	if (*passhead > temp_passhead-1) { //jika tidak ada child node yang terbentuk 
		*passtail = *passhead;
	} else {
		*passtail = temp_passhead-1;
	}
	
	return pparent;
}

void MakeTree(int idx_call, int _head, int _tail) {
	/*
		contoh simulasi pengisian sebuah ptree:
		awalnya ptree diisi dengan posisi awal objek di board (x0,y0);
		head dan tail akan menjadi sebuah pointer terhadap indeks awal dan akhir semua elemen yang dimasukkan ke dalam ptree 
		| (x0,y0) |
			 |  				 
			 v                   
		head = tail                
		
		-selanjutnya dengan memanggil fungsi Tree yang menerima parameter berupa indeks elemen di ptree dan akan mengembalikan pointer 
		head dan tail yang baru, maka Point (x0,y0) akan memiliki child node (terbentuklah sebuah PathTree)
		-misalkan terbentuk 2 child node, sebut saja (x1,y1) dan (x2,y2), maka isi ptree sekarang:
		| (x0,y0) | (x1,y1) | (x2,y2) |
					   |          |
					   v          v 
				      head       tail 
		-dimana fungsi Tree mengembalikan head = 1 dan tail = 2
		
		-selanjutnya secara rekursif akan dibentuk child node secara iteratif dari head sampai tail, dimana dalam kasus ini 
		(x1,y1) dan (x2,y2) masing-masing akan menjadi parent node 
		
		-jika di dalam ptree sudah terdapat target tujuan si objek, maka proses pembuatan PathTree dihentikan
	*/
	
	Node* PP;
	int head, tail, passhead, passtail, counter;
	
	std::cout << "MakeTree " << idx_call << " " << _head << " " << _tail << std::endl;
	
	head = _head;
	tail = _tail;
	counter = head;
	
	/*
	for (int i = 0; i < sizex*sizey*8; i++) {
		if (ptree[i].getX() != -1 && ptree[i].getY() != -1) {
			std::cout << "ptree[" << i << "]: " << ptree[i].getX() << ", " << ptree[i].getY() << " " << stat[ptree[i].getY()][ptree[i].getX()] << std::endl;
		}
	}
	*/
	
	//BAGAIMANA JIKA head=tail dan isi dari ptree[head] = -1? (tidak ada child yg terbentuk)
	
	//cek apakah di ptree sudah terdapat node target 
	for (int i = counter; i <= tail; i++) {
		if (ptree[i].getX() == pintu_s.getX() && ptree[i].getY() == pintu_s.getY()) {
			found_target = i;
			std::cout << "found target at " << ptree[i].getX() << ", " << ptree[i].getY() << std::endl;
			getchar();
			break;
		}
	}
	
	//mendapatkan address dari node parent (sebuah koordinat di board)
	if (found_target == -1) {
		while ((counter < tail) || (counter == tail && idx_call == 1)) {
			PP = Tree(counter, &passhead, &passtail); 
			//jika baru pertama kali memanggil MakeTree, maka inisiasi address node paling atas (proot)
			//menjadi PP 
			if (idx_call == 1) {
				proot = PP;
				Parent(proot) = NULL;
			}
			
			//sampai sini ptree menyimpan banyak child node dari node PP 
			MakeTree(0, passhead, passtail);
			if (found_target == -1) {
				counter++;
			} else {
				break;
			}
		}
	}
	
}

/*
	ptree = [(1,1)] -> posisi awal objek -> nbElmt = 1
	MakeTree(1, 1)
		PP = addr_root (global)
		proot = PP
		ptree = [(2,1), (1,2)] -> nbElmt = 2
		MakeTree(2, 0)
	
	ptree = [(1,1)] - head=0 tail=0 - bentuk child (misal 2 child)
	push 2 node ke ptree 
	ptree = [(1,1), (2,1), (1,2)] - head=1 tail=2
	jika rekursif selesai, pop dari head sampai tail yg sesuai 
	
						(0,0)
		(1,0)					(1,1)	(0,1)		--- t tg s 
(2,0) (2,1) (1,1) (0,1) (0,0)
*/
