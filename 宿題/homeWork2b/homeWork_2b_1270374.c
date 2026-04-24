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

    bool visited[MAX_N][4] = {0};

    int q_state[MAX_N * 4];
    int q_111[MAX_N * 4];

    int front = 0, rear = 0;

    q_state[rear] = I;
    q_111[rear] = 0;
    visited[I][0] = true;
    rear++;

    while (front < rear) {
        int cur = q_state[front];
        int k = q_111[front];
        front++;

        bool isFinal = false;
        for (i = 0; i < g; i++) {
            if (F[i] == cur) {
                isFinal = true;
                break;
            }
        }

        if (isFinal && k == 3) {
            printf("Yes\n");
            return 0;
        }

        for (j = 0; j < t; j++) {
            int next = d[cur][j];
            char c = s[j];

            int next_k;
            if (k == 0) {
                next_k = (c == '1') ? 1 : 0;
            } else if (k == 1) {
                next_k = (c == '1') ? 2 : 0;
            } else if (k == 2) {
                next_k = (c == '1') ? 3 : 0;
            } else {
                next_k = 3;
            }

            if (!visited[next][next_k]) {
                visited[next][next_k] = true;
                q_state[rear] = next;
                q_111[rear] = next_k;
                rear++;
            }
        }
    }

    printf("No\n");
    
    return 0;
}
