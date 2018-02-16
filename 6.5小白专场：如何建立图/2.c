// 用邻接表表示图
#include <stdio.h>
#include <stdlib.h>

#define MaxVertemNum 10

typedef int WeightType;
typedef int DataType;
typedef int Vertex; // 用顶点下标表示顶点

typedef struct  AdjVNode* PtrToAdjVNode;
struct  AdjVNode
{
	Vertex AdjV; // 邻接点下标
	WeightType Weight; // 边权重
	PtrToAdjVNode Next;
};

typedef struct VNode AdjList[MaxVertemNum];
struct VNode
{
	PtrToAdjVNode FirstEdge; // 总是指向第一条边
	DataType Data;
}; // AdjList是邻接表类型

typedef struct GNode* PtrToGNode;
struct GNode
{
	int Nv, Ne; // 顶点数，边数
	AdjList G; // 邻接表
};
typedef PtrToGNode LGraph;

typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex V1, V2; // 有向边<V1, V2>
	WeightType Weight; // 权重
};
typedef PtrToENode Edge;

LGraph CreateGraph(int VertemNum){
	// 初始化一个有VertexNum个顶点但没有边的图
	int i;
	Vertex V, W;
	LGraph Graph;

	Graph = (LGraph) malloc (sizeof(struct GNode));
	Graph -> Nv = VertemNum;
	Graph -> Ne = 0;

	for(i=0; i < Graph -> Nv; i++)
		Graph -> G[i].FirstEdge = NULL;

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E){
	PtrToAdjVNode NewNode;

	// 为V2建立新的邻接点
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode -> AdjV = E -> V2;
	NewNode -> Weight = E -> Weight;
	// 将V2插入V1的表头
	NewNode -> Next = Graph -> G[E -> V1].FirstEdge;
	Graph -> G[E -> V1].FirstEdge = NewNode;

	// 若是无向图，还要插入边<V2, V1>
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode -> AdjV = E -> V1;
	NewNode -> Weight = E -> Weight;
	NewNode -> Next = Graph -> G[E -> V2].FirstEdge;
	Graph -> G[E -> V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
	LGraph Graph;
}

int main(int argc, char const *argv[])
{

	
	return 0;
}
