#include <stdio.h>
#define MAXLenght 1000

// 最大子列和问题
int online(int num,int* l);// 在线处理方式
int D_and_C(int* l,int left,int right);// 分而治之
int max3(int MaxLeft,int MaxRight,int SumLeftRight);

int main(){
	int l[8] = {2,1,-7,-9,5,6,-7,8},res;
	res = online(sizeof(l)/sizeof(l[0]),l);
	printf("online:%d\n", res);

	res=D_and_C(l,0,8-1);
	printf("D_and_C:%d\n", res);
	return 0;
}

int online(int num,int* const l){
	int i;int j=0;
	int max=0;
	for (i=0;i<num;i++){
		j += l[i];
		if(j<0){
			j = 0;
		}else{
			if(j>max){
				max = j;
			}
		}
	}
	return max;
}

int D_and_C(int* l,int left,int right){
	int i,j;
	int center;
	int MaxLeft,MaxRight;
	int MaxLeftCrossLine,MaxRightCrossLine;// 跨线
	if (left == right){
		if(l[left]>0){
			return l[left]; // 到达基线条件,表中只剩一个元素或没有元素
		}
		else{
			return 0;
		}
	}

	center = (right + left)/2;
	MaxLeft = D_and_C(l,left,center);
	MaxRight = D_and_C(l,center+1,right);

	MaxLeftCrossLine = 0;j = 0;
	for(i=center;i>=left;i--){// 从中间向左扫描
		j += l[i];
		if (j > MaxLeftCrossLine){
			MaxLeftCrossLine = j;
		}
	}
	MaxRightCrossLine = 0;j = 0;
	for(i=center+1;i<=right;i++){// 从中间向右扫描
		j += l[i];
		if (j>MaxRightCrossLine){
			MaxRightCrossLine = j;
		}
	}
	printf("%d,%d,%d\n",MaxLeft,MaxRight,MaxLeftCrossLine+MaxRightCrossLine );
	return max3(MaxLeft,MaxRight,MaxLeftCrossLine+MaxRightCrossLine);
}

int max3(int MaxLeft,int MaxRight,int SumLeftRight){
	int i;
	if (MaxLeft > MaxRight){
		i = MaxLeft;
	}else{
		i = MaxRight;
	}
	if(i < SumLeftRight){
		i = SumLeftRight;
	}
	// printf("%d\n",i);
	return i;
}
