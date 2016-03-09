#include "kelinci.h"

kelinci::kelinci(){
	// constructor makhluk dijalankan terlebih dahulu 
	mlapar = maxlapar;
	power = 3;
	dt = 2;
	umur = 30;
	id = 'k';
}
	
kelinci::~kelinci(){}
	
void kelinci::makan(){
	mlapar=maxlapar;
}
	
void kelinci::sembunyi(){}
	
void kelinci::bergerak(){}
