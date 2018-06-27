#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screening_room_manager.h"

#define MAXB 32
#define MAXL 18
#define MAXD 5

char lines[MAXL][MAXD];
int numlines = 0;
char full_path[20] = "";

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
		return 1;
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

void book_seats() {
	char movie = "";
	int seats_num, x, y, seat, w=0;

	printf("\n\nWybierz film aby wyswietlic wolne miesca:\n");
	scanf("%c", &movie);

	show_screening_room(movie);

	printf("\n\nIle miejsc chcesz zarezerwowac?:\n");
	scanf("%d", &seats_num);

	FILE *tmp_file = fopen("files/tmp_file.txt", "wb");

	do {
		printf("Podaj miejsce #%d miejsce (rzad, kolumna)\n", w);
		scanf("%d %d", &x, &y);
		if (lines[x][y] == 1) printf("To miejsce jest juz zajete, sprobuj wybrac inne miejsce.\n", x, y);
		else {
			lines[x][y] = 1;
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
	} else printf("Unable to delete the file");

	return 0;
}

