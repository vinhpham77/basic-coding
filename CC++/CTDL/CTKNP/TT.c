#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct CSN
{
	int du_lieu;
	struct CSN *trai, *phai;
};
struct Tap_Hop
{
	int so;
	struct Tap_Hop *trai, *phai;
};
int tinh_chieu_cao(struct CSN *goc)
{
	int x, y;

	if (goc == NULL)
	{
		return 0;
	}

	x = tinh_chieu_cao(goc->trai);
	y = tinh_chieu_cao(goc->phai);

	return x > y ? x + 1 : y + 1;
}

int max(struct CSN *goc)
{
	int m = INT_MIN;
	int m1;
	int m2;

	if (goc != NULL)
	{
		m = goc->du_lieu;
		m1 = max(goc->trai);
		m2 = max(goc->phai);

		if (m1 > m)
		{
			m = m1;
		}

		if (m2 > m)
		{
			m = m2;
		}
	}

	return m;
}

int min(struct CSN *goc)
{
	int m = INT_MAX;
	int m1;
	int m2;

	if (goc != NULL)
	{
		m = goc->du_lieu;
		m1 = min(goc->trai);
		m2 = min(goc->phai);

		if (m1 < m)
		{
			m = m1;
		}

		if (m2 < m)
		{
			m = m2;
		}

	}

	return m;
}

int la_CTKNP(struct CSN *goc)
{
	if (goc == NULL || (goc == NULL && goc && NULL))
	{
		return 1;
	}

	if (max(goc->trai) < goc->du_lieu && goc->du_lieu < min(goc->phai))
	{
		return la_CTKNP(goc->trai) && la_CTKNP(goc->phai);
	}

	return 0;
}

int la_CCB(struct CSN *t)
{
	int lech;

	if (t == NULL)
	{
		return 1;
	}

	lech = tinh_chieu_cao(t->trai) - tinh_chieu_cao(t->phai);

	if (lech >= -1 && lech <= 1)
	{
		return la_CTKNP(t) && la_CCB(t->trai) && la_CCB(t->phai);
	}

	return 0;
}

int tinh_so_nut(struct CSN *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return tinh_so_nut(goc->trai) + tinh_so_nut(goc->phai) + 1;
}

int la_CCBHH(struct CSN *goc)
{
	int lech;

	if (goc == NULL)
	{
		return 1;
	}

	lech = tinh_so_nut(goc->trai) - tinh_so_nut(goc->phai);

	if (lech >= -1 && lech <= 1)
	{
		return la_CTKNP(goc) && la_CCB(goc->trai) && la_CCB(goc->phai);
	}

	return 0;
}

struct CSN *tao_nut(int n, struct CSN *trai, struct CSN *phai)
{
	struct CSN *nut = (struct CSN*) malloc(sizeof(struct CSN));

	nut->du_lieu = n;
	nut->trai = trai;
	nut->phai = phai;

	return nut;
}

struct Tap_Hop *tao_nut0(int n, struct Tap_Hop *trai, struct Tap_Hop *phai)
{
	struct Tap_Hop *nut = (struct Tap_Hop*) malloc(sizeof(struct Tap_Hop));

	nut->so = n;
	nut->trai = trai;
	nut->phai = phai;

	return nut;
}

int thuoc(struct Tap_Hop *S, int x)
{
	if (S == NULL)
	{
		return 0;
	}

	if (x == S->so)
	{
		return 1;
	}

	if (x < S->so)
	{
		return thuoc(S->trai, x);
	}

	return thuoc(S->phai, x);
}

void liet_ke(struct Tap_Hop *S)
{
	if (S == NULL)
	{
		return;
	}

	printf("%d\n", S->so);
	liet_ke(S->trai);
	liet_ke(S->phai);
}

int la_tap_con(struct Tap_Hop *S1, struct Tap_Hop *S2)
{
	if (S1 == NULL)
	{
		return 1;
	}

	return thuoc(S2, S1->so) && la_tap_con(S1->trai, S2) && la_tap_con(S1->phai, S2);

	return 0;
}

void them(struct Tap_Hop **S, int so)
{
	struct Tap_Hop *X;
	struct Tap_Hop *P;

	if (*S == NULL)
	{
		X = (struct Tap_Hop*) malloc(sizeof(struct Tap_Hop));
		X->so = so;
		X->trai = X->phai = NULL;
		*S = X;
	}
	else
	{
		P = *S;

		if (so < P->so)
		{
			them(&P->trai, so);
		}
		else if (so > P->so)
		{
			them(&P->phai, so);
		}
	}
}

struct Tap_Hop *hieu(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	if (S1 != NULL)
	{
		if (!thuoc(S2, S1->so))
		{
			them(&S3, S1->so);
		}

		S3 = hieu(S1->trai, S2, S3);
		S3 = hieu(S1->phai, S2, S3);
	}

	return S3;
}

struct Tap_Hop *giao(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	if (S1 != NULL)
	{
		if (thuoc(S2, S1->so))
		{
			them(&S3, S1->so);
		}

		S3 = giao(S1->trai, S2, S3);
		S3 = giao(S1->phai, S2, S3);
	}

	return S3;
}

void them_TH(struct Tap_Hop **S1, struct Tap_Hop *S2)
{
	if (S2 == NULL)
	{
		return;
	}

	them(S1, S2->so);
	them_TH(S1, S2->trai);
	them_TH(S1, S2->phai);
}

struct Tap_Hop *hop(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	them_TH(&S3, S1);
	them_TH(&S3, S2);

	return S3;
}


int main()
{
	struct CSN *goc, *n, *n1, *n2, *n3, *n4, *n5;
	struct Tap_Hop *goc0, *n0, *n10, *n20, *n30, *n40, *n50;
	struct Tap_Hop *gocS, *nS, *n1S, *n2S, *n3S, *n4S, *n5S;

	n = tao_nut(2, NULL, NULL);
	n1 = tao_nut(4, n, NULL);
	n2 = tao_nut(12, NULL, NULL);
	n3 = tao_nut(7, n1, n2);
	n4 = tao_nut(14, NULL, NULL);
	n5 = tao_nut(19, n4, NULL);
	goc = tao_nut(13, n3, n5);

	n0 = tao_nut0(2, NULL, NULL);
	n10 = tao_nut0(4, n0, NULL);
	n20 = tao_nut0(11, NULL, NULL);
	n30 = tao_nut0(7, n10, n20);
	n40 = tao_nut0(14, NULL, NULL);
	n50 = tao_nut0(19, n40, NULL);
	goc0 = tao_nut0(13, n30, n50);

	nS = tao_nut0(2, NULL, NULL);
	n1S = tao_nut0(4, nS, NULL);
	n2S = tao_nut0(12, NULL, NULL);
	n3S = tao_nut0(7, n1S, n2S);
	n4S = tao_nut0(14, NULL, NULL);
	n5S = tao_nut0(19, n4S, NULL);
	gocS = tao_nut0(13, n3S, n5S);

//	printf("%d\n", la_CTKNP(goc));
//	printf("%d", la_CCB(goc));
//	printf("\n%d", la_CCBHH(goc));

//	printf("%d\n\n", thuoc(goc0, 2));
//	liet_ke(goc0);
//	printf("\n%d\n", la_tap_con(gocS, NULL));

//	them(&gocS, 22);
//	liet_ke(gocS);

	liet_ke(hieu(gocS, goc0, NULL));
	return 0;
}
