#include <stdio.h>
int Ckn(int k, int n){
	int a[k+1][n+1];
	for(int i=0; i<=k; i++){
		a[i][i]=1;
	}
	for(int i=1; i<=n; i++){
		a[0][i]=1;
	}
	for(int i=1; i<=k; i++){
		for(int j=i+1; j<=n; j++){
			a[i][j]=a[i-1][j-1]+a[i][j-1];
		}
	}
	return a[k][n];
	
}
int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	printf("%d", Ckn(k, n));
	return 0;
}
