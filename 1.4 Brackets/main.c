#include <stdio.h>
#include <stdlib.h>

#include "1_3_Double-linked_list.c"

int main()
{
    pslist list = malloc(sizeof(slist));
    char brac;
    int out; //индекс скобки, которую закрывают новой скобкой brac
    int flag; //"Флаг" - переменная показывающая, может ли данная последовательность быть правильной

    list = list_new();
    flag = 1;

    while((EOF != (brac = getchar()))&&flag)
    {
        if (brac == "{") push(list, 1);
        else if (brac == "(") push(list, 0);
        else {
            pop(list, &out);
            if (!((brac == "}")&&(out == 1)||(brac == ")")&&(out == 0))) flag = 0;
        }
    }

    if (list->list_size != 0) flag = 0; //нечетное кол-во скобок

    if (flag) printf("Последовательность правильная");
    else printf("Последовательность неправильная");

    return 0;
}
