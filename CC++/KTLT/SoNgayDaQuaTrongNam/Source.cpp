#include <iostream>
#include <string>

using namespace std;

bool la_nam_nhuan(int);
void nhap(string&);
void tach_ngay_thang_nam(int&, int&, int&, string);
void khoi_tao_mang(int[], int);
int tinh_so_ngay_da_qua(int, int, int[]);

int main()
{
	string thoi_gian;
	int ngay;
	int thang;
	int nam;
	int so_ngay_cua_thang[13];
	
	nhap(thoi_gian);
	tach_ngay_thang_nam(ngay, thang, nam, thoi_gian);
	khoi_tao_mang(so_ngay_cua_thang, nam);
	cout << "So ngay da qua: " << tinh_so_ngay_da_qua(ngay, thang, so_ngay_cua_thang) << endl;
	system("pause");
	return 0;
}


bool la_nam_nhuan(int nam)
{
	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

void nhap(string& thoi_gian)
{
	cout << "Nhap thoi gian: ";
	cin >> thoi_gian;
}

void tach_ngay_thang_nam(int& ngay, int& thang, int& nam, string thoi_gian)
{
	int vi_tri_tach_1;
	int vi_tri_tach_2;

	vi_tri_tach_1 = thoi_gian.find('-');
	vi_tri_tach_2 = thoi_gian.find('-', vi_tri_tach_1 + 1);
	
	string thangStr = thoi_gian.substr(0, vi_tri_tach_1);
	string ngayStr = thoi_gian.substr(vi_tri_tach_1 + 1, vi_tri_tach_2 - vi_tri_tach_1 - 1);
	string namStr = thoi_gian.substr(vi_tri_tach_2 + 1);

	ngay = stoi(ngayStr);
	thang = stoi(thangStr);
	nam = stoi(namStr);	
}

void khoi_tao_mang(int so_ngay_cua_thang[], int nam)
{
	so_ngay_cua_thang[1] = 31;
	so_ngay_cua_thang[2] = la_nam_nhuan(nam) ? 29 : 28;
	so_ngay_cua_thang[3] = 31;
	so_ngay_cua_thang[5] = 31;
	so_ngay_cua_thang[7] = 31;
	so_ngay_cua_thang[8] = 31;
	so_ngay_cua_thang[10] = 31;
	so_ngay_cua_thang[12] = 31;
	so_ngay_cua_thang[4] = 30;
	so_ngay_cua_thang[6] = 30;
	so_ngay_cua_thang[9] = 30;
	so_ngay_cua_thang[11] = 30;
}

int tinh_so_ngay_da_qua(int ngay, int thang, int so_ngay_cua_thang[])
{
	int so_ngay_da_qua = 0;
	
	for (size_t i = 1; i < thang; i++)
	{
		so_ngay_da_qua += so_ngay_cua_thang[i];
	}
	so_ngay_da_qua += ngay;

	return so_ngay_da_qua;
}
