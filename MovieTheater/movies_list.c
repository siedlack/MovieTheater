#include <stdio.h>
#include "movies_list.h"
#include "csvparser.h"

int movies_list() {
	CsvParser *csvparser = CsvParser_new("movies.csv", ",", 1);
	CsvRow *header;
	CsvRow *row;

	header = CsvParser_getHeader(csvparser);
	if (header == NULL) {
		printf("%s\n", CsvParser_getErrorMessage(csvparser));
		return 1;
	}

	while ((row = CsvParser_getRow(csvparser))) {
		printf("\n");
		char **rowFields = CsvParser_getFields(row);
		for (int i = 0; i < CsvParser_getNumFields(row); i++) {
			printf("%s ", rowFields[i]);
		}
	}

	return 0;
}