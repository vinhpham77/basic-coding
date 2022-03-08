#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input("GS.INP");
	ofstream output("GS.OUT");
	string a;
	string b;
	string temp;
	int length;
	bool bang_nhau = true;

	input >> a >> b;
	temp = a;
	a = a + b;
	b = b + temp;
	length = a.size();

	for (int i = 0; i < length; i++)
	{
		if (a[i] > b[i])
		{
			output << a << endl << b;
			bang_nhau = false;
			break;
		}
		else if (a[i] < b[i])
		{
			output << b << endl << a;
			bang_nhau = false;
			break;
		}
	}

	if (bang_nhau)
	{
		output << a << endl << b;
	}
	input.close();
	output.close();
	return 0;
}