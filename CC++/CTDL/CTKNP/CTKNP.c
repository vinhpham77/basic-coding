#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tu
{
	char t_Anh[20];
	char t_Viet[40];
};
struct Tu_Dien
{
	struct Tu tu;
	struct Tu_Dien *truoc, *sau;
};

struct Tu_Dien *doc_tep(char*);
int them(struct Tu_Dien**, struct Tu);
struct Tu_Dien *doc_tep(char*);
void in_tu_dien(struct Tu_Dien*);
int dem_nut(struct Tu_Dien*);
char *tra_t_Viet(struct Tu_Dien*, char*);
struct Tu_Dien *tim_tu(struct Tu_Dien*, char*);
int xoa_tu(struct Tu_Dien**, char*);
void in_nhung_tu_bat_dau_voi(struct Tu_Dien*, char);
int dem_nhung_tu_sau(struct Tu_Dien*, char*);
int tinh_chieu_cao(struct Tu_Dien*);
struct Tu_Dien *nut_min(struct Tu_Dien *);

int main()
{
	char t_Anh[20];
	char c;
	struct Tu_Dien *td = doc_tep("tudien.txt");

	in_tu_dien(td);

	printf("\nNhap tu tieng Anh can tra: ");
	gets(t_Anh);
	if (tra_t_Viet(td, t_Anh) == NULL)
	{
		printf("Khong tim thay!\n", t_Anh);
	}
	else
	{
		printf("Nghia tieng Viet cua %s la: %s\n", t_Anh, tra_t_Viet(td, t_Anh));
	}

	printf("\nNhap tu tieng Anh can xoa: ");
	gets(t_Anh);
	xoa_tu(&td, t_Anh);
	in_tu_dien(td);\
	
	c = 'h';
	printf("Nhung tu bat dau bang %c\n", c);
	in_nhung_tu_bat_dau_voi(td, c);
	
	printf("\nNhap tu vung muon dem so tu sau no: ");
	fflush(stdin);
	gets(t_Anh);
//  in_tu_dien(tim_tu(td, t_Anh));
	printf("\nSo tu sau %s la: %d", t_Anh, dem_nhung_tu_sau(td, t_Anh));
	
	printf("\nChieu cao cua cay: %d", tinh_chieu_cao(td));
	
	return 0;
}

// a. Thêm một từ vào cây
int them(struct Tu_Dien **goc, struct Tu tu)
{
	int so;
	struct Tu_Dien *p;
	struct Tu_Dien *q;

	if (*goc == NULL)
	{
		q = (struct Tu_Dien*) malloc(sizeof(struct Tu_Dien));
		q->tu = tu;
		q->truoc = NULL;
		q->sau = NULL;
		*goc = q;
	}
	else
	{
		p = *goc;
		so = strcmp(p->tu.t_Anh, tu.t_Anh);

		if (so < 0)
		{
			them(&p->sau, tu);
		}
		else if (so > 0)
		{
			them(&p->truoc, tu);
		}
	}
}

struct Tu_Dien *doc_tep(char *duong_dan)
{
	int k;
	struct Tu tu;
	char str_get[60];
	struct Tu_Dien *td = NULL;
	FILE *f = fopen(duong_dan, "r");

	while (fgets(str_get, 60, f))
	{
		k = strstr(str_get, ":") - str_get;
		strncpy(tu.t_Anh, str_get, k);
		tu.t_Anh[k] = '\0';
		strcpy(tu.t_Viet, str_get + k + 1);
		tu.t_Viet[strlen(tu.t_Viet) - 1] = '\0';
		them(&td, tu);
	}

	fclose(f);
	return td;
}

// b. Tìm nghĩa tiếng Việt của một từ tiếng Anh
char *tra_t_Viet(struct Tu_Dien *goc, char *t_Anh)
{
	int so;
	struct Tu_Dien *p = goc;

	while (p != NULL)
	{
		so = strcmp(p->tu.t_Anh, t_Anh);

		if(so == 0)
		{
			return p->tu.t_Viet;
		}
		else
		{
			if (so > 0)
			{
				p = p->truoc;
			}
			else
			{
				p = p->sau;
			}
		}
	}

	return NULL;
}

