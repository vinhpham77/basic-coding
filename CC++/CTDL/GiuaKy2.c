#include <stdio.h>
#include <stdlib.h>

struct DSSN
{
	int soNguyen;
	struct DSSN *lk;
};

void them_dau(struct DSSN**, int);
void in_DS(struct DSSN*);
long tinh_tong(struct DSSN*);
void sapXepGiam(struct DSSN*);
void xoa(struct DSSN**, int);
void tim_hai_so_tong_bang(struct DSSN*, long);

int main()
{
	struct DSSN *ds = NULL;
	
	them_dau(&ds, 3);
	them_dau(&ds, 4);
	them_dau(&ds, 2);
	them_dau(&ds, 1);
	them_dau(&ds, 7);
	them_dau(&ds, 2);
	them_dau(&ds, 5);
	them_dau(&ds, 4);
	them_dau(&ds, 2);
	them_dau(&ds, 6);
	
	in_DS(ds);
	
	printf("\nTong: %ld\n", tinh_tong(ds));	
//	
//	sapXepGiam(ds);
//	in_DS(ds);
	
//	xoa(&ds, 6);
//	printf("\n");
//	in_DS(ds); 

	printf("\n");
	tim_hai_so_tong_bang(ds, 5);
	return 0;
}

void them_dau(struct DSSN **dau, int x)
{
	struct DSSN *p = (struct DSSN*) malloc(sizeof(struct DSSN));
	
	p->soNguyen = x;
	p->lk = *dau;
	*dau = p;
}

void in_DS(struct DSSN *dau)
{
	struct DSSN *p = dau;
	
	while (p != NULL)
	{
		printf("%d ", p->soNguyen);
		p = p->lk;
	}
}

long tinh_tong(struct DSSN *dau)
{
	long tong = 0;
	
	for (struct DSSN *p = dau; p != NULL; p = p->lk)
	{
		tong += p->soNguyen;
	}
	
	return tong;
}

void sapXepGiam(struct DSSN *dau)
{
	int tmp;
	
	for (struct DSSN *p = dau; p->lk != NULL; p = p->lk)
	{
		for (struct DSSN *q = p->lk; q != NULL; q = q->lk)
		{
			if (p->soNguyen < q->soNguyen)
			{
				tmp = p->soNguyen;
				p->soNguyen = q->soNguyen;
				q->soNguyen = tmp;
			}
		}
	}
}

void xoa(struct DSSN **dau, int x)
{
	struct DSSN *p = *dau;
	struct DSSN *q;
	
	if (p != NULL && p->soNguyen == x)
	{
		*dau = p->lk;
	}
	else
	{
		q = p;
		p = p->lk;
		while (p != NULL)
		{
			if (p->soNguyen == x)
			{
				q->lk = p->lk;
				free(p);
				return;
			}
			q = p;
			p = p->lk;
		}
	}
}
void tim_hai_so_tong_bang(struct DSSN *dau, long s)
{
	long tong;
	
	for (struct DSSN *p = dau; p->lk != NULL; p = p->lk)
	{
		tong = p->soNguyen;
		if (tong >= s)
		{
			continue;
		}
		for (struct DSSN *q = p->lk; q != NULL; q = q->lk)
		{
			if (tong + q->soNguyen == s)
			{
				printf("%d %d", p->soNguyen, q->soNguyen);
				return;
			}
		}
	}
	
	printf("Khong co");
}