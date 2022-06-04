#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 50
#define VO_CUNG 9999999

struct Canh
{
	int dinh_dau;
	int dinh_cuoi;
	float trong_so;
};
struct Do_Thi
{
	int so_dinh;
	int so_canh;
	struct Canh ds_canh[TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in(struct Do_Thi);
struct Do_Thi tim_cay_khung(struct Do_Thi);
void duyet_cay_khung(struct Do_Thi*, struct Do_Thi, int, int*);
void ghep_thanh_phan_lt(int, int, int*, int);
struct Do_Thi kruskal(struct Do_Thi);
struct Do_Thi sort(struct Do_Thi);
int main() 
{
	struct Do_Thi dt, cknn;
	char duong_dan[] = "MTTS.txt";
	doc_tep(&dt, duong_dan);
	in(dt);
	printf("\n");
	cknn = kruskal(dt);
	in(cknn);
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int i, j, so_canh;
	float trong_so;
	struct Canh *c;
	
	fscanf(f, "%d", &dt->so_dinh);
	dt->so_canh = 0;
	for (i = 0; i < dt->so_dinh; i++)
	{
		for (j = 0; j < dt->so_dinh; j++)
		{
			fscanf(f, "%f", &trong_so);
			if (trong_so != VO_CUNG && i < j)
			{
				so_canh = dt->so_canh;
				dt->ds_canh[so_canh].dinh_dau = i;
				dt->ds_canh[so_canh].dinh_cuoi = j;
				dt->ds_canh[so_canh].trong_so = trong_so;
				dt->so_canh++;
			}
		}
	}
	
	fclose(f);
}

struct Do_Thi tim_cay_khung(struct Do_Thi dt)
{
	int i, dinh_duyet = 0;
	struct Do_Thi cay_khung;
	int da_tham[TOI_DA];
	
	cay_khung.so_dinh = dt.so_dinh;
	cay_khung.so_canh = 0;
	
	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	
	duyet_cay_khung(&cay_khung, dt, dinh_duyet, da_tham);
}

void duyet_cay_khung(struct Do_Thi *cay_khung, struct Do_Thi dt, int dinh_duyet, int *da_tham)
{
	int i, dinh, so_canh_ck;
	struct Canh c;
	
	for (i = 0; i < cay_khung->so_dinh; i++)
	{
		c = dt.ds_canh[i];
		if (c.dinh_dau == dinh_duyet)
		{
			dinh = c.dinh_cuoi;
		}
		else if (c.dinh_cuoi == dinh_duyet)
		{
			dinh = c.dinh_dau;
		}
		else 
		{
			dinh = -1;
		}
		
		if (dinh >= 0 && !da_tham[dinh])
		{
			so_canh_ck = cay_khung->so_canh;
			cay_khung->ds_canh[so_canh_ck] = dt.ds_canh[i];
			cay_khung->so_canh++;
			duyet_cay_khung(cay_khung, dt, dinh, da_tham);
		}
	}
}

void in(struct Do_Thi dt)
{
	int i;
	struct Canh c;
	for (i = 0; i < dt.so_canh; i++)
	{	
		c = dt.ds_canh[i];
		printf("%d -> %d : %f,  ", c.dinh_dau, c.dinh_cuoi, c.trong_so);
	}
}

struct Do_Thi kruskal(struct Do_Thi dt)
{
	int thanh_phan[TOI_DA], i, j, dinh_dau, dinh_cuoi;
	struct Do_Thi tam = sort(dt);
	struct Do_Thi moi;
	
	moi.so_canh = 0;
	moi.so_dinh = dt.so_dinh;
	for (i = 0; i < moi.so_dinh; i++)
	{
		thanh_phan[i] = i;
	}
	
	for (j = 0; moi.so_canh < moi.so_dinh - 1; j++)
	{
		dinh_dau = tam.ds_canh[j].dinh_dau;
		dinh_cuoi = tam.ds_canh[j].dinh_cuoi;
		
		if (thanh_phan[dinh_dau] != thanh_phan[dinh_cuoi])
		{
			moi.ds_canh[moi.so_canh++] = tam.ds_canh[j];
			ghep_thanh_phan_lt(dinh_dau, dinh_cuoi, thanh_phan, moi.so_dinh);
		}
	}
	
	return moi;
}

struct Do_Thi sort(struct Do_Thi dt)
{
	int i, j;
	struct Do_Thi moi = dt;
	struct Canh c;
	
	for (i = 0; i < moi.so_canh - 1; i++)
	{
		for (j = i + 1; j < moi.so_canh; j++)
		{
			if (moi.ds_canh[i].trong_so > moi.ds_canh[j].trong_so)
			{
				c = moi.ds_canh[i];
				moi.ds_canh[i] = moi.ds_canh[j];
				moi.ds_canh[j] = c;
			}
		}
	}
	
	return moi;
}

void ghep_thanh_phan_lt(int dinh_dau, int dinh_cuoi, int *thanh_phan, int so_dinh)
{
	int i;
	for (i = 0; i < so_dinh; i++)
	{
		if (thanh_phan[i] == dinh_cuoi)
		{
			thanh_phan[i] = dinh_dau;
		}
	}
}
