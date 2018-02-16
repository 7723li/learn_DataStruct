// 5.2.1 什么是哈夫曼树
// 5.2.2 哈夫曼树的构造
// 5.2.3 哈弗曼编码
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* HuffmanTree;
struct TreeNode
{
	int Weight; // 权重
	HuffmanTree Left, Right;
};

HuffmanTree Huffman(MinHeap H){
	// 假设 H -> Size 个权值已经存在 H -> Elements[] -> Weight中
	int i;
	HuffmanTree T;
	BuildMinHeap(H); // 将H -> Elements[]讲权值调整为最小堆
	for(i=1; i < H->Size; i++){ // 做 H->Size - 1次合并
		// 建立新节点
		T = malloc(sizeof(struct TreeNode));
		// 从最小堆中删除一个结点，作为新树的左子节点
		T -> Left = DeleteMin(H);
		T -> Right = DeleteMin(H);
		// 计算新权值
		T -> Weight = T->Left->Weight + T->Right->Weight;
		Insert(H,T); // 将新树插入最小堆
	}
	T = DeleteMin(H);
	return T;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
