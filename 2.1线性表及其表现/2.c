// 线性表的链式储存实现(链表)
#include <stdio.h>
#include <malloc.h>

typedef int ElementType ;
typedef struct LNode* List;

struct LNode{
	ElementType Data;
	List Next;
};
List PtrL;

int Length(List PtrL);// 求表长
List FindKth(List PtrL,int K);
List FindK(List PtrL,ElementType K);
List Insert(List PtrL,ElementType K,int i);
List Delete(List PtrL,int i);

int main(int argc, char const *argv[])
{
	List L;L=(List)malloc(sizeof(struct LNode));
	int length;
	length = Length(L);
	printf("%d\n", length);
	return 0;
}

int Length(List PtrL){
	List p=PtrL;// p指向表的第一个结点
	int j = 0;
	while(p){
		printf("%p\n", p);
		p = p->Next;
		j++;// 当前p指向的是第j个结点
	}
	return j;
}

List FindKth(List PtrL,int K){// 寻找第K个元素
	List p =PtrL;
	int i=1;
	while(p != NULL && i<K){
		p = p->Next;
		i++;
	}
	if(i == K){
		return p;// 找到第K个，返回指针,即返回此处结点的指针
	}else{
		return NULL;// 否则返回空
	}
}

List FindK(List PtrL,ElementType K){// 查找K在表中的位置
	List p = PtrL;
	int i=1;
	while(p!=NULL && p->Data != K){
		p = p-> Next;
	}
	return p;// 若K输入值非法，则返回表头值
}

List Insert(List PtrL,ElementType K,int i){// 在PtrL的第i点插入k
	List last,new;
	if(i==1){// 新结点在表头
		new=(List)malloc(sizeof(struct LNode));
		new->Data = K;
		new->Next = PtrL;
		return new;// 返回表头指针
	}
	last = FindKth(PtrL,i-1);//查找上一个结点
	if(last == NULL){
		printf("Error");
		return NULL;
	}else{
		new=(List)malloc(sizeof(struct LNode));
		new -> Data = K;
		new -> Next = last -> Next;
		last -> Next = new;
		return PtrL;// 返回新链表的头指针
	}
}

List Delete(List PtrL,int i){// 删除PtrL的第i点
	List p,s;
	if (i==1){//头结点
		s = PtrL;
		if(PtrL != NULL){
			PtrL = PtrL->Next;
		}else{
			return NULL;
		}
		free(s);
		return PtrL;
	}
	p=FindKth(PtrL,i-1);//查找上一个结点
	if(p == NULL){
		printf("not exists\n");
		return NULL;
	}
	else if(p -> Next ==NULL){//尾结点
		printf("not exists\n");
		return NULL;
	}else{
		s = p-> Next;
		p -> Next =s -> Next;
		free(s);
		return PtrL;
	}
}
