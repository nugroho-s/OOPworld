#include "karnivora.h"

karnivora::karnivora() {
}

karnivora::karnivora(Point& p1, Point& p2, Point& p3, Point& p4) : makhluk(isi, 'k', p1, p2, p3, p4) {
	mlapar = 10;
}

karnivora::~karnivora() {
	std::cout << "destructor karnivora" << std::endl;
}

makhluk* karnivora::getmengejar() {
	return mengejar;
}

void karnivora::lihat(Point& _target) {
	int IndexX = getlok().getX();
	int IndexY = getlok().getY();
	int _getarah = getarah();
	Point temp;
	if (_getarah == 0) {
		// mendeteksi sepanjang garis timur 
		while (IndexX < sizex) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX++;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 1) {
		// mendeteksi sepanjang garis tenggara 
		while (IndexX < sizex && IndexY < sizey) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX++; IndexY++;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 2) {
		// mendeteksi sepanjang garis selatan
		while (IndexY < sizey) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexY++;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 3) {
		// mendeteksi sepanjang garis barat daya 
		while (IndexX >= 0 && IndexY < sizey) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX--; IndexY++;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 4) {
		// mendeteksi sepanjang garis barat 
		while (IndexX >= 0) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX--;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 5) {
		// mendeteksi sepanjang garis barat laut 
		while (IndexX >= 0 && IndexY >= 0) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX--; IndexY--;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	} else if (_getarah == 6) {
		// mendeteksi sepanjang utara tenggara 
		while (IndexY >= 0) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexY--;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
	
	} else if (_getarah == 7) {
		// mendeteksi sepanjang garis timur laut  
		while (IndexX < sizex && IndexY >= 0) {
			point_in_while(temp, IndexX, IndexY, _getarah());
			if (temp.getX() == -2 && temp.getY() == -2) {
				//normal return, lanjutkan while loop 
				IndexX++; IndexY--;
			} else {
				//antara mendeteksi atau tidak 
				break;
			}
		}
		_target.set(temp.getX(), temp.getY());
		
	}
	
}

void karnivora::bergerak() {
	makhluk::bergerak();
	mlapar--;
}

void karnivora::printstatmakhluk() {
	makhluk::printstatmakhluk();
	printf("tingkat kelaparan = %d\n", mlapar);
}

int karnivora::getlapar() { 
	return mlapar; 
}

void point_in_while(Point& _target, int _IndexX, int _IndexY, int _arah) {
	if (isi[_IndexY][_IndexX] != '!') {
		if (isi[_IndexY][_IndexX] == 'Z') {
			//detected return  
			_target.set(_IndexX, _IndexY);
		} else {
			if (_arah == 0 && _IndexX == sizex-1) {	//non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 1 && (_IndexX == sizex-1 || _IndexY == sizey-1)) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 2 && _IndexY == sizey-1) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 3 && (_IndexX == 0 || _IndexY == sizey-1)) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 4 && _IndexX == 0) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 5 && (_IndexX == 0 || _IndexY == 0)) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 6 && _IndexY == 0) { //non-detected return 
				_target.set(-1, -1);
			} else if (_arah == 7 && (_IndexX == sizex-1 || _IndexY == 0)) { //non-detected return 
				_target.set(-1, -1);
			} else { //normal return
				_target.set(-2, -2);
			}
		}
	} else {
		//non-detected return 
		_target.set(-1, -1);
	}
}