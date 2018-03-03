// 希尔排序
// 基于插入与冒泡排序思想的算法, 递减间隔进行排序
// 大间隔的排序结果 在进行小间隔排序后 依然按照大间隔的规律
// 增量元素不互质，小增量可能根本不起作用
#include <stdio.h>
#include <stdlib.h>

void printList(int* l, int len){
	int i;
	for(i=0; i<len; i++)
		printf("%d ", l[i]);
	printf("\n");
}


int main(int argc, char const *argv[])
{
	int i, j, k;
	int len = 7, temp;
	int temp1[len] = {654, 698, 32, 305, 1, 321, 204};

	// 原始希尔排序
	for(i = len / 2; i > 0; i /= 2){ // 取间隔
		// 此处开始为插入排序
		for(j = i; j<len; j++){
			temp = temp1[j];
			for(k = j; k >= i && temp1[k - 1] > temp; k -= i)
				temp1[k] = temp1[k - i];
			temp1[k] = temp;
		}
	}

	printList(temp1, len);
	
	return 0;
}
