#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOI_DA 100

struct CTQ
{
	char ten[50];
	int nam_sinh;
	struct CTQ *con, *em;
};

struct CTQ* tao_nut(char*, int, struct CTQ*, struct CTQ*);
void in(struct CTQ*);
void in_rong(struct CTQ*);
int dem_nguoi(struct CTQ*);
int tinh_so_the_he(struct CTQ*);
int tinh_bac(struct CTQ*);

int main()
{
	struct CTQ *goc;
	struct CTQ *ng2, *ng3, *ng4, *ng5, *ng6, *ng7, *ng8;
	ng8 = tao_nut("Nguyen H", 1970, NULL, NULL);
	ng7 = tao_nut("Nguyen G", 1965, NULL, ng8);
	ng6 = tao_nut("Nguyen C", 1935, ng7, NULL);
	ng5 = tao_nut("Nguyen F", 1965, NULL, NULL);
	ng4 = tao_nut("Nguyen E", 1960, NULL, ng5);
	ng3 = tao_nut("Nguyen D", 1955, NULL, ng4);
	ng2 = tao_nut("Nguyen B", 1930, ng3, ng6);
	goc = tao_nut("Nguyen A", 1900, ng2, NULL);

	in(goc);
	printf("\n%d nguoi", dem_nguoi(goc));
	printf("\n%d the he", tinh_so_the_he(goc));
	printf("\n%d bac", tinh_bac(goc));
	return 0;
}

struct CTQ* tao_nut(char *ten, int nam_sinh, struct CTQ *con, struct CTQ *em)
{
	struct CTQ* p = (struct CTQ*) malloc(sizeof(struct CTQ));
	strcpy(p->ten, ten);
	p->nam_sinh = nam_sinh;
	p->con = con;
	p->em = em;
}

void in(struct CTQ *goc)
{
	struct CTQ *p;
	if (goc != NULL)
	{
		printf("%s %d\n", goc->ten, goc->nam_sinh);
		p = goc->con;
		while (p != NULL)
		{
			in(p);
			p = p->em;
		}
	}
}

void in_rong(struct CTQ *goc)
{
	struct CTQ *hd[TOI_DA];
	struct CTQ *p = goc;
	int dau = 0, cuoi = 0;
	hd[0] = goc;
	while (dau <= cuoi)
	{
		p = hd[dau++];
		printf("%s %d ", p->ten, p->nam_sinh);
		p = p->con;

		while (p != NULL)
		{
			hd[++cuoi] = p;
			p = p->em;
		}
	}
}

int dem_nguoi(struct CTQ *goc)
{
	int dem = 0;
	struct CTQ *p;
	if (goc != NULL)
	{
		dem = 1;
		p = goc->con;
		while (p != NULL)
		{
			dem += dem_nguoi(p);
			p = p->em;
		}
	}

	return dem;
}

int tinh_so_the_he(struct CTQ *goc)
{
	int max = 0, n;
	struct CTQ *p;

	if (goc != NULL)
	{
		p = goc->con;
		while (p != NULL)
		{
			n = tinh_so_the_he(p);
			if (n > max)
			{
				max = n;
			}
			p = p->em;
		}
		max++;
	}

	return max;
}

int tinh_bac(struct CTQ *goc)
{
	int bac = 0;
	struct CTQ *p;

	if (goc != NULL)
	{
		for (p = goc->con; p != NULL; p = p->em)
		{
			bac++;
		}
	}

	return bac;
}