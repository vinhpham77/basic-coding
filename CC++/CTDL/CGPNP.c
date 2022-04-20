#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
struct NXCGP
{
	struct CGPNP *cgp;
	struct NXCGP *lk;
};
struct NXTH
{
	int the_he;
	struct NXTH *lk;
};
struct HDCGP
{
	struct CGPNP *cgp;
	struct HDCGP *lk;
};

void push_nxcgp(struct NXCGP**, struct CGPNP*);
struct CGPNP *pop_nxcgp(struct NXCGP**);
void push_nxth(struct NXTH**, int the_he);
int pop_nxth(struct NXTH**);
void add_hdcgp(struct HDCGP**, struct HDCGP**, struct CGPNP*);
struct CGPNP *remove_hdcgp(struct HDCGP**, struct HDCGP**);
struct Nguoi *tao_nguoi(char*, int);
struct CGPNP *tao_nut(struct Nguoi, struct CGPNP*, struct CGPNP*);
void in_truoc(struct CGPNP*);
int dem_nguoi(struct CGPNP*);
int tinh_so_the_he(struct CGPNP*);
int dem_so_nguoi_sinh_truoc(struct CGPNP*, int);
struct Nguoi *tim_nguoi(struct CGPNP*, char*);
struct CGPNP *tim_gia_pha(struct CGPNP*, char*);
int cho_biet_the_he(struct CGPNP*, char*);
int la_con(struct CGPNP*, char*, char*);
int la_con_chau(struct CGPNP*, char*, char*);
void liet_ke_con_chau(struct CGPNP*, char*);
int thay_nguoi(struct CGPNP*, char*, struct Nguoi);
int la_anh_em(struct CGPNP*, char*, char*);
void in_theo_the_he(struct CGPNP*);
int la_cgp_giong_nhau(struct CGPNP*, struct CGPNP*);
int la_nguoi_giong_nhau(struct Nguoi, struct Nguoi);
int them_con(struct CGPNP*, char*, struct Nguoi);

			int laCTKNP(struct CGPNP *t)
			{
				if (t == NULL)
				{
					return 1;
				}
				else if (t->trai == NULL || t->trai->du_lieu < t->du_lieu && (t->phai == NULL || t->du_lieu > t->phai->du_lieu))
				{
					return laCTKNP(t->trai) && laCTKNP(t->phai);
				}
				
				return 0;
			}
int main()
{
	struct CGPNP *goc = NULL, *goc2 = NULL;
	struct CGPNP *ng1, *ng2, *ng3, *ng4, *ng5;
	struct CGPNP *ng6, *ng7, *ng8, *ng9, *ng10, *ng11;
	struct Nguoi *nguoi;
	char ho_ten[30];
	char ho_ten2[30];
	int nam_sinh;

	nguoi = tao_nguoi("Nguyen D", 1960);
	ng1 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen B", 1930);
	ng2 = tao_nut(*nguoi, NULL, ng1);
	nguoi = tao_nguoi("Nguyen E", 1965);
	ng3 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen F", 1970);
	ng4 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen C", 1935);
	ng5 = tao_nut(*nguoi, ng3, ng4);
	nguoi = tao_nguoi("Nguyen A", 1900);
	goc = tao_nut(*nguoi, ng2, ng5);

	printf("In truoc goc\n");
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
		printf("\nKet qua tim kiem: %s\t%d\n", nguoi->ho_ten, nguoi->nam_sinh);
	}

	strcpy(ho_ten, "Nguyen C");
	printf("\n%s thuoc the he thu: %d\n", ho_ten, cho_biet_the_he(goc, ho_ten));

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
	strcpy(ho_ten2, "Nguyen C");
	if (la_con_chau(goc, ho_ten, ho_ten2))
	{
		printf("\n%s la con chau cua %s\n", ho_ten2, ho_ten);
	}
	else
	{
		printf("\n%s khong phai la con chau cua %s\n", ho_ten2, ho_ten);
	}

	strcpy(ho_ten, "Nguyen E");
	strcpy(ho_ten2, "Nguyen F");
	if (la_anh_em(goc, ho_ten, ho_ten2))
	{
		printf("\n%s la anh em voi %s\n", ho_ten, ho_ten2);
	}
	else
	{
		printf("\n%s khong phai la anh em voi %s\n", ho_ten, ho_ten2);
	}

	strcpy(ho_ten, "Nguyen C");
	printf("\nDanh sach con chau cua %s\n", ho_ten);
	liet_ke_con_chau(goc, ho_ten);

	strcpy(ho_ten, "Nguyen C");
	nguoi = tao_nguoi("Nguyen Thay", 1960);
	if (thay_nguoi(goc, ho_ten, *nguoi))
	{
		printf("\nThay %s bang %s, %d thanh cong!\n", ho_ten, nguoi->ho_ten, nguoi->nam_sinh);
	}
	else
	{
		printf("\nThay %s bang %s, %d that bai!\n", ho_ten, nguoi->ho_ten, nguoi->nam_sinh);
	}
