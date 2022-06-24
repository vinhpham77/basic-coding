#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 50

struct Canh
{
	int dinh_dau;
	int dinh_cuoi;
};

struct Do_Thi
{
	int so_canh;
	int so_dinh;
	struct Canh ds[TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in(struct Do_Thi);
int dem_nha_biet_duong(struct Do_Thi, int);
void tim_duong_di(struct Do_Thi, int, int*);
int la_biet_het(struct Do_Thi, int);
//struct Do_Thi tim_cay_khung(struct Do_Thi, int);
//void duyet_sau_CK(struct Do_Thi, struct Do_Thi*, int, int*);

int main()
{
	struct Do_Thi dt;
	doc_tep(&dt, "dothi.txt");
	//in(dt);
	int sv = 0;
	int dem = dem_nha_biet_duong(dt, sv);
	printf("Sinh vien %d biet duong den %d nha\n", sv, dem);
	printf("Sinh vien %d biet het nha cac ban sinh vien(co the qua trung gian): %s", sv, la_biet_het(dt, sv) ? "co" : "khong");
	return 0;
}

void doc_tep(struct Do_Thi *p, char *duong_dan)
{
	FILE *file = fopen(duong_dan, "r");
	struct Canh c;
	p->so_canh = 0;
	int i, j, k;

	fscanf(file, "%d", &p->so_dinh);
	for (i = 0; i < p->so_dinh; i++)
	{
		for (j = 0; j < p->so_dinh; j++)
		{
			fscanf(file, "%d", &k);
			if (k)
			{
				c.dinh_dau = i;
				c.dinh_cuoi = j;
				p->ds[p->so_canh++] = c;
			}
		}
	}
	fclose(file);
}

void in(struct Do_Thi dt)
{
	int i, j;
	for (i = 0; i < dt.so_canh; i++)
	{
		printf("%d %d,  ", dt.ds[i].dinh_dau, dt.ds[i].dinh_cuoi);
	}
}

//struct Do_Thi tim_cay_khung(struct Do_Thi dt, int dinh)
//{
//	struct Do_Thi h;
//	h.so_dinh = dt.so_dinh;
//	h.so_canh = 0;
//	int da_tham[TOI_DA];
//	int i;
//	for (i = 0; i < h.so_dinh; i++)
//	{
//		da_tham[i] = 0;
//	}
//	duyet_sau_CK(dt, &h, dinh, da_tham);
//	return h;
//}
//
//void duyet_sau_CK(struct Do_Thi dt, struct Do_Thi *ck, int dinh, int *da_tham)
//{
//	int i, w;
//	da_tham[dinh] = 1;
//	for (i = 0; i < dt.so_canh; i++)
//	{
//		if (dt.ds[i].dinh_dau == dinh)
//		{
//			w = dt.ds[i].dinh_cuoi;
//		}
//		else if (dt.ds[i].dinh_cuoi == dinh)
//		{
//			w = dt.ds[i].dinh_dau;
//		}
//		else
//		{
//			w = -1;
//		}
//
//		if (w != -1 && !da_tham[w])
//		{
//			ck->ds[ck->so_canh++] = dt.ds[i];
//			duyet_sau_CK(dt, ck, w, da_tham);
//		}
//	}
//}

int dem_nha_biet_duong(struct Do_Thi dt, int dinh)
{
	int i;
	int dem = 0;

	for (i = 0; i < dt.so_canh; i++)
	{
		if (dt.ds[i].dinh_dau == dinh)
		{
			break;
		}
	}

	while (i < dt.so_canh)
	{
		if (dt.ds[i].dinh_dau == dinh)
		{
			dem++;
		}
		i++;
	}

	return dem;
}

int la_biet_het(struct Do_Thi dt, int dinh)
{
	int da_tham[TOI_DA];
	int i;
	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	tim_duong_di(dt, dinh, da_tham);
	for (i = 0; i < dt.so_dinh; i++)
	{
		if (!da_tham[i])
		{
			return 0;
		}
	}
	return 1;
}

void tim_duong_di(struct Do_Thi dt, int dinh, int *da_tham)
{
	da_tham[dinh] = 1;
	int i;
	struct Canh c;
	for (i = 0; i < dt.so_canh; i++)
	{
		if (dt.ds[i].dinh_dau == dinh)
		{
			break;
		}
	}

	while (i < dt.so_canh)
	{
		c = dt.ds[i];
		if (c.dinh_dau == dinh)
		{
			if (!da_tham[c.dinh_cuoi])
			{
				tim_duong_di(dt, c.dinh_cuoi, da_tham);
			}
		}
		else
		{
			break;
		}
		i++;
	}
}
