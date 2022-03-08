#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void twoSumEqualS(int a[], int l, int r, int S){
	if(l==r){
		printf("Khong co");
	}
	if(l<r){
		if(a[l]+a[r]==S){
			printf("%d %d", l, r);
		}
		if(a[l]+a[r]>S){
			twoSumEqualS(a, l, r-1, S);
		}
		if(a[l]+a[r]<S){
			twoSumEqualS(a, l+1, r, S);
		}
	}
}
int main(){
	int n, S;
	scanf("%d%d", &n, &S);
	int a[n];
	nhapM(a, n);
	twoSumEqualS(a, 0, n-1, S);
	return 0;
}
