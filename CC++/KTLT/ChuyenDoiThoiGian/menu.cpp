#include <iostream>
#include <string>

using namespace std;

void hien_thi_menu()
{
	cout << "/t/t/t/tMENU" << endl;
	cout << "1. Nhap thoi gian" << endl;
	cout << "2. Chuyen doi kieu thoi gian" << endl;
	cout << "3. Hien thi thoi gian" << endl;
}

void nhap_thoi_gian(string& thoi_gian, bool la_kieu_24h, int& lua_chon)
{
	int gio;
	int phut;

	cout << "Nhap thoi gian: " << endl;
	cout << "/t1. Kieu 12h" << endl;
	cout << "/t2. Kieu 24h" << endl;
	cout << "/t0. Quay lai" << endl;
	chon(lua_chon);
	system("cls");

	switch (lua_chon)
	{
	case 0: break;
	case 1: 
		nhap_thoi_gian(true);
	default:
		break;
	}
}

void chon(int& lua_chon)
{
	cout << "Chon: " << endl;
	cin >> lua_chon;
}
