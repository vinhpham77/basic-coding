#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void nhap(string hoTen[], int phieuBau[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline(cin, hoTen[i]);
		cout << "Nhap so phieu bau: ";
		cin >> phieuBau[i];
	}
}

long tinhTongPhieuBau(int phieuBau[], int soUCV)
{
	long tongPhieuBau = 0;
	for (int i = 0; i < soUCV; i++) {
		tongPhieuBau += phieuBau[i];
	}
	return tongPhieuBau;
}

void tinhTiLePhieuBau(int phieuBau[], double tiLe[], int soUCV) {
	long tongPhieuBau = tinhTongPhieuBau(phieuBau, soUCV);

	for (int i = 0; i < soUCV; i++) {
		tiLe[i] = (double) phieuBau[i] / tongPhieuBau;
	}
}

void inUngCuVien(string hoTen, int phieuBau, double tiLe) {
	cout << "Ho ten: " << hoTen << endl;
	cout << "So phieu bau: " << phieuBau << endl;
	cout << "Ti le phieu bau: " << setprecision(2) << fixed << tiLe * 100 << "%" << endl;
}

int timSoPBNhieuNhat(int phieuBau[], int soUCV) {
	int max = INT_MIN;

	for (int i = 0; i < soUCV; i++) {
		if (max <= phieuBau[i]) {
			max = phieuBau[i];
		}
	}

	return max;
}

void inDanhSachUCV(string hoTen[], int phieuBau[], double tiLe[], int soUCV) {
	for (int i = 0; i < soUCV; i++) {
		cout << endl;
		inUngCuVien(hoTen[i], phieuBau[i], tiLe[i]);
	}
}

void inUCVCoPBNhieuNhat(string hoTen[], int phieuBau[], double tiLe[], int soUCV) {
	int soPBNhieuNhat= timSoPBNhieuNhat(phieuBau, soUCV);

	for (int i = 0; i < soUCV; i++) {
		if (phieuBau[i] == soPBNhieuNhat) {
			cout << endl;
			inUngCuVien(hoTen[i], phieuBau[i], tiLe[i]);
		}
	}
}