#include <stdio.h>
int main(){
	FILE *fi=freopen("DONGHONUOC.TXT", "r", stdin),
	     *fo=freopen("DONGHONUOC2.TXT", "w+", stdout);
	int n1, n2, n3, n4, k, s, tach=1000;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &k);
	s=((n1*10+n2)*10+n3)*10+n4+k;	
	while(tach>0){
		printf("%d ", s/tach);
		s%=tach;
		tach/=10;
	}
	return 0;	
}
