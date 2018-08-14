#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* readline();
//char** split_string(char*);

void sheft_left_array_2 (int n, int d, int* a) {
	printf("%d\n", d);
	d %= n;
	printf("%d\n", d);
	// int* start_address = a + d;
	int counter = 0, p;

	for (p = d; counter < n; p=(p+1)%n) {
		printf("%d ", a[p]);
		counter++;
	}
}

void sheft_left_array (int n, int d, int* a) {
	int temp, i, j, p;
	// printf("%d\n", d);
	d %= n;
	// printf("%d\n", d);
	for (i = 0; i < d; i++) {
		// printf("%s\n", "Here");
		temp = a[0];
		for (j = 0; j < n-1; j++) {
			a[j] = a[j+1];
		}
		a[n-1] = temp;
	}
	// print
	for (p = 0; p < n; p++) {
		printf("%d ", a[p]);
	}
	// printf("\n");
}

int main() {
	int n, d, i;
	scanf("%d", &n);
	scanf("%d", &d);
	int a[n];
	// int* a = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sheft_left_array(n, d, &a);
	return 0;
}

/*
int main() {
	char** nd = split_string(readline());

	char* n_endptr;
	char* n_str = nd[0];
	int n = strtol(n_str, &n_endptr, 10);

	if (n_endptr == n_str || *n_endptr != '\0') {
		exit(EXIT_FAILURE);
	}

	char* d_endptr;
	char* d_str = nd[1];
	int d = strtol(d_str, &d_endptr, 10);

	if (d_endptr == d_str || *d_endptr != '\0') {
		exit(EXIT_FAILURE);
	}

	char** a_temp = split_string(readline());

	int* a = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		char* a_item_endptr;
		char* a_item_str = *(a_temp + i);
		int a_item = strtol(a_item_str, &a_item_endptr, 10);

		if (a_item_endptr == a_item_str || *a_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}

		*(a + i) = a_item;
	}

	printf("%d\n", n);
	printf("%d\n", d);
	sheft_left_array_2(n, d, a);
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
*/
