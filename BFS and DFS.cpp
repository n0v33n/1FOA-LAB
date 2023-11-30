//1. Define graph, connected graph.
//2. List the different graph traversals. 
//3.Explain DFS traversal.
//4.Explain BFS traversal.
//5.What are the time complexities of BFS and DFS algorithms
// BFS
#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = -1, r = 0;

void bfs(int v) {
    q[++r] = v;
    visited[v] = 1;
    while(f <= r) {
        v = q[++f];
        for(i = 1; i <= n; i++) {
            if(a[v][i] && !visited[i]) {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main() {
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    printf("\nEnter graph data in matrix form:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                a[i][j] = 0;
        }
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);
    printf("\nThe nodes which are reachable are:\n");
    for(i = 1; i <= n; i++) {
        if(visited[i]) {
            printf("%d\t", i);
        }
    }
    if(f > r) {
        printf("\nBFS is not possible");
    }
    return 0;
}
// DFS
//#include<stdio.h>
//
//int a[20][20], reach[20], n;
//
//void dfs(int v) {
//    int i;
//    reach[v] = 1;
//    for(i = 1; i <= n; i++) {
//        if(a[v][i] && !reach[i]) {
//            printf("\n %d->%d", v, i);
//            dfs(i);
//        }
//    }
//}
//
//int main() {
//    int i, j, count = 0;
//    printf("\nEnter number of vertices: ");
//    scanf("%d", &n);
//    for(i = 1; i <= n; i++) {
//        reach[i] = 0;
//        for(j = 1; j <= n; j++) {
//            a[i][j] = 0;
//        }
//    }
//    printf("\nEnter the adjacency matrix:\n");
//    for(i = 1; i <= n; i++) {
//        for(j = 1; j <= n; j++) {
//            scanf("%d", &a[i][j]);
//        }
//    }
//    dfs(1);
//    printf("\n");
//    for(i = 1; i <= n; i++) {
//        if(reach[i]) {
//            count++;
//        }
//    }
//    if(count == n) {
//        printf("\nGraph is connected");
//    } else {
//        printf("\nGraph is not connected");
//    }
//    return 0;
//}

