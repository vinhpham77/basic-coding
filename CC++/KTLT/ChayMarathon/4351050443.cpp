#include <iostream>
#include <fstream>
#include <string>

using namespace std;

constexpr auto SO_VDV = 5;
constexpr auto SO_NGAY_GHI = 7;

bool doc_du_lieu(ifstream&, string, string[], int quang_duong[][SO_NGAY_GHI]);
long tinh_tong_quang_duong(int, int[][SO_NGAY_GHI]);
double tinh_quang_duong_trung_binh(int, int[][SO_NGAY_GHI]);
int tim_quang_duong_dai_nhat(int, int[][SO_NGAY_GHI]);
int tim_quang_duong_ngan_nhat(int, int[][SO_NGAY_GHI]);
void hien_thi_quang_duong(int, int[][SO_NGAY_GHI]);
void hien_thi_menu();
void chon_so_thu_tu(int&);

int main()
{
	int quang_duong[SO_VDV][SO_NGAY_GHI];
	string ten[SO_VDV];
	ifstream input;
	string file = "input.dat";
	int choice = 0;
	int SO_TINH_NANG = 6; 
	int so_thu_tu;

	cout << "1. Doc du lieu" << endl;
	cout << "2. Hien thi thong tin nhung quang duong da chay" << endl;
	cout << "3. Hien thi tong quang duong da chay" << endl;
	cout << "4. Hien thi quang duong trung binh da chay" << endl;
	cout << "5. Hien thi quang duong dai nhat da chay" << endl;
	cout << "6. Hien thi quang duong ngan nhat da chay" << endl;
	cout << "0. Thoat" << endl;
	hien_thi_menu();
	
	while (true)
	{
		switch (choice)
		{
		case 1:
		{
			if (doc_du_lieu(input, file, ten, quang_duong))
			{
				cout << "Doc du lieu thanh cong!" << endl;
			}
			else
			{
				cout << "Doc du lieu that bai!" << endl;
			}
			break;
		}
		case 2:
		{
			chon_so_thu_tu(so_thu_tu);
			hien_thi_quang_duong(choice - 1, quang_duong);
			break;
		}
		case 3:
		{
			chon_so_thu_tu(so_thu_tu);
			cout << "";
			break;
		}
		}
	}
	return 0;
}

bool doc_du_lieu(ifstream& input, string file, string ten[], int quang_duong[][SO_NGAY_GHI])
{
	input.open(file);
	
	if (!input)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < SO_VDV; i++)
		{
			input >> ten[i];
			for (int j = 0; j < SO_NGAY_GHI; j++)
			{
				input >> quang_duong[i][j];
			}
		}
		return true;
	}
}

long tinh_tong_quang_duong(int so_thu_tu, int quang_duong[][SO_NGAY_GHI])
{
	long tong = 0;

	for (int i = 0; i < SO_NGAY_GHI; i++)
	{
		tong += quang_duong[so_thu_tu][i];
	}

	return tong;
}

double tinh_quang_duong_trung_binh(int so_thu_tu, int quang_duong[][SO_NGAY_GHI])
{
	double tong = tinh_tong_quang_duong(so_thu_tu, quang_duong);
	
	return tong / SO_NGAY_GHI;
}

int tim_quang_duong_dai_nhat(int so_thu_tu, int quang_duong[][SO_NGAY_GHI])
{
	int max = quang_duong[so_thu_tu][0];

	for (int i = 1; i < SO_NGAY_GHI; i++)
	{
		if (max < quang_duong[so_thu_tu][i]);
		{
			max = quang_duong[so_thu_tu][i];
		}
	}

	return max;
}

int tim_quang_duong_ngan_nhat(int so_thu_tu, int quang_duong[][SO_NGAY_GHI])
{
	int min = quang_duong[so_thu_tu][0];

	for (int i = 1;	i < SO_NGAY_GHI; i++)
	{
		if (min > quang_duong[so_thu_tu][i])
		{
			min = quang_duong[so_thu_tu][i];
		}
	}

	return min;
}

void hien_thi_quang_duong(int so_thu_tu, int quang_duong[][SO_NGAY_GHI])
{
	cout << "Quang duong da chay: " << endl;
	for (int i = 0; i < SO_NGAY_GHI; i++)
	{
		cout << "\tNgay " << i + 1 << ": " << quang_duong[so_thu_tu][i] << " Km" << endl;
	}
}

void hien_thi_menu()
{
	cout << "1. Doc du lieu" << endl;
	cout << "2. Hien thi thong tin nhung quang duong da chay" << endl;
	cout << "3. Hien thi tong quang duong da chay" << endl;
	cout << "4. Hien thi quang duong trung binh da chay" << endl;
	cout << "5. Hien thi quang duong dai nhat da chay" << endl;
	cout << "6. Hien thi quang duong ngan nhat da chay" << endl;
	cout << "0. Thoat" << endl;
}

void chon_so_thu_tu(int& so_thu_tu)
{
	cout << "So thu tu: ";
	cin >> so_thu_tu;
}
