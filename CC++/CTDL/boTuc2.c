#include <stdio.h>
#include <string.h>

struct Sinh_Vien
{
	char ho_ten[40];
	int nam_sinh;
	float diem_trung_binh;
};

void nhap_SV(struct Sinh_Vien*);
void in_SV(struct Sinh_Vien);
void nhap_DSSV(struct Sinh_Vien[], int);
void in_DSSV(struct Sinh_Vien[], int);
int tim_SV(struct Sinh_Vien[], int, char[]);
void in_DSSV_gioi(struct Sinh_Vien[], int);
void them_SV(struct Sinh_Vien[], int*, struct Sinh_Vien);
int dem_SV_ho_nguyen(struct Sinh_Vien[], int);
void chuyen_doi_ten_ho(char[], char[]);
void sap_xep_DSSV_tang_ho_ten(struct Sinh_Vien[], int);

int main()
{
	struct Sinh_Vien dssv[100];
	struct Sinh_Vien sv_x;
	char ho_ten_tim[40];
	int vi_tri;
	int so_luong_sv_ho_nguyen = 0;
	int so_sv;

	printf("Nhap so luong sinh vien: ");
	scanf("%d", &so_sv);
	nhap_DSSV(dssv, so_sv);
	printf("\n");
	in_DSSV(dssv, so_sv);

	printf("\nNhap ho ten sinh vien can tim: ");
	fflush(stdin);
	gets(ho_ten_tim);
	vi_tri = tim_SV(dssv, so_sv, ho_ten_tim);
	if (vi_tri == -1)
	{
		printf("Khong tim thay sinh vien %s", ho_ten_tim);
	}
	else
	{
		printf("Sinh vien %s co so thu tu la %d", ho_ten_tim, vi_tri);
	}

	printf("\n\nDanh sach sinh vien gioi:\n");
	in_DSSV_gioi(dssv, so_sv);

	printf("\nNhap thong tin sinh vien can them:\n");
	nhap_SV(&sv_x);
	them_SV(dssv, &so_sv, sv_x);

	so_luong_sv_ho_nguyen = dem_SV_ho_nguyen(dssv, so_sv);
	printf("\nSo luong sinh vien co ho Nguyen: %d\n", so_luong_sv_ho_nguyen);

	sap_xep_DSSV_tang_ho_ten(dssv, so_sv);
	printf("\nSau khi sap xep DSSV theo ho ten:\n");
	in_DSSV(dssv, so_sv);

	return 0;
}

void nhap_SV(struct Sinh_Vien* sv)
{
	fflush(stdin);
	printf("Nhap ho ten: ");
	gets(sv->ho_ten);
	printf("Nhap nam sinh: ");
	scanf("%d", &sv->nam_sinh);
	printf("Nhap diem trung binh: ");
	scanf("%f", &sv->diem_trung_binh);
}

void in_SV(struct Sinh_Vien sv)
{
	printf("%s %d %f", sv.ho_ten, sv.nam_sinh, sv.diem_trung_binh);
}

void nhap_DSSV(struct Sinh_Vien sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		nhap_SV(&sv[i]);
	}
}

void in_DSSV(struct Sinh_Vien sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		in_SV(sv[i]);
		printf("\n");
	}
}

// Tim sinh vien trong mang sv co n phan tu theo ho ten,
// tra ve vi tri cua sinh vien do, tra ve -1 neu sinh vien do khong co trong mang
int tim_SV(struct Sinh_Vien sv[], int n, char ho_ten[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ho_ten, sv[i].ho_ten) == 0)
		{
			return i;
		}
	}

	return -1;
}

// In ra man hinh nhung sinh vien gioi (diem trung binh lon hon hoac bang 8)
void in_DSSV_gioi(struct Sinh_Vien sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (sv[i].diem_trung_binh >= 8)
		{
			in_SV(sv[i]);
			printf("\n");
		}
	}
}

void them_SV(struct Sinh_Vien sv[], int* n, struct Sinh_Vien sv_x)
{
	strcpy(sv[*n].ho_ten, sv_x.ho_ten);
	sv[*n].nam_sinh = sv_x.nam_sinh;
	sv[*n].diem_trung_binh = sv_x.diem_trung_binh;
	*n = *n + 1;
}

int dem_SV_ho_nguyen(struct Sinh_Vien sv[], int n)
{
	int dem = 0;
	char ho[] = "Nguyen";
	int do_dai_ho = strlen(ho);
	int so_sanh_ho;

	for (int i = 0; i < n; i++)
	{
		so_sanh_ho = strncmp(ho, sv[i].ho_ten, do_dai_ho);
		if (so_sanh_ho == 0 && sv[i].ho_ten[do_dai_ho] == ' ')
		{
			dem++;
		}
	}

	return dem;
}

void chuyen_doi_ten_ho(char ho_ten[], char ten_ho[])
{
	int i; // duyet xau ho_ten
	int j; // duyet xau ten_ho
	int do_dai_ho_ten = strlen(ho_ten);

	for (i = do_dai_ho_ten - 1; i > -1 && ho_ten[i] != ' '; i--);
	i++; // Gan ten bat dau tu sau vi tri khoang trang cuoi cung
	for (j = 0; i < do_dai_ho_ten; j++)
	{
		ten_ho[j] = ho_ten[i++];
	}
	ten_ho[j++] = ' '; // Tiep tuc cong ho dem vao xau ten_ho
	i = 0;
	while (j < do_dai_ho_ten)
	{
		ten_ho[j] = ho_ten[i];
		i++;
		j++;
	}
	ten_ho[j] = '\0';
}

// Sap xep mang SV tang dan theo ho ten kieu Viet Nam
void sap_xep_DSSV_tang_ho_ten(struct Sinh_Vien sv[], int n)
{
	char ten_ho_trung_gian[40];
	char ds_ten_ho[100][40];
	struct Sinh_Vien sv_trung_gian;

	for (int i = 0; i < n; i++)
	{
		chuyen_doi_ten_ho(sv[i].ho_ten, ds_ten_ho[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(ds_ten_ho[i], ds_ten_ho[j]) > 0)
			{
				strcpy(ten_ho_trung_gian, ds_ten_ho[i]);
				strcpy(ds_ten_ho[i], ds_ten_ho[j]);
				strcpy(ds_ten_ho[j], ten_ho_trung_gian);

				strcpy(sv_trung_gian.ho_ten, sv[i].ho_ten);
				sv_trung_gian.nam_sinh = sv[i].nam_sinh;
				sv_trung_gian.diem_trung_binh = sv[i].diem_trung_binh;
				strcpy(sv[i].ho_ten, sv[j].ho_ten);
				sv[i].nam_sinh = sv[j].nam_sinh;
				sv[i].diem_trung_binh = sv[j].diem_trung_binh;
				strcpy(sv[j].ho_ten, sv_trung_gian.ho_ten);
				sv[j].nam_sinh = sv_trung_gian.nam_sinh;
				sv[j].diem_trung_binh = sv_trung_gian.diem_trung_binh;
			}
		}
	}
}