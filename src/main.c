#include <stdio.h>
#include <stdlib.h>

struct Node {
  double value;
  struct Node *left;
  struct Node *right;
};

struct Node *CreateNewNode(double value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}
// INSERT
struct Node *InsertNewNode(struct Node *currentNode, double value) {
  if (currentNode == NULL) {
    return CreateNewNode(value);
  }
  if (currentNode->value == value) {
    return currentNode;
  }

  if (currentNode->value < value) {
    // Go right
    currentNode->right = InsertNewNode(currentNode->right, value);
  } else {
    // Go left
    currentNode->left = InsertNewNode(currentNode->left, value);
  }

  return currentNode;
}

struct Node *GetSuccessor(struct Node *currentNode) {
  currentNode = currentNode->right;
  while (currentNode != NULL && currentNode->left != NULL) {
    currentNode = currentNode->left;
  }
  return currentNode;
}

int RemoveNode(struct Node *currentNode, double value) {

  struct Node *nodeOfInterest = Search(currentNode, value);
  if (nodeOfInterest == NULL) {
    return -1;
  }
  struct Node *nodeSuccessor = GetSuccessor(nodeOfInterest);
  
  // TODO

}

struct Node *Search(struct Node *currentNode, double value) {

  if (currentNode == NULL) {
    return currentNode;
  }
  if (currentNode->value == value) {
    return currentNode;
  }

  if (currentNode->value > value) {
    return Search(currentNode->left, value);
  }

  return Search(currentNode->right, value);
}

void printTree(struct Node *node) {
  if (node->left != NULL) {
    printTree(node->left);
  }
  printf("%.2f ", node->value);
  if (node->right != NULL) {
    printTree(node->right);
  }
}

void printNode(struct Node *node) {
  if (node == NULL) {
    printf("Head: NULL\n");
  } else {
    printf("Head: %.2f\n", node->value);
  }

  if (node->left == NULL) {
    printf("Left: NULL\n");
  } else {
    printf("Left: %.2f\n", node->left->value);
  }

  if (node->right == NULL) {
    printf("Right: NULL\n");
  } else {
    printf("Right: %.2f\n", node->right->value);
  }
}

// Test
// TODO: Move later
int main() {
  struct Node *root = CreateNewNode(10.0);
  root = InsertNewNode(root, 15);
  root = InsertNewNode(root, 2);
  root = InsertNewNode(root, 25);
  root = InsertNewNode(root, 5);

  printTree(root);
  printf("\n");
}
