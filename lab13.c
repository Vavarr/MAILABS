#include <stdio.h>
#include <assert.h>

int liter(char c){
    if ((c >= 'B' && c <= 'D') ||
            (c >= 'F' && c <= 'H') ||
            (c >= 'J' && c <= 'N') ||
            (c >= 'P' && c <= 'T') ||
            (c >= 'V' && c <= 'X') || (c == 'Z') ||
            (c >= 'b' && c <= 'd') ||
            (c >= 'f' && c <= 'h') ||
            (c >= 'j' && c <= 'n') ||
            (c >= 'p' && c <= 't') ||
            (c >= 'v' && c <= 'x') || (c == 'z')){
                return c;
            }
    else {return 0;}
}

int sep(char c)
{
    if (c == ' ' || c == ',' || c == '\n' || c == '\t') {
        return 1;
    }
    return 0;
}

void unit_test(){
    assert(liter('B') == 66);
    assert(liter('z') == 122);
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
    int flag = 0;
    int check = 1;
    int answ = 0;

    while ((val = getchar()) != EOF) {
        if (sep(val) == 0){
            if ((liter(val) != 0) && (flag == 0)){
                flag = liter(val);
            }
            if ((flag != 0) && (liter(val) != 0) && (liter(val) != flag)){
                check = 0;
            }
        }

        else {
            if ((check == 1) && (flag != 0)){
                answ = 1;
            }
        check = 1;
        }




    }

    if (answ == 1){
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}
