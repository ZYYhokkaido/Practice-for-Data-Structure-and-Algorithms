
typedef struct BSTreeNode
{
    int data;
    BSTreeNode *left;
    BSTreeNode *right;
} BSTree;

/* 查找特定值 */
void SearchData_r(int targ, BSTree *nod)
{
    if (!nod)
    {
        if (nod->data == targ)
        {
            printf("查找值存在，值为%d", nod->data);
        }
        else if (targ < nod->data)
        {
            SearchData_r(targ, nod->left);
        }
        else if (targ > nod->data)
        {
            SearchData_r(targ, nod->right);
        }
    }

    else
    {
        printf("查找值不存在\n");
    }
}

bool SearchData(int targ, BSTree *nod)
{
    BSTree *temp;
    temp = nod;
    while (temp)
    {
        if (targ > temp->data)
        {
            temp = temp->right;
        }
        else if (targ < temp->data)
        {
            temp = temp->left;
        }
    }

    if (temp->data == targ)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 添加新节点 */
BSTree *AddNewNode(BSTree *cur, int NewData)
{
    if (cur == NULL)
    {
        cur = new BSTree;
        cur->data = NewData;
        cur->left = NULL;
        cur->right = NULL;

        return cur;
    }

    if (NewData < cur->data)
    {
        cur->left = AddNewNode(cur->left, NewData);
    }
    else if (NewData > cur->data)
    {
        cur->right = AddNewNode(cur->right, NewData);
    }
    else if (NewData == cur->data)
    {
        printf("不允许插入重复值\n");
        exit(0);
    }

    return cur;
}

/* 删除节点 */
/* cur为待删除节点， parent为待删除节点的父节点 */
void DeletNode(BSTree *parent, BSTree *cur, int DelData)
{
    if (cur == NULL)
    {
        printf("删除的节点不存在\n");
    }

    else if (DelData > cur->data)
    {
        DeletNode(cur, cur->right, DelData);
    }

    else if (DelData < cur->data)
    {
        DeletNode(cur, cur->left, DelData);
    }

    else
    {
        delete cur;
        if (DelData < parent->data)
        {
            parent->left == NULL;
        }
        else
        {
            parent->right == NULL;
        }
    }
}