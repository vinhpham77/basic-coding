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
void shellSort(int a[], int n){
	for(int m=5; m>0; m-=2){
		for(int i=m; i<n; i++){
			int x=a[i], j;
			for(j=i-m; j>=0 && x<a[j]; j=j-m){
				a[j+m]=a[j];
			}
			a[j+m]=x;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	shellSort(a, n);
	inM(a, n);
	return 0;
}
