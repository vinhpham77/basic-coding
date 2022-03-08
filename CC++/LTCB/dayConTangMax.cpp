#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void tinh(int a[], int n, int S[], int truoc[]){
	for(int i=0; i<n; i++){
		S[i]=1;
		truoc[i]=-1;
	}
	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if(a[j]<a[i] && S[i]<S[j]+1){
				S[i]=S[j]+1;
				truoc[i]=j;
			}
		}
	}
}
void KQ(int a[], int n, int S[], int truoc[]){
	int imax=0;
	for(int i=1; i<n; i++){
		if(S[i]>S[imax]){
			imax=i;
		}
	}
	printf("%d\n", S[imax]);
	while(imax>=0){
		printf("%d ", a[imax]);
		imax=truoc[imax];
	}
}
void dayConTangMax(int a[], int n){
	int S[n], truoc[n];
	tinh(a, n, S, truoc);
	KQ(a, n, S, truoc);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	dayConTangMax(a, n);
	return 0;
}
