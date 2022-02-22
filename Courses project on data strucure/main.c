#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "Tree.h"
#include "General.h"

void Display(Element a)
{
    printf("The course of code: %d\n", a.data);
}

int main()
{
    Element courses[10];
    Init(courses);

    Tree coursestree;
    CreatTree(&coursestree);
    FillTree(&coursestree, courses);

    List takenlsit;
    CreateList(&takenlsit);
    GetTakenCources(&takenlsit, courses);

    Stack wantedstack;
    CreateStack(&wantedstack);
    GetWantedCources(&wantedstack, courses);

    Queue allowdqueue, notqueue;
    CreateQueue(&allowdqueue);
    CreateQueue(&notqueue);

    Element course, parent;
    while (!StackEmpty(&wantedstack))
    {
        Pop(&course, &wantedstack);
        if (GetParent(course, &parent, &coursestree))
            if (SearchInList(parent, &takenlsit))
                Append(course, &allowdqueue);
            else
                Append(course, &notqueue);
        else
            Append(course, &notqueue);
    }

    ClearList(&takenlsit);
    ClearStack(&wantedstack);
    ClearTree(&coursestree);

    printf("\nProcessing...\n");

    printf("\nThe following courses are OK to take:\n");
    TraverseQueue(&allowdqueue, &Display);
    printf("\nThe following courses are CANNOT be taken:\n");
    TraverseQueue(&notqueue, &Display);

    return 0;
}
