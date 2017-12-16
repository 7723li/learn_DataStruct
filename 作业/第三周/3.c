//  Tree Traversals Again
//  根据前序和中序，获得后序遍历的结果
//  Push是前序，Pop是中序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 5
#define MAX_SIZE 30

typedef struct Node* Tree;
struct Node
{
    int data;
    struct Node *left, *right;
};
bool isEmpty();
void Push(Tree tn);
Tree Pop();
Tree Top();

Tree Stack[MAX_SIZE];
int values[MAX_SIZE];
int num = 0;
int top = -1;

void PostOrderTraversal(Tree root);

int main()
{
    int n;// 结点数量
    char operation[STR_LEN];
    Tree father, root;
    bool findRoot = 0, Poped = 0;

    scanf("%d", &n);
    for (int i=0;i<2*n;i++)
    {
        scanf("%s", operation);
        if (strcmp(operation, "Push") == 0)
        {
            int value;
            scanf("%d", &value);
            Tree newNode;// 创建一个新的树节点
           	newNode=(Tree)malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            if (!findRoot)
            {
                root = newNode;     //根节点
                Push(newNode);
                findRoot = 1;
            }
            else
            {
            	//若前一个操作不是pop,则父节点为栈顶元素
                if (!Poped)
                    father = Top();
                if (father->left == NULL)
                    father->left = newNode;
                else
                    father->right = newNode;
                //printf("%d\n", newNode->data);
                Push(newNode);
            }
            Poped = 0;
        }
        else
        {
            father = Pop();
            Poped = 1;
        }
    }
    PostOrderTraversal(root);

    for (int i = 0; i < num-1; i++)
        printf("%d ", values[i]);
    printf("%d\n", values[num-1]);

    return 0;
}

void PostOrderTraversal(Tree root)
{
    Tree tn = root;
    if(tn)
    {
        PostOrderTraversal(tn->left);
        PostOrderTraversal(tn->right);
        //将后序遍历出的节点值存入数组便于格式化打印
        values[num++] = tn->data;
    }
}

void Push(Tree tn)
{
    Stack[++top] = tn;
}

Tree Pop()
{
    return Stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

Tree Top()
{
    return Stack[top];
}

// 6
// Push 1
// Push 2
// Push 3
// Pop
// Pop
// Push 4
// Pop
// Pop
// Push 5
// Push 6
// Pop
// Pop
