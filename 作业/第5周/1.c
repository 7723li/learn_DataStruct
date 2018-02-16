// 05-树7 堆中的路径
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* MinHeap; // 最小堆
struct Node
{
	int *data; // 数组
	int nums; // 元素个数
	int size; // 最大容量
};

MinHeap Creat(int size){
	MinHeap H = (MinHeap) malloc (sizeof(struct Node) * size);
	H -> data = (int*) malloc (sizeof(int) * size);
	H -> nums = 0;
	H -> size = size;
	H -> data[0] = 0; // 最小堆哨兵应为最小值

	return H;
}

void Insert(MinHeap H, int val){
	int i;
	i = ++(H -> nums);
	for( ;H->data[i/2] > val; i/=2)
		H -> data[i] = H -> data[i/2];
	H -> data[i] = val;
}

int main(int argc, char const *argv[])
{
	int nums, paths, i, temp;

	scanf("%d %d", &nums, &paths); 
	++nums;// 首位为哨兵，应增加一位

	MinHeap H = Creat(nums);
	for(i=0; i<nums-1; i++){
		scanf("%d", &temp);
		Insert(H, temp);
	}

	for(i=0; i<paths; i++){
		scanf("%d", &temp);
		while(temp/2){
			printf("%d ", H -> data[temp]);
			temp /= 2;
		}
		printf("%d\n", H -> data[temp]);
	}
	
	return 0;
}
