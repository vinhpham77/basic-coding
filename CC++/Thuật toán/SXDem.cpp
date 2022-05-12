#include <stdio.h>
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
int maxM(int a[], int n){
	int max=a[0];
	for(int i=1; i<n; i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	return max;
}
void taoMcheck(int a[], int n, int b[], int m){
	for(int i=0; i<m; i++){
		b[i]=0;
	} //tao mang 0 de check so lan xuat hien
	for(int j=0; j<n; j++){
		b[a[j]]++;
	} //co x thi dem phan tu thu x ( la b[x] ) len 1 lan xuat hien
}
void SXDem(int a[], int n, int b[], int m){
	taoMcheck(a, n, b, m);
	for(int i=0, k=0; i<m; i++){ //k de xd vi tri gan a[], b[i] de check lan xh cua phan tu i
		if(b[i]!=0){
			int j=0;// check lan gan vo a[] cho den khi du b[i] lan xh
			while(k<n && j<b[i]){
				a[k]=i;
				j++;
				k++;
			}	
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	int m=maxM(a, n)+1;
	int b[m];//tao mang co maxM+1 phan tu tu 0 tang dan 1 don vi den maxM
	SXDem(a, n, b, m);
	inM(a, n);
	return 0;
}
