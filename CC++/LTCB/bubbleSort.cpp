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
void bubbleSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1]){
			int tg=a[i];
			a[i]=a[i+1];
			a[i+1]=tg;
		}	
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	bubbleSort(a, n);
	inM(a, n);
	return 0;
}
