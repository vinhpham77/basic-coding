#include <stdio.h>
#include <stdlib.h>

struct Da_Thuc
{
	int mu;
	float he_so;
	struct Da_Thuc *lien_ket;
};

struct Da_Thuc* khoi_tao_DT(float*, int);
void in_DT(struct Da_Thuc*);
double tinh_gia_tri_DT(struct Da_Thuc*, float);
struct Da_Thuc* cong_hai_DT(struct Da_Thuc*, struct Da_Thuc*);
struct Da_Thuc* tinh_dao_ham_bac_mot(struct Da_Thuc*);
struct Da_Thuc* nhan_hai_DT(struct Da_Thuc*, struct Da_Thuc*);
void them_dau(struct Da_Thuc**, int, float);
void them(struct Da_Thuc**, int, float);
void them_cuoi(struct Da_Thuc**, struct Da_Thuc**, int, float);

int main()
{
	struct Da_Thuc *dau_dt1;
	struct Da_Thuc *dau_dt2;
	struct Da_Thuc *dau_dt_moi;
	float a[] = {-10, 0, 7, 5};
	float b[] = {0, 1, -7, 0, 0, 6, -2};

	dau_dt1 = khoi_tao_DT(a, 4);
	dau_dt2 = khoi_tao_DT(b, 7);

	printf("P(x) = ");
	in_DT(dau_dt1);
	printf("\nQ(x) = ");
	in_DT(dau_dt2);

	printf("\n\nP(2) = %lf\n", tinh_gia_tri_DT(dau_dt1, 2));

	dau_dt_moi = cong_hai_DT(dau_dt1, dau_dt2);
	printf("\nR(x) = P(x) + Q(x) = ");
	in_DT(dau_dt_moi);

	dau_dt_moi = tinh_dao_ham_bac_mot(dau_dt1);
	printf("\n\nD(x) = Q'(x) = ");
	in_DT(dau_dt_moi);

	dau_dt_moi = nhan_hai_DT(dau_dt1, dau_dt2);
	printf("\n\nM(x) = P(x) * Q(x) = ");
	in_DT(dau_dt_moi);

	return 0;
}

struct Da_Thuc* khoi_tao_DT(float *mang, int so_pt)
{
	int i;
	struct Da_Thuc *dau = NULL;

	for (i = so_pt - 1; i >= 0; i--)
	{
		them_dau(&dau, i, mang[i]);
	}

	return dau;
}

void in_DT(struct Da_Thuc *dau)
{
	struct Da_Thuc *p;

	if (dau == NULL)
	{
		printf("0");
		
		return;
	}

	printf("%fx^%d", dau->he_so, dau->mu);

	for (p = dau->lien_ket; p != NULL; p = p->lien_ket)
	{
		printf(" + %fx^%d", p->he_so, p->mu);
	}
}

double tinh_gia_tri_DT(struct Da_Thuc *dau, float x)
{
	int i;
	double luy_thua;
	double gia_tri = 0;
	struct Da_Thuc *p = dau;

	while (p != NULL)
	{
		luy_thua = 1;
		
		for (i = 0; i < p->mu; i++)
		{
			luy_thua *= x;
		}
		
		gia_tri += p->he_so * luy_thua;
		p = p->lien_ket;
	}

	return  gia_tri;
}

struct Da_Thuc* cong_hai_DT(struct Da_Thuc *dau_dt1, struct Da_Thuc *dau_dt2)
{
	struct Da_Thuc *dau_dt_moi = NULL;
	struct Da_Thuc *cuoi_dt_moi = NULL;
	struct Da_Thuc *p = dau_dt1;
	struct Da_Thuc *q = dau_dt2;

	while (p != NULL && q != NULL)
	{
		if (p->mu == q->mu)
		{
			them_cuoi(&dau_dt_moi, &cuoi_dt_moi, p->mu, p->he_so + q->he_so);
			p = p->lien_ket;
			q = q->lien_ket;
		}
		else if (p->mu < q->mu)
		{
			them_cuoi(&dau_dt_moi, &cuoi_dt_moi, p->mu, p->he_so);
			p = p->lien_ket;
		}
		else
		{
			them_cuoi(&dau_dt_moi, &cuoi_dt_moi, q->mu, q->he_so);
			q = q->lien_ket;
		}
	}

