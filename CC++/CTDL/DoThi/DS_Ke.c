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
int co_duong_di_sau(struct Do_Thi, int, int, int*, int*);
int la_dt_lien_thong(struct Do_Thi);
void tim_duong_di(struct Do_Thi, int, int, int);
void tim_thanh_phan_lien_thong(struct Do_Thi);
void in_duong_di(int, int, int*);

int main()
{
	char duong_dan[] = "DT.txt";
	struct Do_Thi dt;
	int x, y;
	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);

	x = 0, y = 3;
	printf("\nDuyet theo chieu sau %d den %d: ", x, y);
	tim_duong_di(dt, x, y, 1);
	printf("\nDuyet theo chieu rong %d den %d: ", x, y);
	tim_duong_di(dt, x, y, 0);

	printf("\nLa do thi lien thong: %d\n", la_dt_lien_thong(dt));
	tim_thanh_phan_lien_thong(dt);
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int i, j, dinh_ke;
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
			fscanf(f, "%d", &dinh_ke);
			if (dinh_ke)
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

void duyet_sau(struct Do_Thi dt, int dinh_dau, int *da_tham, int *truoc)
{
	int i, dinh_ke;
	struct DS_Ke *p = dt.ds[dinh_dau];
	da_tham[dinh_dau] = 1;

	while (p != NULL)
	{
		dinh_ke = p->dinh_ke;
		if (!da_tham[dinh_ke])
		{
			truoc[dinh_ke] = dinh_dau;
			duyet_sau(dt, dinh_ke, da_tham, truoc);
		}
		p = p->lk;
	}
}

int co_duong_di_sau(struct Do_Thi dt, int dinh_dau, int dinh_cuoi, int *da_tham, int *truoc)
{
	int i, dinh_ke;
	struct DS_Ke *p = dt.ds[dinh_dau];

	da_tham[dinh_dau] = 1;

	while (p != NULL)
	{
		dinh_ke = p->dinh_ke;
		if (!da_tham[dinh_ke])
		{
			truoc[dinh_ke] = dinh_dau;
			if (dinh_ke == dinh_cuoi || co_duong_di_sau(dt, dinh_ke, dinh_cuoi, da_tham, truoc))
			{
				return 1;
			}
		}
		p = p->lk;
	}

 	return 0;
}


int co_duong_di_rong(struct Do_Thi dt, int dinh_dau, int dinh_cuoi, int *da_tham, int *truoc)
{
	int i, dinh_ke, dau = 0, cuoi = 0;
	struct DS_Ke *p;
	int hang_doi[TOI_DA];

	hang_doi[dau] = dinh_dau;
	da_tham[dinh_dau] = 1;

	while (dau <= cuoi)
	{
		dinh_dau = hang_doi[dau++];
		for (p = dt.ds[dinh_dau]; p != NULL; p = p->lk)
		{
			if (!da_tham[p->dinh_ke])
			{
				truoc[p->dinh_ke] = dinh_dau;
				da_tham[p->dinh_ke] = 1;
				if (p->dinh_ke == dinh_cuoi)
				{
					return 1;
				}
				hang_doi[++cuoi] = p->dinh_ke;
			}
		}
	}

	return 0;
}

int la_dt_lien_thong(struct Do_Thi dt)
{
	int i, dinh_dau = 0;
	int da_tham[TOI_DA], truoc[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}

	duyet_sau(dt, dinh_dau, da_tham, truoc);

	for (i = 0; i < dt.so_dinh; i++)
	{
		if (!da_tham[i])
		{
			return 0;
		}
	}

	return 1;
}

void tim_duong_di(struct Do_Thi dt, int dinh_dau, int dinh_cuoi, int duyet_sau)
{
	int i, da_tham[TOI_DA], truoc[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}

	if (duyet_sau && co_duong_di_sau(dt, dinh_dau, dinh_cuoi, da_tham, truoc))
	{
		in_duong_di(dinh_dau, dinh_cuoi, truoc);
	}
	else if (!duyet_sau && co_duong_di_rong(dt, dinh_dau, dinh_cuoi, da_tham, truoc))
	{
		in_duong_di(dinh_dau, dinh_cuoi, truoc);
	}
	else
	{
  		printf("Khong co duong di tu dinh %d den dinh %d", dinh_dau, dinh_cuoi);
	}
}

void tim_thanh_phan_lien_thong(struct Do_Thi dt)
{
	int i, j, dem = 0;
	int da_tham[TOI_DA], truoc[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}

	i = 0;
	while (i < dt.so_dinh)
	{
		duyet_sau(dt, i, da_tham, truoc);
		printf("\nThanh phan lien thong %d: ", ++dem);
		while (i < dt.so_dinh)
		{
			if (!da_tham[i])
			{
				break;
			}
			else
			{
				printf("%d ", i);
			}
			i++;
		}
	}
}

void in_duong_di(int dinh_dau, int dinh_cuoi, int *truoc)
{
	int dinh = dinh_cuoi;
	while (dinh != dinh_dau)
	{
		printf("%d <= ", dinh);
		dinh = truoc[dinh];
	}
	printf("%d", dinh_dau);
}