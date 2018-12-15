 #include <stdio.h>
 #include <stdlib.h>
 #include "header.h"

int main(void)
{
    pstree_node tree = stree_new(); //указатель на корень


    return 0;
}

pstree_node stree_new(void)
{
    pstree_node tree = malloc(sizeof(struct stree)); //используем указатель, т.к. переменная в функции локальная.

    tree->root = NULL;
    tree->list_size = 0;

    return tree;
}

pstree_node add_node(pstree_node tree, int vaule)
{
    pstree_node node = tree;
    pstree_node new_node = malloc(sizeof(stree_node)); //указатель на новый узел (лист)
    int flag = 1;

    while (flag)
    {
        if ((value < node->value)&&(NULL != node->left)) node = node->left;
        else if((value > node->value)&&(NULL != node->right)) node = node->right;
        else flag = 0;
    }

    if (value < node->value) node->left = new_node;
    else node->right = new_node;

    new_node->parent = node;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = value;

    return new_node;

}

void stree_delete(pstree tree)
{
    while((NULL != node->parent)&&(NULL != node->left)&&(NULL != node->right))
    {
        while ((NULL != node->left)&&(NULL != node->right))
        {
            while (node->left != NULL) node = node->left;
            if (NULL != node->right) node = node->right;
        }

        node = node->parent;
        if (NULL != node->left) free(node->left);
        else free(node->right);
    }
    return 1;

}

void wfs(tree)//обход в ширину
{

}

void dfs(tree) //обход в глубину
{

}