//	in_truoc(goc);

	strcpy(ho_ten, "Nguyen D");
	nguoi = tao_nguoi("Nguyen Con", 2002);
	if (them_con(goc, ho_ten, *nguoi))
	{
		printf("\nThem thanh cong, %s la con cua %s\n", nguoi->ho_ten, ho_ten);
	}
	else
	{
		printf("\nThem that bai, %s da du 2 con\n", ho_ten);
	}
//	in_truoc(goc);

	printf("\nIn theo the he\n");
	in_theo_the_he(goc);

	nguoi = tao_nguoi("Nguyen Con", 2002);
	ng6 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen D", 1960);
	ng7 = tao_nut(*nguoi, NULL, ng6);
	nguoi = tao_nguoi("Nguyen B", 1930);
	ng8 = tao_nut(*nguoi, ng7, NULL);
	nguoi = tao_nguoi("Nguyen E", 1965);
	ng9 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen F", 1970);
	ng10 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen Thay", 1960);
	ng11 = tao_nut(*nguoi, ng10, ng9);
	nguoi = tao_nguoi("Nguyen A", 1900);
	goc2 = tao_nut(*nguoi, ng11, ng8);
	printf("\nIn truoc goc\n");
	in_truoc(goc);
	printf("In truoc goc2\n");
	in_truoc(goc2);
	if (la_cgp_giong_nhau(goc, goc2))
	{
		printf("La hai cgp giong nhau\n");
	}
	else
	{
		printf("La hai cgp khac nhau\n");
	}

	return 0;
}

// a) In danh sách những người có trong cây
void in_truoc(struct CGPNP *goc)
{
	if (goc != NULL)
	{
		printf("%s\t%d\n", goc->du_lieu.ho_ten, goc->du_lieu.nam_sinh);
		in_truoc(goc->trai);
		in_truoc(goc->phai);
	}
}

// b) Đếm số người trong cây
int dem_nguoi(struct CGPNP *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return 1 + dem_nguoi(goc->trai) + dem_nguoi(goc->phai);
}

// c) Tính số thế hệ của cây
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

// d) Đếm số người sinh trước năm x
int dem_so_nguoi_sinh_truoc(struct CGPNP *goc, int nam_sinh)
{
	if (goc == NULL || goc->du_lieu.nam_sinh >= nam_sinh)
	{
		return 0;
	}

	return 1 + dem_so_nguoi_sinh_truoc(goc->trai, nam_sinh) + dem_so_nguoi_sinh_truoc(goc->phai, nam_sinh);
}

// e) Tìm một người trong cây khi biết họ tên
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

// f) Cho biết người tên x thuộc thế hệ thứ mấy trong cây
int cho_biet_the_he(struct CGPNP *goc, char *ten)
{
	int n = 0;
	int dem = 0;
	struct CGPNP *p = goc;
	struct NXTH *nxth = NULL;
	struct NXCGP *nxcgp = NULL;

	while (1)
	{
		n++;
		if (p != NULL)
		{
			if (strcmp(p->du_lieu.ho_ten, ten) == 0)
			{
				dem = n;
				break;
			}
			if (p->phai != NULL)
			{
				push_nxcgp(&nxcgp, p->phai);
				push_nxth(&nxth, n);
			}
			p = p->trai;
		}
		else
		{
			if(nxcgp != NULL)
			{
				p = pop_nxcgp(&nxcgp);
				n = pop_nxth(&nxth);
			}
			else
			{
				break;
			}
		}
	}

	return dem;
}

// g) Kiểm tra người tên y có phải con của người tên x không
int la_con(struct CGPNP *goc, char *ten_phu_huynh, char *ten_con)
{
	struct CGPNP *p = tim_gia_pha(goc, ten_phu_huynh);

	if (p == NULL)
	{
		return 0;
	}

	return p->trai != NULL && strcmp(p->trai->du_lieu.ho_ten, ten_con) == 0 || (p->phai != NULL && strcmp(p->phai->du_lieu.ho_ten, ten_con) == 0);
}

// h) Kiểm tra người tên y có phải con cháu của người tên x không
int la_con_chau(struct CGPNP *goc, char *ten_tien_boi, char *ten_hau_boi)
{
	struct CGPNP *p = tim_gia_pha(goc, ten_tien_boi);
	struct Nguoi *nguoi = tim_nguoi(p, ten_hau_boi);

	return nguoi != NULL && !la_nguoi_giong_nhau(p->du_lieu, *nguoi);
}

