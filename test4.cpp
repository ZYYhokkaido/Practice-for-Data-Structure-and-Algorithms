#include "bits/stdc++.h"
using namespace std;

struct node
{
    int elm;
    struct _node *next;
};

struct node *diff(struct node *a, struct node *b)
{
    if (a == NULL)
    {
        return NULL;
    }
    if (b == NULL)
    {
        return a;
    }

    if (a->elm == b->elm)
    {
        return diff(a->next, b->next);
    }
    else if (a->elm < b->elm)
    {
        a->next = diff(a->next, b);
        return a;
    }
    else if (a->elm > b->elm)
    {
        return diff(a, b->next);
    }
}