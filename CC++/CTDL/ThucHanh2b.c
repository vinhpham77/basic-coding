#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SO_SDT_TOI_DA 10

struct Thue_Bao
{
	char ten[30];
	char dia_chi[50];
	char sdt[SO_SDT_TOI_DA][11];
	int so_sdt;
};
struct Danh_Ba
{
	struct Thue_Bao thue_bao;
	struct Danh_Ba *lien_ket;
};
struct QLDB
{
	struct Danh_Ba *dau;
	struct Danh_Ba *cuoi;
};

void nhap_TB(struct Thue_Bao *);
void in_TB(struct Thue_Bao);
void khoi_tao_QLDB(struct QLDB *);
void nhap_DB(struct QLDB *);
void liet_ke_TB(struct Danh_Ba *);
void them_TB_dau_DB(struct QLDB *, struct Thue_Bao);
int them_TB_cuoi_DB(struct QLDB *, struct Thue_Bao);
int them_TB_sau_ten(struct QLDB *, struct Thue_Bao, char *);
int dem_TB(struct Danh_Ba *);
int xoa_TB_ten(struct QLDB *, char *);
struct Danh_Ba * tim_DB_co_TB_ten(struct Danh_Ba *, char *);
struct Thue_Bao * tim_TB_co_sdt(struct Danh_Ba *, char *);
int them_sdt_vao_tb(struct Danh_Ba *, char *, char *);
int xoa_sdt(struct Danh_Ba *, char *);
int la_sdt_Viettel(char *);
int la_TB_Viettel(struct Thue_Bao);
void tao_DB_Viettel_tu_DB(struct Danh_Ba *, struct QLDB *);
void ghep_hai_DB(struct Danh_Ba *, struct Danh_Ba *);

int main()
{
	char ten[30];
	char sdt[11];
	struct Thue_Bao *tb = (struct Thue_Bao *) malloc(sizeof(struct Thue_Bao));
	struct QLDB *ql = (struct QLDB *) malloc(sizeof(struct QLDB));
	struct QLDB *ql_moi = (struct QLDB *) malloc(sizeof(struct QLDB));
	
	khoi_tao_QLDB(ql);

//	nhap_TB(tb);
//	them_TB_dau_DB(ql, *tb);

	nhap_DB(ql);
//	liet_ke_TB(ql->dau);
//
//	printf("\n");
//	nhap_TB(tb);
//	them_TB_dau_DB(ql, *tb);
//	liet_ke_TB(ql->dau);
//
//	printf("\n");
//	nhap_TB(tb);
//	them_TB_cuoi_DB(ql, *tb);
//	liet_ke_TB(ql->dau);
//
//	printf("\n");
//	nhap_TB(tb);
//	printf("Nhap ten thue bao muon them sau do: ");
//	gets(ten);
//	printf("%d\n", them_TB_sau_ten(ql, *tb, ten));
//	liet_ke_TB(ql->dau);
//
//	printf("\nSo luong thue bao: %d", dem_TB(ql->dau));
//
//	printf("\nNhap ten thue bao muon xoa: ");
//	gets(ten);
//	printf("%d\n", xoa_TB_ten(ql, ten));
//	liet_ke_TB(ql->dau);

//	printf("Nhap sdt cua thue bao muon tim: ");
//	gets(sdt);
//	tb = tim_TB_co_sdt(ql->dau, sdt);
//	if (tb == NULL)
//	{
//		printf("Khong tim thay thue bao nao co sdt %s\n", sdt);
//	}
//	else
//	{
//		in_TB(*tb);
//	}
//
//	printf("\nNhap ten thue bao can them sdt: ");
//	gets(ten);
//	printf("Nhap sdt can them: ");
//	gets(sdt);
//	printf("%d\n", them_sdt_vao_tb(ql->dau, ten, sdt));
//	liet_ke_TB(ql->dau);
//	
//	printf("\nNhap sdt can xoa: ");
//	gets(sdt);
//	printf("%d\n", xoa_sdt(ql->dau, sdt));
//	liet_ke_TB(ql->dau);
	
	
//	tao_DB_Viettel_tu_DB(ql->dau, ql_moi);
//	liet_ke_TB(ql_moi->dau);
	
	return 0;
}

void khoi_tao_QLDB(struct QLDB *ql)
{
	ql->dau = NULL;
	ql->cuoi = NULL;
}

void nhap_TB(struct Thue_Bao *tb)
{
	int i;

	fflush(stdin);
	printf("Nhap ten: ");
	gets(tb->ten);
	printf("Nhap dia chi: ");
	gets(tb->dia_chi);
	printf("Nhap so luong sdt: ");
	scanf("%d", &tb->so_sdt);
	fflush(stdin);

	for(i = 0; i < tb->so_sdt; i++)
	{
		printf("Nhap sdt thu %d: ", i);
		gets(tb->sdt[i]);
	}
}

void in_TB(struct Thue_Bao tb)
{
	int i;

	printf("Ten: %s\nDia chi: %s", tb.ten, tb.dia_chi);

	for(i = 0; i < tb.so_sdt; i++)
	{
		printf("\nSdt thu %d: %s", i, tb.sdt[i]);
	}
}

void nhap_DB(struct QLDB *ql)
{
	int n;
	int i;
	struct Thue_Bao tb;

	printf("Nhap so luong thue bao: ");
	scanf("%d", &n);
	fflush(stdin);
	
	for	(i = 0; i < n; i++)
	{
		nhap_TB(&tb);
		them_TB_cuoi_DB(ql, tb);
	}
}