// c. In cây theo thứ tự từ điển
void in_tu_dien(struct Tu_Dien *goc)
{
	if (goc != NULL)
	{
		in_tu_dien(goc->truoc);
		printf("%s: %s\n", goc->tu.t_Anh, goc->tu.t_Viet);
		in_tu_dien(goc->sau);
	}
}

// d. Xóa 1 từ tiếng Anh x trong cây.
int xoa_tu(struct Tu_Dien **goc, char *t_Anh)
{
	struct Tu_Dien *p;
	struct Tu_Dien *q;
	int so;

	if (*goc == NULL)
	{
		return 0;
	}

	p = *goc;
	so = strcmp(p->tu.t_Anh, t_Anh);

	if (so < 0)
	{
		return xoa_tu(&p->sau, t_Anh);
	}

	if (so > 0)
	{
		return xoa_tu(&p->truoc, t_Anh);
	}

	if (p->truoc == NULL && p->sau == NULL)
	{
		*goc = NULL;
	}
	else if (p->truoc == NULL)
	{
		*goc = p->sau;
		free(p);
	}
	else if (p->sau == NULL)
	{
		*goc = p->truoc;
		free(p);
	}
	else
	{
		q = nut_min(p->truoc);
		strcpy(p->tu.t_Anh, q->tu.t_Anh);
		strcpy(p->tu.t_Viet, q->tu.t_Viet);
		q = q->sau;
	}
}

// e. In lên màn hình từ tiếng Anh và nghĩa tiếng Việt những từ tiếng Anh bắt đầu bằng H có trong cây.
void in_nhung_tu_bat_dau_voi(struct Tu_Dien *goc, char ki_tu)
{
	int so;
	
	if (goc == NULL)
	{
		return;
	}
	
	if (goc->tu.t_Anh[0] == ki_tu)
	{
		printf("%s: %s\n", goc->tu.t_Anh, goc->tu.t_Viet);
		in_nhung_tu_bat_dau_voi(goc->truoc, ki_tu);
		in_nhung_tu_bat_dau_voi(goc->sau, ki_tu);
	}
	else if (goc->tu.t_Anh[0] < ki_tu)
	{
		in_nhung_tu_bat_dau_voi(goc->sau, ki_tu);
	}
	else
	{
		in_nhung_tu_bat_dau_voi(goc->truoc, ki_tu);
	}
}

// f. Đếm trong cây có bao nhiêu từ sau từ t.
int dem_nhung_tu_sau(struct Tu_Dien *goc, char *t_Anh)
{
	struct Tu_Dien *p = tim_tu(goc, t_Anh);
	
	return p != NULL ? dem_nut(p->sau) : -1; 
}

// g. Tính chiều cao của cây.
int tinh_chieu_cao(struct Tu_Dien *goc)
{
	int t;
	int max = 0;
	
	if (goc != NULL)
	{
		t = tinh_chieu_cao(goc->truoc);
		if (t > max)
		{
			max = t;
		}
		
		t = tinh_chieu_cao(goc->sau);
		if (t > max)
		{
			max = t;
		}
		
		max++;	
	}
	
	return max;
}

struct Tu_Dien *tim_tu(struct Tu_Dien *goc, char *t_Anh)
{
	int so;
	struct Tu_Dien *p = goc;

	while (p != NULL)
	{
		so = strcmp(p->tu.t_Anh, t_Anh);

		if(so == 0)
		{
			return p;
		}
		else
		{
			if (so > 0)
			{
				p = p->truoc;
			}
			else
			{
				p = p->sau;
			}
		}
	}

	return NULL;
}

int dem_nut(struct Tu_Dien *goc)
{
	int dem = 0;
	
	if (goc != NULL)
	{
		dem = dem_nut(goc->truoc) + dem_nut(goc->sau) + 1;
	}
	
	return dem;
}

struct Tu_Dien *nut_min(struct Tu_Dien *goc)
{
	struct Tu_Dien *p;

	if(goc == NULL)
	{
		return NULL;
	}

	p = goc;

	if (p->truoc != NULL)
	{
		p = nut_min(goc->truoc);
	}

	return p;
}