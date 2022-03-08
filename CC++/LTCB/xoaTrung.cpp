#include <stdio.h>
void nhapM(int a[], int n){
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void merge(int a[], int l, int m, int r){
	int i=0, k=m+1, b[r-l+1], dem=0;
	if(a[l]<a[k]){
		b[i]=a[l];
		l++;
	}
	else{
		if(a[l]==a[k]){
			b[i]=a[l];
			l++;
			k++;
			dem++;
		}
		else{
			b[i]=a[k];
			k++;
		}
	}
	i++;
	while(l<=m || k<=r){
		while((a[l]<a[k] && l<=m && a[l]>b[i-1]) || (k>r && a[l]>b[i-1] && l<=m){
			b[i]=a[l];
			l++;
			i++;
		}
		while((a[l]>a[k] && k<=r && a[k]>b[i-1]) || (l>m && a[k]>b[i-1] && k<=r)){
			b[i]=a[k];
			k++;
			i++;
		}
		while(a[l]==a[k] && k<=r && l<=m){
			if(a[l]==b[i-1]){
				dem+=2;
			}
			else{
				b[i]=a[l];
				i++;	
			}
			l++;
			k++;
		}
		while(a[l]==b[i-1] && l<=m){
			l++;
			dem++;
		}
		while(a[k]==b[i-1] && k<=m){
			k++;
			dem++;
		}
	}
	a[r-l+1-dem];
}
void boTrung(int a[], int l, int r){
	if(l==r){
		return 1;
	}
	else{
		int m=(l+r)/2;
		int k1=boTrung(a, l, m);
		int k2=boTrung(a, m+1, r);
		merge(a, l, m, r, k1, k2);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	boTrung(a, 0, n-1);
	return 0;
}
