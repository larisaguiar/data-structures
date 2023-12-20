#include "../include/arv.hpp"
#include <iostream>

Node::Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}



AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

int AVLTree::balanceFactor(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

void AVLTree::updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* AVLTree::insert(Node* root, int key) {
    // Implementação da inserção...
    if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        } else if (key > root->key) {
            root->right = insert(root->right, key);
        } else {
            return root; // Duplicates are not allowed
        }

        updateHeight(root);

        int balance = balanceFactor(root);

        // Left Heavy
        if (balance > 1) {
            // Left-Right Case
            if (key > root->left->key) {
                root->left = leftRotate(root->left);
            }
            return rightRotate(root);
        }

        // Right Heavy
        if (balance < -1) {
            // Right-Left Case
            if (key < root->right->key) {
                root->right = rightRotate(root->right);
            }
            return leftRotate(root);
        }

        return root;
}

Node* AVLTree::minValueNode(Node* node) {
    // Implementação do minValueNode...
     Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
}

Node* AVLTree::deleteNode(Node* root, int key) {
    // Implementação da exclusão...
      if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = (root->left != nullptr) ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        updateHeight(root);

        int balance = balanceFactor(root);

        // Left Heavy
        if (balance > 1) {
            // Left-Right Case
            if (balanceFactor(root->left) >= 0) {
                root->left = leftRotate(root->left);
            }
            return rightRotate(root);
        }

        // Right Heavy
        if (balance < -1) {
            // Right-Left Case
            if (balanceFactor(root->right) <= 0) {
                root->right = rightRotate(root->right);
            }
            return leftRotate(root);
        }

        return root;
}

void AVLTree::printPreOrder(Node* node) {
    // Implementação do printPreOrder...
    if (node != nullptr) {
            std::cout << node->key << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
}

void AVLTree::printInOrder(Node* node) {
    // Implementação do printInOrder...
    if (node != nullptr) {
            printInOrder(node->left);
            std::cout << node->key << " ";
            printInOrder(node->right);
        }
}

void AVLTree::printPostOrder(Node* node) {
    // Implementação do printPostOrder...
    if (node != nullptr) {
            printPostOrder(node->left);
            printPostOrder(node->right);
            std::cout << node->key << " ";
    }
}       
