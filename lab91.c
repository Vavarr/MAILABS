#include <stdio.h>


int min(int a, int  b) {

    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int max(int a, int b) {

    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int mod(int N, int n) {
    if (N < 0) {
        N = N * (-1);
    }
    if (n < 0) {
        n = n * (-1);
    }
    while (n < N) {
        N -= n;
    }
    return N;
}

int count_i(int i, int j, int l, int k) {
    int ik = mod(min(max(min((i - j), (i - l)), (j - l)), (i - k)), 30);
    return ik;
}

int count_j(int i, int j, int l, int k) {
    int jk = mod(max(min(max((i - j), (i - l)), (j - l)), (i - k)), 30);
    return jk;
}

int count_l(int i, int j, int l, int k) {
    int lk = (mod(i, 30)) - (mod(j, 30)) + (mod(l, 30)) - (mod(k, 30));
    return lk;
}

int Orientation_calc(int P1_x, int P1_y, int P2_x, int P2_y, int P3_x, int P3_y) {
    int vector_1_x = P2_x - P1_x;
    int vector_2_x = P3_x - P1_x;

    int vector_1_y = P2_y - P1_y;
    int vector_2_y = P3_y - P1_y;
    int cross_product = vector_1_x * vector_2_y - vector_1_y * vector_2_x;
    if (cross_product > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int inside_triangle(int P_x, int P_y) {
    const int A_x = -10;
    const int A_y = 0;
    const int B_x = 0;
    const int B_y = 10;
    const int C_x = -10;
    const int C_y = 20;

    int turns = Orientation_calc(A_x, A_y, B_x, B_y, P_x, P_y) + Orientation_calc(B_x, B_y, C_x, C_y, P_x, P_y) + Orientation_calc(C_x, C_y, A_x, A_y, P_x, P_y);
    if ((turns == 3)||(turns == 0)) {
        return 1;
    }
    else {
        return 0;
    }

}


int main() {

    int check = 0;
    int i = 29;
    int j = -6;
    int l = 1;
    int k = 0;



    while (k < 50) {
        if (inside_triangle(i, j)) {
            printf("Hit. k = %d\t i = %d\t j = %d\t l = %d\n", k, i, j, l);
            check = 1;
            break;
        }
        else {
            int ik = count_i(i, j, l, k);
            int jk = count_j(i, j, l, k);
            int lk = count_l(i, j, l, k);
            k += 1;

            i = ik;
            j = jk;
            l = lk;
        }
    }
    if (check == 0) {
        printf("Miss. k = %d\t i = %d\t j = %d\t l = %d\n", k, i, j, l);
    }



    //int ik = count_i(i, j, l, k);
    //int jk = count_j(i, j, l, k);
    //int lk = count_l(i, j, l, k);
    //k += 1;

    //i = ik;
    //j = jk;
    //l = lk;

    return 0;

}
