#include <stdio.h>
#include <assert.h>
#include <ctype.h>

unsigned int liter(char c){
    c = tolower(c);
    if ((c >= 'b' && c <= 'd') ||
            (c >= 'f' && c <= 'h') ||
            (c >= 'j' && c <= 'n') ||
            (c >= 'p' && c <= 't') ||
            (c >= 'v' && c <= 'x') || (c == 'z')){
        return 1u<<(c-'a');
    }
    else {return 0;}
}

int sep(char c)
{
    if (c == ' ' || c == ',' || c == '\n' || c == '\t' || c == EOF) {
        return 1;
    }

    return 0;
}

void unit_test(){
    assert(liter('B') == 2);
    assert(liter('z') == 33554432);
    assert(liter('1') == 0);
    assert(liter(' ') == 0);
    assert(sep('\n') == 1);
    assert(sep(' ') == 1);
    assert(sep('1') == 0);
    assert(sep('n') == 0);
}


int main(){

    unit_test();

    char val;
    unsigned int set = 0;
    unsigned int flag = 0;
    int answ = 0;

    while ((val = getchar()) != EOF) {
        if ((sep(val)) == 0){
            if ((liter(val)) != 0){
                set = set | liter(val);
                flag = liter(val);
            }
        }

        else {
            if ((flag != 0)&&((set - flag) == 0)){
                answ = 1;
            }
        }
    }
    if ((flag != 0)&&((set - flag) == 0)){
                answ = 1;}

    if (answ == 1){
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}
