#include <stdio.h>
#include <stdlib.h>
//栈:LIFO 线性表的一种特殊的存储结构
#define MAX_SIZE 3
typedef char ElementType;
typedef struct node *seq_stack;

/*
 * 顺序栈
 */
struct node
{
    ElementType data[MAX_SIZE];
    int top;//栈顶元素位置
};

/*
 * 初始化栈
 */
void seq_stack_init(seq_stack *L)
{
    (*L) = (seq_stack)malloc(sizeof(struct node));
    (*L)->top = -1;
}
/*
 * 入栈
 *
 *
 */
void seq_stack_push(seq_stack L, ElementType elem)
{
    if (L->top == MAX_SIZE - 1)
        printf("栈满了\n");
    else
        L->data[++L->top] = elem;
}

/*
 * 出栈
 *
 */
void seq_stack_pop(seq_stack L, ElementType *x)
{
    if (L->top == -1)
        printf("空栈\n");
    else
        *x = L->data[L->top--];
}

//测试
int main()
{
    printf("初始化栈\n");
    seq_stack L;
    seq_stack_init(&L);
    printf("将a,b,c分别入栈\n");
    printf("存入a\n");
    seq_stack_push(L,'a');
    printf("存入b\n");
    seq_stack_push(L,'b');
    printf("%d\n",L->top);
    printf("出栈，元素为:");
    ElementType _x;
    ElementType *x;
    x = &_x;
    seq_stack_pop(L,x);
    printf("%c\n",*x);
    return 0;

}

