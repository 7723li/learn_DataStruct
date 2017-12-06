// 单链表逆转
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* List;
struct Node
{
	int Data;
	List Next;
};
List New(int);
List Reverse(List,int);

int main(int argc, char const *argv[])
{
	List p1,p2;
	int length;scanf("%d",&length);// 链表长度
	p1 = New(length);
	p2=Reverse(p1,length);

	// 清空借用内存
	List* l = (List*)malloc(sizeof(List)*length*2);
	for(int i=0;i<length;i++)
		{l[i]=p1;printf("%d ",l[i]->Data);p1=p1->Next;free(l[i]);}
	printf("\n");	
	for(int i=length;i<length*2;i++)
		{l[i]=p2;printf("%d ",l[i]->Data); p2=p2->Next; free(l[i]);}
	printf("\n");
	free(l);

	return 0;
}

List New(int length){
	List head,mid,tail;
	head = (List)malloc(sizeof(struct Node));
	tail = head;
	
	for(int i=0;i<length;i++){
		mid = (List)malloc(sizeof(struct Node));
		mid -> Data = i+1;// scanf("%d",&(mid->Data))
		tail -> Next = mid;
		tail = tail->Next;
	}
	tail -> Next = NULL;
	tail = head->Next;
	free(head);
	return tail;
}

List Reverse(List p1,int length){
	List* l;// 用于存放指针
	l = (List*)malloc(sizeof(List)*length);
	for(int i=0;i<length;i++){
		l[i] = p1;
		p1 = p1->Next;
	}

	List head,mid,tail;
	head = (List)malloc(sizeof(struct Node));
	tail = head;
	for(int i=length-1;i>=0;i--){
		mid = (List)malloc(sizeof(struct Node));
		mid -> Data = l[i]->Data;
		tail -> Next = mid;
		tail = tail -> Next;
	}
	tail -> Next = NULL;
	tail = head->Next;
	free(head);free(l);
	return tail;
}
