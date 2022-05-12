#include <bits/stdc++.h>
#define for0(i, n) for(int i=1; i<=n; i++)
using namespace std;
int main(){
	int n, k;
	freopen("test.inp", "r", stdin); 
	cin >> n >> k;
	int a[n+1][n+1];
	for0(i, n){
		for0(j, n){
			cin >> a[i][j];
		}
	}
	int s[n+1][n+1];
	s[1][1]=a[1][1];
	for(int i=2; i<=n; i++){
		s[i][1]=s[i-1][1]+a[i][1];	
		s[1][i]=s[1][i-1]+a[1][i];
	}
	for(int i=0; i<=n;i++){
		s[i][0]=0;
		s[0][i]=0;
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
		{
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	int max=s[k][k], dt;
	for(int i=1; i<=n-k+1; i++){
		for(int j=1; j<=n-k+1; j++){
			dt=s[i+k-1][j+k-1]-s[i+k-1][j-1]-s[i-1][j+k-1]+s[i-1][j-1];
			if(max<=dt)
				max=dt;
		}	
	}
	cout << max;
	return 0;
}
