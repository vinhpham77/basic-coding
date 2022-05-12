#include <stdio.h>
#include <limits.h>
void nhapM(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
}
void sapCS(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		b[i]=i;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[b[i]]>a[b[j]]){
				int tg=b[i];
				b[i]=b[j];
				b[j]=tg;
			}
		}
	}
}
int khongGiao(int a[], int b[], int chon[], int i, int x){
	return a[x]>=b[i-1];
}
int xepLichHD(int a[], int b[], int n, int chon[]){
	int CS[n];
	sapCS(b, CS, n);
	chon[0]=CS[0];
	int i=1, j=1;
	while(j<n){
		if(khongGiao(a, b, chon, i, CS[j])){
			chon[i]=CS[j];
			i++;
		}
		j++;
	}
	return i;
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n], chon[n];
	nhapM(a, b, n);
	int d=xepLichHD(a, b, n, chon);
	printf("%d\n", d);
	for(int i=0; i<d; i++){
		printf("%d ",  chon[i]);
	}
}
