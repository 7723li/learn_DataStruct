// 6.4六度空间
#include <stdio.h>
#include <stdlib.h>

int **map, *visted;
int vertex, column;

void CreatGraph(){
	int i, j, a, b;

	map = (int**) malloc (sizeof(int *) * vertex);
	visted = (int*) malloc (sizeof(int) * vertex);

	for(i=0; i<vertex; i++){ // 初始化图
		map[i] = (int*) malloc (sizeof(int) * vertex);
		visted[i] = 0;
		for(j=0; j<vertex; j++)
			map[i][j] = 0;
	}

	for(i=0; i<column; i++){ // 插入边
		scanf("%d %d", &a, &b);
		--a; --b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
}

void PrintGraph(){
	int i, j;
	printf("\n");
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void BFS(int v){
	int Queue[100], front = 0, rear = 0;
	int count = 1, temp, i, level = 0, last = v, rail;

	Queue[rear++] = v; // push
	visted[v] = 1;

	while(front != rear){
		temp = Queue[front++]; // pop
		for(i=0; i<vertex; i++){
			if(visted[i] == 0 && map[temp][i] == 1){
				printf("%d (%d, %d)\n", v+1, temp+1, i+1);
				Queue[rear++] = i;
				visted[i] = 1; // 按题目,矩阵每列只有一个有效数据
				count++;
				rail = i;
			}
		}
		
		// printf("temp = %d last = %d\n", temp+1, last+1);
		if(temp == last){
			level++;
			last = rail;
		}
		if(level == 6)
			break;
	}
	printf("%d: %.2f%%\n", v+1, (count * 100.00) / vertex); 
}

int main(int argc, char const *argv[])
{
	int i, j;
	scanf("%d %d", &vertex, &column);

	CreatGraph();
	PrintGraph();

	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++)
			visted[j] = 0;
		BFS(i);
	}

	return 0;
}

// 10 9
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 9
// 9 10
