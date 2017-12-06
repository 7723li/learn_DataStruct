// 堆栈的链式储存实现
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct SNode* Stack;

struct SNode
{
	ElementType Data;
	Stack Next;
};
Stack CreatStack();
int IsEmpyt(Stack s);// 此时s必定为头结点，与push中有不同
void push(ElementType item,Stack s);// 在指定结点s(一般需要先找到)后插入
ElementType pop(Stack s);// 删除s结点的下一个结点并返回储存的数值

int main(int argc, char const *argv[])
{
	Stack s;
	s = CreatStack();
	printf("%p\n",s);
	pop(s);
	return 0;
}

Stack CreatStack(){
	Stack s;
	s =(Stack)malloc(sizeof(struct SNode)); 
	s->Next=NULL;
	return s;
}

int IsEmpyt(Stack s){
	return (s->Next == NULL);
}

void push(ElementType item,Stack s){
	Stack p;
	p = (Stack)malloc(sizeof(struct SNode));
	p -> Data = item;
	p -> Next = s->Next;
	s -> Next = p;
}

ElementType pop(Stack s){
	if(IsEmpyt(s)){
		printf("Null\n");
		return NULL;
	}
	Stack mid; ElementType a;
	mid = s -> Next;
	s -> Next = mid -> Next;// s->Next->Next
	a = mid -> Data;
	free(mid);
	return a;
}
