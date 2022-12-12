#include <stdio.h>
#include <assert.h>
#include <malloc.h>

int main(){

    int *s;
    int N;
    int min = 999999999;
    int stolb = 0;
    int z;
    int pros = 1;

    scanf("%d\n", &N);

    s = (int*)malloc(N*N * sizeof(int));

    for (int k = 0; k < N; k++){
        for (int u = 0; u < N; u++){
            scanf("%d", (s + k*N + u));
            if ((min >= *(s + k*N + u)) && (u >= stolb)){
                min = *(s + k*N + u);
                stolb = u;
            }
        }
        printf("\n");

    }

    for (int y = 0; y < N; y++){
        z = *(s + y*N + stolb);
        pros = z*pros;
    }

    printf("%d", pros);

    return 0;
}
