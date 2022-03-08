#include <stdio.h>
#include <stdbool.h>

#define SO_PT_TOI_DA 100

void nhap_ds(int[], int);
void in_ds(int[], int);
bool la_ds_con(int[], int, int[], int);
bool la_day_con(int[], int, int[], int);

int main()
{
    int L1[SO_PT_TOI_DA];
    int L2[SO_PT_TOI_DA];
    int m;
    int n;

    printf("Nhap so phan tu ds a: ");
    scanf("%d", &m);
    nhap_ds(L1, m);

    printf("Nhap so phan tu ds b: ");
    scanf("%d", &n);
    nhap_ds(L2, n);

    printf("%d", la_ds_con(L1, m, L2, n));

    printf("%d", la_day_con(L1, m, L2, n));

    return 0;
}

void nhap_ds(int ds[], int size_ds)
{
    int i;

    for (i = 0; i < size_ds; i++)
    {
        scanf("%d", &ds[i]);
    }

}

bool la_ds_con(int L1[], int m, int L2[], int n)
{
    int i;
    int j;
    int dem;

    if (m < n)
    {
        return false;
    }

    for(i = 0; i < m - n; i++)
    {
        dem = 0;

        for (j = i; j < i + n; j++)
        {
            if (L1[j] == L2[dem])
            {
                dem++;
            }
        }

        if (dem == n)
        {
            return true;
        }
    }   

    return false;
}

bool la_day_con(int L1[], int m, int L2[], int n)
{
    int i;
    int j = 0;

    if (m < n)
    {
        return false;
    }

    for (i = 0; i < m; i++)
    {
        if (L1[i] == L2[j])
        {
            j++;

            if (j == n)
            {
                return true;
            }
        }
    }

    return false;
}
