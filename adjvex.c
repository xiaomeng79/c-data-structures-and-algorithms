//邻接表
#include <stdio.h>

#define MAX_VERTEX_NUM 20 //最大的顶点个数
#define VertexType int //顶点的数据类型
#define InfoType int //图中弧或者边包含的信息的类型，用来存放权值等
#define GraphType int//图的种类

//用于指向下一个邻接点，弧和边
typedef struct ArcNode {
    int adjvex;//指向顶点的数组下标
    InfoType *info;//信息域
    struct ArcNode *nextarc;//指向下一个邻接点的指针
}ArcNode;

//存放顶点的信息
typedef struct VNode{
    VertexType data;//顶点数据信息
    ArcNode * firstarc;//第一个邻接点
}Vnode,AdjList[MAX_VERTEX_NUM];

//图
typedef struct {
    AdjList vertices;//图中顶点及各邻接点数组
    int vexnum, arcnum;//图中顶点数和边或弧的数
    GraphType kind;//图的类型
}ALGraph;
