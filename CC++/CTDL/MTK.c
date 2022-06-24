#include <stdio.h>
#include <stdlib.h>

#define TOI_DA 50

struct Do_Thi
{
    int so_dinh;
    int mtk[TOI_DA][TOI_DA];
};

void doc_tep(struct Do_Thi*, char*);
void in(struct Do_Thi);
void duyet_sau(struct Do_Thi, int, int*);
void liet_ke_khong_tham(struct Do_Thi, int);
void liet_ke_khong_ke(struct Do_Thi, int);
int dem_canh(struct Do_Thi);
int la_duong_di(struct Do_Thi, int*, int);

int main()
{
    struct Do_Thi dt;
    int dinh;

    doc_tep(&dt, "mtk.txt");
    //in(dt);
    dinh = 1;
    liet_ke_khong_ke(dt, dinh);
    printf("\n");
    liet_ke_khong_tham(dt, dinh);
    printf("\nSo canh: %d", dem_canh(dt));
    int dinh_arr[] = {1, 3, 2};
    printf("\n%d", la_duong_di(dt, dinh_arr, 3));
    return 0;
}

void doc_tep(struct Do_Thi *dt, char *duong_dan)
{
    FILE *file = fopen(duong_dan, "r");
    fscanf(file, "%d", &dt->so_dinh);
    int i, j;
    for (i = 0; i < dt->so_dinh; i++)
    {
        for (j = 0; j < dt->so_dinh; j++)
        {
            fscanf(file, "%d", &dt->mtk[i][j]);
        }
    }
}

void in(struct Do_Thi dt)
{
    int i, j;
    for (i = 0; i < dt.so_dinh; i++)
    {
        for (j = 0; j < dt.so_dinh; j++)
        {
            printf("%d ", dt.mtk[i][j]);
        }
        printf("\n");
    }
}

void duyet_sau(struct Do_Thi dt, int dinh, int *da_tham)
{
    da_tham[dinh] = 1;
    int i;
    for (i = 0; i < dt.so_dinh; i++)
    {
        if (dt.mtk[dinh][i] && !da_tham[i])
        {
            duyet_sau(dt, i, da_tham);
        }
    }
}

void liet_ke_khong_tham(struct Do_Thi dt, int dinh)
{
    int da_tham[TOI_DA];
    int i;
    for (i = 0; i < dt.so_dinh; i++)
    {
        da_tham[i] = 0;
    }
    duyet_sau(dt, dinh, da_tham);
    for (i = 0; i <dt.so_dinh; i++)
    {
        if (!da_tham[i])
        {
            printf("%d ", i);
        }
    }
}

void liet_ke_khong_ke(struct Do_Thi dt, int dinh)
{
    int i;
    for (i = 0; i < dt.so_dinh; i++)
    {
        if (!dt.mtk[dinh][i])
        {
            printf("%d ", i);
        }
    }
}

//vo huong
int dem_canh(struct Do_Thi dt)
{
    int i, j;
    int dem = 0;

    for (i = 0; i < dt.so_dinh; i++)
    {
        for (j = 0; j < dt.so_dinh; j++)
        {
            if (dt.mtk[i][j] && i <= j)
            {
                dem++;
            }
        }
    }

    return dem;
}


