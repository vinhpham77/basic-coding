#include <stdio.h>
int main(){
	FILE *fi=freopen("DATDAU.txt", "r", stdin),
		 *fo=freopen("DATDAU2.txt", "w+", stdout);
	int i=0, n, k, j, l=1, mark, tg;
	scanf("%d %d", &n, &k);
	int b[n];
	while(i<n){
		 scanf("%d", &b[i]);
		 i++;
	}
	for(i=1; l<=k; i++){
		mark=i;
		for(j=i+1; j<n; j++){
			if(b[mark]<b[j]){
				mark=j;
			}
		}
		tg=b[mark];
		b[mark]=b[i];
		b[i]=tg;
		l++;
	}
	int s=b[0];
	l=1;
	for(i=1; i<n; i++){
		if(l<=k){
			s+=b[i];
			l++;
		}
		else{
			s-=b[i];
		}
	}
	printf("%d", s);
	fclose(fi);
	fclose(fo);
	return 0;
}
