// 线性表顺序储存的创建及方法(数组)
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 1000

typedef int ElementType;
typedef struct LNode* List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};
// 数组的操作
List MakeEmpty();
int Find(ElementType X,List PtrL);
void Insert(ElementType X,int i,List PtrL);// 在第i个位置插入X
void Delete(ElementType X,int i,List PtrL);

int main(){
	List p = MakeEmpty();
	int i;
	int res;
	for(i=0;i<10;i++){
		Insert(i+1,i+1,p);
	}
	res=Find(1,p);
	printf("%d\n", res);
	return 0;
}

List MakeEmpty(){
	List PtrL;// (struct LNode* PtrL)
	PtrL = (List)malloc(sizeof(struct LNode));// 结构类型指针必须先分配内存方可设置值
	PtrL -> Last = -1;//初始状态默认表长度为-1
	return PtrL;// 返回结构指针
}

int Find(ElementType X,List PtrL){
	int i=0;
	while(i<=PtrL->Last && PtrL->Data[i] != X){// 循环条件为查找范围未超出表长度，并且未找到所需节点
		i++;
	}
	if(i > PtrL->Last){
		return -1;
	}else{
		return i;
	}
}

void Insert(ElementType X,int i,List PtrL){
	int j=0;
	if(PtrL->Last == MAXSIZE-1){
		printf("Full\n");// 表满
		return;
	}
	if(i<1 || i>PtrL->Last+2){
		printf("illegal\n");// 位置不合法
		return;
	}
	for(j=PtrL->Last;j>i-1;j--){
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}

void Delete(ElementType X,int i,List PtrL){
	int j=0;
	if(i<1 || i>PtrL->Last+2){
		printf("not exists\n");// 不存在此数据
		return;
	}
	for(j=i;j<=PtrL->Last;j++){
		PtrL->Data[j] = PtrL->Data[j+1];
	}
	PtrL->Last--;
	return;
}
