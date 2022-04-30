#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nguoi
{
	char ho_ten[40];
	int nam_sinh;
};
struct CGP
{
	struct Nguoi du_lieu;
	struct CGP *em, *con;
};
struct Queue
{
	struct CGP *cgp;
	struct Queue *lk;
};

struct CGP *tao_CGP();
void add(struct Queue**, struct Queue**, struct CGP*);
struct CGP *removee(struct Queue**, struct Queue**);
struct CGP *tao_nut(char*, int, struct CGP*, struct CGP*);
void in_theo_the_he(struct CGP*);
int dem(struct CGP*);
int tinh_so_the_he(struct CGP*);
struct CGP *tim(struct CGP*, char*);
int la_con(struct CGP*, char*, char*);
void them_con(struct CGP*, char*, struct Nguoi);
void liet_ke_con_chau(struct CGP*, char*);
void in_the_he(struct CGP*, int);
int tinh_bac(struct CGP*);
int xoa(struct CGP*, char*);
void xoa_cgp(struct CGP*);

int main()
{
	char ho_ten[40];
	char ho_ten2[40];
	struct CGP *goc = tao_CGP();
	struct CGP *p;
	struct Nguoi ng;
	int the_he;

	in_theo_the_he(goc);

	printf("\nSo nguoi trong cay gia pha: %d\n", dem(goc));

	printf("\nSo the he trong cay gia pha: %d\n", tinh_so_the_he(goc));

	strcpy(ho_ten, "Nguyen B");
	p = tim(goc, ho_ten);
	if (p == NULL)
	{
		printf("\nKhong tim thay %s trong cay gia pha\n", ho_ten);
	}
	else
	{
		printf("\nKet qua tim kiem: %s, %d\n", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);
	}

	strcpy(ho_ten, "Nguyen B");
	strcpy(ho_ten2, "Nguyen F");
	if (la_con(goc, ho_ten, ho_ten2))
	{
		printf("\n%s la cha cua %s trong cay gia pha\n", ho_ten, ho_ten2);
	}
	else
	{
		printf("\n%s khong phai la cha cua %s trong cay gia pha\n", ho_ten, ho_ten2);
	}

	strcpy(ng.ho_ten, "Nguyen Van Vinh");
	ng.nam_sinh = 1954;
	them_con(goc, "Nguyen B", ng);
	printf("\nSau khi them %s:\n", ng.ho_ten);
	in_theo_the_he(goc);

	strcpy(ho_ten, "Nguyen B");
	printf("\nCon chau cua %s: \n", ho_ten);
	liet_ke_con_chau(goc, ho_ten);

	the_he = 1;
	printf("\nNhung nguoi thuoc the he thu %d: \n", the_he);
	in_the_he(goc, the_he);

	printf("\nSo bac cua %s: %d\n", goc->con->du_lieu.ho_ten, tinh_bac(goc->con));

	strcpy(ho_ten, "Nguyen B");
	if (xoa(goc, ho_ten))
	{
		printf("\nXoa thanh cong!\n");
	}
	else
	{
		printf("\nKhong the xoa vi khong ton tai %s hoac %s la ong to\n", ho_ten, ho_ten);
	}
	in_theo_the_he(goc);
	return 0;
}

// 1. Tao cay gia pha nhu hinh.
struct CGP *tao_CGP()
{
	struct CGP *goc, *ng1, *ng2, *ng3, *ng4, *ng5, *ng6, *ng7;

	ng1 = tao_nut("Nguyen H", 1970, NULL, NULL);
	ng2 = tao_nut("Nguyen G", 1965, ng1, NULL);
	ng3 = tao_nut("Nguyen C", 1935, NULL, ng2);
	ng4 = tao_nut("Nguyen F", 1965, NULL, NULL);
	ng5 = tao_nut("Nguyen E", 1960, ng4, NULL);
	ng6 = tao_nut("Nguyen D", 1955, ng5, NULL);
	ng7 = tao_nut("Nguyen B", 1930, ng3, ng6);
	goc = tao_nut("Nguyen A", 1900, NULL, ng7);
}

// 2. In cay gia pha theo thu tu the he(dung thuat toan duyet theo chieu rong).
void in_theo_the_he(struct CGP *goc)
{
	struct CGP *p;
	struct Queue *dau, *cuoi;
	int lan_them_trc, lan_them_sau, lan_rut;

	if (goc == NULL)
	{
		return;
	}

	p = goc;
	dau = cuoi = NULL;
	lan_them_trc = 1;
	lan_them_sau = lan_rut = 0;

	do
	{
		printf("%s, %d | ", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);

		if (p->con != NULL)
		{
			add(&dau, &cuoi, p->con);
	  		lan_them_sau++;
		}

		p = p->em;

		if (p == NULL)
		{
			p = removee(&dau, &cuoi);
			lan_rut++;
			if (lan_them_trc == lan_rut)
			{
				printf("\n");
				lan_them_trc = lan_them_sau;
				lan_them_sau = lan_rut = 0;
			}

		}
	}
	while (dau != NULL || p != NULL);
}

// 3. Dem so nguoi co trong cay gia pha.
int dem(struct CGP *goc)
{
	int n;
	struct CGP *p;

	if (goc == NULL)
	{
		return 0;
	}
	else
	{
		n = 1;
		p = goc->con;

		while (p != NULL)
		{
			n += dem(p);
			p = p->em;
		}

		return n;
	}
}

// 4. Tinh so the he cua cay gia pha.
int tinh_so_the_he(struct CGP *goc)
{
	int max, n;
	struct CGP *p;

	if (goc == NULL)
	{
		return 0;
	}
	else
	{
		max = 0;
		p = goc->con;

		while (p != NULL)
		{
			n = tinh_so_the_he(p);
			if (max < n)
			{
				max = n;
			}
			p = p->em;
		}

		return max + 1;
	}
}

