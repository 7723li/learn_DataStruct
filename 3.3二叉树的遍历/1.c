// 二叉树的先序、中序、后序(非递归)
// 斐波那契数列是先序遍历
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef struct Layer* Stack;
typedef struct Node* BinTree;

struct Layer// 栈层
{
	BinTree* li;// 结构指针数组
	int top;
};
Stack CreatStack(int);
bool IsEmpty(Stack);
BinTree Pop(Stack);
void Push(Stack,BinTree);

struct Node// 树节点
{
	int Data;
	BinTree Left;
	BinTree Right;
};
void FirstOrder(BinTree BT);// 先序遍历
void MidOrder(BinTree BT);// 中序遍历
void AfterOrder(BinTree BT);// 后序遍历

int main(int argc, char const *argv[])
{
	return 0;
}

Stack CreatStack(int top){
	Stack New;
	New = (Stack)malloc(sizeof(struct Layer));
	New->top=0;
	New->li=(BinTree*)malloc(sizeof(BinTree)*top);
	return New;
}

inline bool IsEmpty(Stack s){
	return s->top == 0;
}

void Push(Stack s,BinTree ele){
	if(s->top == MaxSize-1){// 栈满
		printf("Full\n");return;
	}
	// 若结点不为空则放到栈顶并指向新栈顶
	if(ele) s->li[s->top++] = ele;
	return;
}

BinTree Pop(Stack s){
	if(IsEmpty(s)){// 栈空
		printf("Empty\n");return false;
	}
	// 先指向下面一层
	return s->li[--s->top];
}

void FirstOrder(BinTree BT){
	BinTree t = BT;
	Stack s = CreatStack(MaxSize);
	while(t || !IsEmpty(s)){
		while(t){
			printf("%5d\n", t->Data);
			Push(s,t);
			t = t->Left;
		}
		if(!IsEmpty(s)){
			t = Pop(s);
			t = t->Right;
		}
	}
	free(s->li);free(s);
}

void MidOrder(BinTree BT){
	BinTree t = BT;
	Stack s = CreatStack(MaxSize);
	while(t || !IsEmpty(s)){
		while(t){/*一直向左并将沿途结点压入堆栈*/
			Push(s,t);
			t = t->Left;
		}
		if(!IsEmpty(s)){
			t = Pop(s);/*结点弹出堆栈*/
			printf("%5d\n", t->Data);
			t = t->Right; /*转向右子树*/
		}
	}
}

void AfterOrder(BinTree BT){
	BinTree t = BT;
	Stack s = CreatStack(MaxSize);
	int flag[MaxSize];
	while(t || !IsEmpty(s)){
		while(t){
			Push(s,t);
			flag[s->top-1]=0;
			t = t->Left;
		}
		while(!IsEmpty(s) && flag[s->top-1]==1){
			t = Pop(s);
			printf("%5d\n", t->Data);
		}
		if(!IsEmpty(s)){
// 因为push操作过后栈中指向空的新栈顶，因此需要指向下一层
			flag[s->top-1]=1;// 设置标记右子树已经访问
			t = s->li[s->top-1];// 仅取出栈顶元素，不弹出
			t = t->Right;
		}
		else break;
	}
}
