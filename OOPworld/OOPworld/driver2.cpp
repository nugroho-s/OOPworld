#include "zebra.h"
#include "singa.h"
#include "board2.h"
#include "list.h"
#include <mutex>
#include <unistd.h>
#include <fstream>

#include <Windows.h>

mutex mu;

void test() {
	std::cout << "test guarded_thread" << std::endl;
}

void print_ruanganHerbivora() {
	// ruangan herbivora
	std::cout << "spawn herbivora" << std::endl;
	std::cout << "min_h_ver: " << min_h_vertical.getX() << ", " << min_h_vertical.getY() << std::endl;
	std::cout << "max_h_ver: " << max_h_vertical.getX() << ", " << max_h_vertical.getY() << std::endl;
	std::cout << "min_h_hor: " << min_h_horizontal.getX() << ", " << min_h_horizontal.getY() << std::endl;
	std::cout << "max_h_hor: " << max_h_horizontal.getX() << ", " << max_h_horizontal.getY() << std::endl;
}

void print_ruanganKarnivora() {
	// ruangan karnivora
	std::cout << "spawn karnivora" << std::endl;
	std::cout << "min_k_ver: " << min_k_vertical.getX() << ", " << min_k_vertical.getY() << std::endl;
	std::cout << "max_k_ver: " << max_k_vertical.getX() << ", " << max_k_vertical.getY() << std::endl;
	std::cout << "min_k_hor: " << min_k_horizontal.getX() << ", " << min_k_horizontal.getY() << std::endl;
	std::cout << "max_k_hor: " << max_k_horizontal.getX() << ", " << max_k_horizontal.getY() << std::endl;
	
}

void print_pintuBenteng() {
	std::cout << "pintu benteng utara (x, y): " << pintu_u.getX() << ", " << pintu_u.getY() << std::endl;
	std::cout << "pintu benteng selatan (x, y): " << pintu_s.getX() << ", " << pintu_s.getY() << std::endl;
}

int main() {
	
	//KAMUS
	
	//int id_randMakhluk;			// nilai random 0-1 untuk menentukan jenis makhluk apa yang ditambahkan 
	//makhluk* mptr;				// pointer ke objek turunan makhluk hidup 
	
	
	
	//ALGORITMA
	
	/** Board **/
	// menciptakan board 
	board();
	// melihat isi board 
	std::cout << "Dunia sabana berhasil terbentuk" << std::endl;
	std::cout << "Silahkan tambahkan makhluk ke dalamnya" << std::endl;
	printboard();
	
	
	
	
	
	
	// menghidupkan objek makhluk
	// misalkan ada 2 objek makhluk hidup 
	string jenisherbivora = "zebra", jeniskarnivora = "singa";
	int bnykobj = 2;
	makhluk* mptr[bnykobj];
	
	mptr[0] = new zebra(min_h_vertical, max_h_vertical, min_h_horizontal, max_h_horizontal);
	tambah(*mptr[0], 'Z');
	mptr[1] = new singa(min_k_vertical, max_k_vertical, min_k_horizontal, max_k_horizontal);
	tambah(*mptr[1], 'S');
	
	// print posisi awal makhluk (random)
	std::cout << "h: "<<mptr[0]->getlok().getX() << " " << mptr[0]->getlok().getY() << std::endl;
	std::cout << "k: "<<mptr[1]->getlok().getX() << " " << mptr[1]->getlok().getY() << std::endl;
	// print board setelah inisiasi posisi awal objek 
	printboard();
	std::cout << "press any key" << std::endl;
	getchar();
	
	// memasukannya ke dalam LOM
	//LOM.addNode(mzebra1);		// zebra 
	//LOM.addNode(msinga1);		// singa 
	// print list 
	//LOM.printList(LOM.head);
	
	/** Kehidupan sabana **/
	
	int dunia_on = 1;
	Point temp;
	while (dunia_on == 1) {
		
		// membuat path ke pintu_s utk herbivora (karnivora belum punya target saat kehidupan dimulai)
		for (int i = 0; i < bnykobj; i++) {
			temp = mptr[i]->gettarget();
			if (temp.getX() != -1 && temp.getY() != -1) {
				// jika objek sudah punya target 
				mptr[i]->makepath(temp);
			} 
		}
		
		// menggerakkan objek satu-satu  
		
		
		dunia_on = 0;
	}
	
	/** Clean up **/
	// dealokasi array untuk board 
	deallocate_board();
	// dealokasi array yg ada di zebra 
	for (int i = 0; i < sizey; i++) {
        delete[] stat[i];
    }
    delete[] stat;
	
	return 0;

}

/*
herbivora:
setelah diletakkan secara random di board (spawn h), herbivora membentuk path ke pintu_s (target = koord. pintu_s)
saat di benteng utara, nilai 'langkah' herbivora = 1 (berpindah ke koord. berikutnya sebanyak 1 satuan)

karnivora:
saat di spawn k, nilai 'langkah' karnivora = 1 dan bergerak secara random 
saat di spawn k, karnivora menscan wilayah di sekitarnya, apakah ada herbivora atau tidak 
jika ada, maka membentuk path dengan target posisi herbivora itu di board, dan mulai mengejar


*/

/*
TAMBAHAN SETELAH printboard() paling atas 
// print posisi pintu masuk tiap benteng
	//print_pintuBenteng();
	//print_ruanganHerbivora();
	//print_ruanganKarnivora();
	
	/** Makhluk **/
	// menciptakan list of makhluk (LOM) kosong 
	//list LOM("lom");
	// menambahkan makhluk ke board dengan keystroke
	/*
	while (true) {
		if (GetAsyncKeyState(VK_UP)) {
			// tekan tombol UP untuk menambahkan makhluk 
			id_randMakhluk = rand() % 2;
			if (id_randMakhluk == 0) {
				//jika nol buat singa dan tambahkan ke dalam board (ditampilkan sebagai karakter 's')
				cout << "alokasi singa" << endl;
				mptr = new singa(1, isi, min_k_vertical, max_k_vertical, min_k_horizontal, max_k_horizontal);
				tambah(*mptr, 's');
			}
			else if (id_randMakhluk == 1) {
				//jika satu buat zebra dan tambahkan ke dalam board (ditampilkan sebagai karakter 'z')
				cout << "alokasi zebra" << endl;
				mptr = new zebra(0, isi, min_h_vertical, max_h_vertical, min_h_horizontal, max_h_horizontal);
				tambah(*mptr, 'z');
			}
			// menambahkan pointer ke dalam LOM 
			LOM.addNode(mptr);	
			
			std::cout << "objek ditambah di posisi: " << mptr->getlok().getX() << ", " << mptr->getlok().getY() << std::endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			// tekan tombol ESC untuk berhenti menambahkan 
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(200);
			while (true) {
				if (GetAsyncKeyState(VK_SPACE))
					break;
			}
		}
		Sleep(100);
	}
*/