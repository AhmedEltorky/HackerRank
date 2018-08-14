#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, m;
	float b, d;
	scanf("%d %d", &n, &m);
	scanf("%f %f", &b, &d);
	printf("%d %d", n+m, n-m);
	printf("\n");
	printf("%.1f %.1f", b+d, b-d);


	return 0;
}
