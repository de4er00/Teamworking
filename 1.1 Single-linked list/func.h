#pragma once


// Forward declaration


typedef struct slist_entry *pslist_entry;

typedef struct slist *pslist;


struct slist_entry
{
    pslist_entry next;

    int value;
};


struct slist
{
    int list_size; // sugar

    pslist_entry head;
};


pslist slist_new(void);

/*
 * Deletes list and all the elements
 * Params: list - pointer to the list
 * Returns none
 */


void slist_delete(pslist list);

/*
 * TODO
 */


int slist_insert(pslist list, int value);

int slist_remove(pslist list, int value);

void slist_print(pslist list);
