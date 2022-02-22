#ifndef GENERAL_H
#define GENERAL_H

void GetWantedCources(Stack *, Element[]);
void GetTakenCources(List *, Element[]);
int GetParent(Element, Element *, Tree *);
int SearchInList(ListEntry, List *);
void FillTree(Tree *, Element[]);
void Init(Element[]);

#endif