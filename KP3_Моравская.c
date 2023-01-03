#include <stdio.h>
#include <math.h>

int main(){

    double a = (-1.0), b = 1.0, x = -1.0;
    double sum_t, chln_t, f;
    int n, iter;
    long double e = 1.0f;

    while (1.0f + e / 2.0f > 1.0f){
            e /= 2.0f;
    }

    printf("Write n: ");
    scanf("%d", &n);
    printf("n = %d \n", n);
    printf("Machine eps double = %.16Le\n", e);
    printf("Table of Teylor values and stand f(x) = ln(2 + x)\n");
    printf("==================================================================\n");
    printf("| x \t | Taylor\t\t | Function\t        | Iters  |\n");
    printf("==================================================================\n");

    for (int i = 1; i <= n+1; i++) {
        iter = 1;
        chln_t = 1;
        f = log(2+x);
        sum_t = log(2);
        while (fabs(chln_t) > e && iter < 100) {
            chln_t = pow((-1), iter-1) * ( pow(x, iter) / iter / pow(2, iter) );
            sum_t += chln_t;
            iter++;
        }
        printf("| %.3f | %.18lf | %.18lf |   %d   |\n", x, sum_t, f, iter);
        printf("------------------------------------------------------------------\n");
        x +=(b - a) / n;
    }

    return 0;

}
