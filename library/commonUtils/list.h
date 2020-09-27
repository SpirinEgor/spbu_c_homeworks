#pragma once
#include <stdbool.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* prev;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
    int size;
} List;

ListElement* createListElement();
List* createList();
ListElement* tail(List* list);
ListElement* head(List* list);
bool isEmpty(List* list);
int size(List* list);
bool insert(ListElement* value, int position, List* list);
void showList(List* list);
ListElement retrieve(int position, List* list);
int locate(ListElement* value, List* list);
bool deleteByPosition(int position, List* list);
void freeList(List* list);
