#include <iostream>
using namespace std;
/*
想好没，写插入的函数
要不你语音我打字，也可以
我这不方便说话，舍友睡觉了
ok

*/

struct ilist{
    int *array;
    int size;
    int capacity;
}
/*
我想下
给点提示
*/

/**
这个是我写的insert，比较简练些.
函数分两步做，找到位置pos(ition)，把x插入到pos的位置上.
你可以看一下.
Let me see see
*/
void myinsert(struct ilist *l,int x){
    
    //找到x应该插入的位置
    int pos = 0;    //x应该插入的位置
    while(pos < l->size && x > l->array[pos]){
        ++pos; //pos++ what is difference? ok
        //在这里都一样的, pos++也可以
    }

    //这段看得怎么样 　还在看 有点绕 ok
    //这段主要是把x插入，顺便把被覆盖的数往后
    //你可以拿实际数字来模拟一下
    /*
    搞一个
    array：   3,5,7,9
    x=6
    size=4
    pos=2

    previous=6
    
    temp=7
    array: 3,5,6,9
    previous=temp 7

    pos=3
    temp=9
    array[pos]=previous 7
    array: 3,5,6,7
    previous 7 = temp 9
    
    pos=4
    previous=9
    array[pos]=9

    pos=5
    break

    
    break

    有思路没
    ok了
    懂了
    可以的
    🐂🍺 我的方法比较绕 不容易想 对 明天继续 先睡觉了 おやすみ
    😄
    这样写的话就比较通用，不用分情况考虑
    ok的 我也睡了~
    晚安~
    哎呀这个还是你来比较好哈哈，我觉得你写一遍就懂了，重新搞一遍康康
    */
    //将x插入到数组中
    int previous = x;   //上一个数，也就是这次要写入的数
    while(pos <= l->size){
        int temp = l->array[pos];   //保存当前位置的数
        l->array[pos] = previous;   //覆盖为上一个数
        previous = temp;    //previous就是下一次要写入的数
        ++pos;
    }

    //改变ilist的大小
    l->size += 1;
}

void append(struct ilist *l, int x){
    //插入有什么函数吗append?
    //要不就先append，不排序了，直接放最后面，试一下

    l->array[l->size] = x;
    l->size += 1;
   
    //写对了，就是这样
    //放前面好点
    //nice
    //对
    //下面写insert吧

    
    /*
    没啊，自己写这个，用不到别的函数
    那再提示下吧
    这个函数要做哪些事情？将x按大小顺序插入
    还有呢 还有啥？hh　なるほど
    改变size大小呀，插入一个size就+1
    就是做这些事
    
    */
}

//提示一下，ilist已经是从小到大的顺序了，不用再排序一次
//(不考虑append的话，先这样吧)
void insert(struct ilist *l,int x){
    int i=0;
    int j=0;    //这个是干啥的，好像只看到j--


    if(x < l->array[0]){
            while(l->size-j != i){
                l->array[l->size - j]=l->array[l->size - j - 1];
                j++;
            } 
            l->array[0] = x;
        }

    else if(x > l->array[l->size - 1]){
        l->array[l->size] = x;
    }
    
    
    else{

        while(i<size){
            if(x > l->array[i] && x < l->array[i+1]){
                break;
            }
            i++;
        }

        while(l->size-j != i){
                    l->array[l->size - j]=l->array[l->size - j - 1];
                    j++;
        }

        l->array[i] = x;

    }

}


int main(){
    struct ilist* list;
    //初始化
    list->size = 0;
    list->array = new int[10];
    list->capacity = 10;

    //没有代码提示嘛，语法忘记了哈哈
    insert(list,3);
    insert(list,2);
    //现在list应该是 2 3
    //比如这样
    cout<< list->array[0];  //3
    cout<< list->array[1];  //2
    cout<< list->size;  //2
}