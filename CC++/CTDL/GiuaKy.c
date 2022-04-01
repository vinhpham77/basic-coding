#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

struct DSTT
{
	char ten[40];
	float thanhTich;
	struct DSTT *lk;
};

void themVDV(struct DSTT**, struct DSTT**, char*, float);
void inDS(struct DSTT*);
float timTT(struct DSTT*, char*);
float timTTCaoNhat(struct DSTT*);
void xoaTatVDVKhongCoTT(struct DSTT**, struct DSTT**);

int main()
{
	struct DSTT *dauDS = NULL;
	struct DSTT *cuoiDS = NULL;

	themVDV(&dauDS, &cuoiDS, "Nguyen Van A", 1);
	themVDV(&dauDS, &cuoiDS, "Nguyen Van B", 0);
	themVDV(&dauDS, &cuoiDS, "Nguyen Van C", 20);
	themVDV(&dauDS, &cuoiDS, "Nguyen Van D", 0);
	themVDV(&dauDS, &cuoiDS, "Nguyen Van E", 9);

	inDS(dauDS);

	printf("Thanh tich cua Nguyen Van A: %f", timTT(dauDS, "Nguyen Van A"));

	printf("\nThanh tich cao nhat: %f\n", timTTCaoNhat(dauDS));


	xoaTatVDVKhongCoTT(&dauDS, &cuoiDS);
	inDS(dauDS);
	return 0;
}

void themVDV(struct DSTT **dau, struct DSTT **cuoi, char *ten, float thanhTich)
{
	struct DSTT *q = (struct DSTT*) malloc(sizeof(struct DSTT));
	struct DSTT *p;

	strcpy(q->ten, ten);
	q->thanhTich = thanhTich;
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

void inDS(struct DSTT *dau)
{
	struct DSTT *p = dau;

	while (p != NULL)
	{
		printf("%s  %f\n", p->ten, p->thanhTich);
		p = p->lk;
	}
}

float timTT(struct DSTT *dau, char *ten)
{
	struct DSTT *p = dau;

	while (p != NULL)
	{
		if (strcmp(p->ten, ten) == 0)
		{
			return p->thanhTich;
		}
		p = p->lk;
	}

	return 0;
}

float timTTCaoNhat(struct DSTT *dau)
{
	struct DSTT *p = dau;
	float max = FLT_MAX;

	while (p != NULL)
	{
		if (max > p->thanhTich)
		{
			max = p->thanhTich;
		}
		p = p->lk;
	}

	return max;
}
void xoaTatVDVKhongCoTT(struct DSTT **dau, struct DSTT **cuoi)
{
	struct DSTT *p = *dau;
	struct DSTT *q;
	struct DSTT *tmp;

	while (*dau!= NULL && !p->thanhTich)
	{
		if (p->lk == NULL)
		{
			*dau = *cuoi = NULL;
		}
		else
		{
			*dau = p->lk;
		}
		free(p);
		p = *dau;
	}

	if(p == NULL)
	{
		return;
	}

	q = p;
	p = p->lk;
	while (p != NULL)
	{
		if (!p->thanhTich)
		{
			if (p == *cuoi)
			{
				*cuoi = p;
			}
			q->lk = p->lk;
			tmp = p;
			free(tmp);
		}
		else
		{
			q = q->lk;
		}
		p = p->lk;
	}
}