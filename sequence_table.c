/*
 * 顺序表
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2 //数组的最大容量

//申明结构
typedef struct Table
{
    int *head;//名为head的长度不确定的数组，“动态数组”
    int length;//使用的长度
    int size;//容量
}table;

/*
 * 初始化顺序表
 *
 * 返回值:table
 */
table initTable()
{
    table t;
    t.head = (int *)malloc(MAX_SIZE * sizeof(int));
    if (!t.head)
    {
        printf("初始化失败\n");
        exit(0);
    }
    t.length = 0;
    t.size = MAX_SIZE;
    return t;
}

/*
 * 插入元素到顺序表
 *
 * 参数说明:
 *      table:顺序表
 *      elem:插入的元素
 *      index:插入的位置
 *
 * 返回值:table
 */
table insert_table(table t, int elem, int index)
{
    //判断插入位置是否有问题
    if (index < 1 || index > t.length + 1)
    {
        printf("插入位置有问题\n");
        return t;
    }
    //判断表是否满，满了就需要重新为表申请空间
    if (t.length == t.size)
    {
        t.head = (int *)realloc(t.head, (t.size * 2) * sizeof(int));
        if (!t.head)
        {
            printf("分配存储失败\n");
            return t;
        }
        t.size *=2;
    }
    //插入操作，需要将插入位置开始的后续元素，后移
    for (int i=t.length - 1; i >= index - 1; i--)
    {
        t.head[i+1] = t.head[i];
    }
    //后移完成，直接将所需插入元素，添加到相应的位置
    t.head[index - 1] = elem;
    //长度加1
    t.length++;
    return t;
}

//测试
int main()
{
    table t = initTable();
    t = insert_table(t,5,1);
    t = insert_table(t,5,1);
    t = insert_table(t,5,1);
    printf("插入元素后长度：%d\n",t.length);
    printf("插入元素后容量：%d\n",t.size);
}

