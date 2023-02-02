#ifndef STACK
#define STACK

#include "Item.h"

void STACKinit(int);
int STACKempty();
void STACKpush(Item);
Item STACKpop();
void STACKprint();

#endif