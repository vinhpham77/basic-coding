#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void sapCSGiam(int a[], int b[], int n){
	for(int i=0; i<n; i++){
		b[i]=i;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[b[i]]<a[b[j]]){
				int tg=b[i];
				b[i]=b[j];
				b[j]=tg;
			}
		}
	}
}
unsigned int trongHoa(int a[], int hoa[], int n){
	int max=0;
	sapCSGiam(a, hoa, n);
	for(int i=0; i<n; i++){
		int s=a[hoa[i]]+i;
		if(max<s){
			max=s;
		}	
	}
	return max+1;
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n], hoa[n];
	nhapM(a, n);
	printf("%u\n", trongHoa(a, hoa, n));
	for(int i=0; i<n; i++){
		printf("%d ", hoa[i]);
	}
	return 0;
}
