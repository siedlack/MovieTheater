#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "ticketdata.h"


void create_ticketfile_with_ticketdata() 
{
	char phonenumber[10];
	char name[30];
	int i,j;
	int cout = 0;
	int name_len = 0;

	getchar();
	printf("Podaj imie i nazwisko: \n");
	fgets(name, sizeof name, stdin);
	name_len = strlen(name);
	for (int i = 0; i < name_len; i++)
	{
		if (isdigit(name[i]))
		{
			printf("Imie i nazwisko nie moga zawierac cyfr \n");
			return 0;
		}
	}
	getchar();
	printf("Podaj numer telefonu i nacisnij enter ");
	fgets(phonenumber, sizeof phonenumber, stdin);

	// sprawdzenie dlugosci numeru telefonu
	if (strlen(phonenumber) != 9)
	{
		printf("Numer telefonu powinien skladac sie z 9 znakow \n");
		return 0;
	}

	for (int j = 0; j < 9; j++)
	{
		if (isdigit(phonenumber[j]))
		{
			cout++;
		}
		else
		{
			printf("Numer telefonu ma sie skladac tylko z cyfr\n");
			return 0;
		}
	}

	char filename[20];
	char buff[255];

	FILE* fp;
	srand(time(NULL));
	sprintf(filename, "%d.txt", rand());

	//wyswitlanie nazwy pliku txt
	printf("Nazwa pliku txt: %s\n" ,filename);

	// zapisanie danych do pliku
	fp = fopen(filename, "w");

	if (NULL == fp)
	{
		fprintf(stderr, "Cannot open file: %s\n", filename);
		return 1;
	}

	fprintf(fp, "Imie i nazwisko: %s", name);
	fprintf(fp, "Numer telefonu: %s", phonenumber);
	fclose(fp);

	// czytanie pliku txt
	fp = fopen(filename, "r");
	if (NULL == fp)
	{
		fprintf(stderr, "Cannot open file: %s\n", filename);
		return 1;
	}
	const size_t line_size = 100;
	char* line = malloc(line_size);
	while (fgets(line, line_size, fp) != NULL) {
		printf(line);
	}
	free(line);
	fclose(fp);

	return 0;
}

