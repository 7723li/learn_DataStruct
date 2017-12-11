// 数据结构二分查找
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct Node* List;
struct Node
{
	int li[MaxSize];
	int length;
};
void find(List,int,int);

int main(int argc, char const *argv[])
{
	List p;int length = 100;
	int tar = 1;
	for(int i=0;i<length;i++){ 
		p -> li[i] = i+1;
	}
	printf("%d\n",1);
	p -> length = length;
	find(p,length,tar);

	return 0;
}

void find(List p,int length,int tar){
	int low = 0,high = length;
	int mid;
	while(low <= high){
		mid = (low + length)/2;
		if (p->li[mid] == tar){
			printf("%d\n", mid+1);
			break;
		}
		if(p->li[mid] < tar){
			low = mid + 1;
		}
		if(p->li[mid] > tar){
			high = mid - 1;
		}
	}
}
