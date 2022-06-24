#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 10
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
	struct DS_Ke* ds[TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in_Do_Thi(struct Do_Thi);
void duyet_sau(struct Do_Thi, int, int*, int*);
int la_dt_lien_thong_manh(struct Do_Thi);
void tim_duong_di_ngan_nhat(struct Do_Thi, int, int);
void dijktra(struct Do_Thi, int, int*, int*);
int lay(int*, int*);
void swap(int*, int*);
void sift_up(int*);
void tao_heap(int*, int*, int);
void sift_down(int*, int, int);

int main()
{
	char duong_dan[] = "DT2.txt";
	struct Do_Thi dt;
	int x, y;
	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);
	printf("\nLa do thi lien thong manh: %d", la_dt_lien_thong_manh(dt));
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int i, j, dinh_ke;
	struct DS_Ke *p;

	fscanf(f, "%d", &dt->so_dinh);
	for (i = 0; i < dt->so_dinh; i++)
	{
		dt->ds[i] = NULL;
	}

	for (i = 0; i < dt->so_dinh; i++)
	{

		for (j = 0; j < dt->so_dinh; j++)
		{
			fscanf(f, "%d", &dinh_ke);
			if (dinh_ke != VO_CUNG)
			{
				p = (struct DS_Ke*) malloc(sizeof(struct DS_Ke));
				p->dinh_ke = j;
				p->lk = dt->ds[i];
				dt->ds[i] = p;
			}
		}
	}
}

void in_Do_Thi(struct Do_Thi dt)
{
	int i, j;
	struct DS_Ke *p;

	for (i = 0; i < dt.so_dinh; i++)
	{
		for (p = dt.ds[i]; p != NULL; p = p->lk)
		{
			printf("%d ", p->dinh_ke);
		}
		printf("\n");
	}
}

void duyet_sau(struct Do_Thi dt, int dinh_dau, int *da_tham, int *truoc)
{
	int i, dinh_ke;
	struct DS_Ke *p = dt.ds[dinh_dau];
	da_tham[dinh_dau] = 1;

	while (p != NULL)
	{
		dinh_ke = p->dinh_ke;
		if (!da_tham[dinh_ke])
		{
			truoc[dinh_ke] = dinh_dau;
			duyet_sau(dt, dinh_ke, da_tham, truoc);
		}
		p = p->lk;
	}
}

int la_dt_lien_thong_manh(struct Do_Thi dt)
{
	int i, j, k;
	int da_tham[TOI_DA], truoc[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		for (j = 0; j < dt.so_dinh; j++)
		{
			da_tham[j] = 0;
		}

		duyet_sau(dt, i, da_tham, truoc);
		for (k = 0; k < dt.so_dinh; k++)
		{
			if (!da_tham[k])
			{
				return 0;
			}
		}
	}

	return 1;
}

void tim_duong_di_ngan_nhat(struct Do_Thi dt, int dinh_dau, int dinh_cuoi)
{
	int i, truoc[TOI_DA], da_tham[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}

	dijktra(dt, dinh_dau, da_tham, truoc);
}

void dijktra(struct Do_Thi dt, int dinh_dau, int *da_tham, int *truoc)
{
//	int i, k, duong_di[TOI_DA], heap[TOI_DA];
//	da_tham[dinh_dau] = 1;
//
//	for (i = 0; i < dt.so_dinh; i++)
//	{
//		duong_di[i] = dt.ds[dinh_dau];
//	}
//	duong_di[dinh_dau] = 0;
//
//	struct DS_Ke *p = dt.ds[dinh_dau];
//	while (p != NULL)
//	{
//
//		p = p->lk;
//	}


}

void sift_down(int *heap, int dau, int so_pt)
{
	int cha = dau;
	int con_trai = cha * 2 + 1;
	int con_phai;
	int con_nho_nhat;

	while (con_trai < so_pt)
	{
		con_nho_nhat = con_trai;
		con_phai = con_trai + 1;

		if (con_phai < so_pt && heap[con_phai] < heap[con_nho_nhat])
		{
			con_nho_nhat = con_phai;
		}

		if (heap[cha] > heap[con_nho_nhat])
		{
			swap(&heap[cha], &heap[con_nho_nhat]);
			cha = con_nho_nhat;
			con_trai = cha * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int lay(int *heap, int *so_pt)
{
	int cuoi = *so_pt - 1;
	*so_pt = *so_pt - 1;
 	swap(&heap[0], &heap[cuoi]);
	sift_down(heap, 0, *so_pt);

	return heap[cuoi];
}

void sift_up(int *heap, int *duong_di, int so_pt)
{
	int con = so_pt - 1;
	int cha;

	while (con > 0)
	{
		cha = (con - 1) / 2;

		if (duong_di[cha] > duong_di[con])
		{
			swap(&heap[cha], &heap[con]);
			con = cha;
		}
		else
		{
			return;
		}
	}
}