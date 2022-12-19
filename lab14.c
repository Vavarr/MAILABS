#include <stdio.h>
#include <assert.h>

int main() {

    int N, i, j, k;

    scanf("%d", &N);

    int s[N][N];
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", &s[i][j]);
        }
        printf("\n");
    }

        for (k = 2*N - 1; k > 0; --k) {
            if (k >= N) {
                i = N - 1;
                j = k - N;
            }
            else {
                i = k - 1;
                j = 0;
            }

        if (k % 2 != 0) {
            for (; (i >= 0) && (j <= N-1); --i, ++j) {
                printf("%d ", s[j][i]);
            }
        }
        else {
            for (; (i >= 0) && (j <= N-1); --i, ++j) {
                printf("%d ", s[i][j]);
            }
        }
    }

    return 0;

}