// i) Liệt kê tất cả con cháu của người tên x
void liet_ke_con_chau(struct CGPNP *goc, char *ten)
{
	struct CGPNP *p = tim_gia_pha(goc, ten);
	in_truoc(p->trai);
	in_truoc(p->phai);
}

// j) Thay người tên x bằng một người ng sao cho gia phả vẫn đúng logic cha lớn tuổi hơn con
int thay_nguoi(struct CGPNP *goc, char *ten, struct Nguoi nguoi)
{
	int nam_sinh;
	struct CGPNP *p;
	struct CGPNP *q;
	struct NXCGP *nxcgp;

	if (goc == NULL)
	{
		return 0;
	}

	p = goc;
	q = NULL;
	nxcgp = NULL;
	nam_sinh = INT_MAX;

	while (1)
	{
		if (p == NULL)
		{
			if (nxcgp == NULL)
			{
				return 0;
			}
			else
			{
				q = pop_nxcgp(&nxcgp);
				p = nxcgp->cgp->phai;
			}
		}

		if (strcmp(p->du_lieu.ho_ten, ten) == 0)
		{
			break;
		}

		if (p->phai != NULL)
		{
			push_nxcgp(&nxcgp, p);
		}

		q = p;
		p = p->trai;
	}

	if (p->trai != NULL && p->trai->du_lieu.nam_sinh < nam_sinh)
	{
		nam_sinh = p->trai->du_lieu.nam_sinh;
	}

	if (p->phai != NULL && p->phai->du_lieu.nam_sinh < nam_sinh)
	{
		nam_sinh = p->phai->du_lieu.nam_sinh;
	}

	if ((q == NULL || q->du_lieu.nam_sinh < nguoi.nam_sinh) && nguoi.nam_sinh < nam_sinh)
	{
		p->du_lieu = nguoi;

		return 1;
	}

	return 0;
}

// k) Kiểm tra hai người tên x, y có phải là anh em không
int la_anh_em(struct CGPNP *goc, char *ten1, char *ten2)
{
	if (goc == NULL || goc->trai == NULL || goc->phai == NULL)
	{
		return 0;
	}

	if (strcmp(goc->trai->du_lieu.ho_ten, ten1) == 0)
	{
		return strcmp(goc->phai->du_lieu.ho_ten, ten2) == 0;
	}

	if (strcmp(goc->trai->du_lieu.ho_ten, ten2) == 0)
	{
		return strcmp(goc->phai->du_lieu.ho_ten, ten1) == 0;
	}

	return la_anh_em(goc->trai, ten1, ten2) || la_anh_em(goc->phai, ten1, ten2);
}

// l) In cây theo từng thế hệ
void in_theo_the_he(struct CGPNP *goc)
{
	struct HDCGP *dau = NULL;
	struct HDCGP *cuoi = NULL;
	struct CGPNP *p = goc;

	while (p != NULL)
	{
		printf("%s\t%d\n", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);

		if (p->trai != NULL)
		{
			add_hdcgp(&dau, &cuoi, p->trai);
		}

		if (p->phai != NULL)
		{
			add_hdcgp(&dau, &cuoi, p->phai);
		}

		p = remove_hdcgp(&dau, &cuoi);
	}
}

