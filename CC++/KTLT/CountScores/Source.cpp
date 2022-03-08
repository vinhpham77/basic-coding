#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int>&);
void sort_vector(vector<int>&);
void output(vector<int>);

int main() {
	vector<int> scores;
	input_vector(scores);
	output(scores);
	system("pause"); 
	return 0;
}

void input_vector(vector<int>& scores) {
	int input_value = 0;

	while (true) {
		cout << "Input a value in the range from 0 to 100: ";
		cin >> input_value;
		if (input_value > -1 && input_value < 101) {
			scores.push_back(input_value);
		} else if (input_value == -999) {
			break;
		} else {
			cout << "Inappropriate value!" << endl;
		}
	}
}

void sort_vector(vector<int>& scores) {
	const int n = static_cast<int>(scores.size());

	if (!scores.empty())
	{
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (scores[i] > scores[j]) {
					temp = scores[i];
					scores[i] = scores[j];
					scores[j] = temp;
				}
			}
		}
	}
}

void output(vector<int> scores) {
	const int n = static_cast<int>(scores.size());

	if (!scores.empty()) {
		int count = 1;
		sort_vector(scores);
		cout << "\nScore\t|   Number of the scores" << endl;
		cout << "--------|-----------------------" << endl;
		for (int i = 0; i < n - 1; i++) {
			if (scores[i] == scores[i + 1]) {
				count++;
			} else {
				cout << scores[i] << "\t|   " << count << endl;
				count = 1;
			}
		}
		cout << scores[n - 1] << "\t|   " << count << endl;
		cout << "--------|-----------------------\n" << endl;
	} else {
		cout << "The list is empty." << endl;
	}
}