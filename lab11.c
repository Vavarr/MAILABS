//char k
//(1, k+1) -> 1
//else if (1, " ") -> 1 and c++
//else -> 1

#include <stdio.h>

int liter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z');
}

int main (){
    int numb = 1;
    int val;
    int symbol;

    int kolvo = 0;

    while ((val = getchar()) != EOF) {
        switch (numb){

            case 1:
                if (liter(val)){
                    symbol = val;
                    numb = 2;
                }
                else {
                    numb = 1;
                }
                break;

            case 2:
                if ((liter(val)) && (val > symbol)){
                    symbol = val;
                    numb = 2;
                }
                else if ((val == ' ')||(val == '\n')){
                    ++kolvo;
                    numb = 1;
                }
                else if ((liter(val)) && (val <= symbol)){
                    numb = 3;
                }
                else {
                    numb = 2;
                }
                break;

            case 3:
                if (liter(val)){
                    numb = 3;
                }
                else if (val == ' '){
                    numb = 1;
                }
                else {
                    numb = 3;
                }
                break;
        }

    }

    printf("result - %d", kolvo);
    return 0;
}
