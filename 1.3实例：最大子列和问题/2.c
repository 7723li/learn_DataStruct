// 复杂度2 得出最大子列和，并获取该子列的头元素和尾元素
#include <stdio.h>
#define MAXLenght 1000

int Subsequence(int length,int* const l,int* head,int* end);

int main(int argc, char const *argv[])
{
	int head=0;int end=0;
	int l[10] = {-10,1,2,3,4,-5,-23,3,7,-21},res;
	int length = sizeof(l)/sizeof(l[0]);
	res = Subsequence(length,l,&head,&end);
	printf("%d,%d,%d",head,end,res);
	return 0;
}

int Subsequence(int length,int* const l,int* head,int* end){
	int i;int j=0;
	int max=0;int list[length];
	for (i=0;i<length;i++){
		j += l[i];
		if(j<=0){
			j = 0;
			list[i] = 0;
		}else{
			list[i] = l[i];
			if(j>max){
				max = j;
				list[i] = l[i];
			}
		}
	}
	for (i=0;i<length;i++){
		printf("%d ", list[i]);
		if(list[i]!=0 && list[i-1]==0){
			*head = list[i];
		}
		if(list[i]==0 && list[i-1]!=0){
			*end = list[i-1];
		}
	}
	printf("\n");
	return max;
}
