#pragma once


typedef struct stree_node *pstree_node;

struct stree_node
{
    pstree_node left;
    pstree_node right;
    pstree_node parent;

    int value;
};

pstree_node stree_new(void);

pstree_node add_node(pstree tree, int vaule);

void stree_delete(pstree tree);

//void stree_print(pslist list);
