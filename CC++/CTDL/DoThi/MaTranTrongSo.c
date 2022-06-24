#include <stdio.h>

#define TOI_DA 100
#define VO_CUNG 9999999

struct Do_Thi
{
	int so_dinh;
	int mtts[TOI_DA][TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in_Do_Thi(struct Do_Thi);
void duyet_sau(struct Do_Thi, int);
void duyet_sauu(struct Do_Thi, int*, int);
void duyet_rong(struct Do_Thi, int);
void duyet_sau_het_dinh(struct Do_Thi);
int dem_canh(struct Do_Thi);
int dem_canh_ke(struct Do_Thi, int);
int liet_ke_khong_tham_rong(struct Do_Thi, int);
void dijkstra(struct Do_Thi, int, int*, int*);
void sift_down(int*, int, int);
void tao_heap(int*, int*, int);
void sift_up(int*, int*, int);
void swap(int*, int*);
int main()
{
	char duong_dan[] = "DT2.txt";
	struct Do_Thi dt;
	int dinh;

	doc_tep(&dt, duong_dan);
	in_Do_Thi(dt);
	printf("\n");
//	dinh = 0;
//	duyet_sau(dt, dinh);
//	printf("\n");
//  dinh = 0;
//	duyet_rong(dt, dinh);
//	printf("\n");
	duyet_sau_het_dinh(dt);
	printf("\nSo canh: %d\n", dem_canh(dt));
	dinh = 2;
	printf("So canh dinh %d ke: %d\n", dinh, dem_canh_ke(dt, dinh));
	dinh = 3;
	printf("Nhung dinh khong duoc tham khi duyet rong dinh %d: ", dinh);
	liet_ke_khong_tham_rong(dt, dinh);
	return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
	FILE *f = fopen(duong_dan, "r");
	int i, j;

	fscanf(f, "%d", &dt->so_dinh);

	for (i = 0; i < dt->so_dinh; i++)
	{
		for (j = 0; j < dt->so_dinh; j++)
		{
			fscanf(f, "%d", &dt->mtts[i][j]);
		}
	}

	fclose(f);
}

void in_Do_Thi(struct Do_Thi dt)
{
	int i, j;

	for (i = 0; i < dt.so_dinh; i++)
	{
		for (j = 0; j < dt.so_dinh; j++)
		{
			printf("%d\t", dt.mtts[i][j]);
		}
		printf("\n");
	}
}

void duyet_sau(struct Do_Thi dt, int dinh)
{
	int da_tham[TOI_DA];
	int i;

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	duyet_sauu(dt, da_tham, dinh);
}

void duyet_sauu(struct Do_Thi dt, int *da_tham, int dinh)
{
	int ke;

	da_tham[dinh] = 1;
	printf("%d ", dinh);

	for (ke = 0; ke < dt.so_dinh; ke++)
	{
		if (dt.mtts[dinh][ke] != VO_CUNG && !da_tham[ke])
		{
			duyet_sauu(dt, da_tham, ke);
		}
	}
}

void duyet_rong(struct Do_Thi dt, int dinh)
{
	int hang_doi[TOI_DA], da_tham[TOI_DA], dau, cuoi, i, ke;
	dau = cuoi = 0;

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	hang_doi[0] = dinh, da_tham[dinh] = 1;

	while (dau <= cuoi)
	{
		dinh = hang_doi[dau++];
		printf("%d ", dinh);

		for (ke = 0; ke < dt.so_dinh; ke++)
		{
			if (dt.mtts[dinh][ke] != VO_CUNG && !da_tham[ke])
			{
				hang_doi[++cuoi] = ke;
				da_tham[ke] = 1;
			}
		}
	}
}

void duyet_sau_het_dinh(struct Do_Thi dt)
{
	int i;
	for (i = 0; i < dt.so_dinh; i++)
	{
		duyet_rong(dt, i);
		printf("\n");
	}
}

int dem_canh(struct Do_Thi dt)
{
	int i, j, dem = 0;

	for (i = 0; i < dt.so_dinh; i++)
	{
		for (j = 0; j < dt.so_dinh; j++)
		{
			if (dt.mtts[i][j] != VO_CUNG)
			{
				dem++;
			}
		}
	}

	return dem / 2;
}

int dem_canh_ke(struct Do_Thi dt, int dinh)
{
	int i, dem = 0;

	for (i = 0; i < dt.so_dinh; i++)
	{
		if (dt.mtts[i][dinh] != VO_CUNG)
		{
			dem++;
		}
	}

	return dem;
}

int liet_ke_khong_tham_rong(struct Do_Thi dt, int dinh)
{
	int hang_doi[TOI_DA], da_tham[TOI_DA], dau, cuoi, i, ke;
	dau = cuoi = 0;

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}
	hang_doi[0] = dinh, da_tham[dinh] = 1;

	while (dau <= cuoi)
	{
		dinh = hang_doi[dau++];
		for (ke = 0; ke < dt.so_dinh; ke++)
		{
			if (dt.mtts[dinh][ke] != VO_CUNG && !da_tham[ke])
			{
				hang_doi[++cuoi] = ke;
				da_tham[ke] = 1;
			}
		}
	}

	for (i = 0; i < dt.so_dinh; i++)
	{
		if (!da_tham[i])
		{
			printf("%d ", i);
		}
	}
}

void tim_ddnn(struct Do_Thi dt, int dinh_dau, int dinh_cuoi)
{
	int i, truoc[TOI_DA], da_tham[TOI_DA];

	for (i = 0; i < dt.so_dinh; i++)
	{
		da_tham[i] = 0;
	}

	dijkstra(dt, dinh_dau, da_tham, truoc);
}

void dijkstra(struct Do_Thi dt, int dinh_dau, int *da_tham, int *truoc)
{
    int i, j, k, vmin, min;
    int duong_di[TOI_DA];
    int heap[TOI_DA];
    for(i = 0; i < dt.so_dinh; i++)
    {
        duong_di[i] = dt.mtts[dinh_dau][i];
        truoc[i] = dinh_dau;
    }
    duong_di[dinh_dau] = 0;
    //tao_heap(heap, duong_di, dt.so_dinh);

    for(k = 0; k < dt.so_dinh; k++)
    {
        //vmin=extracMin(heap, duong_di, dt.so_dinh - k);
        for(j = 0; i < dt.so_dinh - k; j++)
        {
            i = heap[j];
            if(!da_tham[i] && dt.mtts[vmin][i] != VO_CUNG &&
                duong_di[i] > duong_di[vmin] + dt.mtts[vmin][i])
            {
                duong_di[i] = duong_di[vmin] + dt.mtts[vmin][i];
                truoc[i] = vmin;
                sift_up(heap, duong_di, j);
            }
        }
    }
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

int lay(int *heap, int *so_pt)
{
	int cuoi = *so_pt - 1;
	*so_pt = *so_pt - 1;
 	swap(&heap[0], &heap[cuoi]);
	sift_down(heap, 0, *so_pt);

	return heap[cuoi];
}