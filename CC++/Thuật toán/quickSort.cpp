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
void quickSort(int a[], int l, int r){
	if(l<r){
		int x=a[l], m=l, n=r;
		while(m<n){
			while(a[n]>x){
				n--;
			}
			if(n>m){
				a[m]=a[n];
				m++;
			}
			while(a[m]<x && n>m){
				m++;
			}
			if(n>m){
				a[n]=a[m];
				n--;	
			}
		}
		a[m]=x;
		quickSort(a, l, m-1);
		quickSort(a, m+1, r);	
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	quickSort(a, 0, n-1);
	inM(a, n);
	return 0;
}
