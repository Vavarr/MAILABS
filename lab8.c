#include <stdio.h>

int main(){
    int N = 0;
    int k = 0;        //кол-во чисел N
    scanf("%d", &N);

    int s[N];
    for (int i = 0; i < N; ++i){
        int a = 0;
        scanf("%d/n", &a);           //перенос в массив
        s[i] = a;
    }

    for (int i = 0; i < N-1; ++i){
        for (int u = i+1; u < N; ++u){
            if (s[i] > 50) {
                int a = s[i]+s[u];
                if (a%80 == 0){
                    ++k;
                }
            }
            else if (s[u] > 50) {
                    int a = s[i]+s[u];
                    if (a%80 == 0){
                        ++k;
                    }

            }
        }
    }

    printf("%d", k);

    return 0;
}
