#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
	// triangle tr_temp[n];
	triangle *tr_temp = malloc(n * sizeof(triangle));
	int i, k;
	float s_arr[n], p;
	for(i = 0; i < n; i++) {
		p = ((float) tr[i].a+(float) tr[i].b+(float) tr[i].c)/2;
		s_arr[i] = sqrt(p*(p-(float) tr[i].a)*(p-(float) tr[i].b)*(p-(float) tr[i].c));
	}
	// sorting
	int index, j = 0;
	float min = 100000;
	for (k = 0; k < n; k++) {
		min = s_arr[0];
		index = 0;
		for(i = 0; i < n; i++) {
			if (min > s_arr[i]) {
				min = s_arr[i];
				index = i;
			}
		}
		tr_temp[j].a = tr[index].a;
		tr_temp[j].b = tr[index].b;
		tr_temp[j].c = tr[index].c;
		j++;
		s_arr[index] = 100000;
	}
//	tr = tr_temp; // ???? why not working
	for (i = 0; i < n; i++) {
		tr[i].a = tr_temp[i].a;
		tr[i].b = tr_temp[i].b;
		tr[i].c = tr_temp[i].c;
	}
}

int main() {
	int n, i;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
