#pragma once
#include <stdbool.h>
#include "numericOperations.h"

void siftUp(int* numbers, int position);

void siftDown(int* numbers, int n, int position);

void buildHeap(int* numbers, int n);
