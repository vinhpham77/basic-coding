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

void nhap_TB(struct Thue_Bao *);
void in_TB(struct Thue_Bao);
void khoi_tao_DB(struct Danh_Ba **);
void nhap_DB(struct Danh_Ba **);
void liet_ke_TB(struct Danh_Ba *);
void them_TB_dau_DB(struct Danh_Ba **, struct Thue_Bao);
void them_TB_cuoi_DB(struct Danh_Ba **, struct Thue_Bao);
int them_TB_sau_ten(struct Danh_Ba **, struct Thue_Bao, char *);
int dem_TB(struct Danh_Ba *);
int xoa_TB_ten(struct Danh_Ba **, char *);
struct Thue_Bao * tim_TB_co_sdt(struct Danh_Ba *, char *);
int them_sdt_vao_tb(struct Danh_Ba *, char *, char *);
int xoa_sdt(struct Danh_Ba *, char *);

int main()
{
	char ten[30];
	char sdt[11];
	struct Thue_Bao tb;
	struct Thue_Bao *p_tb;
	struct Danh_Ba *db;
	
	khoi_tao_DB(&db);
	
	nhap_DB(&db);
	liet_ke_TB(db);
	
//	nhap_TB(&tb);
//	them_TB_dau_DB(&db, tb);
//	liet_ke_TB(db);
//	
//	nhap_TB(&tb);
//	printf("\nNhap ten thue bao muon them sau do: ");
//	gets(ten);
//	printf("%d\n", them_TB_sau_ten(&db, tb, ten));
//	liet_ke_TB(db);
//
//	printf("\nSo luong thue bao: %d\n", dem_TB(db));
//
//	printf("\nNhap ten thue bao muon xoa: ");
//	gets(ten);
//	printf("%d\n", xoa_TB_ten(&db, ten));
//	liet_ke_TB(db);
//
//	printf("\nNhap sdt cua thue bao can tim: ");
//	gets(sdt);
//	p_tb = tim_TB_co_sdt(db, sdt);
//	if (p_tb == NULL)
//	{
//		printf("Khong co thue bao nao co sdt %s", sdt);
//	}
//	else
//	{
//		in_TB(*p_tb);
//	}
//
//	printf("\nNhap sdt can xoa: ");
//	gets(sdt);
//	printf("%d\n", xoa_sdt(db, sdt));
//	liet_ke_TB(db);
//	
//	printf("\nNhap ten thue bao can them sdt: ");
//	gets(ten);
//	printf("Nhap sdt can them: ");
//	gets(sdt);
//	printf("%d\n", them_sdt_vao_tb(db, ten, sdt));
//	liet_ke_TB(db);

	return 0;
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

void khoi_tao_DB(struct Danh_Ba **db)
{                               
	*db = NULL;
}

void nhap_DB(struct Danh_Ba **db)
{
	int n;
	int i;
	struct Thue_Bao *tb;
	
	printf("Nhap so luong thue bao: ");
	scanf("%d", &n);
	fflush(stdin);
	
	for	(i = 0; i < n; i++)
	{
		tb = (struct Thue_Bao *) malloc(sizeof(struct Thue_Bao));
		nhap_TB(tb);
		them_TB_cuoi_DB(db, *tb);
	}
}

void them_TB_dau_DB(struct Danh_Ba **db, struct Thue_Bao tb)
{
	struct Danh_Ba *q = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));
	
	q->thue_bao = tb;
	q->lien_ket = *db;
	*db = q;
}

void them_TB_cuoi_DB(struct Danh_Ba **db, struct Thue_Bao tb)
{
	struct Danh_Ba *p = *db;
	struct Danh_Ba *p_new = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));
	
	p_new->thue_bao = tb;
	p_new->lien_ket = NULL;
	
	while (p != NULL)
	{
		if (p->lien_ket == NULL)
		{
			p->lien_ket = p_new;
			
			return;
		}
		
		p = p->lien_ket;
	}
	
	*db = p_new;
}

int them_TB_sau_ten(struct Danh_Ba **db, struct Thue_Bao tb, char *ten)
{
	struct Danh_Ba *p = *db;
	struct Danh_Ba *q = (struct Danh_Ba *) malloc(sizeof(struct Danh_Ba));
	
	while (p != NULL)
	{
		if (strcmp(p->thue_bao.ten, ten) == 0)
		{
			q->thue_bao = tb;
			q->lien_ket = p->lien_ket;
			p->lien_ket = q;
			
			return 1;
		}
		
		p = p->lien_ket;
	}
	
	return 0;
}

void liet_ke_TB(struct Danh_Ba *db)
{
	struct Danh_Ba *p = db;
	
	while (p != NULL)
	{
		in_TB(p->thue_bao);
		printf("\n");
		p = p->lien_ket;
	}
}

int dem_TB(struct Danh_Ba *db)
{
	int dem = 0;
	struct Danh_Ba *p = db;
	
	while (p != NULL)
	{
		dem++;
		p = p->lien_ket;
	}
	
	return dem;
}

int xoa_TB_ten(struct Danh_Ba **db, char *ten)
{
	struct Danh_Ba *p = *db;
	struct Danh_Ba *tam;
	
	if (p == NULL)
	{
		return 0;
	}
	
	if (strcmp(p->thue_bao.ten, ten) == 0)
	{
		*db = p->lien_ket;
		free(p);
		
		return 1;
	}
	
	while (p->lien_ket != NULL)
	{
		if (strcmp(p->lien_ket->thue_bao.ten, ten) == 0)
		{
			tam = p->lien_ket;
			p->lien_ket = p->lien_ket->lien_ket;
			free(tam);
			
			return 1;
		}
		
		p = p->lien_ket;
	}
	
	return 0;
}

struct Thue_Bao * tim_TB_co_sdt(struct Danh_Ba *db, char *sdt)
{
	int i;
	struct Danh_Ba *p = db;
	
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

int them_sdt_vao_tb(struct Danh_Ba *db, char *ten, char *sdt)
{
	int i;
	struct Danh_Ba *p = db;
	
	while (p != NULL)
	{
		if (strcmp(p->thue_bao.ten, ten) == 0)
		{
			break;
		}
		
		p = p->lien_ket;
	}
	
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
