// Complete Binary Search Tree
#include <stdlib.h>
#include <stdio.h>

int pow(int a,int b){
	int c = 1;
	if(b==0) return 1;
	while(b--) c *= a;
	return c;
}

void move(int* c,int i,int j){ 
// 将i移动至j,i前j后,将(i,j]之间的前移
	int temp = c[i],k;
	for(k=i; k<j; k++) c[k] = c[k+1];
	c[j] = temp;
}

int main(int argc, char const *argv[])
{
	int i, j, temp;
	int nums, *TreeNodes;
	//树的高度，枝干,底层叶节点
	int height = 0, branches = 0, leaves;
	int times, pos;

	scanf("%d", &nums);
	TreeNodes = (int*) malloc (sizeof(int) * nums);
	for(i=0; i<nums; i++) scanf("%d", &TreeNodes[i]);

	for(i=0; i<nums-1; i++){ // 大小排序
		for(j=i+1; j<nums; j++){
			if(TreeNodes[i] > TreeNodes[j]){
				temp = TreeNodes[i];
				TreeNodes[i] = TreeNodes[j];
				TreeNodes[j] = temp;
			}
		}
	}

	while(true)
		if(branches > 0 && nums/branches == 1) break;
		else branches += pow(2,height++);
	
	leaves = nums - branches;
	for(i=0; i<leaves; i++){ // 叶节点排序
		move(TreeNodes,i,nums-1);
	}

	// 具体操作思路看3.2 3.3图片
	for(height; height>0; height--){ 
		times = pow(2,(height-1)); 
		pos = pow(2,height) - 2;
		for(i=0; i<times; i++){
			move(TreeNodes, i, pos);
		}
	}

	for(i=0; i<nums-1; i++){
		printf("%d ", TreeNodes[i]);
	}
	printf("%d\n", TreeNodes[nums-1]);

	return 0;
}

// 10
// 1 2 3 4 5 6 7 8 9 0
// 21
// 20 19 18 17 16 15 14 13 12 
// 11 10 9 8 7 6 5 4 3 2 1 0
