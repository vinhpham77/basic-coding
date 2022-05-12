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
void sapCS(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		b[i]=i;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[b[i]]>a[b[j]]){
				int tg=b[i];
				b[i]=b[j];
				b[j]=tg;
			}
		}
	}
}
float sapLichPV(int time[], int chon[], int n){
	int CS[n];
	float S=0;
	sapCS(time, CS, n);
	for(int i=0; i<n; i++){
		S=S+time[CS[i]]*(n-i);
		chon[i]=CS[i]+1;
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
