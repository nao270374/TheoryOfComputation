#include <stdio.h>
#include <string.h>
#include <assert.h>

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
    int i,j,k;

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
    for (i = 0; i < g; i++) {
        scanf("%d", &F[i]);
        F[i]--;
    }

    // Read a string w
    scanf("%d", &l);
    assert(l <= MAX_L);
    if (l > 0) scanf("%s", w);
    else       strcpy(w, "");
    assert(strlen(w) == (unsigned)l);

    int cur = I - 1;
    for (i = 0; i < l; i++) {
        char c = w[i];
        int idx = -1;
        for (j = 0; j < t; j++) {
            if (s[j] == c) {
                idx = j;
                break;
            }
        }

        assert(idx != -1);
        cur = d[cur][idx];
        
    }

    for (i = 0; i < g; i++) {
        if (F[i] == cur) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    
    return 0;
}
