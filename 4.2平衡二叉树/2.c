// AVL树之 图文解析 和 C语言的实现
// https://www.cnblogs.com/skywang12345/p/3576969.html#a3
#include <stdio.h>
#include "avltree.h"
#include "avltree.c"

static int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen;
    AVLTree root=NULL;

    printf("== Height: %d\n", avltree_height(root));
    printf("== Add in turn: ");
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        printf("%d ", arr[i]);
        root = avltree_insert(root, arr[i]);
    }

    printf("\n== Preorder traversal: ");
    preorder_avltree(root);

    printf("\n== Middleorder traversal: ");
    inorder_avltree(root);

    printf("\n== Postorder traversal: ");
    postorder_avltree(root);
    printf("\n");

    printf("== Height: %d\n", avltree_height(root));
    printf("== Min: %d\n", avltree_minimum(root)->key);
    printf("== Max: %d\n", avltree_maximum(root)->key);
    printf("== The detailed information of the tree: \n");
    print_avltree(root, root->key, 0);


    i = 8;
    printf("\n== Delete the root: %d", i);
    root = avltree_delete(root, i);

    printf("\n== Height: %d", avltree_height(root));
    printf("\n== Middleorder traversal: ");
    inorder_avltree(root);
    printf("\n== The detailed information of the tree: \n");
    print_avltree(root, root->key, 0);

    // 销毁二叉树
    destroy_avltree(root);
}
