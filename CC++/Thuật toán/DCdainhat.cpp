#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void tinh(int a[], int n, int s[], int truoc[]){
	for(int i=0; i<n; i++){
		s[i]=1; truoc[i]=-1;
	}
	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if(a[i]>a[j] && s[i]<s[j]+1){
				s[i]=s[j]+1;
				truoc[i]=j;
			}
		}
	}
}
void inDC(int a[], int n, int s[], int truoc[]){
	int longest=0; 
	for(int i=1; i<n; i++){
		if(s[i]>s[longest]){
			longest=i;
		}
	}
	printf("Doan con dai nhat co %d phan tu\n", s[longest]);
	int j=s[longest], in[j];
	for(int i=j-1; longest>=0; i--){
		in[i]=a[longest];
		longest=truoc[longest];
	}
	for(int i=0; i<j; i++){
		printf("%d ", in[i]);
	}	
}
void DCdainhat(int a[], int n){
	int s[n], truoc[n];
	tinh(a, n, s, truoc);
	inDC(a, n, s, truoc);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	DCdainhat(a, n);
	return 0;
}
