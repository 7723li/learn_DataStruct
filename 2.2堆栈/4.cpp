#include <cstring>   
#include <iostream>  
using namespace std;    
int vis[3][15],tot;    
  
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
  
int main()    
{    
    search(0);     
    cout<<tot<<endl;  
}  