// m) Kiểm tra hai cây gia phả có giống nhau không(không xét thứ tự)
int la_cgp_giong_nhau(struct CGPNP *goc1, struct CGPNP *goc2)
{
	int a, b, c, d;
	struct CGPNP *p = goc1, *q = goc2;
	struct HDCGP *hd1d = NULL, *hd1c = NULL;

	if (goc1 == NULL && goc2 == NULL)
	{
		return 1;
	}
	if (goc1 != NULL && goc2 != NULL)
	{
		if (!la_nguoi_giong_nhau(p->du_lieu, q->du_lieu))
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	while (1)
	{
		a = p->trai != NULL && q->trai != NULL && la_nguoi_giong_nhau(p->trai->du_lieu, q->trai->du_lieu);
		b = p->phai != NULL && q->phai != NULL && la_nguoi_giong_nhau(p->phai->du_lieu, q->phai->du_lieu);
		c = p->trai != NULL && q->phai != NULL && la_nguoi_giong_nhau(p->trai->du_lieu, q->phai->du_lieu);
		d = p->phai != NULL && q->trai != NULL && la_nguoi_giong_nhau(p->phai->du_lieu, q->trai->du_lieu);

		if (a && p->phai == NULL && q->phai == NULL)
		{
			add_hdcgp(&hd1d, &hd1c, p->trai);
			add_hdcgp(&hd1d, &hd1c, q->trai);
		}
		else if (b && p->trai == NULL && q->trai == NULL)
		{
			add_hdcgp(&hd1d, &hd1c, p->phai);
			add_hdcgp(&hd1d, &hd1c, q->phai);
		}
		else if (c && p->phai == NULL && q->trai == NULL)
		{
			add_hdcgp(&hd1d, &hd1c, p->trai);
			add_hdcgp(&hd1d, &hd1c, q->phai);
		}
		else if (d && p->trai == NULL && q->phai == NULL)
		{
			add_hdcgp(&hd1d, &hd1c, p->phai);
			add_hdcgp(&hd1d, &hd1c, q->trai);
		}
		else if (a && b)
		{
			add_hdcgp(&hd1d, &hd1c, p->trai);
			add_hdcgp(&hd1d, &hd1c, q->trai);
			add_hdcgp(&hd1d, &hd1c, p->phai);
			add_hdcgp(&hd1d, &hd1c, q->phai);
		}
		else if (c && d)
		{
			add_hdcgp(&hd1d, &hd1c, p->trai);
			add_hdcgp(&hd1d, &hd1c, q->phai);
			add_hdcgp(&hd1d, &hd1c, p->phai);
			add_hdcgp(&hd1d, &hd1c, q->trai);
		}
		else
		{
			return p->trai == NULL && p->phai == NULL && q->trai == NULL && q->phai == NULL;
		}

		p = remove_hdcgp(&hd1d, &hd1c);
		q = remove_hdcgp(&hd1d, &hd1c);
	}
}

//	n) Thêm người ng vào con của người tên x. Nếu người tên x đã đủ 2 con thì không thêm
int	them_con(struct CGPNP *goc, char *ten_phu_huynh, struct Nguoi con)
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

struct Nguoi *tao_nguoi(char *ten, int nam_sinh)
{
	struct Nguoi *nguoi = (struct Nguoi*) malloc(sizeof(struct Nguoi));

	strcpy(nguoi->ho_ten, ten);
	nguoi->nam_sinh = nam_sinh;

	return nguoi;
}

struct CGPNP *tao_nut(struct Nguoi nguoi, struct CGPNP *trai, struct CGPNP *phai)
{
	struct CGPNP *nut = (struct CGPNP*) malloc(sizeof(struct CGPNP));

	nut->du_lieu = nguoi;
	nut->trai = trai;
	nut->phai = phai;

	return nut;
}

void push_nxcgp(struct NXCGP **dau, struct CGPNP *cgp)
{
	struct NXCGP *p = (struct NXCGP*) malloc(sizeof(struct NXCGP));

	p->cgp = cgp;
	p->lk = *dau;
	*dau = p;
}

struct CGPNP *pop_nxcgp(struct NXCGP **cuoi)
{
	struct NXCGP *p;
	struct CGPNP *q = NULL;
	\
	if (*cuoi != NULL)
	{
		p = *cuoi;
		q = p->cgp;
		*cuoi = p->lk;
		free(p);
	}

	return q;
}

void push_nxth(struct NXTH **cuoi, int the_he)
{
	struct NXTH *p = (struct NXTH*) malloc(sizeof(struct NXTH));

	p->the_he = the_he;
	p->lk = *cuoi;
	*cuoi = p;
}

int pop_nxth(struct NXTH **cuoi)
{
	struct NXTH *p;
	int the_he = 0;

	if (*cuoi != NULL)
	{
		p = *cuoi;
		the_he = p->the_he;
		*cuoi = p->lk;
		free(p);
	}

	return the_he;
}

void add_hdcgp(struct HDCGP **dau, struct HDCGP **cuoi, struct CGPNP *cgp)
{
	struct HDCGP *p;
	struct HDCGP *q = (struct HDCGP*) malloc(sizeof(struct HDCGP));

	q->cgp = cgp;
	q->lk = NULL;

	if (*dau == NULL)
	{
		*dau = *cuoi = q;
	}
	else
	{
		p = *cuoi;
		p->lk = q;
		*cuoi = q;
	}
}

struct CGPNP *remove_hdcgp(struct HDCGP **dau, struct HDCGP **cuoi)
{
	struct HDCGP *p;
	struct CGPNP *q = NULL;

	if (*dau != NULL)
	{
		p = *dau;
		q = p->cgp;

		if (*dau == *cuoi)
		{
			free(*dau);
			*dau = *cuoi = NULL;
		}
		else
		{
			*dau = p->lk;
			free(p);
		}
	}

	return q;
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

int la_nguoi_giong_nhau(struct Nguoi nguoi1, struct Nguoi nguoi2)
{
	return strcmp(nguoi1.ho_ten, nguoi2.ho_ten) == 0 && nguoi1.nam_sinh == nguoi2.nam_sinh;
}