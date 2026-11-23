#ifndef BTREE_H
#define BTREE_H
#define T 2 
#define MAX_KEYS(2 * T - 1)
#define MAX_CHILDREN(2*T)

typedef struct BTreeNode{
    int keys[MAX_KEYS];
    struct BTreeNode * children[MAX_CHILDREN];
    int n;
    int leaf;
} BTreeNode;
typedef struct {
    BTreeNode *root;
} BTree
BTreeNode *createNode(int leaf);
BTree *createBTree(void);
BTreeNode *search(BTreeNode *root, int key);
void insert(BTree *tree,int key);
void display(BTreeNode *root);
void freeTree(BTreeNode *root);

#endif
