// 两个有序链表序列的合并 
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}


List Read(){
    int n,i;
    scanf("%d",&n);
    // 申请一个头结点 (头结点不储存数据) 
    List L = (List)malloc(sizeof(PtrToNode));
    L->Next=NULL;// 头指针为空  
    if(n){
        List r = L;// r是一个中间变量的节点  
        for(i=0;i<n;i++){
            List p =(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));// 尾插法  
            r -> Next =p;
            r = p;
        }
        r ->Next =NULL;
    }
    return L;
}

List Merge( List L1, List L2 ){
    List pa,pb,pc,L;
    L=(List)malloc(sizeof(struct Node));
    pa=L1->Next;// read处表示链表头结点为空
    pb=L2->Next;
    pc=L;
    while(pa && pb){
        if(pa->Data <= pb->Data){
            pc->Next=pa;
            pc=pa;
            pa=pa->Next;
        }else{
            pc->Next=pb;
            pc=pb;
            pb=pb->Next;
        }
    }
    pc->Next=pa?pa:pb;
    L1->Next=NULL;
    L2->Next=NULL;
    return L;
}

void Print(List L){
    List p =L->Next;
    if(p){
        List r;
        r = L;
        while(r->Next){
            r=r->Next;
            printf("%d ", r->Data);
        }
    }else{
        printf("NULL");
    }
    printf("\n");
}
