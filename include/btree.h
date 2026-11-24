#ifndef BTREE_H
#define BTREE_H

#define T 3 
#define MAX_KEYS (2 * t - 1 )
#define MAX_CHILDREN (2 * T )

typedef struct BTreeNode {
  int keys[MAX_KEYS];
  struct BTreeNode *children[MAX_CHILDREN];
  int n;
  int leaf;
} BTreeNode;

BTreeNode* createNode(int leaf);
void insert(BTreeNode** root, int key);
BTreeNode* search(BTreeNode* root, int key);
void display(BTreeNode* root);
void freeBtree(BTreeNode* root);

#endif
