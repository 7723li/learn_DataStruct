// 广义表(属于多重链表),二元多项式
#include <stdio.h>

typedef int ElementType;
typedef struct GNode* GList;

struct GNode{
	int Tag;// 标志域，0表示结点是单元素，1表示结点是广义表
	union{
		ElementType Data;
		GList subList;
	}URegion;
	GList Next;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}
