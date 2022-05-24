#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 100
#define VO_CUNG 9999999

struct DS_Ke
{
	int dinh_ke;
 	int trong_so;
	struct DS_Ke *lk;
};
struct Do_Thi
{
	int so_dinh;
	struct DS_Ke *ds_ke[TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in_Do_Thi(struct Do_Thi);
int la_duong_di(struct Do_Thi, int*, int);
int co_den(struct DS_Ke*, int);
void liet_ke_den(struct Do_Thi, int);

int main()
{
	char duong_dan[] = "DT2.txt";
	struct Do_Thi dt;
	int dinh[] = {1, 0, 3, 0};

	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);
	printf("\n%d\n", la_duong_di(dt, dinh, 2));
	liet_ke_den(dt, 0);
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int so_dinh, trong_so, i, j;
	struct DS_Ke *q;

	fscanf(f, "%d", &dt->so_dinh);

	for (i = 0; i < dt->so_dinh; i++)
	{
		dt->ds_ke[i] = NULL;
		for (j = 0; j < dt->so_dinh; j++)
		{
			fscanf(f, "%d", &trong_so);
			if (trong_so != VO_CUNG)
			{
				q = (struct DS_Ke*) malloc(sizeof(struct DS_Ke));
				q->dinh_ke = j;
				q->trong_so = trong_so;
				q->lk = dt->ds_ke[i];
				dt->ds_ke[i] = q;
			}
		}
	}
}

void in_Do_Thi(struct Do_Thi dt)
{
	int i, j;
	struct DS_Ke *p;

	for (i = 0; i < dt.so_dinh; i++)
	{
		p = dt.ds_ke[i];
		while (p != NULL)
		{
			printf("%d, %d\t", p->dinh_ke, p->trong_so);
			p = p->lk;
		}
		printf("\n");
	}
}

int la_duong_di(struct Do_Thi dt, int *dinh, int so_dinh)
{
	int i = 0;
	struct DS_Ke *p;

	while (i < so_dinh - 1)
	{
		p = dt.ds_ke[dinh[i]];
		i++;

		if (!co_den(p, dinh[i]))
		{
			return 0;
		}
	}

	return 1;
}

int co_den(struct DS_Ke *d, int dinh)
{
	struct DS_Ke *p = d;

	while (p != NULL)
	{
		if (p->dinh_ke == dinh)
		{
			return 1;
		}
		p = p->lk;
	}

	return 0;
}

void liet_ke_den(struct Do_Thi dt, int dinh)
{
	struct DS_Ke *p;
	int i;

	for (i = 0; i < dt.so_dinh; i++)
	{
		if (co_den(dt.ds_ke[i], dinh))
		{
			printf("%d ", i);
		}
	}

}