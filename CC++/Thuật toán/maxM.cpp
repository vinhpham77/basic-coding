#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int maxM(int a[], int l, int r){
	if(l==r){
		return a[l];
	}
	int m=(l+r)/2;
	int k1=maxM(a, l, m);
	int k2=maxM(a, m+1, r);
	if(k1<=k2){
		return k2;	
	}
	else{
		return k1;
	}	
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	printf("%d", maxM(a, 0, n-1));
	return 0;
}
