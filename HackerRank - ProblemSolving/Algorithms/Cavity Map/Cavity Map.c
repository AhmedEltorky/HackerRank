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

// Complete the cavityMap function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
char** cavityMap(int grid_count, char** grid, int* result_count) {
	*result_count = grid_count;

	for (int r = 0; r < grid_count; r++) {
		for (int c = 0; c < grid_count; c++) {
			if ((r == 0 || r == grid_count-1)||(c == 0 || c == grid_count-1)) {

			} else {
				if (grid[r][c+1] < grid[r][c] && grid[r][c-1] < grid[r][c] && grid[r+1][c] < grid[r][c] && grid[r-1][c] < grid[r][c]) {
					grid[r][c] = 'X';
				}
			}
		}
	}

	return grid;
}

int main() {
	FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

	char* n_endptr;
	char* n_str = readline();
	int n = strtol(n_str, &n_endptr, 10);

	if (n_endptr == n_str || *n_endptr != '\0') {
		exit(EXIT_FAILURE);
	}

	char** grid = malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		char* grid_item = readline();

		*(grid + i) = grid_item;
	}

	int grid_count = n;

	int result_count;
	char** result = cavityMap(grid_count, grid, &result_count);

	for (int i = 0; i < result_count; i++) {
		fprintf(fptr, "%s", *(result + i));

		if (i != result_count - 1) {
			fprintf(fptr, "\n");
		}
	}

	fprintf(fptr, "\n");

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

