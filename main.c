#include <stdio.h>
#include <stdlib.h>
#include "func.h"

pslist list_new(void)
{

    pslist list = malloc(sizeof(struct slist)); // объявление указателя, выделение памяти

    if (NULL == list) // если указатель пуст, то?
        return NULL;

    list->list_size = 0; // размер списка = 0
    list->head = NULL; // нет первого элемента (head)

    return list; //возвращаем указатель на новый список (указатель на структуру slist)
}

/*
pslist_entry slist_pop(pslist list) // переносит head на следующий элемент списка и возвращает старое значение head
{
    if (NULL != list->head)
    {
        return list->head; // возвращает значение head на данный момент
        list->head = (list->head)->next; // переносит head на следующий элемент списка
    }
    else return NULL;
}


void list_delete(pslist list)
{
    pslist_entry head; //указатель на первый элемент списка

    while(NULL != (head = slist_pop(list)))
    {
        free(head); // удаляем каждый элемент списка (освобождаем пямять)
    }

    free(list); // после удаления всех элементв удаляем указатель на список
}
*/
int insert(pslist list, int value)
{
    struct slist_entry *pnew = malloc(sizeof(struct slist_entry));
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

/*
int list_remove(pslist list, int value)
{
    return 0;
}
*/

void print(pslist list)
{
    if ((NULL != list->head)&&(NULL != list))
    {
    pslist_entry pcurrent = list->head;

    printf("List: \n");

    while (pcurrent != NULL)
    {
        printf("> %d\n", pcurrent->value);

        pcurrent = pcurrent->next;
    }
    }
    else
    if (NULL == list->head) printf("Список пуст");
    else
    printf("Списка нет");
}


int main(void)
{
    pslist spisok;


    spisok = list_new();

    insert(spisok, 1);
    insert(spisok, 2);

    print(spisok);

    return 0;
}

