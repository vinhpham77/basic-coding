#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SO_SV_TOI_DA 100 // So luong sinh vien toi da

struct Sinh_Vien
{
    char ho_ten[40];
    int nam_sinh;
    float diem_trung_binh;
};

struct DSSV
{
    struct Sinh_Vien sv[SO_SV_TOI_DA];
    int so_sv;
};

void nhap_sv(struct Sinh_Vien *);
void nhap_dssv(struct DSSV *);
void in_sv(struct Sinh_Vien);
void in_dssv(struct DSSV);
int dem_sv_dtb_lon_bang(struct DSSV, float);
bool xoa_sv(struct DSSV *, char[]);
void tao_ds_sv_gioi(struct DSSV, struct DSSV *);
void sap_xep_dssv_dtb_giam(struct DSSV *);
bool them_sv(struct DSSV *, struct Sinh_Vien);
bool chen_dssv(struct DSSV *, struct DSSV, int);
void ghep_2_dssv_dtb_giam(struct DSSV, struct DSSV, struct DSSV *);
void thong_ke_sv_theo_nam_sinh(struct DSSV);

int main()
{
    struct DSSV dssv;
    struct DSSV dssv_phu;
    struct DSSV dssv_moi;
    struct Sinh_Vien sv;
    int temp;

    nhap_dssv(&dssv);
    // in_dssv(dssv);

    // printf("\ndem = %d\n", dem_sv_dtb_lon_bang(dssv, 6));

    // printf("\n%d\n", xoa_sv(&dssv, "a"));
    // in_dssv(dssv);
    // printf("\n");

    // sap_xep_dssv_dtb_giam(&dssv);
    // in_dssv(dssv);
    // printf("\n");

    // nhap_sv(&sv);
    // them_sv(&dssv, sv);
    // in_dssv(dssv);

    // nhap_dssv(&dssv_phu);

    // printf("Nhap vi tri: ");
    // scanf("%d", &temp);
    // chen_dssv(&dssv, dssv_phu, temp);
    // in_dssv(dssv);

    // sap_xep_dssv_dtb_giam(&dssv);
    // sap_xep_dssv_dtb_giam(&dssv_phu);
    // ghep_2_dssv_dtb_giam(dssv, dssv_phu, &dssv_moi);
    // printf("\n");
    // in_dssv(dssv_moi);

    thong_ke_sv_theo_nam_sinh(dssv);

    return 0;
}

void nhap_sv(struct Sinh_Vien *sv)
{
    fflush(stdin);
    printf("Nhap ho ten: ");
    gets(sv->ho_ten);
    printf("Nhap nam sinh: ");
    scanf("%d", &sv->nam_sinh);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv->diem_trung_binh);
}

void nhap_dssv(struct DSSV *dssv)
{
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &dssv->so_sv);

    for (int i = 0; i < dssv->so_sv; i++)
    {
        nhap_sv(&dssv->sv[i]);
    }
}

void in_sv(struct Sinh_Vien sv)
{
    printf("%s %d %f\n", sv.ho_ten, sv.nam_sinh, sv.diem_trung_binh);
}

void in_dssv(struct DSSV dssv)
{
    for (int i = 0; i < dssv.so_sv; i++)
    {
        in_sv(dssv.sv[i]);
    }
}

// Dem so sinh vien co diem trung binh >= x
int dem_sv_dtb_lon_bang(struct DSSV dssv, float x)
{
    int dem = 0;

    for (int i = 0; i < dssv.so_sv; i++)
    {
        if (dssv.sv[i].diem_trung_binh >= x)
        {
            dem++;
        }
    }

    return dem;
}

bool xoa_sv(struct DSSV *dssv, char ho_ten[])
{
    for (int i = 0; i < dssv->so_sv; i++)
    {
        if (strcmp(dssv->sv[i].ho_ten, ho_ten) == 0)
        {
            dssv->so_sv--;
            while (i < dssv->so_sv)
            {
                dssv->sv[i] = dssv->sv[i + 1];
                i++;
            }

            return true;
        }
    }

    return false;
}

void tao_ds_sv_gioi(struct DSSV ds_goc, struct DSSV *ds_sao)
{
    ds_sao->so_sv = 0;

    for (int i = 0; i < ds_goc.so_sv; i++)
    {
        if (ds_goc.sv[i].diem_trung_binh >= 8)
        {
            ds_sao->sv[ds_sao->so_sv] = ds_goc.sv[i];
            ds_sao->so_sv++;
        }
    }
}

