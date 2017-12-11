// Reversing Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node* List;
struct Node 
{
	int add;
	int Data;
	int next_add;
	List Next;
};
List New(int,int);
List Sort(List,int,int);
List Reverse(List,int,int);

int main(int argc, char const *argv[])
{
	int firstAdd;
	int N,k;// 长度，结点位置
	List* l;int i;
	scanf("%d %d %d",&firstAdd,&N,&k);
	List p1 = New(firstAdd,N);
	List p2 = Sort(p1,firstAdd,N);

	//清空借用内存
	l= (List*)malloc(sizeof(List)*N); i=0;
	while(p1){ l[i]=p1; i++; free(l[i]); p1 = p1->Next;} free(l);

	List p3 = Reverse(p2,N,k);

	l = (List*)malloc(sizeof(List)*N); i=0;printf("\n");
	while(p2){ 
		l[i]=p2; 
		printf("%05d %d %d\n", l[i]->add,l[i]->Data,l[i]->next_add);
		i++; free(l[i]); p2 = p2->Next;
	} free(l);

	l = (List*)malloc(sizeof(List)*N); i=0;printf("\n");
	while(p3){ 
		l[i]=p3; 
		printf("%05d %d %d\n", l[i]->add,l[i]->Data,l[i]->next_add);
		i++; free(l[i]); p3 = p3->Next;
	} free(l);
}

List New(int firstAdd,int N){
	List L1,p1,q1;// head,tail,mid
	L1 = (List)malloc(sizeof(struct Node));// 创建头指针
	L1 -> Next = NULL;
	p1 = L1;
	for(int i=0;i<N;i++){
		q1 = (List)malloc(sizeof(struct Node));
		scanf("%d %d %d",&q1->add,&q1->Data,&q1->next_add);
		p1 -> Next = q1;
		p1 = q1;
	}
	p1 -> Next = NULL;
	p1 = L1 -> Next;
	return p1;
}

List Sort(List p,int firstAdd,int length){
	List p1,p2;
	List head,mid,tail;
	int add,next_add;;
	head = (List)malloc(sizeof(struct Node));
	p1 = p;
	tail = head; 
	while(p1){// 找出头结点，判断条件为地址等于给定的起始地址
		if(p1->add == firstAdd){ 
			mid = (List)malloc(sizeof(struct Node));
			mid -> add = p1 -> add;
			mid -> Data = p1 -> Data;
			mid -> next_add = p1 -> next_add;
			tail -> Next = mid;
			tail = mid;
			break; 
		}
		else p1 = p1 -> Next;}

	
	for(int i=0;i<length-1;i++){
		p1 = p;
		next_add = tail -> next_add;
		while(p1 != NULL){
			if(p1->add == next_add){
				mid = (List)malloc(sizeof(struct Node));
				mid -> add = p1 -> add;
				mid -> Data = p1 -> Data;
				mid -> next_add = p1 -> next_add;
				tail -> Next = mid;
				tail = mid;
				break;
			}
			p1 = p1 -> Next;
		}
	}
	tail -> Next = NULL;
	tail = head->Next;
	return tail;
}

List Reverse(List p,int length,int pos){// 长度，结点位置
	int nod = length/pos;// 链表内需逆转部分段数
	int li_length= nod*pos;
	List head,mid,tail;
	List li[li_length];// 装入需逆转的部分
	for(int i=0;i<li_length;i++){
		li[i] = p;
		p = p -> Next;
	}

	head = (List)malloc(sizeof(struct Node));
	tail = head;
	for(int i=pos-1;i<li_length;i+=pos){
		for(int j=i;j>=i-pos+1;j--){
			mid = (List)malloc(sizeof(struct Node));
			mid -> add = li[j]->add;
			mid -> Data = li[j]->Data;
			mid -> next_add = li[j]->next_add;
			tail -> Next = mid;
			tail = tail -> Next;
		}
	}

	while(p){
		mid = (List)malloc(sizeof(struct Node));
		mid -> add = p->add;
		mid -> Data = p->Data;
		mid -> next_add = p->next_add;
		tail -> Next = mid;
		tail = tail -> Next;
		p = p->Next;
	}

	tail->Next=NULL;
	tail = head -> Next;
	free(li);
	return tail;
}
