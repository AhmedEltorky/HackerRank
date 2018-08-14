#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FILE* fptr;
//char* readline();

/*
 * Complete the timeConversion function below.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s) {
	// fprintf(fptr, "%d\n", sizeof(s));
	int i;
	char s2[sizeof(s)];
	printf("%d\n", sizeof(s));
	for (i = 0; i < sizeof(s); i++) {
		s2[i] = s[i];
		// fprintf(fptr, "%c", s2[i]);
	}

	if (s[8] == 'P') {
		int hr = s[1] - '0';
		hr += (s[0] - '0') * 10;
		if (hr != 12) {
			hr += 12;
		}
		hr %= 24;
		s2[0] = (hr / 10) + '0';
		s2[1] = (hr % 10) + '0';
	} else {
		int hr = s[1] - '0';
		hr += (s[0] - '0') * 10;
		if (hr == 12) {
			s2[0] = '0';
			s2[1] = '0';
		}
	}
	// fprintf(fptr, "\n%s\n", s2);
//	s = &s2;
	// fprintf(fptr, ">> %s\n", s);

//	fprintf(fptr, "%s\n", s);
//	printf("%s\n", s2);
	return &s2;
}

int main() {
//	fptr = fopen(getenv("OUTPUT_PATH"), "w");

//	char* s;
//	scanf("%s", s);
//	
//	int i = 0;
//	while (scanf("%c", (s+i)) != '\n') {
//		printf("%c", *(s+i));
//		i++;
//	}
	
	char *s;
    s = malloc(10 * sizeof(char));
    scanf("%[^\n]", s);
//	s = realloc(s, strlen(s));
	
//	printf("%s\n", s);
	char* result = timeConversion(s);
	printf("%s\n", result);

//	timeConversion(s);

	// fprintf(fptr, "%s\n", result);

//	fclose(fptr);

	return 0;
}

/*
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
*/