void sap_xep_dssv_dtb_giam(struct DSSV *dssv)
{
    struct Sinh_Vien sv_trung_gian;

    for (int i = 0; i < dssv->so_sv - 1; i++)
    {
        for (int j = i + 1; j < dssv->so_sv; j++)
        {
            if (dssv->sv[i].diem_trung_binh < dssv->sv[j].diem_trung_binh)
            {
                sv_trung_gian = dssv->sv[i];
                dssv->sv[i] = dssv->sv[j];
                dssv->sv[j] = sv_trung_gian;
            }
        }
    }
}

// Them sinh vien vao danh sach da xep thu tu giam diem trung binh
bool them_sv(struct DSSV *dssv, struct Sinh_Vien sv)
{
    int i;
    int j;

    if (dssv->so_sv < SO_SV_TOI_DA)
    {
        for (i = 0; i < dssv->so_sv; i++)
        {
            if (dssv->sv[i].diem_trung_binh <= sv.diem_trung_binh)
            {
                for (j = dssv->so_sv - 1; j >= i; j--)
                {
                    dssv->sv[j + 1] = dssv->sv[j];
                }

                dssv->so_sv++;
                dssv->sv[i] = sv;

                return true;
            }
        }

        dssv->sv[dssv->so_sv] = sv;
        dssv->so_sv++;

        return true;
    }

    return false;
}

// Chen dssv l2 vao dssv l1 tai vi tri k
bool chen_dssv(struct DSSV *l1, struct DSSV l2, int k)
{

    if (k > l1->so_sv || k < 0 || l1->so_sv + l2.so_sv > SO_SV_TOI_DA)
    {
        return false;
    }

    for (int i = l1->so_sv - 1; i >= k; i--)
    {
        l1->sv[i + l2.so_sv] = l1->sv[i];
    }

    for (int i = 0; i < l2.so_sv; i++)
    {
        l1->sv[i + k] = l2.sv[i];
    }

    l1->so_sv += l2.so_sv;

    return true;
}

// Ghep 2 dssv duoc sap giam diem trung binh thanh 1 dssv moi da sap giam diem trung binh
void ghep_2_dssv_dtb_giam(struct DSSV dssv_1, struct DSSV dssv_2, struct DSSV *dssv_moi)
{
    int i; // duyet dssv_1
    int j; // duyet dssv_2
    int k; // duyet dssv_moi

    int tong_sv = dssv_1.so_sv + dssv_2.so_sv;

    if (tong_sv < SO_SV_TOI_DA)
    {
        dssv_moi->so_sv = tong_sv;
        i = j = k = 0;
        while (i < dssv_1.so_sv && j < dssv_2.so_sv)
        {
            if (dssv_1.sv[i].diem_trung_binh > dssv_2.sv[j].diem_trung_binh)
            {
                dssv_moi->sv[k] = dssv_1.sv[i];
                i++;
            }
            else
            {
                dssv_moi->sv[k] = dssv_2.sv[j];
                j++;
            }

            k++;
        }

        while (i < dssv_1.so_sv)
        {
            dssv_moi->sv[k] = dssv_1.sv[i];
            i++;
            k++;
        }

        while (j < dssv_2.so_sv)
        {
            dssv_moi->sv[k] = dssv_2.sv[j];
            j++;
            k++;
        }
    }
}

void thong_ke_sv_theo_nam_sinh(struct DSSV l)
{
    if (l.so_sv > 0)
    {
        int min = l.sv[0].nam_sinh;
        int max = l.sv[0].nam_sinh;
        int i;
        int n;
        int dem[200];

        for (i = 0; i < l.so_sv; i++)
        {
            if (min > l.sv[i].nam_sinh)
            {
                min = l.sv[i].nam_sinh;
            }
            if (max < l.sv[i].nam_sinh)
            {
                max = l.sv[i].nam_sinh;
            }
        }

        n = max - min + 1;
        
        for (i = 0; i < n; i++)
        {
            dem[i] = 0;
        }
    
        for (i = 0; i < l.so_sv; i++)
        {
            dem[l.sv[i].nam_sinh - min]++;
        }

        for (i = 0; i < n; i++)
        {
            if (dem[i] != 0)
            {
                printf("%d %d\n", i+min, dem[i]);
            }
        }
    } 
}
