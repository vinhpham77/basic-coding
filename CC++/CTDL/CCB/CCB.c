#include <stdio.h>
#include <stdlib.h>

struct CCB
{
	int so;
	int chieu_cao;
	struct CCB *trai, *phai;
};

struct CCB *them(struct CCB*, int);
struct CCB *xoa(struct CCB*, int);
struct CCB *xoay_trai(struct CCB*);
struct CCB *xoay_phai(struct CCB*);
int lay_chieu_cao(struct CCB*);
int tinh_can_bang(struct CCB*);
struct CCB *lay_nut_nho_nhat(struct CCB*);
int max(int, int);
void cap_nhat_chieu_cao(struct CCB*);
struct CCB *tim(struct CCB*, int);

int main()
{
	struct CCB *goc = NULL;
	const int n = 1000000;
	int i;
	
	for (i = 1; i <= n; i++)
	{
		goc = them(goc, i);
	}
	printf("\nChieu cao cay ban dau: %d\n", lay_chieu_cao(goc));
	
	for (i = 1; i <= n/2; i++)
	{
		goc = xoa(goc, i);
	}
	printf("Chieu cao cay sau khi xoa: %d\n", lay_chieu_cao(goc));
	
	return 0;
}

struct CCB *them(struct CCB *goc, int so)
{
	int cb;

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
	else if (goc->so > so)
	{
		goc->trai = them(goc->trai, so);
	}
	else
	{
		goc->phai = them(goc->phai, so);
	}

	cap_nhat_chieu_cao(goc);
	cb = tinh_can_bang(goc);

	// TH trái-trái
	if (cb > 1 && so < goc->trai->so)
	{
		return xoay_phai(goc);
	}

	// TH trái-phải
	if (cb > 1 && so > goc->trai->so)
	{
		goc->trai = xoay_trai(goc->trai);
		return xoay_phai(goc);
	}

	// TH phải-trái
	if (cb < -1 && so < goc->phai->so)
	{
		goc->phai = xoay_phai(goc->phai);
		return xoay_trai(goc);
	}

	// TH phải-phải
	if (cb < -1 && so > goc->phai->so)
	{
		return xoay_trai(goc);
	}

	return goc;
}

struct CCB *xoa(struct CCB *goc, int so)
{
	int cb;
	struct CCB *tmp;
	
	if (goc == NULL)
	{
		return goc;
	}

	if (so < goc->so)
	{
		goc->trai = xoa(goc->trai, so);
	}
	else if (so > goc->so)
	{
		goc->phai = xoa(goc->phai, so);
	}
	else
	{	
		if (goc->trai == NULL || goc->phai == NULL)
		{
			tmp = goc->trai == NULL ? goc->phai : goc->trai;
			
			if (tmp == NULL)
			{
				tmp = goc;
				goc = NULL;	
			}
			else
			{
				*goc = *tmp;
			}
				
			free(tmp);
		}
		else
		{
			tmp = lay_nut_nho_nhat(goc->phai);
			goc->so = tmp->so;
			goc->phai = xoa(goc->phai, tmp->so);
		}
	}

	if (goc == NULL)
	{
		return NULL;
	}
	
	cap_nhat_chieu_cao(goc);
	cb = tinh_can_bang(goc);

	// TH trái-trái
	if (cb > 1 && tinh_can_bang(goc->trai) >= 0)
	{
		return xoay_phai(goc);
	}

	// TH trái-phải
	if (cb > 1 && tinh_can_bang(goc->trai) < 0)
	{
		goc->trai = xoay_trai(goc->trai);
		return xoay_phai(goc);
	}

	// TH phải-trái
	if (cb < -1 && tinh_can_bang(goc->phai) > 0)
	{
		goc->phai = xoay_phai(goc->phai);
		return xoay_trai(goc);
	}

	// TH phải-phải
	if (cb < -1 && tinh_can_bang(goc->phai) <= 0)
	{
		return xoay_trai(goc);
	}

	return goc;
}

struct CCB *xoay_trai(struct CCB *goc)
{
	struct CCB *x = goc->phai;
	struct CCB *y = x->trai;

	x->trai = goc;
	goc->phai = y;

	cap_nhat_chieu_cao(goc);
	cap_nhat_chieu_cao(x);

	return x;
}

struct CCB *xoay_phai(struct CCB *goc)
{
	struct CCB *x = goc->trai;
	struct CCB *y = x->phai;

	x->phai = goc;
	goc->trai = y;

	cap_nhat_chieu_cao(goc);
	cap_nhat_chieu_cao(x);

	return x;
}

int lay_chieu_cao(struct CCB *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return goc->chieu_cao;
}

int tinh_can_bang(struct CCB *goc)
{
	if (goc == NULL)
	{
		return 0;
	}

	return lay_chieu_cao(goc->trai) - lay_chieu_cao(goc->phai);
}

struct CCB *lay_nut_nho_nhat(struct CCB *goc)
{
	struct CCB *p;

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

int max(int a, int b)
{
	if (a < b)
	{
		return b;
	}

	return a;
}

void cap_nhat_chieu_cao(struct CCB *goc)
{
	if (goc != NULL)
	{
		goc->chieu_cao = max(lay_chieu_cao(goc->trai), lay_chieu_cao(goc->phai)) + 1;
	}
}

struct CCB *tim(struct CCB *goc, int so)
{
	if (goc == NULL)
	{
		return NULL;
	}
	
	if (goc->so == so)
	{
		return goc;
	}
	else if (goc->so < so)
	{
		return tim(goc->trai, so);
	}
	else
	{
		return tim(goc->phai, so);
	}
}