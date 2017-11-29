// 二分法
#include <stdio.h>

int find(int num,int *a,int length);

int main(){
	int a[10] = {1,11,21,31,42,56,60,79,84,95,},res;
	int num =11;
	int length = sizeof(a)/sizeof(a[0]);
	res = find(num,a,length);
	printf("%d\n",res);

	return 0;
}

int find(int num,int *a,int length){
	int low=0;int high = length;
	int mid;
	while(low <= high){
		mid = (low+high)/2;
		if (a[mid] == num){
			return mid;
		}
		if (a[mid] < num){
			low = mid+1;
		}
		if (a[mid] > num){
			high = mid-1;
		}
	}
	return mid;
}
