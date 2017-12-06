// 堆栈的顺序储存实现
#include <stdio.h>

#define MaxSize 1000

typedef struct SNode1* Stack1;
void Push1(Stack1 PtrS, int item);// 单向顺序储存
int Pop1(Stack1 PtrS, int item);
struct SNode1{
	int Data[MaxSize];
	int Top;
};

typedef struct SNode2* Stack2;
void Push2(Stack2 PtrS, int item, int Tag);// 双向顺序储存
int Pop2(Stack2 PtrS, int item, int Tag);
struct SNode2{
	int Data[MaxSize];
	int Top1;
	int Top2;
};

int main(int argc, char const *argv[])
{
	struct SNode2 s;
	s.Top1=-1;
	s.Top2=MaxSize;
	return 0;
}

void Push1(Stack1 PtrS, int item){
	if(PtrS->Top == MaxSize-1){
		printf("堆栈满");
	}else{
		PtrS -> Data[++(PtrS->Top)] == item;
		return;
	}
}

int Pop1(Stack1 PtrS, int item){
	if (PtrS->Top==-1){
		printf("堆栈空");
		return;
	}else{
		return(PtrS->Data[(PtrS->Top)--]);
	}
}
/********************************************************/
void Push2(Stack2 PtrS, int item,int Tag){
	if(PtrS->Top2 - PtrS->Top1 == 1){
		printf("堆栈满");
		return;
	}
	if(Tag==1){
		PtrS->Data[++(PtrS->Top1)]=item;
	}else{
		PtrS->Data[--(PtrS->Top2)]=item;
	}
}

int Pop2(Stack2 PtrS, int item, int Tag){
	if(Tag==1){
		if(PtrS->Top1 == -1){
			printf("堆栈1空");
			return;
		}else{
			return PtrS->Data[(PtrS->Top1)--];
		}
	}else{
		if(PtrS->Top2 == MaxSize){
			printf("堆栈2空");
			return;
		}else{
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
}
