#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DSDiem
{
	char maMH[15];
	float diemMH;
	struct DSDiem *lk;
};

void themDau(struct DSDiem**, char*, float);
void inDS(struct DSDiem*);
float tinhTBC(struct DSDiem*);
float layDiemMH(struct DSDiem*, char*);
void xoa(struct DSDiem**, struct DSDiem*);
void xoaMHTrungGiuCao(struct DSDiem**);

int main()
{
	struct DSDiem *ds = NULL;
	char maMH[] = "M02";
	themDau(&ds, "M03", 8);
	themDau(&ds, "M03", 9);
	themDau(&ds, "M02", 5.7);
	themDau(&ds, "M02", 8.6);
	themDau(&ds, "M03", 5.2);

	inDS(ds);

	printf("\nTBC diem trung binh: %f\n", tinhTBC(ds));
	printf("\nDiem mon hoc cua mon %s: %f\n", maMH, layDiemMH(ds, maMH));
	xoaMHTrungGiuCao(&ds);
	printf("\n");
	inDS(ds);
	return 0;

}

void themDau(struct DSDiem **dau, char *maMH, float diemMH)
{
	struct DSDiem *p = (struct DSDiem*) malloc(sizeof(struct DSDiem));

	strcpy(p->maMH, maMH);
	p->diemMH = diemMH;
	p->lk = *dau;
	*dau = p;
}

void inDS(struct DSDiem *dau)
{
	for (struct DSDiem *p = dau; p != NULL; p = p->lk)
	{
		printf("%s\t%f\n", p->maMH, p->diemMH);
	}
}

float tinhTBC(struct DSDiem *dau)
{
	float tong;
	int sl = 0;

	for (struct DSDiem *p = dau; p != NULL; p = p->lk)
	{
		tong += p->diemMH;
		sl++;
	}

	return tong / sl;
}

float layDiemMH(struct DSDiem *dau, char *maMH)
{
	for (struct DSDiem *p = dau; p != NULL; p = p->lk)
	{
		if (strcmp(p->maMH, maMH) == 0)
		{
			return p->diemMH;
		}
	}

	return -1;
}

void xoa(struct DSDiem **dau, struct DSDiem *p)
{
	struct DSDiem *q;

	if (p == NULL)
	{
		if (*dau == NULL)
		{
			return;
		}
		else
		{
			q = *dau;
			*dau = q->lk;
			free(q);
		}
	}
	else
	{
		q = p->lk;
		p->lk = q->lk;
		free(q);
	}
}

void xoaMHTrungGiuCao(struct DSDiem **dau)
{
	struct DSDiem *p = *dau;
	struct DSDiem *q;
	struct DSDiem *tmp = NULL;
	struct DSDiem *tmq;
	struct DSDiem *s;
	int xoaP;

	while (p != NULL)
	{
		tmq = p;
		s = p;
		for (q = p->lk; q != NULL; q = q->lk)
		{
			if (strcmp(p->maMH, q->maMH) == 0)
			{
				if (q->diemMH > p->diemMH)
				{
					if (q = p->lk)
					{
						s = p->lk;
					}
					xoa(dau, tmp);
					p = q;
				}
				else
				{
					xoa(dau, tmq);
					q = tmq;
				}	
			}
			tmq = q;
		}
		tmp = p;
		
		p = s->lk;
	}
}