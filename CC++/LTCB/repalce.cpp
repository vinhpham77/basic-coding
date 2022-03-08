#include <stdio.h>

void nhapM(int a[6][6], int m, int n)
{
	int i, j;
	for(i=1;i<=m;i++)
	{
		printf("hang %d: \n", i);
		for(j=1;j<=n;j++)
		{
			printf("nhap phan tu thu %d: ", j);
			scanf("%d", &a[i][j]);
		}
	}
}
void inM(int a[6][6], int m, int n)
{
	int i, j;
	for(i=1;i<=m;i++)
	{
		printf("hang %d: \n", i);
		for(j=1;j<=n;j++)
		{
			printf("phan tu thu %d: %d ", j, a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int a[6][6];
	nhapM(a, 5, 5);
	inM(a, 5, 5);
	return 0;
}
