// http://blog.csdn.net/qq_32400847/article/details/51474105
// 回溯算法的定义：回溯算法也叫试探法，
// 它是一种系统地搜索问题的解的方法。
// 回溯算法的基本思想是：从一条路往前走，能进则进，
// 不能进则退回来，换一条路再试。
// 解题的一般步骤是：
// 1.定义一个解空间，它包含问题的解；
// 2.利用适于搜索的方法组织解空间；
// 3.利用深度优先法搜索解空间；
// 4.利用限界函数避免移动到不可能产生解的子空间。
// 问题的解空间通常是在搜索问题的解的过程中动态产生的

// 根据上一节回溯算法的一个扩展
// 八皇后问题
#include <stdio.h>
#include <string.h>
// 如果我们逐行放置皇后则肯定没有任意两个皇后位于同一行，
// 只需要判断列和对角线即可
// vis[0][i]表示列，vis[1][i]和vis[2][i]表示对角线
// 因为(x,y)的y-x值标识了主对角线，x+y值标识了副对角线。
// 由于y-x可能为负，所以存取时要加上n。
int vis[3][15],tot=0;

void search(int cur)    
{    
    int i,j;    
    if(cur==8) tot++;  
    else    
    {    
        for(i=0;i<8;i++)    
        {    
            if(!vis[0][i]&&!vis[1][cur-i+8]&&!vis[2][cur+i])    
            {    
                vis[0][i]=1;    
                vis[1][cur-i+8]=1;    
                vis[2][cur+i]=1;      
                search(cur+1);    
                //改回辅助的全局变量   
                vis[0][i]=0;         
                vis[1][cur-i+8]=0;    
                vis[2][cur+i]=0;    
            }    
        }    
    }    
}  

int main(int argc, char const *argv[])
{
	search(0);
	printf("%d\n", tot);

	return 0;
}
