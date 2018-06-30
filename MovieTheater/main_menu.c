#include <stdio.h>
#include "csvparser.h"
#include "main_menu.h"
#include "reservation_manager.h"
#include "reservation_check.h"

void main_menu() {
	int choice;

	printf("Witaj w supernowoczesnym programie do rezerwacji miejsc w kinie!\n");
	printf("Co chcesz zrobic? Wybierz numer z menu.\n");
	printf("1. Wyswietl filmy.\n");
	printf("2. Sprawdz rezerwacje.\n");
	printf("3. Wyjdz.\n");
	scanf_s("%d", &choice);

	
	switch (choice) {
	case 1:
		movies_list();
		book_seats();
		create_ticketfile_with_ticketdata();
		break;
	case 2:
		check_reservation();
		break;
	case 3:
		printf("Czy na pewno chcesz wyjsc? Wcisnij dowolny klawisz aby potwierdzic.");
		getchar();
		break;
	default:
		printf("Niepoprawny input. Blad aplikacji.\n");
		break;
	}
}