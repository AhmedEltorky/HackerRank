#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the birthdayCakeCandles function below.
int birthdayCakeCandles(int ar_count, int* ar) {
	int arr[ar_count][2];
	for (int i = 0; i < ar_count; i++) {
		arr[i][0] = 0;
		arr[i][1] = 1;
	}

	int index = 1, not_yet = 1;
	for (int i = 0; i < ar_count; i++) {
		for (int k = 0; k < index; k++) {
			if (ar[i] == arr[k][0]) {
				arr[k][1]++;
				not_yet = 0;
			}
		}
		if (not_yet == 1) {
			arr[index-1][0] = ar[i];
			index++;
			not_yet = 1;
		}
	}

	int max = 0;
	for (int i = 0; i < index; i++) {
		if (max < arr[i][1]) {
			max = arr[i][1];
		}
	}
	return max;
}

int main() {
	FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char* ar_count_endptr;
	char* ar_count_str = readline();
	int ar_count = strtol(ar_count_str, &ar_count_endptr, 10);

	if (ar_count_endptr == ar_count_str || *ar_count_endptr != '\0') {
		exit(EXIT_FAILURE);
	}

	char** ar_temp = split_string(readline());

	int* ar = malloc(ar_count * sizeof(int));

	for (int i = 0; i < ar_count; i++) {
		char* ar_item_endptr;
		char* ar_item_str = *(ar_temp + i);
		int ar_item = strtol(ar_item_str, &ar_item_endptr, 10);

		if (ar_item_endptr == ar_item_str || *ar_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}

		*(ar + i) = ar_item;
	}

	int result = birthdayCakeCandles(ar_count, ar);

	fprintf(fptr, "%d\n", result);

	fclose(fptr);

	return 0;
}

char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char* data = malloc(alloc_length);

	while (true) {
		char* cursor = data + data_length;
		char* line = fgets(cursor, alloc_length - data_length, stdin);

		if (!line) {
			break;
		}

		data_length += strlen(cursor);

		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
			break;
		}

		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);

		if (!data) {
			break;
		}

		alloc_length = new_length;
	}

	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}

	data = realloc(data, data_length);

	return data;
}

char** split_string(char* str) {
	char** splits = NULL;
	char* token = strtok(str, " ");

	int spaces = 0;

	while (token) {
		splits = realloc(splits, sizeof(char*) * ++spaces);
		if (!splits) {
			return splits;
		}

		splits[spaces - 1] = token;

		token = strtok(NULL, " ");
	}

	return splits;
}

