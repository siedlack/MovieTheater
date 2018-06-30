#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation_manager.h"

#define MAXB 32
#define MAXL 18
#define MAXD 5

char lines[MAXL][MAXD];
int numlines = 0;
char full_path[20] = "";
char seats[200];

void show_screening_room(char screening_room) {
	int i = 0;
	char buf[MAXB] = { 0 };
	char default_path[10] = "files/sr", ext[10] = ".txt";

	strcat(full_path, default_path);
	strcat(full_path, &screening_room);
	strcat(full_path, ext);

	FILE *fp = fopen(full_path, "r");

	if (fp == 0)
	{
		fprintf(stderr, "cannot open file %s\n", full_path);
		exit(0);
	}

	while (i < MAXL && fgets(buf, MAXB, fp))
	{
		if (sscanf(buf, "%hhd %hhd %hhd %hhd %hhd", &lines[i][0], &lines[i][1], &lines[i][2], &lines[i][3], &lines[i][4]) == 5)
			i++;
	}

	fclose(fp);

	numlines = i;

	int j = 0;

	for (i = 0; i < numlines; i++) {
		for (j = 0; j < MAXD; j++) {
			printf("%hhd ", lines[i][j]);
		}
		printf("\n");
	}
}

const char  *book_seats() {
	char m;
	int movie;
	int seats_num, x, y, seat, w=0;
	
	printf("\n\nWybierz film aby wyswietlic wolne miesca:\n");
	scanf("%d", &movie);
	m = movie + '0';

	show_screening_room(m);

	printf("\n\nIle miejsc chcesz zarezerwowac?:\n");
	scanf("%d", &seats_num);

	FILE *tmp_file = fopen("files/tmp_file.txt", "wb");

	int pos = 0;

	do {
		printf("Podaj miejsce #%d miejsce (rzad, kolumna) liczac od 0.\n", w);
		scanf("%d %d", &x, &y);
		if (lines[x][y] == 1) printf("To miejsce jest juz zajete, sprobuj wybrac inne miejsce.\n", x, y);
		else {
			lines[x][y] = 1;
			pos += sprintf(&seats[pos], "Rzad: %d  Miejsce: %d\n", x, y);
			w++;
		}
		
	} while (w != seats_num);

	for (int i = 0; i < numlines; i++) {
		for (int j = 0; j < MAXD; j++) {
			fprintf(tmp_file, "%d ", lines[i][j]);
		}
		fprintf(tmp_file,"\n");
	}

	fclose(tmp_file);
	if (remove(full_path) == 0) {
		rename("files/tmp_file.txt", full_path);
	} else printf("Unable to delete the file\n");

}

void create_ticketfile_with_ticketdata()
{
	char phonenumber[10];
	char name[30];
	int i, j;
	int cout = 0;
	int name_len = 0;
	int back = 0;

	while (back == 0) {
		getchar();
		printf("\n####################\n");
		printf("Podaj imie i nazwisko:");
		fgets(name, sizeof name, stdin);
		name_len = strlen(name);
		for (int i = 0; i < name_len; i++)
		{
			if (isdigit(name[i]))
			{
				printf("Imie i nazwisko nie moga zawierac cyfr \n");
				back = 0;
				break;
			}
			else {
				back = 1;
			}
		}
	}

	back = 0;
	while (back == 0)
	{
		getchar();
		printf("Podaj numer telefonu: ");
		fgets(phonenumber, sizeof phonenumber, stdin);

		// sprawdzenie dlugosci numeru telefonu
		if (strlen(phonenumber) != 9)
		{
			printf("Numer telefonu powinien skladac sie z 9 znakow \n");
			back = 0;
		}
		else
		{
			back = 1;
		}

		if (back == 1)
		{
			for (int j = 0; j < 9; j++)
			{
				if (isdigit(phonenumber[j]))
				{
					cout++;
				}
				else
				{
					printf("Numer telefonu ma sie skladac tylko z cyfr\n");
					back = 0;
					break;
				}
			}
		}
	}

	char filename[20];
	char buff[255];

	FILE* fp;
	srand(time(NULL));
	sprintf(filename, "files/%d.txt", rand());

	//wyswitlanie nazwy pliku txt
	printf("Nazwa pliku txt: %s\n", filename);

	// zapisanie danych do pliku
	fp = fopen(filename, "w");

	if (NULL == fp)
	{
		fprintf(stderr, "Nie mozna otworzyc pliku: %s\n", filename);
		return 1;
	}

	fprintf(fp, "Imie i nazwisko: %s", name);
	fprintf(fp, "Numer telefonu: %s", phonenumber);
	// zapisywanie miejsc z funkcji book_seats()
	fprintf(fp, "\n%s", seats);

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

