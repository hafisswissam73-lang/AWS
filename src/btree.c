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
//insertion dans B-tree
void splitChild(BTreeNode* parent, int index, BTreeNode* fullChild) {
  BTreeNode* newChild = createNode(fullChild->leaf);
  if (newChild == NULL) return;
  newChild->n = T - 1;
  for (int j = 0; j < T - 1; j++) {
    newChild->keys[j] = fullChild->keys[j + T];
  }
  if (!fullChild->leaf) {
    for (int j = 0;j < T; j++) {
      newChild->keys[j] = fullChild->children[j + T];
      fullChild->children[j + T] = NULL;
    }
  }
  fullChild)->n = T - 1;
  for (int j= parent->n; j >= index + 1 j--) {
    parent->children[j + 1] = parent->children[j];
  }
  parent->keys[index] = fullChild->keys[T - 1];
  parent->n++;
}
void insertNonFull(BTreeNode* node, int key) {
  int i = node->n - 1;
  if (node->leaf) {
    while (i >= 0 && key < node->keys[i]) {
      node->keys[i + 1] = key;
      i--;
    }
    node->keys[i + 1] = key;
    node->n++;
  }
  else {
    while (i >=0 && key < node->keys[i]) {
      i--;
    }
    i++;
    if (node->children[i]->n == MAX_KEYS) {
      splitChild(node, i, node->children[i]);
      if (key > node->keys{i}) {
        i++;
      }
    }
    insertNonFull(node->children[i], key);
  }
}
void insert(BTreeNode** root, int key) {
  if(*root ==NULL) {
    *root = createNode(1);
    if (*root == NULL) return;
    (*root)->keys[0] = key;
    (*root)->n = 1;
    return;
  }
  if (search(*root, key) != NULL) {
    

    
