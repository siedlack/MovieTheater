#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<errno.h>

int main() {
	const char* tab= malloc(5);
	const char * files = "files\\";
	const char * txt = ".txt";
	const char *result = malloc(100);
	char *bufor = malloc(200);
	const char *napis = malloc(200);
	
	printf("podaj 4 cyfrowy kod: \n");
	fgets(tab, 5, stdin);
	
	strcpy(result, files);

	strcat(result, tab);

	strcat(result, txt);
	printf(result);
	printf("\n");

	
	FILE *f = fopen(result, "r");
	if (f == NULL) {

		puts("plik nie istnieje\n");
		system("pause");
		return 1;
	}
	puts("plik istnieje, zara go wypisze, pacz jak leci\n");
	while(!feof(f))
	{
		result = fgets(napis, 200, f);   // wypisuje plik linia po linii
		if (result != NULL)
		{
			printf("%s", napis);
		}
		else
			printf("blad odczytu");
	}
	puts("\n");
	system("pause");
	return 0;

}