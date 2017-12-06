// 堆栈使用，表达式求值
// 例：回溯算法，老鼠走迷宫
#include <stdio.h>
#include <stdlib.h>
 
void visit(int,int);
 
int maze1[7][7] = {
	{2, 2, 2, 2, 2, 2, 2},
    {2, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 0, 0, 2},
    {2, 0, 0, 0, 0, 2, 2},
    {2, 2, 0, 2, 2, 2, 2},
    {2, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 2, 2, 2}
};
int maze[7][7] = {
	{2, 2, 2, 2, 2, 2, 2},
    {2, 0, 0, 0, 0, 0, 2},
    {2, 0, 2, 0, 2, 0, 2},
    {2, 0, 0, 2, 0, 2, 2},
    {2, 2, 0, 2, 0, 2, 2},
    {2, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 2, 2, 2}
};

 
int startI=1,startJ=1;  // 入口
int endI=5,endJ=5;  // 出口
int success=0;
 
int main(void){
    int i, j;
 	
 	// 26~36 显示迷宫
    printf ( "show the maze:\n" );
    for ( i = 0; i < 7; i++ ){
        for ( j = 0; j < 7; j++ ){
        	if ( maze[i][j] == 2 ){
        		printf ( "Aa" );
        	}else{
                printf ( "  " );
            }
        }
        printf ( "\n" );
    }

 	visit(startI,startJ);
    if (success  == 0 ){// 起点为(1,1)，终点为(5,5)
        printf ( "\nno exit！\n" );
	}else{
        printf ( "\nshow the path:\n" );
        for (i=0;i<7;i++){
            for (j=0;j<7;j++){
                if ( maze[i][j] == 2 )
                    printf ( "Aa" );// 围墙
                else if ( maze[i][j] == 1 )
                    printf ( ".." );// 走过的路径
                else
                    printf ( "  " );
            }
            printf ( "\n" );
        }
    }
 
    return 0;
}
 
void visit ( int i, int j ){
    maze[i][j] = 1;// 走过的路径置1
 
    if ( i == endI && j == endJ ) success=1;
 	
 	// 使用递归的好处是可以保存初始状态
    if ( success != 1 && maze[i][j+1] == 0 ) visit ( i, j+1 );
    if ( success != 1 && maze[i+1][j] == 0 ) visit ( i+1, j );
    if ( success != 1 && maze[i][j-1] == 0 ) visit ( i, j-1 );
    if ( success != 1 && maze[i-1][j] == 0 ) visit ( i-1, j );
 
 	// 若未成功且无路可走，则清除本次足迹
    if ( success != 1 ){
    	printf("%d,%d,%d\n",i,j,maze[i][j]);
    	maze[i][j] = 0;
    }

    return;
}

