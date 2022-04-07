#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Nguoi
{
	char ho_ten[30];
	int nam_sinh;
};
struct CGPNP
{
	struct Nguoi du_lieu;
	struct CGPNP *trai, *phai;
};

void tao_nguoi(struct Nguoi*, char*, int);
struct CGPNP *tao_nut(struct Nguoi, struct CGPNP*, struct CGPNP*);
void in_truoc(struct CGPNP*);
int dem_nguoi(struct CGPNP*);
int tinh_so_the_he(struct CGPNP*);
int dem_so_nguoi_sinh_truoc(struct CGPNP*, int);
struct Nguoi *tim_nguoi(struct CGPNP*, char*);
struct CGPNP *tim_phu_huynh(struct CGPNP*, char*);
struct CGPNP *tim_gia_pha(struct CGPNP*, char*);
int cho_biet_the_he(struct CGPNP*, char*);
int la_con(struct CGPNP*, char*, char*);
int la_con_chau(struct CGPNP*, char*, char*);
void liet_ke_con_chau(struct CGPNP*, char*);
void thay_nguoi(struct CGPNP**, char*, struct CGPNP*);
int la_anh_em(struct CGPNP*, char*, char*);
void in_theo_the_he(struct CGPNP*);
int la_giong_nhau(struct CGPNP*, struct CGPNP*);
int them_con(struct CGPNP*, char*, struct Nguoi);

int main()
{
	struct CGPNP *goc = NULL;
	struct CGPNP *th1, *th2, *th3, *th4, *th5;
	struct Nguoi *nguoi = (struct Nguoi*) malloc(sizeof(struct Nguoi));
	char ho_ten[30];
	char ho_ten2[30];
	int nam_sinh;

	tao_nguoi(nguoi, "Nguyen D", 1960);
	th1 = tao_nut(*nguoi, NULL, NULL);
	tao_nguoi(nguoi, "Nguyen B", 1930);
	th2 = tao_nut(*nguoi, NULL, th1);
	tao_nguoi(nguoi, "Nguyen E", 1965);
	th3 = tao_nut(*nguoi, NULL, NULL);
	tao_nguoi(nguoi, "Nguyen F", 1970);
	th4 = tao_nut(*nguoi, NULL, NULL);
	tao_nguoi(nguoi, "Nguyen C", 1935);
	th5 = tao_nut(*nguoi, th3, th4);
	tao_nguoi(nguoi, "Nguyen A", 1900);
	goc = tao_nut(*nguoi, th2, th5);

	in_truoc(goc);

	printf("\nSo nguoi trong gia pha: %d\n", dem_nguoi(goc));

	printf("\nSo the he cua gia pha: %d\n", tinh_so_the_he(goc));

	nam_sinh = 1945;
	printf("\nSo nguoi sinh truoc nam %d: %d\n", nam_sinh, dem_so_nguoi_sinh_truoc(goc, nam_sinh));

	strcpy(ho_ten, "Nguyen C");
	nguoi = tim_nguoi(goc, ho_ten);
	if (nguoi == NULL)
	{
		printf("\nKhong tim thay %s\n", ho_ten);
	}
	else
	{
		printf("\nKet qua tim kiem: %s  %d\n", nguoi->ho_ten, nguoi->nam_sinh);
	}

	strcpy(ho_ten, "Nguyen C");
	strcpy(ho_ten2, "Nguyen E");
	if (la_con(goc, ho_ten, ho_ten2))
	{
		printf("\n%s la con cua %s\n", ho_ten2, ho_ten);
	}
	else
	{
		printf("\n%s khong phai la con cua %s\n", ho_ten2, ho_ten);
	}

	strcpy(ho_ten, "Nguyen C");
	strcpy(ho_ten2, "Nguyen E");
	if (la_con_chau(goc, ho_ten, ho_ten2))
	{
		printf("\n%s la con chau cua %s\n", ho_ten2, ho_ten);
	}
	else
	{
		printf("\n%s khong phai la con chau cua %s\n", ho_ten2, ho_ten);
	}
	
	return 0;
}

void tao_nguoi(struct Nguoi *nguoi, char *ten, int nam_sinh)
{
	strcpy(nguoi->ho_ten, ten);
	nguoi->nam_sinh = nam_sinh;
}

struct CGPNP *tao_nut(struct Nguoi nguoi, struct CGPNP *trai, struct CGPNP *phai)
{
	struct CGPNP *nut = (struct CGPNP*) malloc(sizeof(struct CGPNP));

	nut->du_lieu = nguoi;
	nut->trai = trai;
	nut->phai = phai;

	return nut;
}

void in_truoc(struct CGPNP *goc)
{
	if (goc != NULL)
	{
		printf("%s  %d\n", goc->du_lieu.ho_ten, goc->du_lieu.nam_sinh);
		in_truoc(goc->trai);
		in_truoc(goc->phai);
	}
}

int dem_nguoi(struct CGPNP *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return 1 + dem_nguoi(goc->trai) + dem_nguoi(goc->phai);
}

int tinh_so_the_he(struct CGPNP *goc)
{
	int the_he_trai, the_he_phai;

	if (goc == NULL)
	{
		return 0;
	}

	the_he_trai = tinh_so_the_he(goc->trai);
	the_he_phai = tinh_so_the_he(goc->phai);

	if (the_he_trai >= the_he_phai)
	{
		return the_he_trai + 1;
	}
	else
	{
		return the_he_phai + 1;
	}
}

