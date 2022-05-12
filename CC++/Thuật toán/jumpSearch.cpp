#include <stdio.h>
#include <math.h>
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
int jumpSearch(int a[], int n, int x){
	int k=sqrt(n), t=0, i=0;
	while(i<n && a[i]<x){
		t=i;
		i+=k;
		if(i>n-1){
			i=n-1;
			break;
		}
	}
	for(int j=t; j<=i; j++){
		if(a[j]==x){
			return j;
		}	
	} 
	return -1;
}
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int a[n];
	nhapM(a, n);
	printf("%d", jumpSearch(a, n, x));
	return 0;
}
