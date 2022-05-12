#include <stdio.h>
void nhapM(int a[][], int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; i<n)
	}
} 
int truyVet(int a[][100],int s[][100],int vt[][100],int m,int n,int x)
{
	int i, j, g, h, k ,p=1, f, e, max=a[1][x], v=x; s[1][1]=a[1][x], vt[1][1]=x;
	for(i=2;i<=m;i++)
	{
		h=1;k=p;p=0;
		for(j=1;j<=k;j++,h++)
		{
			f=s[i-1][j];
			if(vt[i-1][j]==1){
				g=1;
				e=1;
			}
			else{
				if(vt[i-1][j]==n){
				g=1; e=n-1;}
				else{
					g=0;e=vt[i-1][j]-1;
				}
			}
			while(g<3)
			{
				s[i][h]=f+a[i][e];
				vt[i][h]=e;
				if(max<s[i][h]){
					max=s[i][h];
					v=h;
				}
				g++; e++;
				h++; p++;
			}
		}
	}
	return v;
}

