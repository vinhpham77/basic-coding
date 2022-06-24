#include <stdio.h>
#include <stdlib.h>

struct CCB
{
	int so;
	int chieu_cao;
	struct CCB *trai, *phai;
};

void cap_nhat_chieu_cao(struct CCB*);
int tinh_can_bang(struct CCB*);
struct CCB* them(struct CCB*, int);
struct CCB* xoa(struct CCB*, int);
struct CCB* xoay_trai(struct CCB*);
struct CCB* xoay_phai(struct CCB*);
int lay_chieu_cao(struct CCB*);
void in(struct CCB*);

int main()
{
	struct CCB *goc = NULL;
	int i;
	srand(0);

	goc = them(goc, 5);
	goc = them(goc, 15);
	goc = them(goc, 25);
	goc = them(goc, 65);
	goc = them(goc, 75);
	goc = them(goc, 34);
	goc = them(goc, 02);
	goc = them(goc, 13);

	goc = xoa(goc, 65);
	in(goc);
	return 0;
}

void cap_nhat_chieu_cao(struct CCB *goc)
{
	int max = 0;
	int m;
	if (goc != NULL)
	{
		max = lay_chieu_cao(goc->trai);
		m = lay_chieu_cao(goc->phai);
		if (m > max)
		{
			max = m;
		}

		goc->chieu_cao = max + 1;
	}
}

int tinh_can_bang(struct CCB *goc)
{
	if (goc == NULL)
	{
		return 0;
	}
	return lay_chieu_cao(goc->trai) - lay_chieu_cao(goc->phai);
}

int lay_chieu_cao(struct CCB *goc)
{
	if (goc == NULL)
	{
		return 0;
	}
	else
	{
		return goc->chieu_cao;
	}
}

struct CCB* them(struct CCB *goc, int so)
{
	if (goc == NULL)
	{
		goc = (struct CCB*) malloc(sizeof(struct CCB));
		goc->so = so;
		goc->chieu_cao = 1;
		goc->trai = goc->phai = NULL;
		return goc;
	}

	if (goc->so == so)
	{
		return goc;
	}
	else if (goc->so < so)
	{
		goc->phai = them(goc->phai, so);
	}
	else
	{
		goc->trai = them(goc->trai, so);
	}

	cap_nhat_chieu_cao(goc);
	int cb = tinh_can_bang(goc);

	if (cb > 1 && so < goc->trai->so)
	{
		return xoay_phai(goc);
	}

	if (cb > 1 && so > goc->trai->so)
	{
		goc->trai = xoay_trai(goc->trai);
		return xoay_phai(goc);
	}

	if (cb < -1 && so < goc->phai->so)
	{
		goc->phai = xoay_phai(goc->phai);
		return xoay_trai(goc);
	}

	if (cb < -1 && so > goc->phai->so)
	{
		return xoay_trai(goc);
	}

	return goc;
}

struct CCB* xoay_trai(struct CCB *goc)
{
	struct CCB *x = goc->phai;
	struct CCB *y = x->trai;

	x->trai = goc;
	goc->phai = y;

	cap_nhat_chieu_cao(goc);
	cap_nhat_chieu_cao(x);

	return x;
}

struct CCB* xoay_phai(struct CCB *goc)
{
	struct CCB *x = goc->trai;
	struct CCB *y = x->phai;

	x->phai = goc;
	goc->trai = y;

	cap_nhat_chieu_cao(goc);
	cap_nhat_chieu_cao(x);

	return x;
}

void in(struct CCB *goc)
{
	if (goc != NULL)
	{
		in(goc->trai);
		printf("%d ", goc->so);
		in(goc->phai);
	}
}

struct CCB* xoa(struct CCB *goc, int so)
{
	if (goc == NULL)
	{
		return goc;
	}

	if (goc->so < so)
	{
		goc->phai = xoa(goc->phai, so);
	}
	else if (goc->so > so)
	{
		goc->trai = xoa(goc->trai, so);
	}
	else
	{
		struct CCB *p;
		if (goc->trai != NULL && goc->phai != NULL)
		{
			p = goc->phai;
			while (p->trai != NULL)
			{
				p = p->trai;
			}
			goc->so = p->so;
			goc->phai = xoa(goc->phai, p->so);
		}
		else
		{
			p = goc->trai ? goc->trai : goc->phai;
			if (p == NULL)
			{
				goc = NULL;
			}
			else
			{
				*goc = *p;
			}
		}
		free(p);
	}

	if (goc == NULL)
	{
		return goc;
	}

	cap_nhat_chieu_cao(goc);
	int cb = tinh_can_bang(goc);
	int cbTrai = tinh_can_bang(goc->trai);

	if (cb > 1 && cbTrai < 0)
	{
		goc->trai = xoay_trai(goc->trai);
		return xoay_phai(goc);
	}
	if (cb > 1 && cbTrai >= 0)
	{
		return xoay_phai(goc);
	}

	int cbPhai = tinh_can_bang(goc->phai);
	if (cb < -1 && cbPhai <= 0)
	{
		return xoay_trai(goc);
	}
	if (cb < -1 && cbPhai > 0)
	{
		goc->phai = xoay_phai(goc->phai);
		return xoay_trai(goc);
	}

	return goc;
}