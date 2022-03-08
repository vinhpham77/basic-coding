#include <stdio.h>
#include <limits.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void thuDVD(int h[], int n, int T){
	int S[n+1], a[n];
	int z=0, w=0, k;
	for(int i=0; i<n; i++){
		a[i]=0;
	}
	while(w<n){
		int min=INT_MAX;
		for(int i=0; i<n; i++){
			if(a[i]==0 && h[i]<=min){
				min=h[i];
				k=i;
			}
		}
		a[k]=1;
		if(z+h[k]<=T){
			z+=h[k];
			w++;
			S[w]=k;
		}
		else{
			break;
		}
	}
	printf("%d\n", w);
	for(int i=1; i<=w; i++){
		printf("%d ", S[i]);
	}
}
int main(){
	int n, T;
	scanf("%d%d", &n, &T);
	int h[n];
	nhapM(h, n);
	thuDVD(h, n, T);
	return 0;	
}
