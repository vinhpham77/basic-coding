#include <stdio.h>
void nhapM(int a[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}
void inM(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}
void straightInsertion(int a[], int n){
	for(int i=0; i<n-1; i++){
		int x=a[i+1], j;
		for(j=i; j>=0 && a[j]>x; j--){// xet tu vi tri trc x sang trai, vi mang da dc sx nen phan tu cuoi <x thi tat ca mang deu <x
				a[j+1]=a[j];		
		}
		a[j+1]=x;//vi j-- r moi xet dk sai ->kt for nen can +1 cho dung vi tri chen
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	straightInsertion(a, n);
	inM(a, n);
	return 0;
}
