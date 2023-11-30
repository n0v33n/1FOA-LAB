//1.   Define Optimal Solution.
//2.   Explain Travelling Sales Person Problem.
//3.   What is the time complexity of Travelling Sales Person Problem?
#include<stdio.h>

#define MAX 100
#define INF 999

int s, c[MAX][MAX];

void swap(int v[], int i, int j) {
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void brute_force(int v[], int n, int i) {
    int j, sum1, k;

    if (i == n) {
        if (v[0] == s) {
            sum1 = 0;
            for (k = 0; k < n - 1; k++) {
                sum1 += c[v[k]][v[k + 1]];
            }
            sum1 += c[v[n - 1]][s];

            printf("Sum = %d\n", sum1);
        }
    } else {
        for (j = i; j < n; j++) {
            swap(v, i, j);
            brute_force(v, n, i + 1);
            swap(v, i, j);
        }
    }
}

void nearest_neighbor(int ver) {
    int min, p, i, j, vis[MAX], from;
    
    for (i = 1; i <= ver; i++)
        vis[i] = 0;
    
    vis[s] = 1;
    from = s;
    int sum = 0;
    
    for (j = 1; j < ver; j++) {
        min = INF;
        for (i = 1; i <= ver; i++) {
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0) {
                min = c[from][i];
                p = i;
            }
        }
        vis[p] = 1;
        from = p;
        sum = sum + min;
    }
    sum += c[from][s];
    printf("\nSolution with nearest neighbor technique is = %d\n", sum);
}

int main () {
    int ver, v[MAX], i, j;
    float optimum = INF;
    int sum; // Declaration of sum in main

    printf("Enter the number of cities: ");
    scanf("%d", &ver);
    
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= ver; i++)
        for (j = 1; j <= ver; j++)
            scanf("%d", &c[i][j]);
    
    printf("\nEnter the source city: ");
    scanf("%d", &s);
    
    brute_force(v, ver, 0);
    nearest_neighbor(ver);
    
    printf("Optimum solution with brute force technique = %f\n", optimum);
    printf("The approximation value is = %f%\n", ((sum / optimum) - 1) * 100);
    
    return 0;
}


