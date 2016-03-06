#include "board.h"
#include <cstdio>

board::board() {
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			isi[i][j] = ' ';
		}
	}
}

void board::printboard() {
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

void board::tambah(makhluk& m) {
	Point P = m.getlok();
	isi[P.getY()][P.getX()] = m.getid();
}

void board::move(makhluk& m) {
	Point P = m.getlok();
	isi[P.getY()][P.getX()] = ' ';
	m.bergerak();
	P = m.getlok();
	isi[P.getY()][P.getX()] = m.getid();
}

void board::hapus(makhluk& m) {
	Point P = m.getlok();
	isi[P.getX()][P.getY()] = ' ';
}

void board::tofile() {
	ofstream ofs("save.csv", ofstream::binary);
	char* buffer;
	int sizeall = (sizey*sizex*2) + (sizey*2);
	buffer = new char[sizeall];
	int b, k;
	b = k = 0;
	int i = 0;
	while (i < sizeall) {
		if (k >= sizex) {
			buffer[i] = 0x0d;
			i++;
			buffer[i] = 0x0a;
			k = 0; b++;
		}
		else {
			buffer[i] = isi[b][k];
			k++;
			i++;
			buffer[i] = 0x2c;
		}
		i++;
	}
	try {
		ofs.write(buffer, sizeall);
	}
	catch (int e) {
		cout << "exception occured: "<<e << endl;
	}
	ofs.close();
}