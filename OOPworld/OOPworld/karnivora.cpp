#include "karnivora.h"

karnivora::karnivora() {
	mlapar = 10;
}

karnivora::~karnivora() {
	//do nothing
}

void karnivora::lihat() {
	dt += 1;
}

void karnivora::bergerak() {
	makhluk::bergerak();
	mlapar--;
}

void karnivora::printstatmakhluk() {
	makhluk::printstatmakhluk();
	printf("tingkat kelaparan = %d\n", mlapar);
}

int karnivora::getlapar() { return mlapar; }