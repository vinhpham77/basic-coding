#include <stdio.h>
void fiboN(int n){
	int f1=1, f2=1, f3=2;
	if(n==1){
		printf("1");
	}
	if(n==2){
		printf("1 1");
	}
	if(n>=3){
		printf("1 1 2");
		for(int i=4; i<=n; i++){
			f1=f2;
			f2=f3;
			f3=f1+f2;
			printf(" %d", f3);
		}
	}
} 
int main(){
	int n;
	scanf("%d", &n);
	fiboN(n);
	return 0;
}
