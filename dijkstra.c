//迪杰斯特拉(dijkstra),求最短路劲算法
#include <stdio.h>

#define MAX_VERTEX_NUM 20 //顶点的最大个数
#define VRType int //弧的权值的类型
#define VertexType int //图中顶点的数据类型
#define INFINITY 65535 //无穷

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; //存储图中顶点的数据
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组，记录顶点之间的关系
    int vexnum,arcnum;//记录顶点和弧的数量
}MGraph;

typedef int PathMatrix[MAX_VERTEX_NUM];//用于存储最短路劲中经过的顶点的下标
typedef int ShortPathTable[MAX_VERTEX_NUM];//用于存储各个最短路径的权值和

//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph *G,VertexType v){
    int i = 0;
    //遍历一维数组，查找变量v
    for (; i < G->vexnum; ++i) {
        if (G->vexs[i] == v)
            break;
    }
    //没找到 -1
    if (i>G->vexnum) {
        printf("没有此顶点");
        return -1;
    }
    return i;
}

//构造有向网
void CreateUDG(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));//顶点和弧
    for (int i = 0; i < G->vexnum; ++i) {
        scanf("%d",&(G->vexs[i]));//顶点值
    }
    for (int i = 0; i < G->vexnum; ++i) {
        for (int j = 0; j < G->vexnum; ++j) {
            G->arcs[i][j] = INFINITY;//初始化为无穷大
        }
    }
    for (int i = 0; i < G->arcnum; ++i) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G,v1);
        int m=LocateVex(G,v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return ;
        }
        G->arcs[n][m]=w;
    }
}

//最短路径，迪杰斯特拉算法，v0表示有向网中起始点所在数组中的下标
void ShortestPath_Dijkstra(MGraph G,int v0,PathMatrix *p, ShortPathTable *D){
    int final[MAX_VERTEX_NUM];//用于存储各顶点是否已经确定最短路径的数组
    //对各数组进行初始化
    for (int v = 0; v < G.vexnum; ++v) {
        final[v]=0;
        (*D)[v]=G.arcs[v0][v];
        (*p)[v]=0;
    }

    //由于以v0位下标的顶点为起始点，所以不用再判断
    (*D)[v0]=0;
    final[v0]=1;
    int k = 0;
    for (int i = 0; i < G.vexnum; ++i) {
        int min = INFINITY;
        //选择到各个顶点权值最小的顶点，为本次确定的最短路径的顶点
        for (int w = 0; w < G.vexnum; ++w) {
            if(!final[w]){
                if ((*D)[w]<min){
                    k=w;
                    min=(*D)[w];
                }
            }
        }
        //设置该顶点的标志位为1，避免下次重复
        final[k]=1;
        //对v0到各顶点的权值进行跟新
        for (int w = 0; w < G.vexnum; ++w) {
            if(!final[w]&&(min+G.arcs[k][w]<(*D)[w])) {
                (*D)[w]=min+G.arcs[k][w];
                (*p)[w]=k;//记录各个最短路径上存在的顶点
            }
        }
    }
}

int main(){
    MGraph G;
    CreateUDG(&G);
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_Dijkstra(G, 0, &P, &D);
    for (int i=1; i<G.vexnum; i++) {
        printf("V%d - V%d的最短路径中的顶点有(逆序)：",0,i);
        printf(" V%d",i);
        int j=i;
        //由于每一段最短路径上都记录着经过的顶点，所以采用嵌套的方式输出即可得到各个最短路径上的所有顶点
        while (P[j]!=0) {
            printf(" V%d",P[j]);
            j=P[j];
        }
        printf(" V0\n");
    }
    printf("源点到各顶点的最短路径长度为:\n");
    for (int i=1; i<G.vexnum; i++) {
        printf("V%d - V%d : %d \n",G.vexs[0],G.vexs[i],D[i]);
    }
    return 0;
}