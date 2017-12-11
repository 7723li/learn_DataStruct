// 顺序查找
#include <stdio.h>

typedef struct LNode* List;
struct LNode
{
	int Element[1000];
	int length;
};

int SequentialSearch(List Tb1,int k){
	int i;
	Tb1 -> Element[0] = k;// 建立哨兵
	// 对照上下两句知识哨兵作用
	for(i=Tb1->length;Tb1->Element[i] != k; i--);
	//for(i=Tb1->length;i>0 && Tb1->Element[i] != k; i--);
	return i;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

