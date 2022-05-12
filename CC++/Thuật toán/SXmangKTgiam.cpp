#include <stdio.h>
void nhapM(char a[], int n){
	for(int i=0; i<n; i++){
		scanf("%c", &a[i]);
	}
}
void inM(char a[], int n){
	for(int i=0; i<n; i++){
		printf("%c ", a[i]);
	}
}
void SXmangKT(char a[], int n){
	int b[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i=0; i<n; i++){
		int k=a[i]-'a';
		b[k]++;
	}
	int k=25, j=0;
	while(j<n){
		if(b[k]!=0){
			a[j]=(char)(k+'a');
			b[k]--;
			j++;
		}	
		else{
			k--;
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	fflush(stdin);
	char a[n];
	nhapM(a, n);
	SXmangKT(a, n);
	inM(a, n);
	return 0;
}
