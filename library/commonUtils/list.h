#ifndef SPBU_2020_C_LIST_H
#define SPBU_2020_C_LIST_H

#include <stdbool.h>

typedef struct ListElement ListElement;
typedef struct List List;

ListElement* createListElement();
int getValue(ListElement* listElement);
List* createList();
ListElement* tail(List* list);
ListElement* head(List* list);
bool isEmpty(List* list);
int size(List* list);
bool insert(ListElement* value, int position, List* list);
void showList(List* list);
ListElement* retrieve(int position, List* list);
int locate(ListElement* value, List* list);
bool deleteByPosition(int position, List* list);
void freeList(List* list);

#endif //SPBU_2020_C_LIST_H