	while (p != NULL)
	{
		them_cuoi(&dau_dt_moi, &cuoi_dt_moi, p->mu, p->he_so);
		p = p->lien_ket;
	}

	while (q != NULL)
	{
		them_cuoi(&dau_dt_moi, &cuoi_dt_moi, q->mu, q->he_so);
		q = q->lien_ket;
	}

	return dau_dt_moi;
}

struct Da_Thuc* tinh_dao_ham_bac_mot(struct Da_Thuc *dau)
{
	struct Da_Thuc *p = dau;
	struct Da_Thuc *dau_dt_moi = NULL;
	struct Da_Thuc *cuoi_dt_moi = NULL;

	while (p != NULL)
	{
		them_cuoi(&dau_dt_moi, &cuoi_dt_moi, p->mu - 1, p->he_so * p->mu);
		p = p->lien_ket;
	}

	return dau_dt_moi;
}

struct Da_Thuc* nhan_hai_DT(struct Da_Thuc *dau_dt1, struct Da_Thuc *dau_dt2)
{
	struct Da_Thuc *p;
	struct Da_Thuc *q;
	struct Da_Thuc *dau_dt_moi = NULL;
	
	if (dau_dt1 == NULL || dau_dt2 == NULL)
	{
		return NULL;	
	}
	
	for (p = dau_dt1; p != NULL; p = p->lien_ket)
	{
		for(q = dau_dt2; q != NULL; q = q->lien_ket)
		{
			them(&dau_dt_moi, p->mu + q->mu, p->he_so * q->he_so);
		}
	}

	return dau_dt_moi;
}

void them_dau(struct Da_Thuc **dau, int mu, float he_so)
{
	struct Da_Thuc *p;

	if (he_so != 0)
	{
		p = (struct Da_Thuc*) malloc(sizeof(struct Da_Thuc));
		p->mu = mu;
		p->he_so = he_so;
		p->lien_ket = *dau;
		*dau = p;
	}
}

// Them phan tu vao vi tri thich hop sao cho cac phan tu co so bac tang dan,
// hoac cong them he so neu co ton tai phan tu co so mu nhu the
void them(struct Da_Thuc **dau, int mu, float he_so)
{
	struct Da_Thuc *p = *dau;
	struct Da_Thuc *q = p;
	struct Da_Thuc *pt;

	if (he_so == 0)
	{
		return;
	}
	
	while (p != NULL && p->mu < mu)
	{
		q = p;
		p = p->lien_ket;
	}

	if (p == q && (p == NULL || p->mu > mu))
	{
		them_dau(dau, mu, he_so);
	}
	else if (p != q && p == NULL)
	{
		them_cuoi(dau, &q, mu, he_so);
	}
	else if (p != NULL && p->mu == mu)
	{
		p->he_so += he_so;
	}
	else
	{
		pt = (struct Da_Thuc*) malloc(sizeof(struct Da_Thuc));
		pt->mu = mu;
		pt->he_so = he_so;
		pt->lien_ket = p;
		q->lien_ket = pt;
	}
}

// Them phan tu vao cuoi da thuc
void them_cuoi(struct Da_Thuc **dau, struct Da_Thuc **cuoi, int mu, float he_so)
{
	struct Da_Thuc *p;
	struct Da_Thuc *q;

	if (he_so == 0)
	{
		return;
	}

	p = (struct Da_Thuc*) malloc(sizeof(struct Da_Thuc));
	p->mu = mu;
	p->he_so = he_so;
	p->lien_ket = NULL;

	if (*cuoi == NULL)
	{
		*dau = *cuoi = p;
	}
	else
	{
		q = *cuoi;
		q->lien_ket = p;
		*cuoi = p;
	}
}