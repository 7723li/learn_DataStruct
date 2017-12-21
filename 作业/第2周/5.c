//  Pop Sequence
// 题目的意思：   
// 栈的大小M，输入序列的长度N
// 默认序列即为1,2,3…,N,入栈也是这个顺序
// 出栈的顺序不定。有K个测试序列，
// 判断每一个测试序列是否是可能的出栈顺序  
// 此题考查堆栈的用法，一堆数按照1，2，3，4....N的顺序入栈
// 如果第M个数要出栈，则前面一定有M-1个数入栈。  
#include <stdio.h>  
#include <stdlib.h>  
  
int main()  
{  
    int stack[1005];  
    int top; // 栈顶
    int m,n,k; 
    scanf("%d%d%d",&m,&n,&k);  
    for(int i=1;i<=k;i++){  
        top=0;  
        int flag=1; // 结果判断标记
        int now=1;
        int number;  
        for(int j=1;j<=n;j++){  
            scanf("%d",&number);
            while(flag && (top==0||stack[top]!=number)){
                top++;
                stack[top]=now;
                if(top>m){  
                    flag=0;  
                    break;  
                }  
                now++;  
            }
            if(flag&&top>=1&&stack[top]==number)  
                top--;  // 弹出顶端数据
        }  
        if(flag)  
            printf("YES\n");  
        else  
            printf("NO\n");  
  
    }  
    return 0;  
}
