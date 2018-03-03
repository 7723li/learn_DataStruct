// Huffman Codes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MaxSize;

typedef struct TNode Node;
struct TNode // 输入节点
{
	int f;
	char c;
};

typedef struct HCode Code;
struct HCode
{
	char c;
	char* code;
};

typedef struct heap Heap;
struct heap
{
	Node* p;
	int size;
};
void Insert(Heap* h, Node record);
int cnt_wpl(Heap *heap);
Node del_heap(Heap *heap);
int find(Node *record, char c);
int check(char* a, char* b);

int main(int argc, char const *argv[])
{
	scanf("%d", &MaxSize);

	// 创建新的最小堆
	Heap *heap = (Heap*) malloc (sizeof(Heap));
	heap -> size = 0;
	heap -> p = (Node*) malloc (sizeof(Node) * (MaxSize + 1));
	heap -> p[0].f = -1000;

	// 储存字符及权重
	Node* record = (Node*) malloc (sizeof(Node) * MaxSize);
	int i, j, k;
	for(i=0; i < MaxSize ;i++){
		getchar();
		scanf("%c %d", &record[i].c, &record[i].f);
		Insert(heap, record[i]);
	}

	int wpl = cnt_wpl(heap);
	printf("wpl = %d\n", wpl); //计算哈夫曼编码的最优WPL

	Code stcode[MaxSize]; // 记录输入字符及对应编码
	int flu = 0, flag = 0, stwpl = 0, num = 0;
	scanf("%d", &num);

	for(k=0; k<num; k++){
		stwpl = 0;
		for(i=0; i<MaxSize; i++){
			getchar();
			stcode[i].code = (char*) malloc (sizeof(char) * MaxSize);
			scanf("%c %s", &stcode[i].c, stcode[i].code);
			flu = find(record, stcode[i].c); // 找对应字符权重
			if(flu == -1)
				flag = -1;
			else
				stwpl += flu * strlen(stcode[i].code); // 计算输入的wpl
		}

		int res = 0;
		for(i=0; i<MaxSize; i++){
			for(j=i+1; j<MaxSize; j++){
				res = check(stcode[i].code, stcode[j].code);
				if(res)
					break;
			}
			if(res)
				break;
		}

		if(flag == -1)
			printf("Not exists\n");
		else{
			if(res)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	
	return 0;
}

int check(char* a, char* b){ // 测试b 是否 a的前缀
	char *big, *small;
	if(strlen(a) >= strlen(b)){
		big = a;
		small = b;
	}
	else{
		big = b;
		small = a;
	}
	return(strstr(big, small)) == big; // 检测子串
}

void Insert(Heap* heap, Node record){
	if(heap -> size == 0){
		heap -> p[1] = record;
		heap -> size++;
	}
	else{
		int i = heap -> size + 1;
		for(; heap -> p[i / 2].f > record.f; i = i / 2)
			heap -> p[i] = heap -> p[i / 2];
		heap -> p[i] = record;
		heap -> size++;
	}
}

int cnt_wpl(Heap *heap){
	int i, record = 0, size = heap -> size;
	Node a1, a2, b1;
	for(i=0; i<size-1; i++){
		a1 = del_heap(heap);
		a2 = del_heap(heap);
		b1.f = a1.f + a2.f;
		b1.c = '*';
		record += b1.f;
		Insert(heap, b1);
	}
	return record;
}

Node del_heap(Heap *heap){
	if(heap -> size == 0)
		printf("Empty\n");
	else{
		Node record = heap -> p[1];
		Node temp = heap -> p[heap -> size];
		int pa = 1, ch = 0;
		heap -> size -= 1;

		 // 从顶向下过滤，注意终止条件  
		for(pa = 1;2 * pa <= heap -> size; pa = ch){
			ch = 2* pa;
			if(ch != heap -> size && (heap -> p[ch].f > heap -> p[ch + 1].f))
				ch++;
			if(temp.f < heap -> p[ch].f)
				break;
			else
				heap -> p[pa] = heap -> p[ch];
		}
		heap -> p[pa] = temp;
		return record;
	}
}

int find(Node *record, char c){
	Node *p = record;
	int i = 0;
	for(i=0; i<MaxSize; i++){
		if(p[i].c == c)
			return p[i].f;
	}
	return -1;
}