// 5. Tim xem mot nguoi co ho ten x co trong cay gia pha khong?
struct CGP *tim(struct CGP *goc, char *ho_ten)
{
	struct CGP *p;
	struct CGP *q;

	if (goc == NULL)
	{
		return NULL;
	}

	if (strcmp(goc->du_lieu.ho_ten, ho_ten) == 0)
	{
		return goc;
	}
	else
	{
		for (p = goc->con; p != NULL; p = p->em)
		{
			q = tim(p, ho_ten);
			if (q != NULL)
			{
				return q;
			}
		}

		return NULL;
	}
}

// 6. Kiem tra nguoi ten y co phai con nguoi ten x trong cay gia pha khong?
int la_con(struct CGP *goc, char *ht_x, char *ht_y)
{
	struct CGP *p = tim(goc, ht_x);
	struct CGP *q;

	for (q = p->con; q != NULL; q = q->em)
	{
		if (strcmp(q->du_lieu.ho_ten, ht_y) == 0)
		{
			return 1;
		}
	}

	return 0;
}

// 7. Them nguoi q vao con cua nguoi ten x trong cay.
//    Biet rang cac nut con cua mot nguoi duoc sap xep theo thu tu tang. cua nam sinh.
void them_con(struct CGP *goc, char *ho_ten, struct Nguoi nguoi)
{
	struct CGP *p = tim(goc, ho_ten);
	struct CGP *q;
	struct CGP *l;
	struct CGP *tmp;

	if (p == NULL || p->du_lieu.nam_sinh >= nguoi.nam_sinh)
	{
		return;
	}

	q = tao_nut(nguoi.ho_ten, nguoi.nam_sinh, NULL, NULL);
	l = p->con;
	tmp = NULL;

	while (l != NULL)
	{
		if (l->du_lieu.nam_sinh >= nguoi.nam_sinh)
		{
			break;
		}
		else
		{
			tmp = l;
			l = l->em;
		}
	}

	if (tmp == NULL)
	{
		p->con = q;
		q->em = l;
	}
	else
	{
		tmp->em = q;
		q->em = l;
	}
}

// VE NHA
// 1. Liet ke con, chau cua mot nguoi co ho ten x.
void liet_ke_con_chau(struct CGP *goc, char *ho_ten)
{
	struct CGP *p = tim(goc, ho_ten);

	if (p != NULL)
	{
		in_theo_the_he(p->con);
	}
}

// 2. In nhung nguoi thuoc the he thu k.
void in_the_he(struct CGP *goc, int the_he)
{
	struct CGP *p;

	if (goc != NULL)
	{
		if (the_he > 1)
		{
			for (p = goc->con; p != NULL; p = p->em)
			{
				in_the_he(p, the_he - 1);
			}
		}
		else if (the_he == 1)
		{
			printf("%s, %d\n", goc->du_lieu.ho_ten, goc->du_lieu.nam_sinh);
		}
	}
}

// 3. Tinh bac cua cay.
int tinh_bac(struct CGP *goc)
{
	int bac = 0;
	struct CGP *p;

	for (p = goc->con; p != NULL ; p = p->em, bac++)
		;

	return bac;
}

// 4. Xoa mot nguoi tren cay co ten x(x khong phai ong to cua dong ho).
int xoa(struct CGP *goc, char *ho_ten)
{
	struct CGP *p;
	struct CGP *tmp;
	struct CGP *q;

	if (goc == NULL)
	{
		return 0;
	}

	tmp = goc;
	p = goc->con;

	while (p != NULL)
	{
		if (strcmp(p->du_lieu.ho_ten, ho_ten) == 0)
		{
			break;
		}
		else
		{
			if (xoa(p, ho_ten))
			{
				return 1;
			}

			tmp = p;
			p = p->em;
		}
	}

	if (p == NULL)
	{
		return 0;
	}
	else if (tmp == goc)
	{
		goc->con = p->em;
	}
	else
	{
		tmp->em = p->em;
	}

	xoa_cgp(p);
	return 1;
}


struct CGP *tao_nut(char *ho_ten, int nam_sinh, struct CGP *em, struct CGP *con)
{
	struct CGP *p = (struct CGP*) malloc(sizeof(struct CGP));

	strcpy(p->du_lieu.ho_ten, ho_ten);
	p->du_lieu.nam_sinh = nam_sinh;
	p->em = em;
	p->con = con;

	return p;
}

void add(struct Queue **dau, struct Queue **cuoi, struct CGP *cgp)
{
	struct Queue *p;
	struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));

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

struct CGP *removee(struct Queue **dau, struct Queue **cuoi)
{
	struct Queue *p;
	struct CGP *q;

	if (*dau == NULL)
	{
		return NULL;
	}
	else
	{
		p = *dau;
		q = p->cgp;

		if (*dau == *cuoi)
		{
			*dau = *cuoi = NULL;
		}
		else
		{
			*dau = p->lk;
		}

		free(p);
		return q;
	}
}

void xoa_cgp(struct CGP *goc)
{
	struct CGP *p;
	struct CGP *q;
	struct Queue *dau, *cuoi;

	if (goc == NULL)
	{
		return;
	}

	p = goc->con;
	dau = cuoi = NULL;

	while (dau != NULL || p != NULL)
	{
		if (p->con != NULL)
		{
			add(&dau, &cuoi, p->con);
		}

		q = p;
		free(q);
		p = p->em;

		if (p == NULL)
		{
			p = removee(&dau, &cuoi);
		}
	}

	free(goc);
}
