#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 10

struct DS_Ke
{
	int dinh_ke;
	struct DS_Ke *lk;
};
struct Do_Thi
{
	int so_dinh;
	struct DS_Ke* ds[TOI_DA];	
};

void doc_tep(struct Do_Thi*, char*);
void in_Do_Thi(struct Do_Thi);
void duyet_sau(struct Do_Thi, int, int*, int*);
void tim_duong_di(struct Do_Thi, int);
void in_duong_di(int, int, int*);
int main()
{
	char duong_dan[] = "DT.txt";
	struct Do_Thi dt;
	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);
	printf("\n");
	tim_duong_di(dt, 2);
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int i, j, ke;
	struct DS_Ke *p;
	
	fscanf(f, "%d", &dt->so_dinh);
	for (i = 0; i < dt->so_dinh; i++)
	{
		dt->ds[i] = NULL;
	}
	
	for (i = 0; i < dt->so_dinh; i++)
	{
		
		for (j = 0; j < dt->so_dinh; j++)
		{
			fscanf(f, "%d", &ke);
			if (ke)
			{
				p = (struct DS_Ke*) malloc(sizeof(struct DS_Ke));
				p->dinh_ke = j;
				p->lk = dt->ds[i];
				dt->ds[i] = p;
			}
		}	
	}
}

void in_Do_Thi(struct Do_Thi dt)
{
	int i, j;
	struct DS_Ke *p;
	
	for (i = 0; i < dt.so_dinh; i++)
	{
		for (p = dt.ds[i]; p != NULL; p = p->lk)
		{
			printf("%d ", p->dinh_ke);
		}
		printf("\n");
	}
}

void duyet_sau(struct Do_Thi dt, int dinh, int *da_tham, int *truoc)
{
	int i, ke;
	struct DS_Ke *p = dt.ds[dinh];
	
	da_tham[dinh] = 1;
	printf("%d ", dinh);
	
	while (p != NULL)
	{
		ke = p->dinh_ke;
		if (!da_tham)
		{
			truoc[ke] = dinh;
			duyet_sau(dt, ke, da_tham, truoc);
		}
		p = p->lk;
	}
}

void tim_duong_di(struct Do_Thi dt, int dinh)
{
	int i, cuoi;
	int da_tham[TOI_DA], truoc[TOI_DA];
	
	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	
	duyet_sau(dt, dinh, da_tham, truoc);
	in_duong_di(dinh, cuoi, truoc);
}

void in_duong_di(int dinh_dau, int dinh_cuoi, int *truoc)
{
//	int dinh = dinh_cuoi;
//	while (dinh_dau != dinh)
//	{
//		printf("%d <= ", dinh);
//		dinh = truoc[dinh];
//	}
//	printf("%d", dinh_dau);	
}
