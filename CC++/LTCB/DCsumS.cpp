#include <stdio.h>
int DCsumS(int a[], int n, int S){
	int X;
	for(int m=0; m<n-1; m++){
		for(int i=0; i<n; i++){
			X=a[i];
			for(int j=i+1; j<=i+m; j++){
				X+=a[j];
			}
			if(X==S){
				printf("%d %d", i+1, m+1);
				return 1;
			}	
		}
	}
	return 0;
} 
int main(){
	int n, S, d;
	FILE *fi=freopen("sumeq.txt", "r", stdin),
	  	 *fo=freopen("sumeq2.txt", "w", stdout);
	scanf("%d %d", &n, &S);
	int a[n], b[n+n-2], X=0;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		b[i]=a[i];
		X+=a[i];
	}
	for(int i=n, j=0; i<n+n-2; i++, j++){
		b[i]=a[j];
	}
	d=DCsumS(b, n, S);
	if(d==0){
		if(X==S){
			printf("1 %d", n);
		}
		else{
			printf("0");
		}
	}
	return 0;
}
