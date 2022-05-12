#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int binarySearch(int a[], int l, int r, int x){
	if(r==l && a[r]!=x){
		return -1;
	}
	int m=(r+l)/2;
	if(a[m]==x){
		return m;
	}
	else{
		if(a[m]<x){
			binarySearch(a, m+1, r, x);
		}
		else{
			binarySearch(a, l, m-1, x);
		}
	}
}
int main(){
	int n, x;
	scanf("%d%d", &n ,&x);
	int a[n];
	nhapM(a, n);
	printf("%d", binarySearch(a, 0, n, x));
	return 0;
}
