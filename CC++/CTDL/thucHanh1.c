#include <stdio.h>
#include <string.h>

#define SL_TB_TOI_DA 100
#define SL_SDT_TOI_DA 10

struct Thue_Bao
{
	char ten[30];
	char dia_chi[50];
	char sdt[SL_SDT_TOI_DA][11];
	int sl_sdt;
};
struct Danh_Ba
{
	struct Thue_Bao thue_bao[SL_TB_TOI_DA];
	int sl_tb;
};

void thong_bao_thao_tac(int);
void nhap_thue_bao(struct Thue_Bao *);
void nhap_danh_ba(struct Danh_Ba *);
void in_thue_bao(struct Thue_Bao);
void in_danh_ba(struct Danh_Ba);
int them_sdt_vt(struct Danh_Ba *danh_ba, char *, int);
int them_sdt_ten(struct Danh_Ba *danh_ba, char *, char *);
void them_thue_bao_xep_tang(struct Danh_Ba *, struct Thue_Bao);
int them_thue_bao_vt(struct Danh_Ba *, struct Thue_Bao, int);
int xoa_thue_bao_vt(struct Danh_Ba *, int);
int xoa_thue_bao_ten(struct Danh_Ba *, char *);
int xoa_sdt(struct Danh_Ba *, char *);
int xoa_sdt_vt(struct Danh_Ba *, int, int);
int tim_thue_bao_ten(struct Danh_Ba, char *);
int tim_thue_bao_sdt(struct Danh_Ba, char *);
void sap_xep_ten_tang(struct Danh_Ba *);
int la_sdt_Viettel(char *);
void liet_ke_tb_dung_Viettel(struct Danh_Ba);

int main()
{
	struct Danh_Ba danh_ba;
	struct Thue_Bao thue_bao;
	int vt;
	char ten[30];
	char sdt[11];

	nhap_danh_ba(&danh_ba);
//	in_danh_ba(danh_ba);

	printf("\n");
	nhap_thue_bao(&thue_bao);
	printf("Nhap vi tri can them thue bao vao: ");
	scanf("%d", &vt);
	thong_bao_thao_tac(them_thue_bao_vt(&danh_ba, thue_bao, vt));
//	in_danh_ba(danh_ba);

	printf("\nNhap vi tri thue bao can xoa: ");
	scanf("%d", &vt);
	thong_bao_thao_tac(xoa_thue_bao_vt(&danh_ba, vt));
//	in_danh_ba(danh_ba);

	fflush(stdin);
	printf("\nNhap ten thue bao can tim: ");
	gets(ten);
	printf("Thue bao o vi tri: %d", tim_thue_bao_ten(danh_ba, ten));

	printf("\nNhap ten thue bao can xoa: ");
	gets(ten);
	thong_bao_thao_tac(xoa_thue_bao_ten(&danh_ba, ten));
//	in_danh_ba(danh_ba);

	printf("\nNhap so dien thoai cua thue bao can tim: ");
	gets(sdt);
	printf("Thue bao o vi tri: %d", tim_thue_bao_sdt(danh_ba, sdt));

	printf("\nNhap ten thue bao can them sdt: ");
	gets(ten);
	printf("Nhap so dien thoai: ");
	gets(sdt);
	thong_bao_thao_tac(them_sdt_ten(&danh_ba, sdt, ten));
//	in_danh_ba(danh_ba);

	sap_xep_ten_tang(&danh_ba);
//	in_danh_ba(danh_ba);

	printf("\nNhap so dien thoai can xoa: ");
	gets(sdt);
	thong_bao_thao_tac(xoa_sdt(&danh_ba, sdt));
//	in_danh_ba(danh_ba);

	printf("\n");
	liet_ke_tb_dung_Viettel(danh_ba);

	printf("\n");
	nhap_thue_bao(&thue_bao);
	them_thue_bao_xep_tang(&danh_ba, thue_bao);
	printf("\n");
	in_danh_ba(danh_ba);

	getchar();
	return 0;
}

void thong_bao_thao_tac(int thanh_cong)
{
	if (thanh_cong)
	{
		printf("Thanh cong!\n");
	}
	else
	{
		printf("That bai!\n");
	}
}
void nhap_thue_bao(struct Thue_Bao *thue_bao)
{
	int i;

	fflush(stdin);
	printf("Nhap ten thue bao: ");
	gets(thue_bao->ten);
	printf("Nhap dia chi: ");
	gets(thue_bao->dia_chi);
	printf("Nhap so luong sdt: ");
	scanf("%d", &thue_bao->sl_sdt);
	fflush(stdin);

	for (i = 0; i < thue_bao->sl_sdt; i++)
	{
		printf("Nhap so dien thoai thu %d: ", i);
		gets(thue_bao->sdt[i]);
	}
}

