#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sinh_Vien
{
	char ho_ten[30];
	int nam_sinh;
	float dtb;
};
struct DSSV
{
	struct Sinh_Vien sv;
	struct DSSV *lien_ket;
};
struct QLDS
{
	struct DSSV *dau;
	struct DSSV *cuoi;
};

void khoi_tao_DSSV(struct QLDS *);
void in_SV(struct Sinh_Vien);
void in_DSSV(struct DSSV *);
void them_SV(struct QLDS *, struct Sinh_Vien);
int dem_SV(struct DSSV *);
void tao_DSSV_gioi(struct QLDS *, struct DSSV *);
struct DSSV * tim_DSSV_ho_ten(struct DSSV *, char *);
int xoa_SV_ho_ten(struct QLDS *, char *);
int them_SV_vao_vi_tri(struct QLDS *, struct Sinh_Vien, int);
int xoa_SV_vi_tri(struct QLDS *, int);
void chen_DSSV_sau_SV_ho_ten(struct QLDS *, struct QLDS *, char *);
void dao_nguoc_DSSV(struct DSSV *);

int main()
{
	struct QLDS *ql = (struct QLDS *) malloc(sizeof(struct QLDS));
	struct QLDS *ql_2 = (struct QLDS *) malloc(sizeof(struct QLDS));
	struct QLDS *ql_ds_gioi = (struct QLDS *) malloc(sizeof(struct QLDS));
	struct Sinh_Vien sv1 = {"A", 2002, 6.8};
	struct Sinh_Vien sv2 = {"B", 2002, 6.0};
	struct Sinh_Vien sv3 = {"C", 2002, 8.2};
	struct Sinh_Vien sv4 = {"D", 2002, 7.9};
	struct Sinh_Vien sv5 = {"E", 2002, 9.4};

	struct Sinh_Vien sv6 = {"Z", 2002, 6.8};
	struct Sinh_Vien sv7 = {"Y", 2002, 6.0};
	struct Sinh_Vien sv8 = {"X", 2002, 8.2};
	struct Sinh_Vien sv9 = {"V", 2002, 7.9};
	struct Sinh_Vien sv10 = {"U", 2002, 9.4};
	
	struct Sinh_Vien sv = {"TT", 2000, 7.8};

	khoi_tao_DSSV(ql);
	them_SV(ql, sv1);
	them_SV(ql, sv2);
	them_SV(ql, sv3);
	them_SV(ql, sv4);
	them_SV(ql, sv5);
	
	khoi_tao_DSSV(ql_2);
	them_SV(ql_2, sv6);
	them_SV(ql_2, sv7);
	them_SV(ql_2, sv8);
	them_SV(ql_2, sv9);
	them_SV(ql_2, sv10);

//	printf("%d\n", dem_SV(ql->dau));

//	khoi_tao_DSSV(ql_ds_gioi);
//	tao_DSSV_gioi(ql_ds_gioi, ql->dau);
//	in_DSSV(ql_ds_gioi->dau);

//	them_SV_vao_vi_tri(ql, sv, 2);
//	xoa_SV_vi_tri(ql, 7);
//	in_DSSV(ql->dau);
	chen_DSSV_sau_SV_ho_ten(ql, ql_2, "E");
	in_SV(ql->cuoi->sv);
	//in_DSSV(ql->dau);
	dao_nguoc_DSSV(ql->dau);
	in_DSSV(ql->dau);
	return 0;
}

void khoi_tao_DSSV(struct QLDS *ql)
{
	ql->dau = NULL;
	ql->cuoi = NULL;
}

void in_SV(struct Sinh_Vien sv)
{
	printf("%s %d %f", sv.ho_ten, sv.nam_sinh, sv.dtb);
}

void in_DSSV(struct DSSV *dau)
{
	struct DSSV *p = dau;

	while (p != NULL)
	{
		in_SV(p->sv);
		printf("\n");
		p = p->lien_ket;
	}
}
void them_SV(struct QLDS *ql, struct Sinh_Vien sv)
{
	struct DSSV *p;
	struct DSSV *p_new;

	p = ql->cuoi;
	p_new = (struct DSSV *) malloc(sizeof(struct DSSV));
	p_new->sv = sv;
	p_new->lien_ket = NULL;

	if (p != NULL)
	{
		p->lien_ket = p_new;
		ql->cuoi = p_new;
	}
	else
	{
		ql->dau = p_new;
		ql->cuoi = p_new;
	}
}

int dem_SV(struct DSSV *dau)
{
	struct DSSV *p = dau;
	int dem = 0;

	while (p != NULL)
	{
		dem++;
		p = p->lien_ket;
	}

	return dem;
}

