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
int soHT(int n)
{
	int S=0;
	for(int i=1; i<=n/2; i++)
		if(n%i==0)
			S+=i;
	if(S==n)
		return 1;
	return 0;
}
void bubbleSort(int a[], int n)
{
	int dem;
	do
	{
		dem=0;
		for(int i=0; i<n-1; i++)
			if(a[i]>a[i+1])
			{
				int tg=a[i];
				a[i]=a[i+1];
				a[i+1]=tg;
			}
			else
				dem++;
		n--;
	}
	while(dem<n);
}
void MaxHT(int a[], int n)
{
	bubbleSort(a, n);
	int check=0;
	for(int i=n-1; i>=0; i--)
		if(soHT(a[i]))
		{
			printf("%d", a[i]);
			check=1;
			break;
		}
	if(check==0)
		printf("Khong co");
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	MaxHT(a, n);
	return 0;
}
