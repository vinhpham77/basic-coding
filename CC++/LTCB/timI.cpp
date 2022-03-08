#include <stdio.h>
#include <math.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int timI(int a[], int l, int r){
	int m=(l+r)/2;
	if(l>r){
		return -1;
	}
	if(m==a[m]){
		return m;
	}
	else{
		if(m<a[m]){
			timI(a, m+1, r);
		}
		else
			return -1;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	printf("%d", timI(a, 0, n-1));
	return 0;	
} 