void tao_DSSV_gioi(struct QLDS *ql_ds_gioi, struct DSSV *dau)
{
	struct DSSV *p = dau;
	struct Sinh_Vien sv;

	while (p != NULL)
	{
		if (p->sv.dtb >= 8)
		{
			them_SV(ql_ds_gioi, p->sv);
		}

		p = p->lien_ket;
	}
}

int xoa_SV_ho_ten(struct QLDS *ql, char *ho_ten)
{
	struct DSSV *p = ql->dau;
	struct DSSV *tam;

	if (p == NULL)
	{
		return 0;
	}

	//TH xoa Sinh_Vien dau
	if (strcmp(p->sv.ho_ten, ho_ten) == 0)
	{
		ql->dau = p->lien_ket;

		if (p->lien_ket == NULL)
		{
			ql->cuoi = NULL;
		}

		free(p);

		return 1;
	}

	//TH xoa Sinh_Vien o sau
	while (p->lien_ket != NULL)
	{
		if (strcmp(p->lien_ket->sv.ho_ten, ho_ten) == 0)
		{
			if (ql->cuoi == p->lien_ket)
			{
				ql->cuoi = p;
			}

			tam = p->lien_ket;
			p->lien_ket = p->lien_ket->lien_ket;
			free(tam);

			return 1;
		}

		p = p->lien_ket;
	}

	return 0;
}

int them_SV_vao_vi_tri(struct QLDS *ql, struct Sinh_Vien sv, int vi_tri)
{
	int dem = 0;
	int la_tb_cuoi;
	struct DSSV *p_new = (struct DSSV *) malloc(sizeof(struct DSSV));
	struct DSSV *p = ql->dau;

	if (vi_tri < 0)
	{
		return 0;
	}
	else if (vi_tri == 0)
	{
		p_new->sv = sv;
		p_new->lien_ket = ql->dau;
		ql->dau = p_new;

		return 1;
	}

	while (dem < vi_tri - 1 && p != NULL)
	{
		dem++;
		p = p->lien_ket;
	}

	if (p != NULL)
	{
		p_new->sv = sv;
		la_tb_cuoi = p->lien_ket == NULL;
		p_new->lien_ket = p->lien_ket;
		p->lien_ket = p_new;

		if (la_tb_cuoi)
		{
			ql->cuoi = p_new;
		}

		return 1;
	}

	return 0;
}

int xoa_SV_vi_tri(struct QLDS *ql, int vi_tri)
{
	struct DSSV *p = ql->dau;
	struct DSSV *tam;
	int dem = 0;

	if (p == NULL || vi_tri < 0)
	{
		return 0;
	}

	//TH xoa Sinh_Vien dau
	if (vi_tri == 0)
	{
		ql->dau = p->lien_ket;

		if (p->lien_ket == NULL)
		{
			ql->cuoi = NULL;
		}

		free(p);

		return 1;
	}

	//TH xoa Sinh_Vien o sau
	while (dem < vi_tri - 1 && (p->lien_ket != NULL))
	{
		dem++;
		p = p->lien_ket;
	}

	if (p->lien_ket != NULL)
	{
		if (ql->cuoi == p->lien_ket)
		{
			ql->cuoi = p;
		}

		tam = p->lien_ket;
		p->lien_ket = p->lien_ket->lien_ket;
		free(tam);

		return 1;
	}

	return 0;
}

struct DSSV * tim_DSSV_ho_ten(struct DSSV *dau, char *ho_ten)
{
	struct DSSV *p = dau;
	
	while (p != NULL)
	{
		if ( strcmp(p->sv.ho_ten, ho_ten) == 0)
		{
			return p;
		}
		
		p = p->lien_ket;
	}
	
	return NULL;
}

void chen_DSSV_sau_SV_ho_ten(struct QLDS *ql_dich, struct QLDS *ql_phu, char *ho_ten)
{
	struct DSSV *p = tim_DSSV_ho_ten(ql_dich->dau, ho_ten);
	struct DSSV *tmp;
	struct DSSV *q = ql_phu->dau;
	struct DSSV *pt;
	
	if (q == NULL || p == NULL)
	{
		return;
	}
	
	tmp = p->lien_ket;
	while (q != NULL)
	{
		pt = (struct DSSV*) malloc(sizeof(struct DSSV));
		pt->sv = q->sv;
		pt->lien_ket = NULL;
		p->lien_ket = pt;
		p = pt;
		q = q->lien_ket;
	}
	
	p->lien_ket = tmp;
	if (tmp == NULL)
	{
		ql_dich->cuoi = p;
	}
}

void dao_nguoc_DSSV(struct DSSV *dau)
{
	struct DSSV *p = dau;
	struct DSSV *q;
	struct Sinh_Vien tmp;
	
	while (p != NULL)
	{
		for (q = p->lien_ket; q != NULL; q = q->lien_ket)
		{
			tmp = p->sv;
			p->sv = q->sv;
			q->sv = tmp;	
		}
		
		p = p->lien_ket;
	}
}
