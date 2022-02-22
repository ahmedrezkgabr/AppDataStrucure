#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "Tree.h"
#include "General.h"

void GetWantedCources(Stack *ps, Element e[])
{
    int n, t;
    printf("Entre the numper of the wanted courses: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Entre the code of the course no.:%d ", i + 1);
        scanf("%d", &t);
        switch (t)
        {
        case 304:
            Push(e[0], ps);
            break;
        case 217:
            Push(e[1], ps);
            break;
        case 419:
            Push(e[2], ps);
            break;
        case 207:
            Push(e[3], ps);
            break;
        case 101:
            Push(e[4], ps);
            break;
        case 315:
            Push(e[5], ps);
            break;
        case 313:
            Push(e[6], ps);
            break;
        case 404:
            Push(e[7], ps);
            break;
        case 311:
            Push(e[8], ps);
            break;
        case 415:
            Push(e[9], ps);
            break;
        default:
            printf("INVALID CODE\n");
            i--;
            break;
        }
    }
    printf("-----------------------------\n\n");
}

void GetTakenCources(List *pl, Element e[])
{
    int n, t;
    printf("Entre the no. of already studied courses: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Entre the code of the course no.:%d ", i + 1);
        scanf("%d", &t);
        switch (t)
        {
        case 304:
            InsertList(0, e[0], pl);
            break;
        case 217:
            InsertList(0, e[1], pl);
            break;
        case 419:
            InsertList(0, e[2], pl);
            break;
        case 207:
            InsertList(0, e[3], pl);
            break;
        case 101:
            InsertList(0, e[4], pl);
            break;
        case 315:
            InsertList(0, e[5], pl);
            break;
        case 313:
            InsertList(0, e[6], pl);
            break;
        case 404:
            InsertList(0, e[7], pl);
            break;
        case 311:
            InsertList(0, e[8], pl);
            break;
        case 415:
            InsertList(0, e[9], pl);
            break;
        default:
            printf("INVALID CODE\n");
            i--;
            break;
        }
    }
    printf("-----------------------------\n\n");
}

void Init(Element e[])
{
    /*the courses in the program*/
    static Element e0, e1, e2, e3, e4, e5, e6, e7, e8, e9;
    e0.data = 304;
    e0.key = 0;
    e1.data = 217;
    e1.key = 1;
    e2.data = 419;
    e2.key = 2;
    e3.data = 207;
    e3.key = 3;
    e4.data = 101;
    e4.key = 4;
    e5.data = 315;
    e5.key = 5;
    e6.data = 313;
    e6.key = 6;
    e7.data = 404;
    e7.key = 7;
    e8.data = 311;
    e8.key = 8;
    e9.data = 415;
    e9.key = 9;

    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
    e[3] = e3;
    e[4] = e4;
    e[5] = e5;
    e[6] = e6;
    e[7] = e7;
    e[8] = e8;
    e[9] = e9;
}
void FillTree(Tree *pt, Element e[])
{
    InsertTree(pt, &e[4]);
    InsertTree(pt, &e[3]);
    InsertTree(pt, &e[8]);
    InsertTree(pt, &e[1]);
    InsertTree(pt, &e[6]);
    InsertTree(pt, &e[9]);
    InsertTree(pt, &e[0]);
    InsertTree(pt, &e[2]);
    InsertTree(pt, &e[5]);
    InsertTree(pt, &e[7]);
}

int GetParent(Element course, Element *pparent, Tree *pt)
{
    int found = 0;
    TreeNode *q = pt->root, *r = NULL;
    while (q && !(found = EQ(course.key, q->entry.key))) /*try to find the wanted node*/
    {
        r = q;
        if (LT(course.key, q->entry.key))
            q = q->left;
        else
            q = q->right;
    }
    if (found)
    {
        *pparent = r->entry;
    }
    return found;
}

int SearchInList(Element parent, List *pl)
{
    ListNode *pn = pl->head;
    int found;
    while (pn && !(found = EQ(pn->entry.data, parent.data)))
    {
        pn = pn->next;
    }
    return found;
}
