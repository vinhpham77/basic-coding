#include <stdio.h>
#include <limits.h>
void nhapM(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
}
int koGiao(int a[], int b[], int chon[], int w, int x){
	for(int i=0; i<w; i++){
		if((a[chon[i]]<=a[x] && a[x]<b[chon[i]]) || (a[x]<=a[chon[i]] && a[chon[i]]<b[x])){
			return 0; 
		}
	}
	return 1;	
}
int	khongGiaoNhau(int a[], int b[], int n){
	int chon[n], check[n], w=0, k;
	for(int i=0; i<n; i++){
		check[i]=0;
	}
	for(int i=0; i<n; i++){
		int min=INT_MAX;
		for(int i=0; i<n; i++){
			if(check[i]==0 && b[i]<=min){
				min=b[i];
				k=i;
			}
		}
		check[k]=1;
		if(koGiao(a, b, chon, w, k)){
			chon[w]=k;
			w++;
		}
	}
	return w;	
}
int main(){
	int n;
	scanf("%d", &n); 
	int a[n], b[n];
	nhapM(a, b, n);
	printf("%d", khongGiaoNhau(a, b, n));
	return 0;
}
