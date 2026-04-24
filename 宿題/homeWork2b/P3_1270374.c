#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_N 10000
#define MAX_T 50
#define MAX_L 10000

int main() {
    int n,t,g,I;
    static char s[MAX_T];
    static int d[MAX_N][MAX_T];
    static int F[MAX_N];
    int l;
    static char w[MAX_L];
    int i,j;
    bool visited[MAX_N] = {0};

    // Read a DFA M
    scanf("%d%d%d", &n, &t, &g);
    assert(n <= MAX_N && t <= MAX_T && g <= n);
    scanf("%s", s);
    assert(strlen(s) == (unsigned)t);

    for  (i = 0; i < n; i++) {
        for (j = 0; j < t; j++) {
            scanf("%d", &d[i][j]);
            d[i][j]--;
        }
    }
    scanf("%d", &I);
    I--;
    for (i = 0; i < g; i++) {
        scanf("%d", &F[i]);
        F[i]--;
    }

    int queue[MAX_N];
    int front = 0, rear = 0;
    

    queue[rear++] = I;
    visited[I] = true;

    while (front < rear) {
        int cur = queue[front++];

        bool isFinal = false;
        for (i = 0; i < g; i++) {
            if (F[i] == cur) {
                isFinal = true;
                break;
            }
        }

        if (!isFinal) {
            printf("No\n");
            return 0;
        }

        for (j = 0; j < t; j++) {
            int next = d[cur][j];
            if (!visited[next]) {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }

    printf("Yes\n");
    
    return 0;
}
