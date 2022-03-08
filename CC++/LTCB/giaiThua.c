#include <stdio.h>
int main(){
	FILE *fi=freopen("giaithua.inp", "r", stdin),
	     *fo=freopen("giaithua2.out", "w+", stdout);
	int n, i;
	long long gt = 1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		gt*=i;
	}
	printf("%lld", gt);
	fclose(fi);
	fclose(fo);
	return 0;
}
