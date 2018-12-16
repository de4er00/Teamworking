#include <stdio.h>
#include <stdlib.h>
#include "AVL-tree.c"

//AVL-tree.c - файл, содержащий реализацию дерева.
//pstruct_node - указатель на структуру node, которая задает узел.
//root - указатель на корень дерева.

int long_branch(pstruct_node node);//Функция, возвращающая глубину подграфа вершины node.
int chek_tree(pstruct_node root);

int main()
{
    if (chek_tree(root)) printf("Дерево является АВЛ-деревом");
    else printf("Дерево не является АВЛ-деревом");

    return 0;
}

int chek_tree(pstruct_node root)
{
    if ((NULL != (root->left))&&(NULL != (root->right))) return chek_tree(root->left)*chek_tree(root->right);
    else if (((long_branch(root->left)- long_branch(root->right))<2)&&((long_branch(root->left)- long_branch(root->right))>-2)) return 1;
    else return 0;
}

int long_branch(pstruct_node node)
{
    if (NULL != node)return 0;
    else if (long_branch(node->left) > long_branch(node->right)) return (long_branch(node->left) + 1;
    else return long_branch(node->right) + 1;
}
