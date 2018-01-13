// Complete Binary Search Tree
// 基本思路是用平衡二叉树的方法解决
#include <stdlib.h>
#include <stdio.h>

typedef struct CBTNode *CBTTree;
struct CBTNode
{
	int val;
	CBTTree left;
	CBTTree right;
	int height;
};
int MAX(int,int);
int getHeight(CBTTree T);
CBTTree LLRotation(CBTTree k2);
CBTTree RRRotation(CBTTree k1);
CBTTree RLRotation(CBTTree k1);
CBTTree LRRotation(CBTTree k2);
CBTTree CreateNode(int val, CBTTree left, CBTTree right);
CBTTree Insert(CBTTree T,int val);
void LevelTraversal(CBTTree T, int nums);

void FroneTravel(CBTTree T){
	if(T != NULL){
		printf("%d ", T -> val);
		FroneTravel(T -> left);
		FroneTravel(T -> right);
	}
}

void InorderTravel(CBTTree T){
	if(T != NULL){
		InorderTravel(T -> left);
		printf("%d ", T -> val);
		InorderTravel(T -> right);
	}
}

int main(int argc, char const *argv[])
{
	int i;
	int NodeNum, val;
	CBTTree Tree = NULL;

	scanf("%d",&NodeNum);
	for(i=0; i<NodeNum; i++){
		scanf("%d", &val);
		Tree = Insert(Tree, val);
	}
	FroneTravel(Tree); printf("\n");
	InorderTravel(Tree); printf("\n");
	// LevelTraversal(Tree,NodeNum);
	
	return 0;
}

int MAX(int a,int b){
	return a > b ? a : b;
}

int getHeight(CBTTree T){
	return T == NULL ? -1 : T -> height;
}

CBTTree LLRotation(CBTTree k2){
	CBTTree k1;

	k1 = k2 -> left;
	k2 -> left = k1 -> right;
	k1 -> right = k2;

	k2 -> height = 
		MAX(getHeight(k2 -> left), getHeight(k2 -> right)) + 1;
	k1 -> height = 
		MAX(getHeight(k1 -> left), k1 -> height) + 1;

	return k1;
}

CBTTree RRRotation(CBTTree k1){
	CBTTree k2;

	k2 = k1 -> right;
	k1 -> right = k2 -> left;
	k2 -> left = k1;

	k1 -> height = 
		MAX(getHeight(k1 -> left), getHeight(k1 -> right)) + 1;
	k2 -> height = 
		MAX(getHeight(k2 -> left), k2 -> height) + 1;

	return k1;
}

CBTTree RLRotation(CBTTree k1){
	k1 -> right = LLRotation(k1 -> right);
	return RRRotation(k1);
}

CBTTree LRRotation(CBTTree k2){
	k2 -> left = RRRotation(k2 -> left);
	return LLRotation(k2);
}

CBTTree CreateNode(int val, CBTTree left, CBTTree right){
	CBTTree T = (CBTTree) malloc (sizeof(struct CBTNode));
	T -> val = val;
	T -> left = left;
	T -> right = right;
	T -> height = 0;
	return T;
}

CBTTree Insert(CBTTree T,int val){
	if(T == NULL) T = CreateNode(val,NULL,NULL);

	else if(val < T -> val){
		T -> left = Insert(T -> left, val);
		if(getHeight(T -> left) - getHeight(T -> right) == 2){
			if(val < T -> left -> val){
				T = LLRotation(T);
			}
			else{
				T = LRRotation(T);
			}
		}
	}

	else if(val > T -> val){
		T -> right = Insert(T -> right, val);
		if(getHeight(T -> right) - getHeight(T -> left) == 2){
			if(val > T -> right -> val){
				T = RRRotation(T);
			}
			else{
				T = RLRotation(T);
			}
		}
	}
	else return NULL;

	T -> height = 
		MAX(getHeight(T -> left), getHeight(T -> right));
	return T;
}

void LevelTraversal(CBTTree T, int nums){// 层序遍历
	CBTTree queue[nums], temp;
	int i, head = 0, tail = 0; // 队列指针

	queue[tail++] = T;
	for(i=1; i<nums; i++){
		temp = queue[head++];
		printf("%d\n", temp -> val);
		queue[tail++] = temp -> left;
		queue[tail++] = temp -> right;
	}
}
