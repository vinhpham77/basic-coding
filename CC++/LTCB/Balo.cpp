#include <iostream>
using namespace std;
void nhapM(int a[], int n){
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
}
void inM(int a[], int n){
	for(int i=1; i<=n; i++){
		cout << a[i] << " ";
	}
}
void copyM(int a[], int b[], int n){
	for(int i=1; i<=n; i++){
		a[i]=b[i];
	}
}
int Balo(int Weight[], int Cost[], int n, int balo){
	int Vtruoc[balo+1], Vsau[balo+1];
	for(int i=0; i<=balo; i++){
		Vtruoc[i]=0;	
	}
	int vat=1;
	while(vat<=n){
		for(int i=1; i<=balo; i++){		
			int max=0, k=i/Weight[vat];
			for(int j=0; j<=k; j++){
				int temp=Cost[vat]*j + Vtruoc[i-Weight[vat]*j];
				if(max<temp){
					max=temp;
				}
			}
			Vsau[i]=max;
		}
		if(vat<=n-1){
			copyM(Vtruoc, Vsau, balo);
		}
		/*inM(Vtruoc, balo);
		cout << endl;*/
		vat++;
	}
	return Vsau[balo];
}
int main(){
	int n, balo;
	cin >> n >> balo;
	int Weight[n+1], Cost[n+1];
	nhapM(Weight, n);
	nhapM(Cost, n);
	cout << Balo(Weight, Cost, n, balo);
	return 0;
}
