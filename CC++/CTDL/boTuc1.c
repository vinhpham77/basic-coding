#include <stdio.h>
#include <stdbool.h>

void nhap_mang(int[], int);
void in_mang(int[], int);
int tim_so_lon_nhat(int[], int);
int tao_mang_so_chan(int[], int[], int);
double tinh_trung_binh_cong_mang(int[], int);
int tim_vi_tri_trong_mang(int[], int, int);
void sap_xep_mang_tang(int[], int);
void ghep_2_mang_tang_thanh_1_mang_tang(int[], int, int[], int, int[]);
void dem_so_luong_cua_tung_phan_tu_mang(int[], int);

int main()
{
    int n;
    int m;
    int max;
    double avg;
    int a[100];
    int b[100];
    int c[100];

    scanf("%d", &n);
    nhap_mang(a, n);
    in_mang(a, n);

    max = tim_so_lon_nhat(a, n);
    printf("\nSo lon nhat: %d\n", max);

    m = tao_mang_so_chan(a, b, n);
    printf("b[] = ");
    in_mang(b, m);

    avg = tinh_trung_binh_cong_mang(a, n);
    printf("\nTrung binh cong: %f\n", avg);

    sap_xep_mang_tang(a, n);
    printf("a[] sau khi sap tang: ");
    in_mang(a, n);
    sap_xep_mang_tang(b, m);
    printf("\nb[] sau khi sap tang: ");
    in_mang(b, m);

    ghep_2_mang_tang_thanh_1_mang_tang(a, n, b, m, c);
    printf("\nc[] = ");
    in_mang(c, m + n);

    printf("\nc[i]  So luong\n");
    dem_so_luong_cua_tung_phan_tu_mang(c, m + n);

    return 0;
}

void nhap_mang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void in_mang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int tim_so_lon_nhat(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }

    return max;
}

// Tao mang so chan b tu mang so nguyen a co n phan tu,
// tra ve so phan tu cua mang b
int tao_mang_so_chan(int a[], int b[], int n)
{
    int j = 0; // j la so phan tu cua mang b

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }

    return j;
}

double tinh_trung_binh_cong_mang(int a[], int n)
{
    double tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong += a[i];
    }

    return tong / n;
}

// Tra ve vi tri cua x trong mang a co n phan tu,
// tra ve -1 neu x khong co trong mang a
int tim_vi_tri_trong_mang(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            return i;
        }
    }

    return -1;
}

void sap_xep_mang_tang(int a[], int n)
{
    int trung_gian;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                trung_gian = a[i];
                a[i] = a[j];
                a[j] = trung_gian;
            }
        }
    }
}

// Ghep mang tang a co n phan tu va mang tang b co m phan tu thanh mang tang c
void ghep_2_mang_tang_thanh_1_mang_tang(int a[], int n, int b[], int m, int c[])
{
    int i = 0; // duyet mang a
    int j = 0; // duyet mang b
    int k = 0; // duyet mang c

    while (true)
    {
        if (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                c[k] = a[i];
                i++;
            }
            else
            {
                c[k] = b[j];
                j++;
            }
            k++;
        }
        else
        {
            break;
        }
    }

    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

void dem_so_luong_cua_tung_phan_tu_mang(int a[], int n)
{
    int trung_lap[100];
    int dem[100];

    for (int i = 0; i < n; i++)
    {
        trung_lap[i] = false;
        dem[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!trung_lap[i])
        {
            dem[i]++;
            for (int j = i + 1; j < n; j++)
            {
                if (!trung_lap[j] && a[i] == a[j])
                {
                    dem[i]++;
                    trung_lap[j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!trung_lap[i])
        {
            printf("%d\t%d\n", a[i], dem[i]);
        }
    }
}