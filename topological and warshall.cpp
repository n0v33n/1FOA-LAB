//1.   Define transitive closure.
//2.   Define topological sequence.
//3.   What is the time complexity of Warshall'salgorithm?
//1.   Obtain the Topological ordering of vertices in a given digraph. 
// Graph
#include <stdio.h>

int a[10][10], n, indegree[10];

void find_indegree() {
    int j, i, sum;
    for (j = 0; j < n; j++) {
        sum = 0;
        for (i = 0; i < n; i++)
            sum += a[i][j];
        indegree[j] = sum;
    }
}

void topology() {
    int i, u, v, t[10], s[10], top = -1, k = 0;
    find_indegree();
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            s[++top] = i;
    }
    while (top != -1) {
        u = s[top--];
        t[k++] = u;
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    s[++top] = v;
            }
        }
    }
    printf("The topological Sequence is:\n");
    for (i = 0; i < n; i++)
        printf("%d  ", t[i]);
}

int main() {
    int i, j;
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    topology();
    return 0;
}

//2.   Compute the transitive closure of a given directed graph using Warshall's algorithm.
#include <stdio.h>

int n, a[10][10], p[10][10];

void path() {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            p[i][j] = a[i][j];
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (p[i][k] == 1 && p[k][j] == 1)
                    p[i][j] = 1;
}

int main() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    path();
    printf("\nThe path matrix is shown below:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
    return 0;
}

