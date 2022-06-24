#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tu
{
	char tAnh[30];
	char tViet[50];
};

struct Tu_Dien
{
	struct Tu tu;
	struct Tu_Dien *trai, *phai;
};

struct Tu_Dien* doc_tep(char*);
void them(struct Tu_Dien**, struct Tu);
void in_tu_dien(struct Tu_Dien*);
char* tim_nghia(struct Tu_Dien*, char*);
struct Tu_Dien* xoa(struct Tu_Dien*, char*);

int main()
{
	struct Tu_Dien *tu_dien = doc_tep("CTKNP.txt");
	//char *it = tim_nghia(tu_dien, "RAM");
	//printf("nghia tieng viet: %s\n", it);
	tu_dien = xoa(tu_dien, "cat");
	in_tu_dien(tu_dien);
	return 0;
}

struct Tu_Dien* doc_tep(char *duong_dan)
{
	struct Tu_Dien *tu_dien = NULL;
	FILE *file = fopen(duong_dan, "r");
	char w[80];
	struct Tu tu;
	int length;

	while (fgets(w, 80, file) != NULL)
	{
		length = strlen(w);
		if(w[length - 1] == '\n')
		{
			w[length - 1] = '\0';
		}
		length = strstr(w, ":") - w;
		strncpy(tu.tAnh, w, length);
		tu.tAnh[length] = '\0';
		strcpy(tu.tViet, w+length+1);
		them(&tu_dien, tu);
	}

	fclose(file);
	return tu_dien;
}

void them(struct Tu_Dien **tu_dien, struct Tu tu)
{
	struct Tu_Dien *p = *tu_dien;
	struct Tu_Dien *q;

	if (*tu_dien == NULL)
	{
		q = (struct Tu_Dien*) malloc(sizeof(struct Tu_Dien));
		q->tu = tu;
		q->trai = q->phai = NULL;
		*tu_dien = q;
	}
	else
	{
		if (strcmp(p->tu.tAnh, tu.tAnh) > 0)
		{
			them(&p->trai, tu);
		}
		else if (strcmp(p->tu.tAnh, tu.tAnh) < 0)
		{
			them(&p->phai, tu);
		}
	}
}

void in_tu_dien(struct Tu_Dien *tu_dien)
{
	if (tu_dien != NULL)
	{
		in_tu_dien(tu_dien->trai);
		printf("%s: %s\n", tu_dien->tu.tAnh, tu_dien->tu.tViet);
		in_tu_dien(tu_dien->phai);
	}
}

char* tim_nghia(struct Tu_Dien *tu_dien, char *tAnh)
{
	int kqss;
	if (tu_dien == NULL)
	{
		return NULL;
	}
	else
	{
		kqss = strcmp(tu_dien->tu.tAnh, tAnh);
		if (kqss == 0)
		{
			return tu_dien->tu.tViet;
		}
		else if (kqss == 1)
		{
			return tim_nghia(tu_dien->trai, tAnh);
		}
		else
		{
			return tim_nghia(tu_dien->phai, tAnh);
		}
	}
}

struct Tu_Dien* xoa(struct Tu_Dien *tu_dien, char *tAnh)
{
	struct Tu_Dien *q;
	int kqss;

	if (tu_dien == NULL)
	{
		return tu_dien;
	}

	kqss = strcmp(tu_dien->tu.tAnh, tAnh);
	if (kqss < 0)
	{
		tu_dien->phai = xoa(tu_dien->phai, tAnh);
	}
	else if (kqss > 0)
	{
		tu_dien->trai = xoa(tu_dien->trai, tAnh);
	}
	else
	{
		if (tu_dien->trai != NULL && tu_dien->phai != NULL)
		{
			q = tu_dien->phai;
			while (q->trai != NULL)
			{
				q = q->trai;
			}

			tu_dien->tu = q->tu;
			tu_dien->phai = xoa(tu_dien->phai, q->tu.tAnh);
		}
		else
		{
			q = tu_dien->trai ? tu_dien->trai : tu_dien->phai;
			if (q != NULL)
			{
				*tu_dien = *q;
			}
			else
			{
				tu_dien = NULL;
			}
		}

		free(q);
	}

	return tu_dien;
}