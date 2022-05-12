#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void inM(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
void bubbleSort(int a[], int n){
	int l=0, r=n-1, k;
	while(l<r){
		for(int g=r; g>l; g--){
			if(a[g]<a[g-1]){
				int tg=a[g];
				a[g]=a[g-1];
				a[g-1]=tg;
				k=g;
			}
		}
		for(int h=l=k; h<r; h++){
			if(a[h]>a[h+1]){
				int tg=a[h];
				a[h]=a[h+1];
				a[h+1]=tg;
				k=h;
			}
		}
		r=k;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	bubbleSort(a, n);
	inM(a, n);
	return 0;
}
