#include <stdio.h>
#include <limits.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void SXgiam(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		b[i]=a[i];
	}
	int check;
	do{
		check=0;
		for(int i=0; i<n-1; i++){
			if(b[i]<b[i+1]){
				int tg=b[i];
				b[i]=b[i+1];
				b[i+1]=tg;
				check=1;
			}
		}
	while(check==1);
}
int lapLich(int a[], )
int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	nhapM(a, n);
	nhapM(b, n);
	return 0;
}
