#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Exch(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void QuickSort(int a[], int low, int high) {
    if (low >= high) {
        return;
    }

    int key = low;
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= a[key]) {
            i++;
        }
        while (a[j] > a[key]) {
            j--;
        }
        if (i < j) {
            Exch(&a[i], &a[j]);
        }
    }
    Exch(&a[j], &a[key]);
    QuickSort(a, low, j - 1);
    QuickSort(a, j + 1, high);
}

int main() {
    int n, k;
    clock_t st, et;
    double ts;

    printf("\nEnter How many Numbers: ");
    scanf("%d", &n);

    int a[1000];
    printf("\nThe Random Numbers are:\n");
    for (k = 0; k < n; k++) {
        a[k] = rand() % 1000; // Generating random numbers between 0 and 999
        printf("%d\t", a[k]);
    }

    st = clock();
    QuickSort(a, 0, n - 1);
    et = clock();

    printf("\nSorted Numbers are: \n");
    for (k = 0; k < n; k++) {
        printf("%d\t", a[k]);
    }

    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nThe time taken is %e", ts);

    return 0;
}

