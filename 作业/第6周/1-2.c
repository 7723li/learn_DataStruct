// 列出连通集 - 2
// 用邻接表完成, 结论是用邻接矩阵完成最佳
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10
#define MaxListLen MaxVertexNum * MaxVertexNum

int len;
int DFSList[MaxListLen];
int BFSList[MaxListLen];

typedef int Vertex;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
	int visted;
	Vertex AdjV; // 邻接点下标, 即顶点编号
	PtrToAdjVNode Next;
};

typedef struct VNode AdjList[MaxVertexNum]; //链表数最多等于顶点数
struct VNode
{
	PtrToAdjVNode FirstEdge; // 每个头结点总是指向第一个邻接点
};

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv, Ne;
	AdjList G; // 邻接表
};
typedef PtrToGNode LGraph;
LGraph CreateGraph(int VertexNum);
LGraph BuildGraph();
void PrintGrapt(LGraph Graph);
int in(int* l, int n);
void DFS(LGraph Graph, Vertex V);

typedef struct ENode* Edge;
struct ENode
{
	Vertex V1, V2;
};
void InsertEdge(LGraph Graph, Edge E);

int main(int argc, char const *argv[])
{
	LGraph Graph = BuildGraph();
	PrintGrapt(Graph);

	int i;
	for(i=0; i<MaxListLen; i++){
		DFSList[i] = -1;
		BFSList[i] = -1;
	}

	len = 0; DFS(Graph, 0);

	for(i=0; i<len; i++)
		printf("%d ", DFSList[i]);
	printf("\n");
	
	return 0;
}

LGraph CreateGraph(int VertexNum){
	Vertex V, W;
	LGraph Graph;

	Graph = (LGraph) malloc (sizeof(struct GNode));;
	Graph -> Nv = VertexNum;
	Graph -> Ne = 0;

	for(V=0; V < Graph -> Nv; V++)
		Graph -> G[V].FirstEdge = NULL; // 空链表头指针指向空

	return Graph;
}

void InsertEdge(LGraph Graph, Edge E){
	PtrToAdjVNode NewNode;
	int i = 0;

	// 创建新的邻接点
	NewNode = (PtrToAdjVNode) malloc (sizeof(struct AdjVNode));
	NewNode -> AdjV = E -> V2;
	NewNode -> visted = 0;

	// 插入
	NewNode -> Next = Graph -> G[E -> V1].FirstEdge;
	Graph -> G[E -> V1].FirstEdge = NewNode;

	// 无向图
	NewNode = (PtrToAdjVNode) malloc (sizeof(struct AdjVNode));
	NewNode -> AdjV = E -> V1;
	NewNode -> visted = 0;
	NewNode -> Next = Graph -> G[E -> V2].FirstEdge;
	Graph -> G[E -> V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
	int Nv, i;
	Edge E;
	scanf("%d", &Nv);

	LGraph Graph = CreateGraph(Nv);
	scanf("%d", &(Graph -> Ne));
	for(i=0; i < Graph -> Ne; i++){
		E = (Edge) malloc (sizeof(struct ENode));
		scanf("%d %d", &(E -> V1), &(E -> V2));
		InsertEdge(Graph, E);
	}

	return Graph;
}

void PrintGrapt(LGraph Graph){
	int i = 0;
	PtrToAdjVNode Node;
	printf("\n");
	for(i; i < Graph -> Nv; i++){
		Node = Graph -> G[i].FirstEdge;
		printf("%d ", i);
		while(Node){
			printf("%d ", Node -> AdjV);
			Node = Node -> Next;
		}
		printf("\n");
	}
	printf("\n");
}

int in(int *l, int n){
	int i;
	for(i=0; l[i] != -1; i++)
		if(l[i] == n)
			return 1;
	return 0;
}

void DFS(LGraph Graph, Vertex V){
	if(V == Graph -> Nv) return;

	PtrToAdjVNode Node = Graph -> G[V].FirstEdge;
	while(Node != NULL){
		if(Node -> visted == 0){
			// printf("%d %d\n", V, Node -> AdjV);
			if(!in(DFSList, V))
				DFSList[len++] = V;
			if(!in(DFSList, Node -> AdjV))
				DFSList[len++] = Node -> AdjV;
			Node -> visted = 1;
			DFS(Graph, Node -> AdjV);
		}
		Node = Node -> Next;
	}

	DFSList[len++] = -2;
	DFS(Graph, V + 1);
}
