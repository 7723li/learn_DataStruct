// 队列的链式储存结构
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

struct Node{
	ElementType Data;
	struct Node* Next;
};

typedef struct QNode* Queue;
struct QNode{// 链队列结构
	struct Node* rear;// 指向队尾结点
	struct Node* front;// 指向队头结点
};
ElementType DeleteQ(Queue PtrQ);
void Insert(Queue PtrQ, ElementType Elem);

int main(){
	Queue p;
	p = (Queue)malloc(sizeof(struct QNode));
	p -> rear = NULL;p -> front = NULL;
	int i;
	for(i=0;i<10;i++){
		Insert(p,i);
	}
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a60,0x5d2af0

	DeleteQ(p);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a70,0x5d2af0
	DeleteQ(p);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a80,0x5d2af0
	DeleteQ(p);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a90,0x5d2af0

	Insert(p,100);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a90,0x5d2a60
	Insert(p,101);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a90,0x5d2a70
	Insert(p,102);
	printf("%p,%p\n",p -> front,p -> rear);// 0x5d2a90,0x5d2a80

	while(p -> front != NULL){
		printf("%d ", p -> front -> Data);
		p -> front = p -> front -> Next;
	}
	printf("\n");

	return 0;
}

ElementType DeleteQ(Queue PtrQ){
	struct Node* Frontcell;
	ElementType FrontElem;

	if(PtrQ -> front == NULL){
		printf("Empty\n");
	}
	Frontcell = PtrQ->front;
	FrontElem = Frontcell -> Data;
	if(PtrQ -> front == PtrQ->rear){// 队列中只有一个元素
		PtrQ -> front = PtrQ -> rear =NULL;// 删除后队列置为空
	}else{
		PtrQ -> front = Frontcell ->Next;
	}
	free(Frontcell);
	return FrontElem;
}

void Insert(Queue PtrQ, ElementType Elem){
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p -> Data = Elem;
	p -> Next =NULL;

	if(PtrQ -> front == NULL){
		PtrQ -> front = p;
		PtrQ -> rear = p;
	}else{
		PtrQ -> rear -> Next = p;
		PtrQ -> rear = p;
	}
}
