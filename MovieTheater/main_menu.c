#include <stdio.h>
#include "main_menu.h"
#include "movies_list.h"

int main_menu() {
	int choice;

	printf("Witaj w supernowoczesnym programie do rezerwacji miejsc w kinie!\n");
	printf("Co chcesz zrobic? Wybierz numer z menu.\n");
	printf("1. Wyswietl filmy.\n");
	printf("2. Sprawdz rezerwacje.\n");
	printf("3. Wyjdz z naszej supernowoczesnej aplikacji\n");
	scanf_s("%d", &choice);

	switch (choice) {
		case 1:
			movies_list();
			break;
		case 2:
			// TODO sprawdzenie rezerwacji
			create_ticketfile_with_ticketdata();
			system("pause");
			break;
		default:
			printf("Czy na pewno chcesz wyjsc? To naprawde dobra apka");
			getchar();
			break;
	}

	return 0;
}