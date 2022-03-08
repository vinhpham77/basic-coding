#include "UngCuVien.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	int soUCV = 0;
	string hoTen[100];
	int phieuBau[100];
	double tiLe[100];
	
	cout << "Nhap so luong ung cu vien: ";
	cin >> soUCV;	
	nhap(hoTen, phieuBau, soUCV);
	tinhTiLePhieuBau(phieuBau, tiLe, soUCV);
	cout << "\n*THONG TIN CAC UNG CU VIEN*";
	inDanhSachUCV(hoTen, phieuBau, tiLe, soUCV);
	cout << "\n*THONG TIN UNG CU VIEN CO SO PHIEU BAU NHIEU NHAT*";
	inUCVCoPBNhieuNhat(hoTen, phieuBau, tiLe, soUCV);
	system("pause");
	return 0;
}