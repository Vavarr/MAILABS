#include <stdio.h>
#include <assert.h>

int ost(int n){
    return (n%2);
}

void unit_test(){
    assert(ost(2) == 0);
    assert(ost(1) == 1);
    assert(ost(10) == 0);
    assert(ost(3) == 1);
    assert(ost(7263576) == 0);
}

int main(){

    unit_test();

    int num;
    int one = 0;
    int zero = 0;

    scanf("%d", &num);

    while (num >= 1){
        if (ost(num)==1){
            ++one;
        }
        else if (ost(num)==0){
            ++zero;
        }
        num /= 2;
    }

    if (one == zero){
        printf("True");
    }
    else {
        printf("False");
    }

    return 0;
}
