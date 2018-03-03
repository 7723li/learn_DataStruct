// 冒泡，插入排序
// 两者每次交换都只能消除一个逆序对
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
	int temp1[] = {654, 698, 32, 305, 1, 321, 204};
	int temp2[] = {654, 698, 32, 305, 1, 321, 204};
	int i, j, len = sizeof(temp1) / sizeof(temp1[0]);
	int flag, temp, count;

	// 冒泡，最好情况T = O(N), 最坏O(N^2)
	count = 0;
	for(i=len-1; i>=0; i--){
		flag = 0;
		for(j=0; j<i; j++){
			if(temp1[j] > temp1[j + 1]){
				count += 1;
				flag = 1;
				temp = temp1[j];
				temp1[j] = temp1[j+1];
				temp1[j+1] = temp;
			}
		}
		if(flag == 0)
			break;
	}
	printf("count = %d\n", count);
	printList(temp1, len);

	// 插入排序, 最好情况T = O(N), 最坏O(N^2)
	count = 0;
	for(i=1; i<len; i++){
		temp = temp2[i];
		for(j=i; j>0 && temp2[j-1] > temp; j--){
			count += 1;
			temp2[j] = temp2[j-1];
		}
		temp2[j] = temp;
	}
	printf("count = %d\n", count);
	printList(temp2, len);

	return 0;
}
