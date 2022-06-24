#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 50

struct Do_Thi
{
	int so_dinh;
	int mtk[TOI_DA][TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in(struct DO_Thi);

int main()
{
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *file = fopen(duong_dan, "r");
	fscanf(file, "%d", &dt->so_dinh);
	int i, j;
	for (i = 0; i < dt->so_dinh; i++)
	{
		for (j = 0; j < dt->so_dinh; i++)
		{
			fscanf(file, "%d", &dt->mtk[i][j]);
		}
	}
}

void in(struct Do_Thi dt)
{
	int i, j;
	for (i = 0; i < dt.so_dinh; i++)
	{
		for (j = 0; j < dt.so_dinh; j++)
		{
			printf("%d ", dt.mtk[i][j]);
		}
		printf("\n");
	}
}