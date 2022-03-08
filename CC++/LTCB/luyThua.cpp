#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int luyThua(int a, int n){
	if(n==0){
		return 1;	
	}
	int tg=luyThua(a, n/2);
	if(n%2){
		return tg*tg*a;
	}
	else{
		return tg*tg;
	}
}
int main(){
	int a, n;
	scanf("%d%d", &a, &n);
	printf("%d", luyThua(a, n));
	return 0;
}
