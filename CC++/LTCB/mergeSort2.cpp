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
void merge(int a[], int l, int m, int r){
	int n=(r-l)+1, b[n], k=m+1, h=l, i=0;
	while(i<n){
		if((a[h]>a[k] && k<=r && h<=m) || (k<=r && h>m)){
			b[i]=a[k];
			k++; i++;
		}
		if((a[k]>=a[h] && k<=r && h<=m ) || (h<=m && k>r)){
			b[i]=a[h];
			h++; i++;
		}
	}
	for(i=0; i<n; i++, l++){
		a[l]=b[i];	
	}
}
void mergeSort(int a[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	mergeSort(a, 0, n-1);
	inM(a, n);
	return 0;
}
