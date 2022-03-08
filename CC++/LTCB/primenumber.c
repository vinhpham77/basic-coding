#include <stdio.h>
#include <math.h>
int laSoNT(long long n)
{
	long long i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main(){
	FILE *fi=freopen("primenumber.txt","r",stdin),
		 *fo=freopen("primenumber2.txt","w+",stdout);
	long long n, i=2;
	scanf("%lld", &n);
	for(i=2;i<n;i++)
	{
		if(laSoNT(i)==1)
		{
			printf("%lld ", i);
		}
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
