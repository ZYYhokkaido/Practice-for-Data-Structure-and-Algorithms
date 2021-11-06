//Shift + Alt + F

/**********************************************

两个有序数组，合并为一个大的有序数组

1,3,5 + 2,4,6,8 --> 1,2,3,4,5,6,8 

**********************************************/
void merge(int a[], int m, int b[], int n, int c[], int o)
{
    if (o < m + n)
        return;

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < m)
        c[k++] = a[i++];

    while (j < n)
        c[k++] = b[j++];
}

/**********************************************

数组元素翻转

1,5,2,4,8 --> 8,4,2,5,1 

**********************************************/
void reverse(int a[], int n)
{
    int s = 0, e = n - 1;
    while (s < e)
    {
        SWAP(a[s], a[e]);
        s++;
        e--;
    }
}

/********************************************** 无头节点|单向|非循环 链表 **********************************************/
typedef struct _NODE
{
    int val;
    _NODE *next;
    _NODE(int v)
    {
        val = v;
        next = NULL;
    }
} NODE;

void trvl(NODE *h)
{

    for (NODE *i = h; i != NULL; i = i->next)

        cout << i->val << ",";

    cout << endl;
}

bool search(NODE *h, int v)
{

    for (NODE *i = h; i != NULL; i = i->next)

        if (i->val == v)
            return true;

    return false;
}

NODE *insert_head(NODE *h, int v)
{

    NODE *n = new NODE(v);

    n->next = h;

    return n;
}

NODE *insert_tail(NODE *h, int v)
{
    NODE *n = new NODE(v);
    if (NULL == h)
        return n;
    NODE *i = h;
    while (i->next)
        i = i->next;
    i->next = n;
    return h;
}

NODE *del(NODE *h, int v)
{

    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d;
    while (i->next)
    {
        if (i->next->val == v)
        {
            NODE *n = i->next;
            i->next = n->next;
            delete n;
        }
        else
            i = i->next;
    }
    i = d->next;
    delete d;
    return i;
}

//TODO
NODE *del(NODE *h, int v)
{

    if (h->val == v)
    {
        Node *head = h->next;
        delete h;
        return head;
    }

    else
    {
        Node *i = h;
        while (i->next->val != v)
        {
            i = i->next;
        }

        Node *n = i->next;
        i->next = i->next->next;
        delete n;
    }
    return h;
}

/********************************************** 合并两个有序链表，使之继续有序 **********************************************/
NODE *merge(NODE *h1, NODE *h2)
{

    if (NULL == h2)
        return h1;

    if (NULL == h1)
        return h2;

    NODE *d = new NODE(0);
    NODE *i = d;
    while (h1 && h2)
    {

        if (h1->val < h2->val)
        {

            i->next = h1;

            h1 = h1->next;
        }
        else
        {

            i->next = h2;

            h2 = h2->next;
        }
        i = i->next;
    }
    if (h1)
        if (h2)

            i->next = h1;
    i->next = h2;

    i = d->next;
    delete d;
    return i;
}

/**********************************************
有序插入链表
**********************************************/
NODE *insert_sorted(NODE *h, int v)
{
    NODE *n = new NODE(v);
    if (h->val > v)
    {
        n->next = h;
        return n;
    }

    NODE *i = h;
    while (i->next && i->next->val < v)
        i = i->next;
    n->next = i->next;
    i->next = n;

    return h;
}

/**********************************************
翻转链表
**********************************************/
NODE *reverse(NODE *h)
{
    if (NULL == h || NULL == h->next)
        return h;
    NODE *d = new NODE(0);
    d->next = h;
    NODE *i = d, *j = d->next, *k;
    while (j)
    {
        k = j->next;
        j->next = i;
        i = j;
        j = k;
    }
    d->next->next = NULL;
    delete d;
    return i;
}

NODE *reverse(NODE *h)
{
    if (NULL == h || NULL == h->next)
        return h;

    NODE *now = h, next = h->next, pre;
    h->next = NULL;

    while (next != NULL)
    {
        pre = now;
        now = next;
        next = now->next;
        now->next = pre;
    }

    return now;
}

