#include "zebra.h"
#include "singa.h"
#include "board2.h"
//#include "list.h"
#include <mutex>
#ifdef WIN32
#include <io.h>
#elif WIN64
#include <io.h>
#elif UNIX
#include <unistd.h>
#endif
#include <fstream>

mutex mu;

void test() {
	std::cout << "test guarded_thread" << std::endl;
}


int main() {
	
	int dunia_on = 1;
	// menciptakan board 
	board();
	// melihat isi board 
	printboard();
	// print posisi pintu masuk tiap benteng
	std::cout << "pintu benteng utara (x, y): " << pintu_u.getX() << ", " << pintu_u.getY() << std::endl;
	std::cout << "pintu benteng selatan (x, y): " << pintu_s.getX() << ", " << pintu_s.getY() << std::endl;
	for (int i = 0; i < sizepintu_p; i++) {
		std::cout << "pintu benteng khusus ke-" << i << " (x, y): " << pintu_p[i].getX() << ", " << pintu_p[i].getY() << std::endl;	
	}
	
	// ruangan herbivora
	std::cout << "spawn herbivora" << std::endl;
	std::cout << "min_h_ver: " << min_h_vertical.getX() << ", " << min_h_vertical.getY() << std::endl;
	std::cout << "max_h_ver: " << max_h_vertical.getX() << ", " << max_h_vertical.getY() << std::endl;
	std::cout << "min_h_hor: " << min_h_horizontal.getX() << ", " << min_h_horizontal.getY() << std::endl;
	std::cout << "max_h_hor: " << max_h_horizontal.getX() << ", " << max_h_horizontal.getY() << std::endl;
	
	// ruangan karnivora
	std::cout << "spawn karnivora" << std::endl;
	std::cout << "min_k_ver: " << min_k_vertical.getX() << ", " << min_k_vertical.getY() << std::endl;
	std::cout << "max_k_ver: " << max_k_vertical.getX() << ", " << max_k_vertical.getY() << std::endl;
	std::cout << "min_k_hor: " << min_k_horizontal.getX() << ", " << min_k_horizontal.getY() << std::endl;
	std::cout << "max_k_hor: " << max_k_horizontal.getX() << ", " << max_k_horizontal.getY() << std::endl;
	
	
	// menciptakan list of makhluk (LOM)
	//list LOM("lom");
	
	// menghidupkan objek makhluk
	// misalkan ada 2 objek makhluk hidup 
	string jenisherbivora = "zebra", jeniskarnivora = "singa";
	int bnykobj = 2;
	makhluk* mptr[2];
	for (int i = 0; i < bnykobj; i++) {
		if (jenisherbivora == "zebra") {
			mptr[i] = new zebra(0, isi, min_h_vertical, max_h_vertical, min_h_horizontal, max_h_horizontal);
		} else {
			mptr[i] = new singa(1, isi, min_k_vertical, max_k_vertical, min_k_horizontal, max_k_horizontal);
		}		
	}
	
	// print posisi awal makhluk (random)
	std::cout << "h: "<<mptr[0]->getlok().getX() << " " << mptr[0]->getlok().getY() << std::endl;
	std::cout << "k: "<<mptr[1]->getlok().getX() << " " << mptr[1]->getlok().getY() << std::endl;
	
	// memasukannya ke dalam LOM
	//LOM.addNode(mzebra1);		// zebra 
	//LOM.addNode(msinga1);		// singa 
	// print list 
	//LOM.printList(LOM.head);
	
	// ! kehidupan dimulai !
	
	mptr[0]->makepath();
	
	//belum selesai
	while (dunia_on == 1) {
		
		// make path ke pintu_s utk herbivora 
		for (int i = 0; i < bnykobj; i++) {
			//mptr[0]->makepath(target);
		}
		
		
		
		
		dunia_on = 0;
	}
	
	//printboard();
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