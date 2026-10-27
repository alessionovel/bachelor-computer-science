#include <iostream>

using namespace std;

#include "tree-list.h"

void init(tree & t) {
  t=NULL;
}

void deinit(tree & t) {
  if (t!=NULL) {
    deinit(t->left);
    deinit(t->right);
    delete t;
  }
}

tree  insert(tree t, char v) {
  if (t==NULL) {
    t = new node; 
    t->item = v;
    t->left = NULL; 
    t->right = NULL; 
  }
  else if (v <= t->item) 
    t->left = insert(t->left, v);
  else if (v > t->item) 
    t->right = insert(t->right, v);
  return t;
}


tree  cerca (tree  t,char elem) { 
  tree res;
  if ((t==NULL) || (elem==t->item))
    res = t;
  else if (elem <= t->item) 
    res = cerca(t->left,elem);
  else if (elem > t->item)
    res = cerca(t->right,elem);
  return res;
}

void print_ordered(tree  t) {
  if (t!=NULL) {
    print_ordered(t->left);
    cout << t->item << endl;
    print_ordered(t->right);
  }
}

void print_indented(tree t,int depth) { 
  int i;
  if (t!=NULL) {
    print_indented(t->right,depth+1);
    for(i=0;i<depth;i++) 
      cout << "  ";
    cout << t->item << endl;
    print_indented(t->left,depth+1);
  }
}

void riempiBilanciato(tree& radice, int* valori, int inizio, int fine){
    if (inizio<=fine){
        int meta = (inizio+fine)/2;
        radice = insert(radice, valori[meta]);
        riempiBilanciato(radice, valori, inizio, meta-1);
        riempiBilanciato(radice, valori, meta+1, fine);
    }
}

node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

node* deleteNode(struct node* root, char key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->item)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->item)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->item = temp->item;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}

void printBT(const std::string& prefix, const node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->item << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, false);
    }
}

void printBT(const node* node)
{
    printBT("", node, false);    
}


