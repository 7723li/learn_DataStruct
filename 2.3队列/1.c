// 队列的顺序储存结构
// 以下实现的为循环队列，可有效避免溢出
#include <stdio.h>

#define MaxSize 1000

typedef int ElementType;

typedef struct QNode* Queue;
struct QNode
{
	ElementType Data[MaxSize];
	int rear;// 尾
	int front;// 头
};
void AddQ(Queue PtrQ,ElementType item);
ElementType DeleteQ(Queue PtrQ);

int main(){

	return 0;
}

void AddQ(Queue PtrQ,ElementType item){
	if((PtrQ -> rear+1) % MaxSize == PtrQ -> front){
		printf("full\n");
		return;
	}
	PtrQ -> rear = (PtrQ -> rear + 1)%MaxSize;
	PtrQ -> Data[PtrQ -> rear] = item;
}

ElementType DeleteQ(Queue PtrQ){
	if(PtrQ -> front == PtrQ -> rear){
		printf("empty\n");
	}else{
		PtrQ -> front =(PtrQ -> front + 1) % MaxSize;
		return PtrQ -> Data[PtrQ -> front];
	}
}
