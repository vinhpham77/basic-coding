#include <iostream>

using namespace std;

void nhap(double& gia_tu_van, double& tong_tgian_tu_van, double& thu_nhap);
void xuat(double gia_tu_van, double tong_tgian_tu_van, double thu_nhap);
double tinh_Tien(double gia_tu_van, double tong_tgian_tu_van, double thu_nhap);

int main() {
	double gia_tu_van, tong_tgian_tu_van, thu_nhap;
	nhap(gia_tu_van, tong_tgian_tu_van, thu_nhap);
	xuat(gia_tu_van, tong_tgian_tu_van, thu_nhap);
	return 0;
}

void nhap(double& gia_tu_van, double& tong_tgian_tu_van, double& thu_nhap) {
	cout << "Nhap gia tu van theo gio: ";
	cin >> gia_tu_van;
	cout << "Nhap tong thoi gian tu van: ";
	cin >> tong_tgian_tu_van;
	cout << "Nhap so tien thu nhap: ";
	cin >> thu_nhap;
}

void xuat(double gia_tu_van, double tong_tgian_tu_van, double thu_nhap) {
	cout << tinh_Tien(gia_tu_van, tong_tgian_tu_van, thu_nhap) << endl;
}
double tinh_Tien(double gia_tu_van, double tong_tgian_tu_van, double thu_nhap) {
	double thanh_toan = 0;
	if (thu_nhap <= 25000 && tong_tgian_tu_van > 30) {
		thanh_toan = gia_tu_van * 0.4 * (tong_tgian_tu_van - 30) / 60;
	}
	else if (thu_nhap > 25000 && tong_tgian_tu_van > 30) {
		thanh_toan = gia_tu_van * 0.7 * (tong_tgian_tu_van - 20) / 60;
	}
	return 0;
}