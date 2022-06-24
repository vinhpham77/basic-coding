#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CTQ
{
	char ten[30];
	struct CTQ *con, *em;
};

struct CTQ* tao_nut(char*, struct CTQ*, struct CTQ*);
struct CTQ* tao_cay();
int la_con_chau(struct CTQ*, char*, char*);
struct CTQ* tim(struct CTQ*, char*);
void in_kiem_tra_con_chau(struct CTQ*, char*, char*);

int main()
{
	struct CTQ *goc = tao_cay();
	char ten1[30], ten2[30];
	strcpy(ten1, "Bill");
	strcpy(ten2, "Rohan");

	in_kiem_tra_con_chau(goc, "Bill", "Rohan");
	printf("\n");
	in_kiem_tra_con_chau(goc, "Sal", "Steve");
	return 0;
}

struct CTQ* tao_nut(char *ten, struct CTQ *con, struct CTQ *em)
{
	struct CTQ *p = (struct CTQ*) malloc(sizeof(struct CTQ));
	strcpy(p->ten, ten);
	p->con = con;
	p->em = em;
	return p;
}

struct CTQ* tao_cay()
{
	struct CTQ *goc, *ng1, *ng2, *ng3, *ng4, *ng5, *ng6, *ng7, *ng8, *ng9;
	ng1 = tao_nut("Bill", NULL, NULL);
	ng2 = tao_nut("Tom", ng1, NULL);
	ng3 = tao_nut("Em", ng2, NULL);
	ng4 = tao_nut("Sal", NULL, ng3);
	ng5 = tao_nut("Rohan", ng4, NULL);
	ng6 = tao_nut("Ella", NULL, NULL);
	ng7 = tao_nut("Bob", NULL, ng6);
	ng8 = tao_nut("Lee", NULL, ng7);
	ng9 = tao_nut("Steve", ng8, ng5);
	goc = tao_nut("John", ng9, NULL);
	return goc;
}

int la_con_chau(struct CTQ *goc, char *x, char*y)
{
	struct CTQ *ong_ba = tim(goc, x);
	struct CTQ *con_chau;
	if (ong_ba != NULL)
	{
		con_chau = tim(ong_ba, y);
		return con_chau != NULL && con_chau != ong_ba;
	}

	return 0;
}

struct CTQ* tim(struct CTQ *goc, char *ten)
{
	struct CTQ *p, *q;

	if (goc == NULL)
	{
		return NULL;
	}

	if (strcmp(goc->ten, ten) == 0)
	{
		return goc;
	}
	else
	{
		for (p = goc->con; p != NULL; p = p->em)
		{
			q = tim(p, ten);
			if (q != NULL)
			{
				return q;
			}
		}

		return NULL;
	}
}

void in_kiem_tra_con_chau(struct CTQ *goc, char *x, char *y)
{
	int k = la_con_chau(goc, x, y);
	char v[10];
	if (k)
	{
		strcpy(v, "co");
	}
	else
	{
		strcpy(v, "khong");
	}
	printf("%s %s con chau voi %s", x, v, y);
}