#include <stdio.h>
void nhapM(int a[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
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
int lanXHMax(int a[], int n)
{
	bubbleSort(a, n);
	int dem, max=0, mark;
	for(int i=0; i<n-1; i++)
	{
		for(dem=1; i<n-1 && a[i]==a[i+1]; i++,dem++);
		if(dem>max)
		{
			max=dem;
			mark=a[i-1];
		}
	} 
	return mark;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	nhapM(a, n);
	printf("%d", lanXHMax(a, n));
	return 0;
}
