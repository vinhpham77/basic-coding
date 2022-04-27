#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Eng_Dictionary
{
	char word[20];

};

void insert_word(struct Eng_Dictionary*, char*);
struct Eng_Dictionary* init();
int find(struct Eng_Dictionary*, char*);
int read_txt(struct Eng_Dictionary*, char*);
void print(struct Eng_Dictionary*);

int main()
{

	return 0;
}