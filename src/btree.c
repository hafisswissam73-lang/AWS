#include <stdio.h>
#include <stdlib.h>
#include "../include/btree.h"

//create a new B-TREE node
BTreeNode* createNode(int leaf) {
  BtreeNode* node= malloc(sizeof(BTreeNode));
  if (node == NULL) {
    return NULL;
  }
  node->n = 0;
  node->leaf = leaf;
  for (int i = 0; i < MAX_CHIDREN; i++) {
    node->children[i] = NULL;
  }
  return node;
}
//Search for a key
BTreeNode* search(BTreeNode* root, int key) {
  if (root == NULL) {
    return NULL;
  }
  int i = 0;
  while (i < root->n && key ==root->keys[i]) {
    i++;
  }
  if (i< root->n && key == root->keys[i]) {
    return root;
  }
  return search(root->children[i], key);
}

//display the B-TREE
void display(BTreeNode* root) {
  if(root == NULL) {
    return;
  }
  int i;
  for (i=0; i<root->n; i++) {
    if(!root->leaf) {
      display(root->children[i]);
    }
    printf("%d ", root->keys[i]);
  }
  if (!root->leaf) {
    display(root->children[i]);
  }
}
