// 解题思路：
// 将初始序列建成搜索二叉树,其余不建
// 在比较时，每输入一个比较序列的数值就比较一次
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode
{
	int val;
	Tree Left,Right;
	int flag; // 标记结点是否被访问过
};
Tree MakeTree(int);
Tree NewNode(int);
Tree Insert(Tree,int);
void ResetT(Tree);
void FreeTree(Tree);
bool Judge(Tree,int);
bool check(Tree,int);

int main(int argc, char const *argv[])
{
	int N,L,i;
	Tree T;

	scanf("%d",&N);
	while(N){
		scanf("%d",&L);
		T = MakeTree(N);// 建立初始搜索树
		for(i=0;i<L;i++){// 比较L次
			if(Judge(T,N))// 每次单独输入一个序列进行比较
				printf("Yes\n");
			else 
				printf("No\n");
			ResetT(T); // 清空T中的标记flag
		}
		FreeTree(T);
		scanf("%d",&N);
	}

	return 0;
}

Tree MakeTree(int N){
	Tree T;
	int i,val;
	scanf("%d",&val);// 输入初始序列的根节点数值
	T = NewNode(val);// 创建根节点
	for(i=1;i<N;i++){
		scanf("%d",&val);// 输入其余节点
		// 每次从根节点开始,按照搜索二叉树的规则插入
		T = Insert(T,val);
	}
	return T;
}

Tree NewNode(int val){
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T -> val = val;
	T -> Left = T -> Right = NULL;
	T -> flag = 0;
	return T;
}

Tree Insert(Tree T,int val){
	if(!T) T = NewNode(val);// 若树为空则创建新的树节点
	// 若树不为空，根据大小插入，左小右大
	else{
		if(val > T->val) T->Right = Insert(T->Right,val);
		if(val <= T->val) T->Left = Insert(T->Left,val);
	}
	return T;
}

bool Judge(Tree T,int N){
	int i,val;
	int Flag=0;//此处0代表目前还一致,1代表以及不一致
	scanf("%d",&val);// 比较序列的根节点数值
	if(val != T->val) Flag = 1;// 根数值不同，则树不一致
	else T->flag = 1;// 标志根节点已被已访问过
	for(i=1;i<N;i++){
		scanf("%d",&val);
		// 若已知树不一致，仍继续进行输入，但不进行比较
		if(!Flag && !check(T,val)) Flag=1;
	}
	if(Flag) return false;
	else return true;
}

bool check(Tree T,int val){
	// 若某节点已被标记，则进行左或右分支比较
	// 若分支数值与比较数值不等，即可判断不为同一棵树
	if(T->flag){
		if(val < T->val) return check(T->Left,val);
		else if(val > T->val) return check(T->Right,val);
		else return false;
	}
	else{
		if(val == T->val){
			T->flag=1;
			return true;
		}
		else return false;
	}
}

void ResetT(Tree T){
	if(T->Left) ResetT(T->Left);
	if(T->Right) ResetT(T->Right);
	T -> flag = 0;
}

void FreeTree(Tree T){
	if(T->Left) FreeTree(T->Left);
	if(T->Right) FreeTree(T->Right);
	free(T);
}

// 4 2
// 3 1 4 2
// 3 4 1 2
// 3 2 4 1
// 2 1
// 2 1
// 1 2
// 0
