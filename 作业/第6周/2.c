// Saving James Bond - Easy Version
// 例题6.3不存图改进版
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MapSize 100
#define dia 15 // 中心小岛半径

typedef struct Node Vertex;
struct Node
{
	int V, W;
};

int *vistied, N;
double D;
Vertex *G;

int IsSave(Vertex V){
	if(V.V >= 80 || V.W >= 80) return 1;
	if(V.V <= 20 || V.W <= 20) return 1;
	return 0;
}

int FirstJump(Vertex V1, Vertex V2){
	return 
		sqrt(pow((V1.V-V2.V), 2) + pow((V1.W-V2.W), 2)) <= D + dia;
}

int Jump(Vertex V1, Vertex V2){
	return 
		sqrt(pow((V1.V - V2.V), 2) + pow((V1.W - V2.W) ,2)) <= D;
}

int DFS(Vertex V){
	if(IsSave(V)) {
		printf("safe in (%d, %d)\n", V.V, V.W);
		return 1;
	}

	int i, res = 0;
	for(i=0; i<N; i++){
		if(vistied[i] == 0){
			if(Jump(V, G[i])){
				vistied[i] = 1;
				printf("from (%d, %d) to (%d, %d)\n", V.V, V.W ,G[i].V, G[i].W);
				vistied[i] = 1;
				res = DFS(G[i]);
				if(res == 1) return 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Vertex island;
	island.V = MapSize / 2; island.W = MapSize / 2;

	int V, W;
	scanf("%d %lf", &N, &D) ;
	G = (Vertex*) malloc (sizeof(Vertex) * N);
	vistied = (int*) malloc (sizeof(int) * N);

	int i;
	for(i=0; i<N; i++){
		scanf("%d %d", &V, &W);
		G[i].V = V + 50; G[i].W = W + 50;
		vistied[i] = 0;
	}

	// for(i=0; i<N; i++)
	// 	printf("%d, %d\n", G[i].V, G[i].W);

	int res = 0;
	for(i=0; i < N; i++){
		if(vistied[i] == 0){
			if(FirstJump(G[i], island)){
				printf("from (50, 50) to (%d, %d)\n", G[i].V, G[i].W);
				vistied[i] = 1;
				res = DFS(G[i]);
				if(res == 1) break;
			}
		}
	}

	if(res == 1)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}
	