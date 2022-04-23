#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Tap_Hop
{
	int so;
	int chieu_cao;
	struct Tap_Hop *trai, *phai;
};

int thuoc(struct Tap_Hop*, int);
struct Tap_Hop *them(struct Tap_Hop*, int);
void liet_ke(struct Tap_Hop*);
int la_tap_con(struct Tap_Hop*, struct Tap_Hop*);
struct Tap_Hop *giao(struct Tap_Hop*, struct Tap_Hop*, struct Tap_Hop*);
struct Tap_Hop *hop(struct Tap_Hop*, struct Tap_Hop*, struct Tap_Hop*);
struct Tap_Hop *hieu(struct Tap_Hop*, struct Tap_Hop*, struct Tap_Hop*);
struct Tap_Hop *xoay_trai(struct Tap_Hop*);
struct Tap_Hop *xoay_phai(struct Tap_Hop*);
int lay_chieu_cao(struct Tap_Hop*);
int tinh_can_bang(struct Tap_Hop*);
struct Tap_Hop *lay_nut_nho_nhat(struct Tap_Hop*);
void cap_nhat_chieu_cao(struct Tap_Hop*);

int main()
{
	struct Tap_Hop *S = NULL, *R = NULL;
	int i, so;
	
	for (i = 0; i < 20; i++)
	{
		S = them(S, i);
	}
	
	so = 5;
	if (thuoc(S, so))
	{
		printf("%d thuoc S\n", so);
	}
	else
	{
		printf("%d khong thuoc S\n", so);
	}
	
	liet_ke(S);
	
	R = them(R, 10);
	R = them(R, 90);
	R = them(R, 5);
	R = them(R, 7);
	R = them(R, 22);
	if (la_tap_con(R, S))
	{
		printf("\nR la tap con cua S\n");
	}
	else
	{
		printf("\nR khong phai tap con cua S\n");
	}
	
	liet_ke(giao(R, S, NULL));
//	printf("%d\n", la_CTKNP(goc));
//	printf("%d", la_CCB(goc));
//	printf("\n%d", la_CCBHH(goc));

//	printf("%d\n\n", thuoc(goc0, 2));
//	liet_ke(goc0);
//	printf("\n%d\n", la_tap_con(gocS, NULL));

//	them(&gocS, 22);
//	liet_ke(gocS);

	return 0;
}

// a) a) Kiểm tra một số nguyên x có thuộc tập hợp S không?
int thuoc(struct Tap_Hop *S, int so)
{
	if (S == NULL)
	{
		return 0;
	}

	if (so == S->so)
	{
		return 1;
	}

	if (so < S->so)
	{
		return thuoc(S->trai, so);
	}

	return thuoc(S->phai, so);
}

// b) Liệt kê các số trong tập hợp S.
void liet_ke(struct Tap_Hop *S)
{
	if (S == NULL)
	{
		return;
	}

	printf("%d  ", S->so);
	liet_ke(S->trai);
	liet_ke(S->phai);
}

// c) Kiểm tra S1 có là tập con của S2 không?
int la_tap_con(struct Tap_Hop *S1, struct Tap_Hop *S2)
{
	if (S1 == NULL)
	{
		return 1;
	}

	return thuoc(S2, S1->so) && la_tap_con(S1->trai, S2) && la_tap_con(S1->phai, S2);

	return 0;
}



struct Tap_Hop *hieu(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	if (S1 != NULL)
	{
		if (!thuoc(S2, S1->so))
		{
			them(S3, S1->so);
		}

		S3 = hieu(S1->trai, S2, S3);
		S3 = hieu(S1->phai, S2, S3);
	}

	return S3;
}

// d) Tìm giao của hai tập hợp S1 và S2.
struct Tap_Hop *giao(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	if (S1 != NULL)
	{
		if (thuoc(S2, S1->so))
		{
			S3 = them(S3, S1->so);
		}

		S3 = giao(S1->trai, S2, S3);
		S3 = giao(S1->phai, S2, S3);
	}

	return S3;
}

void them_TH(struct Tap_Hop **S1, struct Tap_Hop *S2)
{
//	if (S2 == NULL)
//	{
//		return;
//	}
//
//	them(S1, S2->so);
//	them_TH(S1, S2->trai);
//	them_TH(S1, S2->phai);
}

struct Tap_Hop *hop(struct Tap_Hop *S1, struct Tap_Hop *S2, struct Tap_Hop *S3)
{
	them_TH(S3, S1);
	them_TH(S3, S2);

	return S3;
}

void cap_nhat_chieu_cao(struct Tap_Hop *S)
{
	int a;
	int b;
	
	if (S == NULL)
	{
		return;
	}
	
	a = lay_chieu_cao(S->trai);
	b = lay_chieu_cao(S->phai);
	
	if (a >= b)
	{
		S->chieu_cao = a + 1;
	}
	
	S->chieu_cao = b + 1;
}

int tinh_can_bang(struct Tap_Hop *S)
{
	if (S == NULL)
	{
		return 0;
	}
	
	return lay_chieu_cao(S->trai) - lay_chieu_cao(S->phai);
}

struct Tap_Hop *xoay_trai(struct Tap_Hop *S)
{
	struct Tap_Hop *X = S->phai;
	struct Tap_Hop *Y = X->trai;
	
	X->trai = S;
	S->phai = Y;
	
	cap_nhat_chieu_cao(S);
	cap_nhat_chieu_cao(X);
	
	return X;\
}

struct Tap_Hop *xoay_phai(struct Tap_Hop *S)
{
	struct Tap_Hop *X = S->trai;
	struct Tap_Hop *Y = X->phai;
	
	X->phai = S;
	S->trai = Y;
	
	cap_nhat_chieu_cao(S);
	cap_nhat_chieu_cao(X);
	
	return X;
}

int lay_chieu_cao(struct Tap_Hop *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return goc->chieu_cao;
}

struct Tap_Hop *lay_nut_nho_nhat(struct Tap_Hop *goc)
{
	struct Tap_Hop *p;
	
	if (goc == NULL)
	{
		return NULL;
	}
	
	p = goc;
	while (p->trai != NULL)
	{
		p = p->trai;
	}
	
	return p;	
}

struct Tap_Hop *them(struct Tap_Hop *S, int so)
{
	int cb;
	
	if (S == NULL)
	{
		S = (struct Tap_Hop*) malloc(sizeof(struct Tap_Hop));
		S->so = so;
		S->chieu_cao = 1;
		S->trai = S->phai = NULL;	
	}
	
	if (S->so == so)
	{
		return S;
	}
	else if (S->so < so)
	{
		S->phai = them(S->phai, so);
	}
	else
	{
		S->trai = them(S->trai, so);
	}
	
	cap_nhat_chieu_cao(S);
	cb = tinh_can_bang(S);
	
	if (cb > 1 && so > S->trai->so)
	{
		return xoay_phai(S);
	}
	
	if (cb > 1 && so < S->trai->so)
	{
		S->trai = xoay_trai(S->trai);
		return xoay_phai(S);
	}
	
	if (cb < -1 && so > S->phai->so)
	{
		return xoay_trai(S);
	}
	
	if (cb < -1 && so < S->phai->so)
	{
		S->phai = xoay_phai(S->phai);
		return xoay_trai(S);
	}
	
	return S;
}