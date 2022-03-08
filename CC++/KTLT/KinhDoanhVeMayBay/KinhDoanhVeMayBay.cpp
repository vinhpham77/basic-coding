#include <fcntl.h>
#include <io.h>
#include <iostream>
#include "KinhDoanhVeMayBay.h"
#include "ThongSo.h"
#include <Windows.h>
#include <fstream>

using namespace std;

void chonChoNgoi(wchar_t luaChonVe, wchar_t& luaChonHang, wchar_t& luaChonGhe, bool& kiemTraThoat) {

	while (true) {
		wcout << L"Tại: " << endl;
		switch (luaChonVe) {
			case '1':
				wcout << L"\t1 - " << HANG_HANG_NHAT_CUOI << L": Hàng tương ứng" << endl;
				wcout << L"\t0. Thoát" << endl;
				break;
			case '2':
				wcout << L""
		}
		chon(luaChonHang);
		if (laThoat(luaChonHang)) {
			kiemTraThoat = true;
			break;
		} else if ((short)luaChonHang > short) {

		}
		wcout << L"Vị trí chỗ ngồi: " << endl;
		wcout << L"\t";
		for (short i = 1; i <= SO_GHE; i++) {
			wcout << L"" << luaChonHang << (char)(65 + i) << "   ";
		}
		wcout << endl;
		if (laThoat(cot)) {
			break;
		}

		if (SO_HANG > 0 && SO_HANG < 14 && cot > 0 && cot < 7) {
			if (laChoNgoiTrong(choNgoi[hang - 1][cot - 1])) {
				cout << "Thao tac thanh cong" << endl;
				break;
			} else {
				cout << "Thao tac khong thanh cong. Cho ngoi da duoc dat truoc";
			}
		} else {
			cout << "Thao tac khong thanh cong. Nhap vi tri khong dung";
		}
		Sleep(500);
		system("cls");
	}
}

void thongBaoChonSai() {
	wcout << L"Lựa chọn không thích hợp." << endl;
	Sleep(500);
	wcout << L"Vui lòng chọn lại" << endl;
	Sleep(500);
	system("cls");
}

short thongKeLoaiVe(char choNgoi[][SO_GHE], short hang_ghe_dau, short hang_ghe_cuoi) {
	short tongVe = 0;

	for (short i = hang_ghe_dau; i < hang_ghe_cuoi; i++) {
		for (short j = 0; j < SO_GHE; i++) {
			if (!laChoNgoiTrong(choNgoi[i][j])) {
				tongVe++;
			}
		}
	}

	return tongVe;
}

void thongKeLoaiVe(char[][SO_GHE]) {

}

void chonLoaiVe(wchar_t& luaChon, bool& kiemTraThoat) {
	while (true) {
		wcout << L"Các loại vé:" << endl;
		wcout << L"\t1. Hạng nhất" << endl;
		wcout << L"\t2. Hạng thương gia" << endl;
		wcout << L"\t3. Hạng phổ thông" << endl;
		chon(luaChon);
		if (laThoat(luaChon)) {
			kiemTraThoat = true;
			break;
		} else if (luaChon != '1' && luaChon != '2' && luaChon != '3') {
			thongBaoChonSai();
		}
	}
}

void banVe(char choNgoi[][SO_GHE]) {
	wchar_t luaChonHang;
	wchar_t luaChonGhe;
	bool kiemTraThoat = false;

	chonLoaiVe(luaChonHang, kiemTraThoat);
	if (kiemTraThoat) {
		return;
	} else {
		chonChoNgoi()
	}
}

void hienThiMenu() {
	wcout << L"Danh sách các chức năng:" << endl;
	wcout << L"\t1. Bán vé" << endl;
	wcout << L"\t2. Hủy vé" << endl;
	wcout << L"\t3. Thống kê số lượng từng loại vé đã bán" << endl;
	wcout << L"\t4. Hiển thị sơ đồ chỗ ngồi" << endl;
	wcout << L"\t5. Sao lưu và phục hồi dữ liệu" << endl;
	wcout << L"\t6. Thoát" << endl;
}

void chon(wchar_t& luaChon) {
	wcout << L"Lựa chọn số tương ứng: ";
	wcin >> luaChon;
}

void khoiTaoChoNgoi(char choNgoi[][SO_GHE]) {
	for (short i = 0; i < SO_HANG; i++) {
		for (short j = 0; j < SO_GHE; j++) {
			choNgoi[i][j] = ' ';
		}
	}
}

bool laThoat(wchar_t& luaChon) {
	return luaChon == '0';
}

bool laChoNgoiTrong(char choNgoi) {
	return choNgoi == ' ';
}

void hienThiSoDo(char choNgoi[][SO_GHE]) {
	wcout << "   \tA\tB\tC\tD\tE\tF" << endl;
	for (short i = 0; i < 13; i++) {
		wcout << " " << i + 1;
		if (i < 9) {
			wcout << " ";
		}
		for (short j = 0; j < 6; j++) {
			wcout << "\t" << choNgoi[i][j];
		}
		wcout << endl;
	}
}

void huyVe(char[][SO_GHE]) {

}