int dem_so_nguoi_sinh_truoc(struct CGPNP *goc, int nam_sinh)
{
	if (goc == NULL || goc->du_lieu.nam_sinh >= nam_sinh)
	{
		return 0;
	}
	else
	{
		return 1 + dem_so_nguoi_sinh_truoc(goc->trai, nam_sinh) + dem_so_nguoi_sinh_truoc(goc->phai, nam_sinh);
	}
}

struct Nguoi *tim_nguoi(struct CGPNP *goc, char *ten)
{
	struct Nguoi *nguoi;

	if (goc == NULL)
	{
		return NULL;
	}

	if (strcmp(goc->du_lieu.ho_ten, ten) == 0)
	{
		return &goc->du_lieu;
	}

	nguoi = tim_nguoi(goc->trai, ten);
	return nguoi != NULL ? nguoi : tim_nguoi(goc->phai, ten);
}

struct CGPNP *tim_gia_pha(struct CGPNP *goc, char *ten)
{
	struct CGPNP *gia_pha;

	if (goc == NULL)
	{
		return NULL;
	}

	if (strcmp(goc->du_lieu.ho_ten, ten) == 0)
	{
		return goc;
	}

	gia_pha = tim_gia_pha(goc->trai, ten);
	return gia_pha != NULL ? gia_pha : tim_gia_pha(goc->phai, ten);
}

struct CGPNP *tim_phu_huynh(struct CGPNP *goc, char *ten)
{
	struct CGPNP *p;

	if (goc == NULL)
	{
		return NULL;
	}

	if (goc->trai != NULL && strcmp(goc->trai->du_lieu.ho_ten, ten) == 0)
	{
		return goc;
	}

	if (goc->phai != NULL && strcmp(goc->phai->du_lieu.ho_ten, ten) == 0)
	{
		return goc;
	}

	p = tim_phu_huynh(goc->trai, ten);
	return p != NULL ? p : tim_phu_huynh(goc->phai, ten);
}

int cho_biet_the_he(struct CGPNP *goc, char *ten)
{
	struct CGPNP *p, *q;

	if (goc == NULL)
	{
		return 0;
	}

	p = goc->trai;
	q = goc->phai;

	return 0;
}

int la_con(struct CGPNP *goc, char *ten_phu_huynh, char *ten_con)
{
	struct CGPNP *p = tim_gia_pha(goc, ten_phu_huynh);

	if (p == NULL)
	{
		return 0;
	}

	return p->trai != NULL && strcmp(p->trai->du_lieu.ho_ten, ten_con) == 0 || (p->phai && strcmp(p->phai->du_lieu.ho_ten, ten_con) == 0);
}

int la_con_chau(struct CGPNP *goc, char *ten_tien_boi, char *ten_hau_boi)
{
//	struct CGPNP *p = tim_phu_huynh(goc, ten_tien_boi);
//	struct Nguoi *nguoi;
//	
//	if (p == NULL)
//	{
//		return 0;
//	}
//
//	nguoi = tim_nguoi(p->trai, ten_hau_boi);
//	if (nguoi == NULL || nguoi == &p->trai->du_lieu)
//	{
//		nguoi = tim_nguoi(p->phai, ten_hau_boi);
//		return nguoi != NULL && nguoi != &p->phai;
//	}
//	return nguoi != NULL && nguoi != &p->trai->du_lieu && nguoi != &p->phai->du_lieu;
	struct CGPNP *ngan_xep[100];
	int n;
	struct CGPNP *p;
	struct CGPNP *q;
	
	if (strcmp(goc->du_lieu.ho_ten, ten_tien_boi) == 0)
	{
		return tim_nguoi(goc->trai, ten_hau_boi) != NULL ? 1 : tim_nguoi(goc->phai, ten_hau_boi) != NULL;
	}
	
	n = -1;
	p = goc;
	q = NULL;
	
	do
	{
		if (p->phai != NULL)
		{
			ngan_xep[++n] = p->phai;
		}
		
		q = p;
		p = p->trai;
		
		if (p == NULL)
		{
			p = ngan_xep[n--];
		}
		else
		{
		
		}
		if (p != NULL && strcmp(p->du_lieu.ho_ten, ten_tien_boi) == 0)
		{
			break;
		}
	}
	while (p != NULL || n > -1);
	
}

void liet_ke_con_chau(struct CGPNP *goc, char *ten);
void thay_nguoi(struct CGPNP **goc, char *ten_bi_thay, struct CGPNP *gia_pha_thay);
int la_anh_em(struct CGPNP *goc, char *ten_1, char *ten_2);
void in_theo_the_he(struct CGPNP *goc);
int la_giong_nhau(struct CGPNP *goc_1, struct CGPNP *goc_2);

int them_con(struct CGPNP *goc, char *ten_phu_huynh, struct Nguoi con)
{
	struct CGPNP *p = tim_gia_pha(goc, ten_phu_huynh);

	if (p != NULL)
	{
		if (p->trai == NULL)
		{
			p->trai = tao_nut(con, NULL, NULL);
			return 1;
		}

		if (p->trai == NULL)
		{
			p->phai = tao_nut(con, NULL, NULL);
			return 1;
		}
	}

	return 0;
}
