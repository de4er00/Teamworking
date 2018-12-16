 #include <stdio.h>
 #include <stdlib.h>
 #include "header.h"

int main(void)
{
    pstree_node tree = stree_new(6); //указатель на корень

    add_node(tree, 5);
    add_node(tree, 3);
    add_node(tree, 2);
    add_node(tree, 9);
    add_node(tree, 10);
    add_node(tree, 8);

    print_tree(tree);
    printf("end\n");

    stree_delete(tree);


    return 0;
}

pstree_node stree_new(int value) //создание дерева
{
    pstree_node tree = malloc(sizeof(struct stree_node)); //используем указатель, т.к. переменная в функции локальная.

    tree->parent = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = value;

    return tree;
}

pstree_node add_node(pstree_node tree, int value) //вставка нового элемента
{
    pstree_node node = tree;
    pstree_node new_node = malloc(sizeof(struct stree_node)); //указатель на новый узел (лист)
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


    printf("add node> %d  parent %d\n", value, new_node->parent->value);

    return new_node;

}

int delete_node(pstree_node del, int value) //удаление узла
{
    if (del->value != value) return -1; //ошибка - неправильная пара(ключ - значение)

    pstree_node old = del;
    pstree_node node = malloc(sizeof(struct stree_node));

    if (del->parent->left == del) del->parent->left = NULL;
    else del->parent->right = NULL;

    while((node = dfs(old)) != del)
    {
        add_node(del->parent, node->value);
        free(old);
        old = node;
    }
    return 0;
}

int stree_delete(pstree_node tree)//удаление дерева
{
    pstree_node node = tree;

    while((NULL != node->parent)&&(NULL != node->left)&&(NULL != node->right)) //можно реализавать через обход в глубину
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
    return 0;

}

int wfs(pstree_node tree)//обход в ширину - аналогично обходу в глубину, только теперь нужно хранить long - расстояние до корня
{
    return 0;
}

pstree_node dfs(pstree_node old) //обход в глубину - принимает предыдущий элемент в обходе и возвращает следующий, если все элементы уже обошли, то выводитя корень.
{
    pstree_node node = old;

    if ((old != node->left)&&(NULL != node->left)&&(old != node->right)) return node->left;
    else if (((NULL == node->left)||(old == node->left))&&(NULL != node->right)&&(old == node->right)) return node->right;
    else
    {
        while ((((NULL == node->left)||(old == node->left))&&(NULL == node->right))||(old == node->right))
        {
            old = node;
            node = node->parent;

        }

        if ((NULL == node->parent)&&(((NULL == node->left)&&(NULL == node->right))||(old == node->right))) return old;// дерево закончилось

        else if (old == node->left) return node->right;
        else return node->left;
    }
    return 0;

}

int print_tree(pstree_node tree) //нужно реализовать в более понятном виде. через обход в ширину?
{
    pstree_node old = tree;
    pstree_node node = malloc(sizeof(struct stree_node));

    printf(" %d\n", old->value);

    while((node = dfs(old)) != tree)
    {
        old = node;
        printf(" %d\n", old->value);
    }
    return 0;
}
