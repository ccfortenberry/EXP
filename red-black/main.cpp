#include <type_traits>
using std::remove_reference;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include "header/redblack.h"

template<typename FIt>
void treesort(FIt first, FIt last) {
	using ValueType = typename remove_reference<decltype(*first)>::type;
	using RBTree = RedBlackTree<RedBlackNode<ValueType> >;
	
	cout << "Making a tree to put it into" << endl;
	// The BETTER way would just be use a node and go from there
	// but here I'll use a wrapper
	RBTree tree();
	// Insert the vector into the tree
}

int main() {
	using ValueType = int;
	
	vector<ValueType> stuff{6, 4, 10, 8, 15, 2, 5, 1, 200};
	
	cout << "Making a vector of ints: " << endl;
	for (auto i : stuff)
		cout << i << " ";
	cout << endl << endl;
	
	treesort(stuff.begin(), stuff.end());
	
	system("pause");
	return 0;
}