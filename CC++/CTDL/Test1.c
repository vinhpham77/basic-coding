#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cau a. Khai bao kieu du lieu
struct TB
{
	char ten[100];
	char sdt[11];
};

struct CTKNP
{
	struct TB tb;
	struct CTKNP *trai, *phai;
};

void them(struct CTKNP**, struct TB);
void liet_ke_sdt_bat_dau(struct CTKNP*, char*);
void in(struct CTKNP*);

//cau d. Ham main
int main()
{
	struct CTKNP *goc = NULL;
	struct TB tb;

	strcpy(tb.ten, "Aplha");
	strcpy(tb.sdt, "0984126703");
	them(&goc, tb);
	strcpy(tb.ten, "Beta");
	strcpy(tb.sdt, "0984387103");
	them(&goc, tb);
	strcpy(tb.ten, "Lena");
	strcpy(tb.sdt, "0975127431");
	them(&goc, tb);
	strcpy(tb.ten, "But");
	strcpy(tb.sdt, "0985187999");
	them(&goc, tb);
	strcpy(tb.ten, "Colc");
	strcpy(tb.sdt, "0989729110");
	them(&goc, tb);
	//in(goc);

	printf("\n");
	liet_ke_sdt_bat_dau(goc, "0989");
	return 0;
}

//cau b. Them mot thue bao vao cay
void them(struct CTKNP **goc, struct TB tb)
{
	struct CTKNP *p;
	int kqss;

	if (*goc == NULL)
	{
		p = (struct CTKNP*) malloc(sizeof(struct CTKNP));
		p->tb = tb;
		p->trai = p->phai = NULL;
		*goc = p;
	}
	else
	{
		p = *goc;
		kqss = strcmp(p->tb.sdt, tb.sdt);

		if (kqss < 0)
		{
			them(&p->phai, tb);
		}
		else if (kqss > 0)
		{
			them(&p->trai, tb);
		}
	}
}

//cau c. Liet ke cac sdt co phan dau la x
void liet_ke_sdt_bat_dau(struct CTKNP *goc, char *x)
{
	if (goc != NULL)
	{
		int kqss = strncmp(goc->tb.sdt, x, strlen(x));
		if (kqss == 0)
		{
			printf("%s\n", goc->tb.sdt);
			liet_ke_sdt_bat_dau(goc->trai, x);
			liet_ke_sdt_bat_dau(goc->phai, x);
		}
		else if (kqss < 0)
		{
			liet_ke_sdt_bat_dau(goc->phai, x);
		}
		else
		{
			liet_ke_sdt_bat_dau(goc->trai, x);
		}
	}
}

void in(struct CTKNP *goc)
{
	if (goc != NULL)
	{
		in(goc->trai);
		printf("%s %s\n", goc->tb.ten, goc->tb.sdt);
		in(goc->phai);
	}
}