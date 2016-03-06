#include "makhluk.h"
#include "singa.h"
#include "karnivora.h"
#include "zebra.h"
#include <iostream>
#include "board.h"

void test() {
	cout << "test guarded_thread" << endl;
}

using namespace std;

int main() {
	list<makhluk*> LOM; //list berisi pointer makhluk
	board b;
	makhluk* temp;
	int makhluk;
	while (true) {
		if (GetAsyncKeyState(VK_UP))
		{
			makhluk = rand() % 2;
			if (makhluk == 0) {
				//jika nol buat singa
				cout << "alokasi singa" << endl;
				temp = new singa;
			}
			else {
				//jika satu buat zebra
				cout << "alokasi zebra" << endl;
				temp = new zebra;
			}
			LOM.emplace_back(temp);
			b.tambah(*temp);
		}
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(200);
			while (true) {
				if (GetAsyncKeyState(VK_SPACE))
					break;
			}
		}
		Sleep(100);
	}
	for (auto& x : LOM) {
		(*x).printstatmakhluk();
	}
	b.printboard();
	b.tofile();
	return 0;
}