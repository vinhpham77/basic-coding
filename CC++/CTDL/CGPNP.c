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
struct Ngan_Xep
{
	struct CGPNP *cgp;
	int the_he;
	struct Ngan_Xep *lk;
};

void push(struct Ngan_Xep**, struct CGPNP*, int);
void pop(struct Ngan_Xep**);
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
void thay_nguoi(struct CGPNP**, char*, struct CGPNP*);
int la_anh_em(struct CGPNP*, char*, char*);
void in_theo_the_he(struct CGPNP*);
int la_giong_nhau(struct CGPNP*, struct CGPNP*);
int them_con(struct CGPNP*, char*, struct Nguoi);

int main()
{
	struct CGPNP *goc = NULL;
	struct CGPNP *th1, *th2, *th3, *th4, *th5;
	struct Nguoi *nguoi;
	char ho_ten[30];
	char ho_ten2[30];
	int nam_sinh;

	nguoi = tao_nguoi("Nguyen D", 1960);
	th1 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen B", 1930);
	th2 = tao_nut(*nguoi, NULL, th1);
	nguoi = tao_nguoi("Nguyen E", 1965);
	th3 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen F", 1970);
	th4 = tao_nut(*nguoi, NULL, NULL);
	nguoi = tao_nguoi("Nguyen C", 1935);
	th5 = tao_nut(*nguoi, th3, th4);
	nguoi = tao_nguoi("Nguyen A", 1900);
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
	strcpy(ho_ten2, "Nguyen D");
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

	return 0;
}

// a) In danh sách những người có trong cây
void in_truoc(struct CGPNP *goc)
{
	if (goc != NULL)
	{
		printf("%s  %d\n", goc->du_lieu.ho_ten, goc->du_lieu.nam_sinh);
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
	struct CGPNP *p = goc;
	struct Ngan_Xep *nx = NULL;
	int dem = 0;
	int n = 0;

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
				push(&nx, p->phai, n);
			}
			p = p->trai;
		}
		else
		{
			if(nx != NULL)
			{
				p = nx->cgp;
				n = nx->the_he;
				pop(&nx);
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

int la_con_chau(struct CGPNP *goc, char *ten_tien_boi, char *ten_hau_boi)
{
	struct Ngan_Xep *nx = NULL;
	struct CGPNP *p = goc;
	int th_hau_boi = 0;
	int th_tien_boi = 0;
	int n = 0;

	while (1)
	{
		n++;

		if (p == NULL)
		{
			if (nx == NULL)
			{
				break;
			}
			else
			{
				p = nx->cgp;
				n = nx->the_he;
				pop(&nx);
			}
		}

		if (th_tien_boi == 0 && strcmp(p->du_lieu.ho_ten, ten_tien_boi) == 0)
		{
			th_tien_boi = n;
		}
		else
		{
			if (th_hau_boi == 0 && strcmp(p->du_lieu.ho_ten, ten_hau_boi) == 0)
			{
				th_hau_boi = n;
			}
		}

		if (th_tien_boi != 0 && th_hau_boi != 0)
		{
			break;
		}

		if (p->phai != NULL)
		{
			push(&nx, p->phai, n + 1);
		}

		p = p->trai;
	}

	return th_hau_boi != 0 && th_tien_boi < th_hau_boi;
}

// i) Liệt kê tất cả con cháu của người tên x
void liet_ke_con_chau(struct CGPNP *goc, char *ten)
{
	struct Ngan_Xep *nx = NULL;
	struct CGPNP *p = goc;
	int n = 0;
	int th_tien_boi = 0;

	th_tien_boi = cho_biet_the_he(goc, ten);

	if (th_tien_boi == 0)
	{
		return;
	}

	while (1)
	{
		n++;

		if (p == NULL)
		{
			if (nx == NULL)
			{
				break;
			}
			else
			{
				p = nx->cgp;
				n = nx->the_he;
				pop(&nx);
			}
		}

		if (th_tien_boi < n)
		{
			printf("%s  %d\n", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);
		}

		if (p->phai != NULL)
		{
			push(&nx, p->phai, n + 1);
		}

		p = p->trai;
	}
}

// j) Thay người tên x bằng một người ng
void thay_nguoi(struct CGPNP **goc, char *ten, struct CGPNP *gp)
{
//	struct Ngan_Xep *nx = NULL;
//	struct CGPNP *p = goc;
//
//	while (1)
//	{
//		n++;
//
//		if (p == NULL)
//		{
//			if (nx == NULL)
//			{
//				break;
//			}
//			else
//			{
//				p = nx->cgp;
//				n = nx->the_he;
//				pop(&nx);
//			}
//		}
//
//		if (strcmp(p->du_lieu.ho_ten, ten) == 0)
//		{
//
//		}
//
//		if (p->phai != NULL)
//		{
//			push(&nx, p->phai, n + 1);
//		}
//
//		p = p->trai;
//	}
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

void in_theo_the_he(struct CGPNP *goc);
int la_giong_nhau(struct CGPNP *goc1, struct CGPNP *goc2)
{
//	struct Ngan_Xep *nx1 = NULL, *nx2 = NULL;
//	struct CGPNP *p = goc1, *q = goc2;
//	int n;
//
//		while (1)
//		{
//			n++;
//
//			if (p == NULL)
//			{
//				if (q != NULL)
//				{
//					return 0;
//				}
//
//				if (nx1 == NULL)
//				{
//					if (nx2)
//						break;
//				}
//				else
//				{
//					p = nx->cgp;
//					n = nx->the_he;
//					pop(&nx);
//				}
//			}
//
//			if (p->phai != NULL)
//			{
//
//
//				if (th_tien_boi < n)
//				{
//					printf("%s  %d\n", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);
//				}
//				push(&nx, p->phai, n + 1);
//			}
//
//			p = p->trai;
//		}
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

void push(struct Ngan_Xep **cuoi, struct CGPNP *cgp, int the_he)
{
	struct Ngan_Xep *p = (struct Ngan_Xep*) malloc(sizeof(struct Ngan_Xep));

	p->cgp = cgp;
	p->the_he = the_he;
	p->lk = *cuoi;
	*cuoi = p;
}

void pop(struct Ngan_Xep **cuoi)
{
	struct Ngan_Xep *p = *cuoi;

	*cuoi = p->lk;
	free(p);
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