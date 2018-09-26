#include <stdio.h>
#include <stdlib.h>

/*
 * 链栈
 */
#define NULL_STACK NULL
typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
}link_stack;

//初始化
link_stack *link_stack_init()
{
    return NULL_STACK;
}

//入栈
link_stack *link_stack_push(link_stack *l, char c)
{
    link_stack *pl = (link_stack *)malloc(sizeof(link_stack));
    pl->data = c;
    pl->next = l;
    l = pl;
    return pl;
}

//出栈
link_stack *link_stack_pop(link_stack *l)
{
    if (l == NULL_STACK)
    {
        printf("栈内无元素\n");
        return l;
    }
    printf("元素:%c\n",l->data);
    l = l->next;
    return l;
}

//测试
int main()
{
    link_stack *l;
    l = link_stack_init();
    printf("入栈元素:%c\n",'a');
    l = link_stack_push(l,'a');
    printf("入栈元素:%c\n",'b');
    l = link_stack_push(l,'b');
    l = link_stack_pop(l);
    l = link_stack_pop(l);
    l = link_stack_pop(l);

    return 0;
}