void nhap_danh_ba(struct Danh_Ba *danh_ba)
{
	int i;

	printf("Nhap so luong thue bao: ");
	scanf("%d", &danh_ba->sl_tb);

	for (i = 0; i < danh_ba->sl_tb; i++)
	{
		nhap_thue_bao(&danh_ba->thue_bao[i]);
	}
}

void in_thue_bao(struct Thue_Bao thue_bao)
{
	int i;
	
	printf("Ten thue bao: %s\n", thue_bao.ten);
	printf("Dia chi: %s\n", thue_bao.dia_chi);
	printf("So luong so dien thoai: %d\n", thue_bao.sl_sdt);

	for (i = 0; i < thue_bao.sl_sdt; i++)
	{
		printf("So dien thoai thu %d: %s\n", i, thue_bao.sdt[i]);
	}
}

void in_danh_ba(struct Danh_Ba danh_ba)
{
	int i;
	
	for (i = 0; i < danh_ba.sl_tb; i++)
	{
		in_thue_bao(danh_ba.thue_bao[i]);
	}
}

int them_thue_bao_vt(struct Danh_Ba *danh_ba, struct Thue_Bao thue_bao, int vt)
{
	int i;

	if (vt < 0 || vt > danh_ba->sl_tb || danh_ba->sl_tb == SL_TB_TOI_DA)
	{
		return 0;
	}

	for (i = danh_ba->sl_tb; i > vt; i--)
	{
		danh_ba->thue_bao[i] = danh_ba->thue_bao[i - 1];
	}

	danh_ba->thue_bao[vt] = thue_bao;
	danh_ba->sl_tb++;

	return 1;
}

int xoa_thue_bao_vt(struct Danh_Ba *danh_ba, int vt)
{
	int i;

	if (vt < 0 || vt >= danh_ba->sl_tb || danh_ba->sl_tb == 0)
	{
		return 0;
	}

	for (i = vt + 1; i < danh_ba->sl_tb; i++)
	{
		danh_ba->thue_bao[i - 1] = danh_ba->thue_bao[i];
	}

	danh_ba->sl_tb--;

	return 1;
}

int tim_thue_bao_ten(struct Danh_Ba danh_ba, char *ten)
{
	int i;

	for (i = 0; i < danh_ba.sl_tb; i++)
	{
		if (strcmp(danh_ba.thue_bao[i].ten, ten) == 0)
		{
			return i;
		}
	}

	return -1;
}

int xoa_thue_bao_ten(struct Danh_Ba *danh_ba, char *ten)
{
	int vt = tim_thue_bao_ten(*danh_ba, ten);

	return xoa_thue_bao_vt(danh_ba, vt);
}

int tim_thue_bao_sdt(struct Danh_Ba danh_ba, char *sdt)
{
	int i;
	int j;

	for (i = 0; i < danh_ba.sl_tb; i++)
	{
		for (j = 0; j < danh_ba.thue_bao[i].sl_sdt; j++)
		{
			if (strcmp(danh_ba.thue_bao[i].sdt[j], sdt) == 0)
			{
				return i;
			}
		}
	}

	return -1;
}

void sap_xep_ten_tang(struct Danh_Ba *danh_ba)
{
	int i;
	int j;
	struct Thue_Bao tg;

	for(i = 0; i < danh_ba->sl_tb  -1; i++)
	{
		for(j = i + 1; j < danh_ba->sl_tb; j++)
		{
			if(strcmp(danh_ba->thue_bao[i].ten, danh_ba->thue_bao[j].ten) > 0)
			{
				tg = danh_ba->thue_bao[i];
				danh_ba->thue_bao[i] = danh_ba->thue_bao[j];
				danh_ba->thue_bao[j] = tg;
			}
		}
	}
}

int them_sdt_vt(struct Danh_Ba *danh_ba, char *sdt, int vt_tb)
{
	int n;

	if (vt_tb > -1 && vt_tb < danh_ba->sl_tb && danh_ba->thue_bao[vt_tb].sl_sdt < SL_SDT_TOI_DA)
	{
		n = danh_ba->thue_bao[vt_tb].sl_sdt;
		strcpy(danh_ba->thue_bao[vt_tb].sdt[n], sdt);
		danh_ba->thue_bao[vt_tb].sl_sdt++;

		return 1;
	}

	return 0;
}

int them_sdt_ten(struct Danh_Ba *danh_ba, char *sdt, char *ten)
{
	int vt = tim_thue_bao_ten(*danh_ba, ten);

	return them_sdt_vt(danh_ba, sdt, vt);
}

