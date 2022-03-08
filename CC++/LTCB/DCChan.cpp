#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int max3(int a, int b, int c){
	if( (a==b && b==c) || (a==b && a>c) || (a==c && a>b) || (a>b & b==c) || (a>b && a>c) ){
		return a;
	}
	if( (a==c && a<b) || (b==c && a<b) || (a<b && b>c) ){
		return b;
	}
	if( (a<c && a==b) || (c>a && c>b) ){
		return c;
	}
}
int DCChan(int a[], int l, int r){
	if(l==r){
		if(a[l]%2){
			return 0;
		}
		else{
			return 1;
		}
	}
	int m=(l+r)/2;
	int k1=DCChan(a, l, m);
	int k2=DCChan(a, m+1, r);
	int k3=0;
	while(l<r){
		if(a[r]%2==0){
			k3++;
		}
		r--;
	}
	return max3(k1, k2, k3);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	int d=DCChan(a, 0, n-1);
	int dem, i, l, r;
	for(i=0; i<n-1; i++){
		dem=0;
		if(a[i]%2==0){
			dem++;
			l=i;
			for(r=i+1; r<n && a[r]%2==0; r++){	
				dem++;
			}
			if(dem==d){
				printf("%d %d", l, r-1);
				return 0;
			}
		}
	}
	printf("Khong co");
	return 0;
}
