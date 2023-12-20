#include "../include/arv.hpp"
#include <iostream>

int main() {
    AVLTree avlTree;

    int n;
    std::cin >> n;

    char operation;
    int key;

    for (int i = 0; i < n; ++i) {
        std::cin >> operation >> key;

        if (operation == 'i') {
            avlTree.root = avlTree.insert(avlTree.root, key);
        } else if (operation == 'r') {
            avlTree.root = avlTree.deleteNode(avlTree.root, key);
        }
    }

    avlTree.printPreOrder(avlTree.root);
    std::cout << std::endl;

    avlTree.printInOrder(avlTree.root);
    std::cout << std::endl;

    avlTree.printPostOrder(avlTree.root);
    std::cout << std::endl;

    return 0;
}
