#include <stdio.h>
#include <malloc.h>

typedef struct PolyNode* Polynomial;
struct PolyNode
{
	int coef;// 系数
	int expon;// 指数
	Polynomial next;
};
Polynomial PolyAdd(Polynomial p1,Polynomial p2);// 生成一个新的链表
Polynomial ReadPoly();
int Compare(int,int);
void Attach(int,int,Polynomial*);

int main(){

	return 0;
}

int Compare(int p1coef,int p2coef){
	if(p1coef > p2coef){
		return 1;
	}
	if(p1coef < p2coef){
		return -1;
	}
	if(p1coef == p2coef){
		return 0;
	}
}

void Attach(int coef,int expon,Polynomial* rear){
	Polynomial p;
	p = (Polynomial)malloc(sizeof(struct PolyNode));
	p -> coef = coef;
	p -> expon = expon;
	p -> next =NULL;
	/* 将P指向的新结点插入到当前结果表达式尾项的后面 */ 
	(*rear) -> next = p;
	*rear = p;
}

// p1,p2分别指向两个多项式的第一个结点,不断循环
Polynomial PolyAdd(Polynomial p1,Polynomial p2){
	int sum;
	Polynomial front,rear,temp;// 链表头，尾，当前结点
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;// 初始化时头尾指向同一处
	while(p1 && p2){
		switch(Compare(p1->coef,p2->coef)){
			case 1: 
				Attach(p1->coef,p1->expon,&rear);
				p1 = p1 -> next;
				break;
			case -1: 
				Attach(p2->coef,p2->expon,&rear);
				p2 = p2 -> next;
				break;
			case 0:
				sum = p1->coef + p2->coef;
				if(sum) Attach(sum,p1->expon,&rear);
				p1 = p1->next;
				p2 = p2->next;
				break;
		}
	}

	// 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去
	for(;p1;p1=p1->next) Attach(p1->coef,p1->expon,&rear);
	for(;p2;p2=p2->next) Attach(p2->coef,p2->expon,&rear);

	rear -> next = NULL;
	temp = front;
	front = front ->next;// 令front指向结果多项式第一个非零项
	free(temp);// 释放临时空表头结点
	return front;
}

Polynomial ReadPoly(){
	Polynomial p,rear,t;
	int c,e,N;

	scanf("%d",&N);
	p=(Polynomial)malloc(sizeof(struct PolyNode));
	p->next=NULL;
	rear = p;
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,e,&rear);
	}
	t=p; p=p->next; free(t);
	return p;
}