/**********************************************
  删除链表的重复元素，保留一个  
  1 -> 1 -> 1 -> 2 -> 3 -> NULL
  3 -> 3 -> 3
**********************************************/
NODE *del_repeat_remain_one(NODE *h)
{

    NODE *current = h, *next = h->next, *temp;
    while (next != NULL)
    {
        if (current->val == next->val)
        {
            temp = next;
            next = temp->next;
            delete temp;
        }

        else
        {
            current->next = next;

            current = next;
            next = next->next;
        }
    }

    current->next = NULL;
    return h;
}

/**********************************************
完全删除链表的重复元素

1 -> 2 -> 2 -> 2 -> 3 -> 5
比如说：
current: 3
next: 5
next_next: NULL
找到当前节点current的下一个元素，这个元素没有重复


**********************************************/
NODE *del_repeat(NODE *h)
{
    NODE *start = new NODE(0);
    start->next = h;
    NODE *current = start, *next = start->next, *next_next = next->next, *temp;

    while (next != NULL && next_next != NULL)
    {
        if (next->val == next_next->val)
        {
            temp = next_next;
            next_next = next_next->next;
            delete temp;
        }

        else
        {
            delete next;
            next = next_next;
            next_next = next->next;
            current->next = next;
        }
    }
    current->next = NULL;

    temp = start->next;
    delete start;
    return temp;
}

/********************************************** 
 
    带头结点|双向|循环链表

**********************************************/
typedef struct _NODE
{
    int val;
    _NODE *next, *prev;
} NODE;

NODE *make_node(int v)
{
    NODE *n = new NODE();
    n->val = v;
    n->next = n->prev = n;
    return n;
}

void trvl(NODE *h)
{
    if (NULL == h)
        return;
    for (NODE *i = h->next; i != h; i = i->next)
        cout << i->val << ",";
    cout << endl;
}

bool search(NODE *h, int v)
{
    if (NULL == h)
        return false;
    for (NODE *i = h->next; i != h; i = i->next)
        if (i->val == v)
            return true;
    return false;
}

NODE *insert_head(NODE *h, int v)
{
    NODE *n = make_node(v);
    if (NULL == h)
        h = make_node(0);
    n->next = h->next;
    n->prev = h;
    h->next->prev = n;
    h->next = n;
    return h;
}

NODE *insert_tail(NODE *h, int v)
{
    NODE *n = make_node(v);
    if (NULL == h)
        h = make_node(0);
    n->next = h;
    n->prev = h->prev;
    h->prev->next = n;
    h->prev = n;
    return h;
}

NODE *del(NODE *h, int v)
{
    if (NULL == h)
        return h;
    for (NODE *i = h->next; i != h; i = i->next)
    {
        if (i->val == v)
        {
            i->prev->next = i->next;
            i->next->prev = i->prev;
            delete i;
            break;
        }
    }
    return h;
}

/*
            0, 0   
3           0, 1
3 4         0, 2
3 4 5       0, 3
pop()   =>>  3      1, 3

判断空的条件:   front == rear  (假设一开始 0 )
push一个元素：  rear = 1
front:  0 (没有指向任何一个元素，指向第一个元素的前面)
所以你要取第一个元素，它的地址就是front+1

length: 5
front: 3
rear: 2

       f
[3,4,5,6,7]
     r



length: 3
[]
[1]
[1,2]
[,2]
[,2,3]
push?   [4,2,3]          (rear+1)%SIZE




*/

typedef struct _NODE
{
    int val;
    _NODE *next;
    _NODE(int _val)
    {
        val = _val;
        next = NULL;
    }
} NODE;

typedef struct _QUEUE
{
    _QUEUE *front;
    _QUEUE *rear;
    _QUEUE() { front = rear = NULL; }
} QUEUE;

bool empty(QUEUE *q)
{
    if (q->front == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void push(QUEUE *q, int val)
{
    NODE *n = new NODE(val);
    if (q->front == NULL)
    {
        q->front = n;
        q->rear = n;
    }

    else
    {
        q->rear->next = n;
        q->rear = n;
    }
}

int pop(QUEUE *q)
{
    NODE *temp;
    int temp_val;
    temp = p->front;
    p->front = p->front->next;
    if (p->front == NULL)
    {
        p->rear = NULL;
    }
    temp->val = temp_val;
    delete temp;
    return temp_val;
}