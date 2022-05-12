#include <stdio.h>
#include <limits.h>
void nhapM(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
	}
}
void sapCSGiam(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		b[i]=i;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[b[i]]<a[b[j]]){
				int tg=b[i];
				b[i]=b[j];
				b[j]=tg;
			}
		}
	}
}
void xepLich(int time[], int cost[], int n){
	int chon[n], CS[n];
	for(int i=0; i<n; i++){
		chon[i]=0;
	}
	sapCSGiam(cost, CS, n);
	chon[0]=CS[0];
	for(int i=0; i<n; i++){
		
	}
	
}
int main(){
	int n;
	scanf("%d", &n);
	int time[n], cost[n];
	nhapM(time, cost, n);
	xepLich(time, cost, n);
	return 0;
}
