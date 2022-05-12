#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int binarySearch(int a[], int l, int r, int x){
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			return m;
		}
		else{
			if(a[m]<x){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
	}
	return -1;	
}
int main(){
	int n, x;
	scanf("%d%d", &n ,&x);
	int a[n];
	nhapM(a, n);
	printf("%d", binarySearch(a, 0, n, x));
	return 0;
}
