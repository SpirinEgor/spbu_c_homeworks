#ifndef SPBU_2020_C_CYCLICLIST_H
#define SPBU_2020_C_CYCLICLIST_H

#include "list.h"

typedef struct CyclicList
{
    List* list;
    int currentIndex;
} CyclicList;

CyclicList* createCyclicList();

void updateCurrentIndex(CyclicList* cyclicList);
void increaseCurrentIndex(int increment, CyclicList* cyclicList);
int getCurrentValue(CyclicList* cyclicList);
bool deleteCurrent(CyclicList* cyclicList);
void freeCyclicList(CyclicList* cyclicList);

#endif //SPBU_2020_C_CYCLICLIST_H