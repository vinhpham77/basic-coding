#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 20
struct DS_Ke
{
	int dinh_ke;
	struct DS_Ke *lk;
};
struct Do_Thi
{
	int so_tinh;
	struct DS_Ke *ds[TOI_DA];
};

void doc_tep(char*, struct Do_Thi*);
void them(int, int, struct Do_Thi*);

int main()
{
	struct Do_Thi *g;
	doc_tep("dothi.txt", g);
	return 0;
}

void doc_tep(char *ten_tep, struct Do_Thi *g)
{
	FILE *f; int i,j, tg;
	f = fopen(ten_tep,"r");
	fscanf(f,"%d",&g->so_tinh);
	for(i=0;i<g->so_tinh;i++)
	{
		g->ds[i] = NULL;
	}
	for(i=0;i<g->so_tinh;i++)
	{
		for(j=0;j<g->so_tinh;j++)
		{
			fscanf(f,"%d",&tg);
			if(tg==1)
			{
				them(i,j,g);
			}
		}
	}

	fclose(f);
}

void them(int i, int j, struct Do_Thi *g)
{
	struct DS_Ke *p;
	p = (struct DS_Ke*)malloc(sizeof(struct DS_Ke));
	p->dinh_ke = j;
	p->lk = g->ds[i];
	g->ds[i] = p;
}