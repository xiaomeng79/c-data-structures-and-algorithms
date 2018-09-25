#include <stdio.h>
#include <stdlib.h>

/*
 * 链表结构
 *
 * 头结点:有时，在链表的第一个结点之前会额外增设一个结点，结点的数据域一般不存放数据(哨兵模式)
 * 首元结点：链表中第一个元素所在的结点，它是头结点后边的第一个结点
 * 头指针：永远指向链表中第一个结点的位置（如果链表有头结点，头指针指向头结点；否则，头指针指向首元结点）
 */

 /*
  * 总结:
  * 线性表的链式存储相比于顺序存储，有两大优势：
  * 1. 链式存储的数据元素在物理结构没有限制，当内存空间中没有足够大的连续的内存空间供顺序表使用时，可能使用链表能解决问题。（链表每次申请的都是单个数据元素的存储空间，可以利用上一些内存碎片）
  * 2. 链表中结点之间采用指针进行链接，当对链表中的数据元素实行插入或者删除操作时，只需要改变指针的指向，无需像顺序表那样移动插入或删除位置的后续元素，简单快捷。
  * 链表和顺序表相比，不足之处在于，当做遍历操作时，由于链表中结点的物理位置不相邻，使得计算机查找起来相比较顺序表，速度要慢
  */
typedef struct Link
{
    int elem;
    struct Link *next;
}link;

/*
 * 链表的初始化
 *
 * 参数说明：
 *
 * 返回参数:
 *      link:返回头指针
 *
 */
link *initLink()
{
    link *p = (link *)malloc(sizeof(link));//创建一个头结点
    link *temp = p; //声明一个指针指向头结点，用于遍历链表
    //生成链表,创建一个链表（1，2，3，4）
    for (int i = 1; i < 5; ++i) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp=temp->next;
    }

    return p;

}

/*
 * 链表查找某结点，遍历结点
 *
 * 参数说明:
 *      link:头指针
 *      elem:查找的元素
 *
 * 返回值:
 *      -1：没有元素; >1:元素位置
 *
 */
int selectElem(link *p, int elem)
{
    link *t = p;
    int i = 1;
    while (t->next)
    {
        t = t->next;
        if (t->elem == elem)
            return i;
        i++;
    }
    return -1;
}

/*
 * 修改结点的数据域
 *
 *
 * 参数说明:
 *      p:头指针
 *      add：结点在链表的位置
 *      newElem:新值
 *
 * 返回值:
 *      p:头指针
 */
link *amendElem(link *p, int add, int newElem)
{
    link *temp = p;
    temp = temp->next;//指向首元结点
    //遍历到修改结点
    for (int i = 1; i < add; ++i) {
        temp=temp->next;
        if (i == add -1)
            temp->elem = newElem;
    }
    return p;

}

/*
 * 插入结点
 * 3种情况:
 * 1. 插入到链表的首部，也就是头结点和首元结点中间；
 * 2. 插入到链表中间的某个位置；
 * 3. 插入到链表最末端；
 *
 * 参数说明:
 *      link:头指针
 *      elem：新增元素
 *      add:插入的位置
 *
 * 返回值:
 *      link
 */
link *insertElem(link *p, int elem, int add)
{
    //创建临时结点
    link *temp = p;
    //找到要插入位置的上一个结点
    for (int i = 1; i < add; ++i) {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }

    //创建插入结点
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

/*
 * 删除结点
 * 参数说明:
 *      p:头指针
 *      add:删除位置
 * 返回值:
 *      p:头指针
 */

link *delLink(link *p, int add)
{
    link *temp = p;
    //temp指向被删除结点的上一个结点
    for (int i = 1; i < add; ++i) {
        temp = temp->next;
    }
    link *del = temp->next;//保存删除的指针
    temp->next = temp->next->next;//删除的方法就是更改前一个结点的指针域
    free(del);
    return p;
}

/*
 * 显示链表元素
 *
 * 参数说明：
 *      p:头指针
 */
void display(link *p)
{
    link *temp = p;
    //只要temp指针指向的next不指向NULL
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}

//测试
int main()
{
    printf("初始化链表\n");
    link *p = initLink();
    display(p);
    printf("在第4个位置插入元素5\n");
    p = insertElem(p, 5, 4);
    display(p);
    printf("删除元素3\n");
    p = delLink(p,3);
    display(p);
    printf("查找5的位置");
    int address = selectElem(p,5);
    if (address == -1)
        printf("没有该元素");
    else
        printf("元素2的位置：%d\n",address);
    printf("更改第3的位置的元素为7，\n");
    p = amendElem(p,3,7);
    display(p);
    return 0;
}


