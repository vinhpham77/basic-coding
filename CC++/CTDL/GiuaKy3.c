#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DSSach
{
	char tenSach[50];
	char tenTG[40];
	struct DSSach *lk;
};

void themCuoi(struct DSSach**, struct DSSach**, char*, char*);
void inDS(struct DSSach*);
int demSachCuaTG(struct DSSach*, char*);
int timSach(struct DSSach*, char*, char*);
void xoaSachCuoiCuaTG(struct DSSach**, struct DSSach**, char*);

int main()
{
	struct DSSach *dauDS = NULL;
	struct DSSach *cuoiDS = NULL;
	char tenSach[] = "Sao Hoa";
	char tacGia[] = "Nguyen Van A";

	themCuoi(&dauDS, &cuoiDS, "Mat trang", "Nguyen Van A");
	themCuoi(&dauDS, &cuoiDS, "Tinh nguoi", "Le Hoai");
	themCuoi(&dauDS, &cuoiDS, "Bien menh", "Le Hoai");
	themCuoi(&dauDS, &cuoiDS, "Thuc vat Nam Phi", "Nguyen Trung");
	themCuoi(&dauDS, &cuoiDS, "Sao Hoa", "Nguyen Van A");

	inDS(dauDS);

	printf("So luong sach cua tac gia %s: %d\n", tacGia, demSachCuaTG(dauDS, tacGia));

	if (timSach(dauDS, tenSach, tacGia))
	{
		printf("Co sach %s cua tac gia %s\n", tenSach, tacGia);
	}
	else
	{
		printf("Khong co sach %s cua tac gia %s\n", tenSach, tacGia);
	}

	xoaSachCuoiCuaTG(&dauDS, &cuoiDS, tacGia);
	inDS(dauDS);
	return 0;
}

void themCuoi(struct DSSach **dau, struct DSSach **cuoi, char *tenSach, char *tenTG)
{
	struct DSSach *p = (struct DSSach*) malloc(sizeof(struct DSSach));
	struct DSSach *q;

	strcpy(p->tenSach, tenSach);
	strcpy(p->tenTG, tenTG);
	p->lk = NULL;

	if (*dau == NULL)
	{
		*dau = *cuoi = p;
	}
	else
	{
		q = *cuoi;
		q->lk = p;
		*cuoi = p;
	}
}

void inDS(struct DSSach *dau)
{
	for (struct DSSach *p = dau; p != NULL; p = p->lk)
	{
		printf("%s, %s\n", p->tenSach, p->tenTG);
	}
}

int demSachCuaTG(struct DSSach *dau, char *tenTG)
{
	int dem = 0;

	for (struct DSSach *p = dau; p != NULL; p = p->lk)
	{
		if (strcmp(p->tenTG, tenTG) == 0)
		{
			dem++;
		}
	}

	return dem;
}

int timSach(struct DSSach *dau, char*tenSach, char*tenTG)
{
	for (struct DSSach *p = dau; p != NULL; p = p->lk)
	{
		if (strcmp(p->tenTG, tenTG) == 0 && strcmp(p->tenSach, tenSach) == 0)
		{
			return 1;
		}
	}

	return 0;
}

void xoaSachCuoiCuaTG(struct DSSach **dau, struct DSSach **cuoi, char *tenTG)
{
	struct DSSach *p = *dau;
	struct DSSach *q;
	struct DSSach *tmp = NULL;

	if (p == NULL)
	{
		return;
	}
	else if (strcmp(p->tenTG, tenTG) == 0)
	{
		if (p->lk == NULL)
		{
			*dau = *cuoi = p->lk;
			free(p);
			return;
		}
		else
		{
			tmp = p;
		}
	}

	q = p;
	p = p->lk;

	while (p != NULL)
	{
		if (strcmp(p->tenTG, tenTG) == 0)
		{
			tmp = q;
		}
		q = p;
		p = p->lk;
	}

	if (tmp == *dau)
	{
		*dau = tmp->lk;
		free(tmp);
	}
	else if (tmp != NULL && strcmp(tmp->lk->tenTG, tenTG) == 0)
	{
		q = tmp->lk;
		if (q == *cuoi)
		{
			*cuoi = tmp;
		}
		tmp->lk = q->lk;
		free(q);
	}
}