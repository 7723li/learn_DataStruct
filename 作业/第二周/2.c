// 一元多项式的乘法与加法运算
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* List;
struct Node
{
	int coef;// 系数
	int expon;// 指数
	List Next;
};
List Read();// 新建一个链表
List Add(List,List);// 加法
int* Muti(List,List,int*);// 乘法
void Connect(int coef,int expon,List* tail);

int main(int argc, char const *argv[])
{
	int length1=0,length2=0,length;
	List p,p1,p2,p3;
	int* p4;

	p1 = Read();p2 = Read(); 

	p = p1;while(p){length1++;p = p->Next;}// 统计长度
	p = p2;while(p){length2++;p = p->Next;}
	length = length1*length2*2;// 用于乘法中创建最大数组

	p3=Add(p1,p2);
	p4 = Muti(p1,p2,&length);

	for(int i=0;i<length-1;i++){
		printf("%d ",p4[i]);
	}
	printf("%d\n", p4[length-1]);

	while(p3 != NULL){
		if(p3 -> Next == NULL){
			printf("%d %d", p3->coef,p3->expon);
		}else{
			printf("%d %d ", p3->coef,p3->expon);
		}
		p3 = p3->Next;
	}printf("\n");

	return 0;
}

List Read(){
	int coef,expon;
	int length;
	List head,mid,tail;
	head = (List)malloc(sizeof(struct Node));// 头结点不存放数据
	tail = head;
	scanf("%d",&length);
	for(int i=0;i<length;i++){
		scanf("%d %d",&coef,&expon);
		mid = (List)malloc(sizeof(struct Node));
		mid -> coef = coef; mid -> expon = expon;
		tail -> Next = mid;// (*tail).Next = mid,即head.Next=mid
		tail = mid;
	}
	tail -> Next =NULL;
	head = head -> Next;// 移动到存放数据的第一个结点
	return head;
}

void Connect(int coef,int expon,List* Tail){
	List mid;
	mid = (List)malloc(sizeof(struct Node));
	mid -> coef = coef;
	mid -> expon = expon;
	// Tail即原函数中tail指针的指针，因此需先取值(tail指针)再附地址值
	(*Tail) -> Next = mid;// *(*Tail).Next = mid
	(*Tail) = mid;
	return;
}

List Add(List p1,List p2){
	List head,tail;
	head = (List)malloc(sizeof(struct Node));
	tail = head;
	while(p1 && p2){
		if(p1 -> expon > p2 -> expon){
			Connect(p1->coef,p1->expon,&tail);
			p1 = p1 -> Next;// 向后移一位
		}
		else if(p2 -> expon > p1 -> expon){
			Connect(p2->coef,p2->expon,&tail);
			p2 = p2 -> Next;
		}
		else{
			if((p1 -> coef) + (p2 -> coef)){// 系数相加不为0
				Connect((p1 -> coef) + (p2 -> coef),p1 -> expon,&tail);
				p1 = p1 -> Next;
				p2 = p2 -> Next;
			}
		}
	}
	// 判断p1或p2是否还存在剩余数据，存在则连接到链表上
	while(p1 != NULL){
		Connect(p1->coef,p1->expon,&tail);
		p1 = p1->Next;
	}
	while(p2 != NULL){
		Connect(p2->coef,p2->expon,&tail);
		p2 = p2 -> Next;
	}
	tail -> Next = NULL;
	head = head -> Next;
	return head;
}

int* Muti(List p1,List p2,int* l){
	int returnL=0;// 计算后实际需打印长度
	int coef,expon;
	int length = *l;// 最大数组长度
	int* num_list;// 数组结构[系数,指数,系,指...]
	int i,j;
	int flag = 1;// 用于检测数组是否为空
	num_list = (int*)malloc(length*sizeof(int));
	for(i=0;i<=length;i++){num_list[i]=0;}//将新建数组全部清零
	while(p1){
		List p = p2;// 创建p2的克隆体
		while(p){
			coef = (p1->coef) * (p->coef);// 系数相乘
			expon = (p1->expon) + (p->expon);// 指数相加
			// 因为第一个指数都为最大,因此和也必然最大,必然放在首位
			if(flag){
				num_list[0]=coef; num_list[1]=expon;
				flag = 0;// 数组不为空
				p = p -> Next;
				returnL++;
				continue;
			}
			for(i=length-1;i>0;i-=2){
				if(expon < num_list[i]){// 小于数组中的某指数i
					returnL++;
					for(j=length-1-2;j>i;j-=2){// 将i后的元素全部向后移
						num_list[j+2] = num_list[j];
						num_list[j+2-1] = num_list[j-1];
					}	
					num_list[i+2] = expon;
					num_list[i+2-1] = coef;
					break;
				}
				else if(expon == num_list[i]){
					num_list[i-1] +=  coef;
					break;
				}
			}
			p = p -> Next;
		}
		p1 = p1 -> Next;
	}
	*l = returnL*2;
	return num_list;
}
