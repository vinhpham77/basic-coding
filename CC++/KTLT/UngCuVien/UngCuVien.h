#pragma once
#include <string>

using namespace std;

int timSoPBNhieuNhat(int phieuBau[], int soUCV);
long tinhTongPhieuBau(int phieuBau[], int soUCV);
void inDanhSachUCV(string hoTen[], int phieuBau[], double tiLe[], int soUCV);
void inUCVCoPBNhieuNhat(string hoTen[], int phieuBau[], double tiLe[], int soUCV);
void inUngCuVien(string hoTen, int phieuBau, double tiLe);
void nhap(string hoTen[], int phieuBau[], int soUCV);
void tinhTiLePhieuBau(int phieuBau[], double tiLe[], int soUCV);