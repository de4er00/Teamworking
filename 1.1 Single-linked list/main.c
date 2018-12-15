#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(void)
{
    pslist spisok;

    spisok = slist_new();

    insert_end(spisok, 5);
    insert_end(spisok, 5);
    insert_end(spisok, 5);
    insert_end(spisok, 1);
    insert_end(spisok, 1);
    insert_end(spisok, 5);
    insert_end(spisok, 5);
    insert_end(spisok, 5);
    insert_end(spisok, 1);
    insert_end(spisok, 2);
    insert_end(spisok, 5);
    insert_end(spisok, 5);
    insert_end(spisok, 1);
    insert_end(spisok, 5);
    insert_end(spisok, 3);
    insert_end(spisok, 5);
    insert_end(spisok, 1);
    insert_end(spisok, 5);

    print(spisok);
    slist_remove(spisok, 5);
    print(spisok);
    slist_remove(spisok, 1);
    print(spisok);
    slist_remove(spisok, 2);
    print(spisok);
    slist_remove(spisok, 3);
    print(spisok);
    printf("-----");
    slist_delete(spisok);


    spisok = slist_new();

    insert_start(spisok, 5);
    insert_start(spisok, 5);
    insert_start(spisok, 5);
    insert_start(spisok, 1);
    insert_start(spisok, 1);
    insert_start(spisok, 5);
    insert_start(spisok, 5);
    insert_start(spisok, 5);
    insert_start(spisok, 1);
    insert_start(spisok, 2);
    insert_start(spisok, 5);
    insert_start(spisok, 5);
    insert_start(spisok, 1);
    insert_start(spisok, 5);
    insert_start(spisok, 3);
    insert_start(spisok, 5);
    insert_start(spisok, 1);
    insert_start(spisok, 5);

    print(spisok);
    slist_remove(spisok, 5);
    print(spisok);
    slist_remove(spisok, 1);
    print(spisok);
    slist_remove(spisok, 2);
    print(spisok);
    slist_remove(spisok, 3);
    print(spisok);
    printf("-----");
    slist_delete(spisok);


    return 0;
}

pslist slist_new(void)//создание нового листа
{

    pslist list = malloc(sizeof(struct slist)); // объявление указателя, выделение памяти

    if (NULL == list) // если указатель пуст, то?
        return NULL;

    list->list_size = 0; // размер списка = 0
    list->head = NULL; // нет первого элемента (head)

    return list; //возвращаем указатель на новый список (указатель на структуру slist)
}

void slist_delete(pslist list)//удаление листа по указателю на лист
{
    pslist_entry head2 = malloc(sizeof(struct slist_entry));

    while(NULL != list->head)//можно через list_size
    {
        head2 = list->head;
        list->head = list->head->next;
        free(head2); // удаляем каждый элемент списка (освобождаем пямять)
    }

    free(list); // после удаления всех элементв удаляем указатель на список
}


int insert_end(pslist list, int value)//вставка ового элемента в конец списка
{
    pslist_entry pnew = malloc(sizeof(struct slist_entry));//  объявление указателя на новый элемент, выделение памяти
    pslist_entry pend = list->head;


    if (pnew == NULL)
        return -1;  //?


    if (NULL == list->head) list->head = pnew;
    else {
        while(NULL != pend->next) pend = pend->next;
        pend->next = pnew;
    }


    list->list_size++;
    pnew->next = NULL;
    pnew->value = value;

    printf("New element: %d\n", pnew->value);

    return 0;
}

int insert_start(pslist list, int value)//вставка нового элемента в начало списка
{
    struct slist_entry *pnew = malloc(sizeof(struct slist_entry)); //  объявление указателя на новый элемент, выделение памяти
  //struct pslist_entry pnew = malloc(sizeof(struct slist_entry)); ?

    if (pnew == NULL)
        return -1;


    pnew->next = list->head;
    pnew->value = value;

    printf("New element: %d\n", pnew->value);

    list->head = pnew;
    list->list_size++;

    return 0;
}


int slist_remove(pslist list, int value)//удаление всех элементов со значением value
{
    //pslist_entry pold, pnew ,pend = malloc(sizeof(struct slist_entry));?
    pslist_entry pold = malloc(sizeof(struct slist_entry));
    pslist_entry pend = malloc(sizeof(struct slist_entry));
    pslist_entry pnew = malloc(sizeof(struct slist_entry));


    while((NULL != list->head)&&(list->head->value == value))
    {
        pold = list->head;
        list->head = list->head->next;
        free(pold);  // удаление структуры, на которую указывает указатель??? как выглядит удаление самой переменной pold???
    }

    pend = list->head;

    while(NULL != pend)
    {
        if (pend->value == value)
        {

            while((NULL != pend->next)&&(pend->value == value))
            {
                pold = pend;
                pend = pend->next;

                free(pold);

                list->list_size--;
            }

            if (pend->value != value) pnew->next = pend;
            else pnew->next = NULL;
        }

        pnew = pend;
        pend = pend->next;

    }
    //free(&pold); //освобождение выделенной памяти под указатель?? нужно ли?
    //free(*pend);
    pold = pend;
    return 0;
}



void print(pslist list)//выводит элементы списка по порядку начиная с первого
{
    pslist_entry pend = list->head;

    printf("List: \n");

    while (pend != NULL)
    {
        printf("> %d\n", pend->value);

        pend = pend->next;
    }

    printf("end\n");
}
