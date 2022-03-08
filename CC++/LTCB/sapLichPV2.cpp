#include <stdio.h>
#include <limits.h>
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
int select(int a[], int check[], int n){
	int min=INT_MAX, k;
	for(int i=0; i<n; i++){
		if(check[i]==0 && a[i]<=min){
			min=a[i];
			k=i;
		}	
	}
	return k;
}
float sapLichPV(int time[], int chon[], int n){
	float S=0;
	int check[n];
	for(int i=0; i<n; i++){
		check[i]=0;
	}
	for(int i=0; i<n; i++){
		int x=select(time, check, n);
		S+=time[x]*(n-i);
		chon[i]=x+1;
		check[x]=1;
	}
	return S;
}
int main(){
	int n;
	scanf("%d", &n);
	int time[n], chon[n];
	nhapM(time, n);
	printf("%f\n", sapLichPV(time, chon, n));
	inM(chon, n);
	return 0;
}
