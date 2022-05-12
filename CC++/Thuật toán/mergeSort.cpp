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
	int i=0, h=l, k=m+1, n=r-l+1, b[n];
	while(h<=m && k<=r){
		if(a[h]>a[k]){
			b[i]=a[k];
			k++;
		}
		else{
			b[i]=a[h];
			h++;
		}
		i++;
	}
	while(h<=m){
		b[i]=a[h];
		h++;
		i++;
	}
	while(k<=r){
		b[i]=a[k];
		k++;
		i++;
	}
	for(i=0; i<n; i++){
		a[l+i]=b[i];
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
