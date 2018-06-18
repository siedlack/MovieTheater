#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticketdata.h"


void create_ticketfile_with_ticketdata()
{
	char phonenumber[10];
	char name[60];
	printf("Podaj imie i nazwisko \n");
	fgets(name, sizeof name, stdin);
	printf("Podaj numer telefonu: \n");
	fgets(phonenumber, sizeof phonenumber, stdin);

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