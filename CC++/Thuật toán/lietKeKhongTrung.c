#include <stdio.h>

#define MAX 100

void nhap_m(int*, int);
void liet_ke_khong_trung(int*, int);

int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    nhap_m(a, n);
    liet_ke_khong_trung(a, n);
    return 0;
}

void nhap_m(int *a, int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void liet_ke_khong_trung(int *a, int n)
{
    int trung[MAX], i, j;
    for (i = 0; i < n; i++)
    {
        trung[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (trung[i] == 0)
        {
            printf("%d ", a[i]);
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    trung[j] = 1;
                }
            }
        }
    }
}