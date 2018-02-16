// File Transfer
// 用集合解决
// TSSN To Simple Sometimes naive
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10000

typedef int ElementType; // 默认元素可以用非负整数表示
typedef int Setname; // 默认用根节点的下表作为集合名称
typedef ElementType SetType[MaxSize];

Setname Find(SetType S, ElementType X){
	// 默认集合元素全部初始化为-1
	
	// TSSN
	// for(; S[X] >= 0; X = S[X])
	// 	return X;

	// 路径压缩
	// 直接把根节点压缩成下面所有节点的父节点,使此路径所有高度为1
	if(S[X] < 0) // 找到集合的根
		return X;
	else
		return S[X] = Find(S, S[X]);
}

void Union(SetType S, Setname Root1, Setname Root2){
	// 默认R1和R2是不同集合的根节点
	
	// TSSN
	// S[Root2] = Root1;
	
	// 按秩归并
	// 按两树的规模进行归并，把节点少的归并到多的树上
	if(S[Root2] < S[Root1]){
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

void Init(SetType S, int n){
	int i=0;
	for(i; i<n; i++) 
		S[i] = -1;
}

void Input_Connection(SetType S);
void Check_Connection(SetType S);
void Check_NetWork(SetType S, int n);
int main(int argc, char const *argv[])
{
	SetType S;
	int n;
	char in;
	scanf("%d\n", &n);
	Init(S, n);

	do{
		scanf("%c", &in);
		switch(in){
			case 'I': Input_Connection(S); break; // Union(Find)
			case 'C': Check_Connection(S); break; // Find
			case 'S': Check_NetWork(S, n); break;
		}
	}
	while(in != 'S');
	
	return 0;
}

void Input_Connection(SetType S){
	ElementType u, v;
	Setname Root1, Root2;
	scanf("%d %d", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 != Root2){
		Union(S, Root1, Root2);
	}
}

void Check_Connection(SetType S){
	ElementType u, v;
	Setname Root1, Root2;
	scanf("%d %d", &u, &v);
	Root1 = Find(S, u-1);
	Root2 = Find(S, v-1);
	if(Root1 == Root2) printf("yes\n");
	else printf("no\n");
}

void Check_NetWork(SetType S, int n){
	int i, counter = 0;
	for(i=0; i<n; i++)
		if(S[i] < 0) counter++;
	if(counter == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", counter);
}
