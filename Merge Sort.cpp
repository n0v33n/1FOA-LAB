//1.   What is the running time of merge sort?
//2. What technique is used to sort elements in merge sort?
//3.   Is merge sort in place sorting algorithm? 
//4.   Define stable sort algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[50000]; // Local array for merging
    
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int a[], int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
}

int main() {
    int n, k;
    clock_t st, et;
    double ts;

    printf("\nEnter How many Numbers: ");
    scanf("%d", &n);

    int a[50000];
    printf("\nThe Random Numbers are:\n");
    for (k = 0; k < n; k++) {
        a[k] = rand() % 1000; // Generating random numbers between 0 and 999
        printf("%d\t", a[k]);
    }

    st = clock();
    MergeSort(a, 0, n - 1);
    et = clock();

    printf("\nSorted Numbers are: \n");
    for (k = 0; k < n; k++) {
        printf("%d\t", a[k]);
    }

    ts = (double)(et - st) / CLOCKS_PER_SEC;
    printf("\nThe time taken is %e", ts);

    return 0;
}

