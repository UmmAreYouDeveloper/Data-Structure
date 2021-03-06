#include <stdio.h>

typedef int element;
int size, i = 0;

int partition(element a[], int begin, int end) {
	int  pivot, L, R, t;
	element temp;
	L = begin;
	R = end + 1;
	pivot = begin;

	printf("\n [Step %d: pivot=%d ] \n", ++i, a[pivot]);
	do {
		do {
			L++; // start L = begin
		} while ((a[L] < a[pivot]) && (L <= R));
		do {
			R--; // start R = end            
		} while ((a[R] >= a[pivot]) && (L <= R));

		if (L < R) { // swap the locations of L and R 
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
		}
	} while (L < R);

	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;

	for (t = 0; t < size; t++) printf(" %d", a[t]);    // print the up-to-date sorted array results
	printf("\n");
	return R;    // return pivot location
}

void quickSort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);
		quickSort(a, begin, p - 1);// Quick sort of the left subset of the pivot
		quickSort(a, p + 1, end);// Quick sort of the right subset of the pivot
	}
}

void main() {
	element list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	printf("\n [ Initialization ] \n");
	for (int i = 0; i < size; i++) printf(" %d", list[i]);
	printf("\n");
	quickSort(list, 0, size - 1);
	getchar();
}