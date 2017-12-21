//  List Leaves
#include <stdio.h>
#include <ctype.h>

struct Node
{
    int root;    //记录节点是否为根节点
    int left;    //左子树
    int right;   //右子树
};

int main(){
    int n;     //存储节点个数 N <= 10
    struct Node nodes[10];
    scanf("%d",&n);
    //printf("%d",n);
    for(int i = 0; i < n; i++){//初始化树节点
        nodes[i].root = 1;     //没有连接的节点都是根节点
        nodes[i].left = -1;    //没有左子树
        nodes[i].right = -1;   //没有右子树
    }
    for(int i = 0; i < n; i++){//构造树
        char ch1,ch2;
        scanf("\n%c %c",&ch1,&ch2);
        if(isdigit(ch1)){               //左子树存在，将左子树连接至该点
            nodes[i].left = ch1 - '0';  //指针指向左子树
            nodes[ch1 - '0'].root = 0;  //左子树取消根节点标记
        }
        if(isdigit(ch2)){
            nodes[i].right = ch2 - '0';
            nodes[ch2 - '0'].root = 0;
        }
    }

    int root;   //根节点序号
    for(int i = 0; i < n; i++)
        if(nodes[i].root == 1){
            root = i;
            break;
        }

    //构造完树后，层序遍历树，依次输出叶子节点；层序遍历：从根节点开始依次将左右儿子入队，直至队列为空
    int leaves = 0;   //记录输出叶节点的个数
    int queue[10];    //节点队列，只保存节点下标
    int head = 0, rear = 0;
    queue[rear++] = root;  //根节点入队
    while(rear - head){
        int node = queue[head++];  //队首节点出队

        if(nodes[node].left == -1 && nodes[node].right == -1){
            if(leaves)   //输出第一个时，不输出空格
                printf(" ");
            printf("%d",node);
            ++leaves;
        }
        if(nodes[node].left != -1)  //如果存在，左子树入队
            queue[rear++] = nodes[node].left;
        if(nodes[node].right != -1) //如果存在，右子树入队
            queue[rear++] = nodes[node].right;
    }
    return 0;
}
