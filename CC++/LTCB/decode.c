#include <stdio.h>
int main(){
	FILE *fi=freopen("decode.txt", "r", stdin),
	     *fo=freopen("decode2.txt", "w+", stdout);
	char c;
	int k, d;
	for(d=scanf("%c", &c); d!=EOF; d=scanf("%c", &c)){
		if(c!=' '){
			k=c-1;
			printf("%c", (char)k);	
		}
		else
			printf("%c", c);
	}
	fclose(fi);
	fclose(fo);
	return 0;	
}
