#include <iostream>
#include <math.h>
using namespace std;
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}
void inM(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
int tongTienReNhat(int D[], int A[], int B[], int n, int R){
	int sxChenhLechGia[n], A_rehon_B[n];
	for(int i=0; i<n; i++){
		A_rehon_B[i]=-1;
	}
	//inM(A_rehon_B, n);
	for(int i=0; i<n; i++){
		int mark, max=-1;
		for(int j=0; j<n; j++){
			int chenhLech=abs(A[j]-B[j]);
			if(A_rehon_B[j]==-1 && chenhLech>max){
				max=chenhLech;
				mark=j;
			}
		}
		sxChenhLechGia[i]=mark;
		if(A[mark]<B[mark]){
			A_rehon_B[mark]=1;
		}
		else{
			A_rehon_B[mark]=0;
		}
	}
	//inM(sxChenhLechGia, n);
	//inM(A_rehon_B, n);
	int S=0;
	for(int i=0; i<n; i++){
		if(A_rehon_B[i]==0){
			S+=D[i]*B[i];
		}
		else{
			if(D[i]<=R){
				S+=D[i]*A[i];
				R-=A[i];
			}
			else{
				S=S+(R*A[i]+(D[i]-R)*B[i]);
			}
		}
	}
	return S;
}
int main(){
	int n, R;
	cin >> n >> R;
	int D[n], A[n], B[n];
	nhapM(D, n);
	nhapM(A, n);
	nhapM(B, n);
	cout << tongTienReNhat(D, A, B, n, R);
	return 0;
}
