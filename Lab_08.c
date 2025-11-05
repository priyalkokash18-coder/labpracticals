#include <stdio.h>
#define INF 9999
#define MAX 10
int main() {
    int n, start;
    int G[MAX][MAX], visited[MAX] = {0}, distance[MAX];
    int i, j, count, minDist, nextNode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter starting node (1 to %d): ", n);
    scanf("%d", &start);
    start--;
    for (i = 0; i < n; i++) {
        if (G[start][i] == 0)
            distance[i] = INF;
        else
            distance[i] = G[start][i];
    }
    distance[start] = 0;
    visited[start] = 1;
    for (count = 1; count < n - 1; count++) {
        minDist = INF;
        for (i = 0; i < n; i++)
            if (distance[i] < minDist && !visited[i]) {
                minDist = distance[i];
                nextNode = i;
            }
        visited[nextNode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i] && (minDist + G[nextNode][i] < distance[i]) && G[nextNode][i] != 0)
                distance[i] = minDist + G[nextNode][i];
    }
    printf("\nShortest distances from node %d:\n", start + 1);
    for (i = 0; i < n; i++)
        printf("To node %d = %d\n", i + 1, distance[i]);
    return 0;
}
