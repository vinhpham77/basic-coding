#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EngDic
{
	struct EngDic *sub[27];
};
void insertWord(struct EngDic *d, char *w)
{
	struct EngDic *p = d; int i,j, k;
	for(i=0; i< strlen(w); i++)
	{
		j = w[i]-'a';
		if (p->sub[j]!=NULL)
			p = p->sub[j];
		else
		{
			p->sub[j] = (struct EngDic*) malloc(sizeof(struct EngDic));
			if(p->sub[j]==NULL) {
			printf("Loiiiii!"); return;}
			p = p->sub[j];
			for(k = 0; k < 27; k++) p->sub[k]=NULL;
		}
	}
	if(p->sub[26]==NULL)
	{
		p->sub[26] = (struct EngDic*) malloc(sizeof(struct EngDic));
		p = p->sub[26];
		for(k = 0; k < 27; k++) p->sub[k] = NULL;
	}
	else printf("\nTrung %s", w);
}
int find(struct EngDic *d, char *w)
{
	struct EngDic *p = d; int i,j, k;
	for(i=0; i< strlen(w); i++)
	{
		j = w[i]-'a';
		if (p->sub[j]!=NULL)
			p = p->sub[j];
		else
			return 0;
	}
	return p->sub[26]!=NULL;
}
void printEngDic(struct EngDic *d, char w[], int k)
{
	int i;
	if (d->sub[26]!=NULL)
	{
		w[k]='\0';
		printf("%s\n", w);
	}
	for(i=0; i< 26; i++)
		if(d->sub[i]!=NULL)
		{
			w[k]=(char)('a'+i);
			printEngDic(d->sub[i],w,k+1);
		}
}

struct EngDic* initDic()
{
	struct EngDic *goc = (struct EngDic*) malloc(sizeof(struct EngDic));
	int k;
	for(k = 0; k < 27; k++) goc->sub[k] = NULL;
	return goc;
}

int readDic(char *fileName, struct EngDic *goc)
{
	FILE *f; char w[40];
 	f = fopen(fileName,"r");
 	if(f==NULL) printf("Loi!!!");
 	int d = 0;
 	while (fgets(w, 40, f) != NULL)
 	{
 		int k = strlen(w);
 		if(w[k-1]=='\n') w[k-1]='\0';
 		insertWord(goc,w);
 		d++;
	}
	fclose(f);
	return d;
}
void main()
{
	struct EngDic *goc;int k; char w[40];
	goc = initDic();
	printf("Loading...");
	k = readDic("words_alpha.txt", goc);
	printf("%d words finished.\n",k);
	printf("Searching...\n");
	k = find(goc, "dichlorodiphenyltrichloroethane");
	printf("\n%d", k);
	printEngDic(goc, w, 0);
}