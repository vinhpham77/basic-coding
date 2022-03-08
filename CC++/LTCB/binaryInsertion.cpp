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
void binaryInsertion(int a[], int n){
	for(int i=0; i<n-1; i++){
		int x=a[i+1];
		int l=0;
		int r=i;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]<=x){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
		int j;
		for(j=i; j>=l; j--){
			a[j+1]=a[j];
		}
		a[l]=x; 
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	binaryInsertion(a, n);
	inM(a, n);
	return 0;
}
