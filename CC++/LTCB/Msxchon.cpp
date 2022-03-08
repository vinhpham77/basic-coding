#include <stdio.h>
void nhapM(int a[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
}
void inM(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
}
void Msxchon(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		int mark=i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[mark])
				mark=j;
		int tg=a[i];
		a[i]=a[mark];
		a[mark]=tg;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	Msxchon(a, n);
	inM(a, n);
	return 0;
}

