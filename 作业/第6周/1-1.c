// 列出连通集 - 1
// 用邻接矩阵完成
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVertexNum 10
#define MaxListLen MaxVertexNum * MaxVertexNum

int len;
int DFSList[MaxListLen];
int BFSList[MaxListLen];

typedef int WeightType;
typedef int Vertex;

typedef struct GNode* PtrToGNode;
struct GNode
{
 	int Nv, Ne;
 	WeightType G[MaxVertexNum][MaxVertexNum]; 
 	int visted[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;
MGraph CreatGraph(int VertexNum);
MGraph BuildGraph();
void PrintGraph(MGraph Graph);

typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex V1, V2; // 有向边<V1, V2>
};
typedef PtrToENode Edge;
void InsertEdge(MGraph Graph, Edge E);

typedef struct QNode* Queue;
struct QNode
{
	Vertex Data[MaxListLen];
	int head, rear;
};
void EnQueue(Queue Q, Vertex V);
Vertex DeQueue(Queue Q);
int isEmpty(Queue Q);

int in(int* l, int n);
void DFS(MGraph G ,Vertex V);
void BFS(MGraph G ,Vertex V);

int main(int argc, char const *argv[])
{
	int i, j, flag = 0;
	for(i=0; i<MaxListLen; i++){
		DFSList[i] = -1;
		BFSList[i] = -1;
	}

	MGraph Graph = BuildGraph();
	
	len = 0; DFS(Graph, 0);

	printf("{ ");
	for(i=0; i < len; i++){
		if(DFSList[i] == -2)
			flag = 1;
		else{
			if(flag){
				flag = 0;
				printf("}\n{ ");
			}
			printf("%d ", DFSList[i]);
		}
	}
	printf("}\n");

	for(i=0; i < Graph -> Nv; i++){
		flag = 1;
		for(j=0; j < Graph -> Nv; j++){
			if(Graph -> visted[i][j] == 1)
				flag = 0;
			Graph -> visted[i][j] = 0;
		}
		if(flag == 1) printf("{ %d }\n", i);
	}


	len = 0; BFS(Graph, 0);

	printf("{ ");
	for(i=0; i < len; i++){
		if(BFSList[i] == -2)
			flag = 1;
		else{
			if(flag){
				flag = 0;
				printf("}\n{ ");
			}
			printf("%d ", BFSList[i]);
		}
	}
	printf("}\n");

	for(i=0; i < Graph -> Nv; i++){
		flag = 1;
		for(j=0; j < Graph -> Nv; j++){
			if(Graph -> visted[i][j] == 1)
				flag = 0;
			Graph -> visted[i][j] = 0;
		}
		if(flag == 1) printf("{ %d }\n", i);
	}

	return 0;
}

MGraph CreatGraph(int VertexNum){
 	// 初始化一个有VertexNum个顶点单无边的图
 	Vertex V, W;
 	MGraph Graph;

 	Graph = (MGraph) malloc (sizeof(struct GNode));
 	Graph -> Nv = VertexNum;
 	Graph -> Ne = 0;

 	for(V=0; V<VertexNum; V++)
 		for(W=0; W<VertexNum; W++){
 			Graph -> G[V][W] = 0;
 			Graph -> visted[V][W] = 0;
 		}

 	return Graph;
}

void InsertEdge(MGraph Graph, Edge E){
  	// 无向图
  	Graph -> G[E -> V1][E -> V2] = 1;
  	Graph -> G[E -> V2][E -> V1] = 1;
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv); // 自定顶点数
	Graph = CreatGraph(Nv);
	scanf("%d", &(Graph->Ne)); // 输入边数

	if(Graph -> Ne != 0){
		E = (Edge) malloc (sizeof(struct ENode));
		for(i=0; i< Graph -> Ne; i++){
			scanf("%d %d", &(E -> V1), &(E -> V2)); // 两个端点
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

void PrintGraph(const MGraph Graph){
	int i, j;
	printf("\n");
	for(i=0; i< Graph -> Nv; i++){
		for(j=0; j< Graph -> Nv; j++)
			printf("%d ", Graph -> G[i][j]);
		printf("\n");
	}
}

int in(int* l, int n){
	int i = 0;
	for(i; i < len; i++)
		if(n == l[i])
			return 1;
	return 0;
}

void DFS(const MGraph Graph, Vertex V){
	if(V == Graph -> Nv) return;
	int i, j;
	for(i = 0; i < Graph -> Nv; i++){
		if(Graph -> G[V][i] == 1){
			if(Graph -> visted[V][i] == 0){
				Graph -> visted[V][i] = 1;
				Graph -> visted[i][V] = 1;
				// printf("%d %d\n", V, i);
				if(!in(DFSList, V))
					DFSList[len++] = V;
				if(!in(DFSList, i))
					DFSList[len++] = i;
				DFS(Graph, i);
			}
		}
	}
	DFSList[len++] = -2;
	DFS(Graph, V+1);
}

void EnQueue(Queue Q, Vertex V){
	Q -> Data[++Q -> rear] = V;
}

Vertex DeQueue(Queue Q){
	return Q -> Data[++Q -> head];
}

int isEmpty(Queue Q){
	return Q -> head == Q -> rear;
}

void BFS(MGraph Graph, Vertex V){
	if(V == Graph -> Nv) return;
	int i = 0;
	Queue Q = (Queue) malloc (sizeof(struct QNode));
	Q -> head = -1;
	Q -> rear = -1;
	for(i=0; i < Graph -> Nv; i++){
		if(Graph -> G[V][i] == 1){
			if(Graph -> visted[V][i] == 0){
				Graph -> visted[V][i] = 1;
				Graph -> visted[i][V] = 1;
				EnQueue(Q, i);
				if(!(in(BFSList, V)))
					BFSList[len++] = V;
				if(!(in(BFSList, i)))
					BFSList[len++] = i;
			}
		}
	}

	while(!isEmpty(Q)){
		Vertex temp = DeQueue(Q);
		BFS(Graph, temp);
	}

	BFSList[len++] = -2;
	BFS(Graph, V + 1);
}
