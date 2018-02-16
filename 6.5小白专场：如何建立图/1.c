// 用邻接矩阵表示图
#include <stdio.h>
#include <stdlib.h>

#define MaxVertemNum 10

typedef int WeightType;
typedef int DataType;
typedef int Vertex; // 用顶点下标表示顶点

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv, Ne; // 顶点数, 边数
	WeightType G[MaxVertemNum][MaxVertemNum];
	// DataType Data[MaxVertemNum]; // 存顶点的数据
};
typedef PtrToGNode MGraph; // 以邻接矩阵存储的图类型

typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex V1, V2; // 有向边<V1, V2>
	WeightType Weight; // 权重
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertemNum){
	// 初始化一个有VertexNum个顶点但没有边的图
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph) malloc (sizeof(struct GNode));
	Graph -> Nv = VertemNum;
	Graph -> Ne = 0;

	for(V=0; V < Graph -> Nv; V++)
		for(W=0; W < Graph -> Nv; W++)
			// 图初始化时各顶点都不相连
			// G[V][W] = 1 表示V顶点与W顶点之间有一条边
			Graph -> G[V][W] = 0;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E){
	Graph -> G[E -> V1][E -> V2] = E -> Weight; // 插入边<V1, V2>

	// 若是无向图, 还要插入边<v2, v1>
	Graph -> G[E -> V2][E -> V1] = E -> Weight;
}

MGraph BuildGraph(){
	int Nv, i;
	MGraph Graph;
	Edge E;

	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	scanf("%d", &(Graph -> Ne));

	if(Graph -> Nv != 0){
		E = (Edge) malloc (sizeof(struct ENode));
		for(i=0; i<Graph -> Ne; i++){
			scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
			InsertEdge(Graph, E);
		}
	}

	// // 如果顶点有数据的话，读入数据
	// for(i=0; i<Graph->Nv; i++)
	// 	scanf("%d", &(Graph -> Data[i]));

	return Graph;
}

int main(int argc, char const *argv[])
{
	int i, j;
	MGraph Graph = BuildGraph();

	for(i=0; i<Graph->Nv; i++){
		for(j=0; j<Graph->Nv; j++){
			printf("%d ", Graph -> G[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

// 8
// 2
// 1 2 3
// 2 3 4
// 0 0 0 0 0 0 0 0
// 0 0 3 0 0 0 0 0
// 0 3 0 4 0 0 0 0
// 0 0 4 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0
