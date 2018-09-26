#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

QNode *initQueue()
{
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->next = NULL;
    return queue;
}

QNode *enQueue(QNode *rear, int data)
{
    QNode *enElem = (QNode*)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    //使用尾插法向链队列中添加数据元素
    rear->next = enElem;
    rear = enElem;
    return rear;
}

void DeQueue(QNode *front, QNode *rear)
{
    if (front->next == NULL)
    {
        printf("队列为空");
        return ;
    }
    QNode *p = front->next;
    printf("%d", p->data);
    front->next = p->next;
    if (rear == p)
    {
        rear = front;
    }
    free(p);
}

int main()
{
    QNode *queue, *front, *rear;
    queue = front = rear = initQueue();//创建头结点
    //向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    //入队完成，所有数据元素开始出队列
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);
    DeQueue(front, rear);

    return 0;
}