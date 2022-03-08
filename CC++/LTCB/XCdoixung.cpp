#include <stdio.h>
#include <string.h>
int XCdoixung(char a[], int l, int r){
	int d, c;
	if(l==r){
		printf("%c\n", a[l]);
		return 1;
	}
	for(d=l,c=r; d<=c && a[d]==a[c]; d++,c--);
	if(a[c]==a[d])
	{
		while(l<=r){
			printf("%c", a[l]);
			l++;
		}
		printf("\n");
		return 1;
	}
	return 0;
}
int main(){
	FILE *fi=freopen("xau.txt", "r", stdin),
	  	 *fo=freopen("xau2.txt", "w", stdout);
	int d, i=0;
	char a[255];
	do{
		d=scanf("%c", &a[i]);
		i++;
	}
	while(d!=EOF);
	for(int k=0; k<i-2; k++){
		for(int j=i-3; j>=k; j--){
			if(a[j]==a[k]){
				d=XCdoixung(a, k, j);
				if(d){
					k=j;
					break;
				}
			}	
		}
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
