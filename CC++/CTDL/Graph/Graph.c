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
void tao_DS_Ke(struct DS_Ke*, int, int, struct DS_Ke*);
void in_Do_Thi(struct Do_Thi);

int main()
{
	char duong_dan[] = "DT2.txt";
	struct Do_Thi dt;
	int i;
	
	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);
	return 0;
}

void doc_tep(struct Do_Thi *g, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int so_dinh, trong_so, i, j;
	char nut_ke[20];
	struct DS_Ke *p;
	struct DS_Ke *q;
	
	fscanf(f, "%d", &so_dinh);
	g->so_dinh = so_dinh;
	
	for (i = 0; i < so_dinh; i++)
	{
		p = g->ds_ke[i];
		for (j = 0; j < so_dinh; j++)
		{
			fscanf(f, "%d", &trong_so);
			if (trong_so != VO_CUNG)
			{
				q = (struct DS_Ke*) malloc(sizeof(struct DS_Ke));
				tao_DS_Ke(q, j, trong_so, NULL);
				*p = *q;
				p = p->lk;
			}
		}
	}
}

void tao_DS_Ke(struct DS_Ke *p, int dinh_ke, int trong_so, struct DS_Ke *lk)
{
	p->dinh_ke = dinh_ke;
	p->trong_so = trong_so;
	p->lk = lk;
}

void in_Do_Thi(struct Do_Thi g)
{
	int i, j;
	struct DS_Ke *p;
	
	for (i = 0; i < g.so_dinh; i++)
	{
		p = g.ds_ke[i];
		while (p != NULL)
		{
			printf("%d, %d\t", p->dinh_ke, p->trong_so);
			p = p->lk;
		}
		printf("\n");
	}
	
}
