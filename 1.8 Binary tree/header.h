#pragma once


typedef struct stree_node *pstree_node;

struct stree_node
{
    pstree_node left;
    pstree_node right;
    pstree_node parent;

    int value;
};

pstree_node stree_new(int value);

pstree_node add_node(pstree_node tree, int value);

int delete_node(pstree_node del, int value);

int stree_delete(pstree_node tree);

pstree_node dfs(pstree_node old );

int wfs(pstree_node tree);

int print_tree(pstree_node);
