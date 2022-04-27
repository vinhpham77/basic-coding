#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nguoi
{
	char ho_ten[40];
	int nam_sinh;
};
struct CGP
{
	struct Nguoi du_lieu;
	struct CGP *em, *con;
};
struct Queue
{
	struct CGP *cgp;
	struct CGP *lk;
};

struct CGP *tao_CGP();
void add(struct Queue**, struct Queue**, struct CGP*);
struct CGP *remove(struct Queue**, struct Queue**);
struct CGP *tao_nut(char*, int, struct CGP*, struct CGP*);
void in_theo_the_he(struct CGP*);
int dem(struct CGP*);
int tinh_so_the_he(struct CGP*);
struct CGP *tim(struct CGP*, char*);
int la_con(struct CGP*, char*, char*);
int them_con(struct CGP*, char*, struct Nguoi*);

int main()
{
	struct CGP *goc = tao_CGP();


	return 0;
}

void in_theo_the_he(struct CGP *goc)
{
	struct CGP *p;

	if (goc != NULL)
	{
		p = goc;
		printf("%s, %d\n", p->du_lieu.ho_ten, p->du_lieu.nam_sinh);

	}
}
int dem(struct CGP*);
int tinh_so_the_he(struct CGP*);
struct CGP *tim(struct CGP*, char*);
int la_con(struct CGP*, char*, char*);
int them_con(struct CGP*, char*, struct Nguoi*);

struct CGP *tao_CGP()
{
	struct CGP *goc, *ng1, *ng2, *ng3, *ng4, *ng5, *ng6, *ng7;

	ng1 = tao_nut("Nguyen H", 1970, NULL, NULL);
	ng2 = tao_nut("Nguyen G", 1965, ng1, NULL);
	ng3 = tao_nut("Nguyen C", 1935, NULL, ng2);
	ng4 = tao_nut("Nguyen F", 1965, NULL, NULL);
	ng5 = tao_nut("Nguyen E", 1960, ng4, NULL);
	ng6 = tao_nut("Nguyen D", 1955, ng5, NULL);
	ng7 = tao_nut("Nguyen B", 1930, ng3, ng6);
	goc = tao_nut("Nguyen A", 1900, NULL, ng7);
}

struct CGP *tao_nut(char *ho_ten, int nam_sinh, struct CGP *em, struct CGP *con)
{
	struct CGP *p = (struct CGP*) malloc(sizeof(struct CGP*));

	strcpy(p->du_lieu.ho_ten, ho_ten);
	p->du_lieu.nam_sinh = nam_sinh;
	p->em = em;
	p->con = con;

	return p;
}

void add(struct Queue **dau, struct Queue **cuoi, struct CGP *cgp)
{
	struct Queue *p;
	struct Queue *q = (struct Queue*) malloc(sizeof(struct CGP*));

	q->cgp = cgp;
	q->lk = NULL;

	if (*dau == NULL)
	{
		*dau = *cuoi = q;
	}
	else
	{
		p = *cuoi;
		p->lk = q;
		*cuoi = q;
	}
}

struct CGP *remove(struct Queue **dau, struct Queue **cuoi)
{
	struct Queue *p;
	struct CGP *q;

	if (*dau == NULL)
	{
		return NULL;
	}
	else
	{
		p = *dau;
		q = p->cgp;

		if (*dau == *cuoi)
		{
			free(*dau);
			free(*cuoi);
			*dau = *cuoi = NULL;
		}
		else
		{
			*dau = p->lk;
			free(p);
		}

		return q;
	}
}