#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "csvparser.h"
#include "main_menu.h"
#include "ticketdata.h"

void main() {
	main_menu();
	get_ticketdata();

	getchar();
}