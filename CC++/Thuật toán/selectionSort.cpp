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
void selectionSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		int mark=i;
		for(int j=i+1; j<n; j++){
			if(a[mark]>a[j]){
				mark=j;
			}
		}
		int tg=a[mark];
		a[mark]=a[i];
		a[i]=tg;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n); 
	selectionSort(a, n);
	inM(a, n);
	return 0;
}
