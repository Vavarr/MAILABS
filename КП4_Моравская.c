#include <stdio.h>
#include <float.h>
#include <math.h>

long double var6(long double x) {
    return (-cosl(powl(x,0.52)+2));
}

long double var6_der(long double x) {
    return ( (13*sinl(powl(x,0.52)+2)) / 25 / powl(x,0.52) );
}

int var6_conv(long double a, long double b) {
    int check_I = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (var6_der(x) >= 1) {
            check_I = 0;
        }
    }
    return check_I;
}

long double Iteration(long double a, long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = var6(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = var6(x0);
    }
    return x1;
}


long double var7(long double x) {
    return (  3*logl(x)*logl(x) + 6*logl(x) - 5  );
}

long double var7_der1(long double x) {
    return (  (6*logl(x)+6) / x  );
}

long double var7_der2(long double x) {
    return (  (-6*logl(x))/x/x  );
}

int var7_conv(long double a, long double b) {
    int check_N = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (fabsl(var7(x) * var7_der2(x)) >= powl(var7_der1(x), 2)) {
            check_N = 0;
        }
    }
    return check_N;
}

long double Newton(long double a, long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = x0 - var7(x0) / var7_der1(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = x0 - var7(x0) / var7_der1(x0);
    }
    return x1;
}



int main() {
    long double a = 0.5, b = 1;
    printf("Variant 6 (Iteration):\t x+cos(x^0.52 + 2) \n");
    if (var6_conv(a, b)) {
        printf("Convergent:\tYes\n");

        long double root = Iteration(a, b);
        printf("Root:\t%.10Lf\n", root);

        long double result = root + cosl(powl(root,0.52)+2);
        printf("Veryfy:\t%.10Lf\n\n", result);
    } else {
        printf("Convergent:\tNo\n\n");
    }


    a = 1;
    b = 3;
    printf("Variant 7 (Newton):\t 3(ln(x))^2 + 6ln(x) - 5 \n");
    if (var7_conv(a, b)) {
        printf("Convergent:\tYes\n");

        long double root = Newton(a, b);
        printf("Root:\t%.10Lf\n", root);

        long double result = var7(root);
        printf("Veryfy:\t%.10Lf\n", result);
    } else {
        printf("Convergent:\tNo\n\n");
    }
}
