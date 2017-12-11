// 二分查找
#include <stdio.h>

struct Node
{
	int li[1000];
	int length;
};

int main(int argc, char const *argv[])
{
	int a[13] = {5,16,39,45,51,98,100,202,226,321,368,444,501};
	int low = 0, high = 13;
	int tar = 5;
	int mid;
	while(low <= high){
		mid = (high + low)/2;
		if (a[mid] == tar){
			printf("%d\n", mid+1);
			break;
		}
		if(a[mid] > tar){
			high = mid - 1;
		}
		if(a[mid] < tar){
			low = mid + 1;
		}
	}
	return 0;
}
