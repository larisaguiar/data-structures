#ifndef AVL_NODE_H
#define AVL_NODE_H

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k);
};


class AVLTree {
public:
    Node* root;

    AVLTree();

    int height(Node* node);
    int balanceFactor(Node* node);
    void updateHeight(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* root, int key);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);
    void printPreOrder(Node* node);
    void printInOrder(Node* node);
    void printPostOrder(Node* node);
};
#endif