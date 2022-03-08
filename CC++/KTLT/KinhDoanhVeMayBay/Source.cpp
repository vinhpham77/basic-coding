#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "KinhDoanhVeMayBay.h"
#include "ThongSo.h"
#include <fstream>

using namespace std;

int main() {
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	//ofstream out;
	char choNgoi[SO_HANG][SO_GHE];
	wchar_t luaChon;
	bool daLuu = false;
	khoiTaoChoNgoi(choNgoi);
	while (true) {
		hienThiMenu();
		chon(luaChon);
		switch (luaChon) {
			case '1': 
				banVe(choNgoi); 
				break;
			case '2':
				huyVe(choNgoi); 
				break;
			/*case '3':
				thongKeLoaiVe();
				*/
		}
	}
	system("pause");
	return 0;
}