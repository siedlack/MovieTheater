#include <stdio.h>
#include "ticketdata.h"

int get_ticketdata() {
	char phonenumber[10];
	char name[60];
	printf("Podaj imie i nazwisko \n");
	fgets(name, sizeof name, stdin);
	printf("Podaj numer telefonu: \n");
	fgets(phonenumber, sizeof phonenumber, stdin);
	printf_s("%s %s \n", name, phonenumber);

	return 0;
}