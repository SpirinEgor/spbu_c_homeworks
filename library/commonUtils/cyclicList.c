#include "cyclicList.h"
#include "malloc.h"

CyclicList* createCyclicList()
{
    CyclicList* newCyclicList = calloc(1, sizeof(CyclicList));
    newCyclicList->list = createList();
    newCyclicList->currentIndex = -1;
}

void updateCurrentIndex(CyclicList* cyclicList)
{
    cyclicList->currentIndex = cyclicList->currentIndex % size(cyclicList->list);
}

void increaseCurrentIndex(int increment, CyclicList* cyclicList)
{
    cyclicList->currentIndex = (cyclicList->currentIndex + increment) % size(cyclicList->list);
}

int getCurrentValue(CyclicList* cyclicList)
{
    return retrieve(cyclicList->currentIndex, cyclicList->list).value;
}

bool deleteCurrent(CyclicList* cyclicList)
{
    deleteByPosition(cyclicList->currentIndex, cyclicList->list);
    --cyclicList->currentIndex;
    updateCurrentIndex(cyclicList);
}

void freeCyclicList(CyclicList* cyclicList)
{
    freeList(cyclicList->list);
    free(cyclicList);
}
