#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
int execute(int a[], int n, int j, int b[], int S){
	for(int i=0; i<=1; i++){
		b[j]=i;
		if(j!=n-1){
			execute(a, n, j+1, b, S);
		}
		else{
			int t=0;
			for(int k=0; k<n; k++){
				t=t+a[k]*b[k];
			}
			if(t==S){
				for(int i=0; i<n; i++){
					if(b[i]){
						printf("%d ", i);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
void inNP(int a[], int n, int S){
	int b[n];
	int d=execute(a, n, 0, b, S);
	if(d==0){
		printf("Khong co");
	}
}
int main(){
	int n, S;
	scanf("%d%d", &n, &S);
	int a[n];
	nhapM(a, n);
	inNP(a, n, S);
	return 0;
}
