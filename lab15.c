#include <stdio.h>
#include <assert.h>

int main(){

    int N;
    int min = 999999999;
    int stolb = 0;
    int z;
    int pros = 1;

    scanf("%d\n", &N);

    int s[N][N];

    for (int k = 0; k < N; k++){
        for (int u = 0; u < N; u++){
            scanf("%d", &s[k][u]);
            if ((min >= s[k][u]) && (u >= stolb)){
                min = s[k][u];
                stolb = u;
            }
        }
        printf("\n");

    }

    for (int y = 0; y < N; y++){
        z = s[y][stolb];
        pros = z*pros;
    }

    printf("%d", pros);

    return 0;
}
