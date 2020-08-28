#include <iostream>
#include <string>
#include "Recursion.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"

int main() {
	BinarySearchTree bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(20);
	bst.insert(8);
	bst.insert(30);
	bst.inOrder(bst.root);
	std::cout << std::endl;
	std::cout << bst.search(20) << std::endl;
	std::cout << bst.deleteNode(bst.root,20) << std::endl;
	bst.inOrder(bst.root);
	return 0;
}