#include <stdio.h>
#include <stdlib.h>
//十字链表,存储有向图和有向网
#define MAX_VERTEX_NUM 20 //最大顶点数
#define InfoType int //弧的信息
#define VertexType int //顶点信息


//弧节点
typedef struct ArcBox{
    int tailvex,headvex;//弧尾，弧头对应的顶点在数组中的位置下标
    struct ArcBox *hlink, *tlink;//指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关的信息的指针
}ArcBox;

//顶点节点
typedef struct VexNode{
    VertexType data//顶点的数据域
    ArcBox *firstin, *firstout;//指向以该顶点为弧头和弧尾的链表的首个节点
}VexNode;

//图
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
    int vexnum,arcnum;//记录图的顶点数和弧数
}OLGraph;

//查找
int LocateVex(OLGraph *G, VertexType v){
    int i = 0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) {
        if (G->xlist[i].data == v)
            break;
    }
    //找不到，输出提示语句，返回 -1
    if (i>G->vexnum) {
        printf("没有此顶点");
        return -1;
    }
    return i;
}

//构建十字链表函数
void CreateDG(OLGraph *G){
    //输入有向图的顶点数和弧数
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (int i = 0; i < G->vexnum; ++i) {
        scanf("%d",&(G->xlist[i].data));
        G->xlist[i].firstin = NULL;
        G->xlist[i].firstout = NULL;
    }
    //构建十字链表
    for (int j = 0; j < G->arcnum; ++j) {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        //确定值在数组中的位置下标
        int k = LocateVex(G,v1);
        int m = LocateVex(G,v2);
        //存在
        if (k != -1 && m != -1){
            //建立弧的结点
            ArcBox *p = (ArcBox *)malloc(sizeof(ArcBox));
            p->tailvex = k;
            p->headvex = m;
            //采用头插法插入新的p结点
            p->hlink=G->xlist[m].firstin;
            p->tlink=G->xlist[k].firstout;
            G->xlist[m].firstin=G->xlist[k].firstout = p;
        }
    }
}