void liet_ke_TB(struct Danh_Ba *dau)
{
	struct Danh_Ba *p = dau;

	while (p != NULL)
	{
		in_TB(p->thue_bao);
		printf("\n");
		p = p->lien_ket;
	}
}

void them_TB_dau_DB(struct QLDB *ql, struct Thue_Bao tb)
{
	struct Danh_Ba *p_new = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));

	p_new->thue_bao = tb;

	if (ql->dau == NULL)
	{
		p_new->lien_ket = NULL;
		ql->dau = p_new;
		ql->cuoi = p_new;
	}
	else
	{
		p_new->lien_ket = ql->dau;
		ql->dau	= p_new;
	}
}

int them_TB_cuoi_DB(struct QLDB *ql, struct Thue_Bao tb)
{
	struct Danh_Ba *p;
	struct Danh_Ba *p_new;

	if (tim_DB_co_TB_ten(ql->dau, tb.ten) != NULL)
	{
		return 0;
	}

	p = ql->cuoi;
	p_new = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));

	p_new->thue_bao = tb;
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

	return 1;
}

int them_TB_sau_ten(struct QLDB *ql, struct Thue_Bao tb, char *ten)
{
	int la_tb_cuoi;
	struct Danh_Ba *p_new;
	struct Danh_Ba *p = tim_DB_co_TB_ten(ql->dau, ten);

	if (p == NULL)
	{
		return 0;
	}


	la_tb_cuoi = p->lien_ket == NULL;
	p_new = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));
	p_new->thue_bao = tb;
	p_new->lien_ket = p->lien_ket;
	p->lien_ket = p_new;

	if (la_tb_cuoi)
	{
		ql->cuoi = p_new;
	}

	return 1;
}

struct Danh_Ba * tim_DB_co_TB_ten(struct Danh_Ba *dau, char *ten)
{
	struct Danh_Ba *p = dau;

	while (p != NULL)
	{
		if (strcmp(p->thue_bao.ten, ten) == 0)
		{
			return p;
		}

		p = p->lien_ket;
	}

	return NULL;
}

struct Thue_Bao * tim_TB_co_sdt(struct Danh_Ba *dau, char *sdt)
{
	int i;
	struct Danh_Ba *p = dau;
	
	while (p != NULL)
	{
		for (i = 0; i < p->thue_bao.so_sdt; i++)
		{
			if (strcmp(p->thue_bao.sdt[i], sdt) == 0)
			{
				return &p->thue_bao;
			}
		}
		
		p = p->lien_ket;
	}
	
	return NULL;
}

int dem_TB(struct Danh_Ba *dau)
{
	struct Danh_Ba *p = dau;
	int dem = 0;

	while (p != NULL)
	{
		dem++;
		p = p->lien_ket;
	}

	return dem;
}

int xoa_TB_ten(struct QLDB *ql, char *ten)
{
	struct Danh_Ba *p = ql->dau;
	struct Danh_Ba *tam;
	
	if (p == NULL)
	{
		return 0;
	}
	
	if (strcmp(p->thue_bao.ten, ten) == 0)
	{
		ql->dau = p->lien_ket;

		if (p->lien_ket == NULL)
		{
			ql->cuoi = NULL;
		}

		free(p);

		return 1;
	}

	while (p->lien_ket != NULL)
	{
		if (strcmp(p->lien_ket->thue_bao.ten, ten) == 0)
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

int them_sdt_vao_tb(struct Danh_Ba *dau, char *ten, char *sdt)
{
	int i;
	struct Danh_Ba *p = tim_DB_co_TB_ten(dau, ten);
	
	if (p != NULL && p->thue_bao.so_sdt < SO_SDT_TOI_DA)
	{
		strcpy(p->thue_bao.sdt[p->thue_bao.so_sdt], sdt);
		p->thue_bao.so_sdt++;
		
		return 1;
	}
	
	return 0;
}

int xoa_sdt(struct Danh_Ba *db, char *sdt)
{
	int i;
	struct Danh_Ba *p = db;
	
	while (p != NULL)
	{
		for (i = 0; i < p->thue_bao.so_sdt && strcmp(p->thue_bao.sdt[i], sdt) != 0; i++);
		
		if (i < p->thue_bao.so_sdt)
		{	
			for (i++; i < p->thue_bao.so_sdt; i++)
			{
				strcpy(p->thue_bao.sdt[i - 1], p->thue_bao.sdt[i]);
			}
			
			p->thue_bao.so_sdt--;
			
			return 1;
		}
		
		p = p->lien_ket;
	}
	
	return 0;
}

int la_sdt_Viettel(char *sdt)
{
	int dk1 = strstr(sdt, "09") == &sdt[0] && (sdt[2] == '8' || sdt[2] == '7');
	
	return dk1 || strstr(sdt, "0169") == &sdt[0];
}

int la_TB_Viettel(struct Thue_Bao tb)
{
	int i;
	
	for (i = 0; i < tb.so_sdt && !la_sdt_Viettel(tb.sdt[i]); i++);
	
	return i < tb.so_sdt;
}

void tao_DB_Viettel_tu_DB(struct Danh_Ba *dau, struct QLDB *ql_moi)
{
	struct Danh_Ba *p = dau;
	
	khoi_tao_QLDB(ql_moi);
	
	while (p != NULL)
	{
		if (la_TB_Viettel(p->thue_bao))
		{
			them_TB_cuoi_DB(ql_moi, p->thue_bao);
		}
		
		p = p->lien_ket;
	}
}