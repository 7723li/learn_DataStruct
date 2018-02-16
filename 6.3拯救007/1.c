// Saving James Bond - Easy Version
// 第六周作业2.c为改进版
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MapSize 100
#define dia 15 // 中心小岛半径

int G[MapSize][MapSize];
int vistied[MapSize][MapSize];
// the number of crocodiles, the maximum distance jump
int N;
double D;

int IsSave(int V, int W){
	if(V >= 80 || W >= 80) return 1;
	if(V <= 20 || W <= 20) return 1;
	return 0;
}

int FirstJump(int V, int W){
	return sqrt((V-50)*(V-50) + (W-50)*(W-50)) <= D + dia;
}

int Jump(int V, int W, int v, int w){
	return sqrt((V-v)*(V-v) + (W-w)*(W-w)) <= D;
}

int DFS(int V, int W){
	if(IsSave(V, W)) {
		printf("safe in (%d, %d)\n", V, W);
		return 1;
	}
	int i, j;
	for(i=0; i<MapSize; i++){
		for(j=0; j<MapSize; j++){
			if(G[i][j] == 1){
				if(vistied[i][j] == 0){
					if(Jump(V, W, i, j)){
						printf("(%d, %d) (%d, %d)\n", V, W, i, j);
						vistied[i][j] = 1;
						DFS(i, j);
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int i, j;
	for(i=0; i<MapSize; i++){
		for(j=0; j<MapSize; j++){
			G[i][j] = 0;
			vistied[i][j] = 0;
		}
	}

	int V1, V2;
	scanf("%d %lf", &N, &D) ;
	for(i=0; i<N; i++){
		scanf("%d %d", &V1, &V2);
		G[V1+50][V2+50] = 1;
	}

	int res = 0;
	i = 0; j = 0;
	for(i=0; i < MapSize; i++){
		for(j=0; j < MapSize; j++){
			if(G[i][j] == 1){
				if(vistied[i][j] == 0){
					if(FirstJump(i, j)){
						printf("(50, 50) (%d, %d)\n", i, j);
						vistied[i][j] = 1;
						res = DFS(i, j);
						if(res == 1) {
							i = MapSize;
							break;
						}
					}
				}
			}
		}
	}

	if(res == 1)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}
	