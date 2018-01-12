// Root of AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode* AvlTree;
struct TreeNode
{
	int key;
	int height;
	AvlTree left;
	AvlTree right;
};

int MAX(int a,int b){
	return a > b ? a : b;
}

int getHeight(AvlTree Tree){
	return (Tree == NULL) ? -1 : Tree -> height;
}

AvlTree LLRotation(AvlTree k2){
	AvlTree k1;

	k1 = k2 -> left;
	k2 -> left = k1 -> right;
	k1 -> right = k2;

	k2 -> height = 
		MAX(getHeight(k2 -> left), getHeight(k2 -> right)) + 1;
	k1 -> height = 
		MAX(getHeight(k1 -> left), k1 -> height) + 1;

	return k1;
}

AvlTree RRRotation(AvlTree k1){
	AvlTree k2;

	k2 = k1 -> right;
	k1 -> right = k2 -> left;
	k2 -> left = k1;

	k1 -> height = 
		MAX(getHeight(k1 -> left), getHeight(k1 -> right)) + 1;
	k2 -> height = 
		MAX(getHeight(k2 -> left), k2 -> height) + 1;

	return k2;
}

AvlTree RLRotation(AvlTree k1){
	k1 -> right = LLRotation(k1 -> right);
	return RRRotation(k1);
}

AvlTree LRRotation(AvlTree k2){
	k2 -> left = RRRotation(k2 -> left);
	return LLRotation(k2);
}

// 创建结点
AvlTree Create(int key, AvlTree left, AvlTree right){
	AvlTree p = (AvlTree)malloc(sizeof(struct TreeNode));
	if(p == NULL) return NULL;
	p -> key = key;
	p -> height = 0;
	p -> left = left;
	p -> right = right;
	return p;
}

AvlTree Insert(AvlTree Tree, int key){
	if(Tree == NULL){ // 新树
		Tree = Create(key, NULL, NULL);
		if(Tree == NULL) return NULL;
	}

	// 应该将key插入到"tree的左子树"的情况
	else if (key < Tree -> key){
		Tree -> left = Insert(Tree -> left, key);
		if(getHeight(Tree->left) - getHeight(Tree->right) == 2){
			if(key < Tree -> left ->key){
				Tree = LLRotation(Tree);
			}
			else{
				Tree = LRRotation(Tree);
			}
		}
	}

	// 应该将key插入到"tree的右子树"的情况
	else if (key > Tree -> key){
		Tree -> right = Insert(Tree -> right, key);
		if(getHeight(Tree->right) - getHeight(Tree->left) == 2){
			if(key > Tree -> right ->key){
				Tree = RRRotation(Tree);
			}
			else{
				Tree = RLRotation(Tree);
			}
		}
	}

	else {printf("...\n");}

	Tree -> height = 
		MAX(getHeight(Tree -> left), getHeight(Tree -> right))+1;

	return Tree;
}

int main(int argc, char const *argv[])
{
	int i, NodeNums, key;
	AvlTree root = NULL;

	scanf("%d", &NodeNums);
	for(i=0; i<NodeNums; i++){
		scanf("%d", &key);
		root = Insert(root, key);
	}

	printf("%d\n", root -> key);
	
	return 0;
}

// 5
// 88 70 61 96 120
// 7
// 88 70 61 96 120 90 65