int xoa_sdt_vt(struct Danh_Ba *danh_ba, int vt_tb, int vt_sdt)
{
	int i;

	if(vt_tb >= danh_ba->sl_tb || vt_tb < 0 || vt_sdt < 0 || vt_sdt >= danh_ba->thue_bao[vt_tb].sl_sdt)
	{
		return 0;
	}

	for(i = vt_sdt + 1; i < danh_ba->thue_bao[vt_tb].sl_sdt; i++)
	{
		strcpy(danh_ba->thue_bao[vt_tb].sdt[i - 1], danh_ba->thue_bao[vt_tb].sdt[i]);
	}

	danh_ba->thue_bao[vt_tb].sl_sdt--;
	return 1;
}

int xoa_sdt(struct Danh_Ba *danh_ba, char *sdt)
{
	int i;
	int j;

	for(i = 0; i < danh_ba->sl_tb; i++)
	{
		for( j = 0; j < danh_ba->thue_bao[i].sl_sdt; j++)
		{
			if(strcmp(danh_ba->thue_bao[i].sdt[j], sdt) == 0)
			{
				return xoa_sdt_vt(danh_ba, i, j);
			}
		}
	}

	return 0;
}

// Thue bao dung mang Viettel la thue bao co dung sdt bat dau bang 097 hoac 098
int la_sdt_Viettel(char *sdt)
{
//	return strstr(sdt, "097") == &sdt[0] || strstr(sdt, "098") == &sdt[0];
	return strstr(sdt, "09") == &sdt[0] && (sdt[2] == '7' || sdt[2] == '8');
}

void liet_ke_tb_dung_Viettel(struct Danh_Ba danh_ba)
{
	int i;	
	int j;
	int co_sdt_Viettel;
	
	for (i = 0; i < danh_ba.sl_tb; i++)
	{
		co_sdt_Viettel = 0;
		for (j = 0; j < danh_ba.thue_bao[i].sl_sdt && co_sdt_Viettel == 0; j++)
		{
			if (la_sdt_Viettel(danh_ba.thue_bao[i].sdt[j]))
			{
				in_thue_bao(danh_ba.thue_bao[i]);
				co_sdt_Viettel = 1;
			}
		}
	}
}

// Them nhung sdt cua thue_bao chua co trong danh_ba->thue_bao[vi_tri].sdt[]
void them_ds_sdt(struct Danh_Ba *danh_ba, struct Thue_Bao thue_bao, int vt)
{
	int i;
	int n = danh_ba->thue_bao[vt].sl_sdt;
	char xau_ds_sdt[SL_SDT_TOI_DA * 11 + 12] = "";

	if(danh_ba->thue_bao[vt].sl_sdt == SL_SDT_TOI_DA)
	{
		return;
	}

	for(i = 0; i < n; i++)
	{
		strcat(xau_ds_sdt, danh_ba->thue_bao[vt].sdt[i]);
		strcat(xau_ds_sdt, ";");
	}

	for(i = 0; i < thue_bao.sl_sdt && n < SL_SDT_TOI_DA; i++)
	{
		if(strstr(xau_ds_sdt, thue_bao.sdt[i]) == NULL)
		{
			strcpy(danh_ba->thue_bao[vt].sdt[n], thue_bao.sdt[i]);
			danh_ba->thue_bao[vt].sl_sdt++;
			n++;
		}
	}
}

// Them thue_bao vao danh_ba neu chua co trong danh ba,
// nguoc lai thi them nhung sdt cua thue_bao chua co o thue bao da co trong danh_ba.
void them_thue_bao_xep_tang(struct Danh_Ba *danh_ba, struct Thue_Bao thue_bao)
{
	int i;
	int j;
	int kq_so_ten;

	for (i = 0; i < danh_ba->sl_tb; i++)
	{
		kq_so_ten = strcmp(danh_ba->thue_bao[i].ten, thue_bao.ten);

		if (kq_so_ten > 0)
		{
			them_thue_bao_vt(danh_ba, thue_bao, i);
			return;
		}
		else if(kq_so_ten == 0)
		{
			if(strcmp(danh_ba->thue_bao[i].dia_chi, thue_bao.dia_chi) == 0)
			{
				them_ds_sdt(danh_ba, thue_bao, i);
				return;
			}
			else
			{
				break;
			}
		}
	}

	for(j = i + 1; j < danh_ba->sl_tb; j++)
	{
		kq_so_ten = strcmp(danh_ba->thue_bao[j].ten, thue_bao.ten);

		if(kq_so_ten == 0)
		{
			if(strcmp(danh_ba->thue_bao[j].dia_chi, thue_bao.dia_chi) == 0)
			{
				them_ds_sdt(danh_ba, thue_bao, j);
				return;
			}
		}
		else
		{
			break;
		}
	}

	them_thue_bao_vt(danh_ba, thue_bao, i);
}