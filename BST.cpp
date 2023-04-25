#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int data) {
   node *Node = new node;
   Node->key = data;
   Node->right = NULL;
   Node->left = NULL;
   return Node;
}
struct node* minValueNode(struct node* node)
{
    if (node->left == NULL){
      return node;
    }
    return minValueNode(node->left);
}

struct node *search(struct node *node,int key){
  if(node == NULL){
    return NULL;
  }
  if(node->key == key ){
    return node;
  }
  if(node->key>key){
    return search(node->left,key);
  }
  return search(node->right,key);
};



// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root->left!= NULL){
    traverseInOrder(root->left);
  }
  cout << root->key;
  if(root->right != NULL){
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL){
    
   return newNode(key);
  }else if(node->key > key){
    // cout << node->key;
    node->left = insertNode(node->left,key);
  }else{
    node->right = insertNode(node->right,key);
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 if(root == NULL){
  return root;
 }else if(root->key > key){
  root->left = deleteNode(root->left,key);
  
 }else if(root->key < key){
  root->right = deleteNode(root->right,key);
 }else{
  if (root->left == NULL && root->right == NULL){
    return NULL;
  }else if(root->left == NULL){
    return root->right;
  }else if(root->right == NULL){
    return root->left;
  }
  struct node *temp = minValueNode(root->right);
  root->key = temp->key;
  root->right = deleteNode(root->right, temp->key);
 }

 
 return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
 }
  
  traverseInOrder(root);
}