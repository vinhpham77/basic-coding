#include <bits/stdc++.h>

using namespace std;

string name[5];
int dist[5][7];

ifstream fin;

void ReadFile() {
    for (int i = 0; i < 5; i++) {
        fin >> name[i];
        for (int j = 0; j < 7; j++) {
            fin >> dist[i][j];
        }
    }
}

void Show() {
    for (int i = 0; i < 5; i++) {
        cout << name[i] << " ";
        for (int j = 0; j < 7; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void CalcSum() {
    for (int i = 0; i < 5; i++) {
        cout << name[i] << " ";
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += dist[i][j];
        }
        cout << sum << endl;
    }
}

void CalcAver() {
    for (int i = 0; i < 5; i++) {
        cout << name[i] << " ";
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += dist[i][j];
        }
        cout << (float)sum / 7 << endl;
    }
}

void FindMinMax() {
    for (int i = 0; i < 5; i++) {
        cout << name[i] << " ";
        int _min = dist[i][0], _max = dist[i][0];
        for (int j = 0; j < 7; j++) {
            _min = min(_min, dist[i][j]);
            _max = max(_max, dist[i][j]);
        }
        cout << "Min: " << _min << " Max: " << _max << endl;
    }
}

int main() {

    fin.open("input.dat");
    ReadFile();
    Show();
    CalcSum();
    CalcAver();
    FindMinMax();
    fin.close();
    return 0;
}