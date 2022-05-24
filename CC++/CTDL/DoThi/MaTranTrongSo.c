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