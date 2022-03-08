#include <cstdlib>;
#include <fstream>;
#include <iostream>;
#include <Windows.h>

using namespace std;

double total_coffee_volume(int&, int&, int&, fstream&, string);
double total_money_got_by_selling(int&, int&, int&, fstream&, string);
void count_each_size_sold(int&, int&, int&, fstream&, string);
void choose_num_cups(short&, bool&);
void choose_size(short&, bool&);
void display_menu();
void inform_wrong_choice();
void sell_coffe(int&, int&, int&);

int main() {
	string file_path = "";
	istream fileIn(;
	ofstream fileOut;
	fileIn.read;
	short choice;

	do {
		display_menu();
		if (choice == 1) {
			sell_coffe(file, file_path);
		}
	} while (choice == 0);
	
	return 0;
}

void sell_coffe(fstream &output, string file_path) {
	short size_choice;
	short num_cups;
	bool isQuit;

	while (true) {
		choose_size(size_choice, isQuit);
		if (!isQuit) {
			choose_num_cups(num_cups, isQuit);
		}
		if (!isQuit) {

		}
	}
	
	if (size_choice != 0) {

		
	}
	output.close();
}

void count_each_size_sold(int& num_S_cups, int& num_M_cups, int& num_L_cups, fstream& input, string file_path) {
	input.open(file_path);
	num_S_cups = num_M_cups = num_L_cups = 0;
	short size;
	short num_cups;
	while (!input.eof()) {
		input >> size;
		input >> num_cups;
		if (size == 1) {
			num_S_cups += num_cups;
		}
		else if (size == 2) {
			num_M_cups += num_cups;
		}
		else if (size == 3) {
			num_L_cups += num_cups;
		}
	}
	input.close();
}

void choose_num_cups(short& num_cups, bool& isQuit) {
	isQuit = false;

	do {
		cout << "Choose an appropriate number:" << endl;
		cout << "\t1-100: The number of cups you want\n\t0. Quit" << endl;
		cout << "Your choice: ";
		cin >> num_cups;
		if (num_cups == 0) {
			isQuit == true;
			break;
		}
		else if (num_cups < 0 || num_cups > 99) {
			inform_wrong_choice;
		}
		else {
			break;
		}
	} while (true);
	Sleep(5);
	system("cls");
}

void choose_size(short& size_choice, bool& isQuit) {
	isQuit = false;

	do {
		cout << "Choose an appropriate number:" << endl;
		cout << "\t1. Small size\n\t2. Medium size\n\t3. Large size\n\t0. Quit" << endl;
		cout << "Your choice: ";
		cin >> size_choice;
		if (size_choice == 0) {
			isQuit = true;
			break;
		}
		else if (size_choice < 0 || size_choice > 3) {
			inform_wrong_choice();
		}
		else {
			break;
		}
	} while (true);
	Sleep(5);
	system("cls");
}

double total_coffee_volume(int& num_S_cups, int& num_M_cups, int& num_L_cups, fstream& input, string file_path) {
	float const S_CUP_PRICE = 1.75f;
	float const M_CUP_PRICE = 1.90f;
	float const L_CUP_PRICE = 2.00f;
	double total_S_cups_money, total_M_cups_money, total_L_cups_money;
	count_each_size_sold(num_S_cups, num_M_cups, num_L_cups, input, file_path);

	total_S_cups_money = num_S_cups * S_CUP_PRICE;
	total_M_cups_money = num_M_cups * M_CUP_PRICE;
	total_L_cups_money= num_L_cups * L_CUP_PRICE;

	return total_S_cups_money + total_M_cups_money + total_L_cups_money;
}

double total_money_got_by_selling(int& num_S_cups, int& num_M_cups, int& num_L_cups, fstream& input, string file_path) {
	short const S_CUP_VOLUME = 9;
	short const M_CUP_VOLUME = 12;
	short const L_CUP_VOLUME = 15;
	double total_S_cups_volume, total_M_cups_volume, total_L_cups_volume;
	count_each_size_sold(num_S_cups, num_M_cups, num_L_cups, input, file_path);

	total_S_cups_volume = num_S_cups * S_CUP_VOLUME;
	total_M_cups_volume = num_M_cups * M_CUP_VOLUME;
	total_L_cups_volume = num_L_cups * L_CUP_VOLUME;

	return total_S_cups_volume + total_M_cups_volume + total_L_cups_volume;
}

void display_menu() {
	cout << "Choose an appropriate number:" << endl;
	cout << "\t1. Sell coffee" << endl;
	cout << "\t2. Display the number of cups of each size" << endl;
	cout << "\t3. Display total coffe volume that sold" << endl;
	cout << "\t4. Display total money got by selling coffee" << endl;
	cout << "\t0. Quit" << endl;
	cout << "Your choice: ";
}

void inform_wrong_choice() {
	cout << "Inappropriate! Please choose again!" << endl;
	Sleep(5);
	system("cls");
}
