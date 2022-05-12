#include <stdio.h>
#include <math.h>
int KC(int xA, int yA, int xB, int yB){
	return sqrt((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA));
}
int main(){
	FILE *fi=freopen("khoangcach.txt", "r", stdin),
		 *fo=freopen("khoangcach2.txt", "w", stdout);
	unsigned int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int xA, xB, yA, yB;
		scanf("%d %d %d %d", &xA, &yA, &xB, &yB);
		float xM=(xA+xB)/2;
		printf("%d ", KC(xM, 0, xA, yA)+KC(xM, 0, xB, yB));
	}
	return 0;
}
