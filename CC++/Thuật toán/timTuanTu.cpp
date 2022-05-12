#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int timTuanTu(int a[], int n, int x){
	for(int i=0; i<n; i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}
int main(){
	int n, x;
	scanf("%d%d", &n ,&x);
	int a[n];
	nhapM(a, n);
	printf("%d", timTuanTu(a, n, x));
	return 0;
}
