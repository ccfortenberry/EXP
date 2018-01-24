#ifndef FILE_REDBLACK_H_INCLUDED
#define FILE_REDBLACK_H_INCLUDED

#include <memory>
using std::shared_ptr;
using std::make_shared;

// The core tree node
enum Color {RED, BLACK};
template<typename ValueType>
struct RedBlackNode {
	ValueType _data;
	bool color; // true = red, false = black
	shared_ptr<RedBlackNode> _left, _right, _parent;
	
	// Ctor
	explicit RedBlackNode(ValueType data)
		:_data(data),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr)
	{}
	
	~RedBlackNode() noexcept = default;
};

// Recursive node insertion
template<typename FIt>
shared_ptr<RedBlackNode<FIt> > insert(shared_ptr<RedBlackNode<FIt> > root, const FIt & it) {
	// Base Case
	if (!root)
		root = make_shared<RedBlackNode>(*it);
	
	// Recursive Case(s)
	if (*it < root->_data) {
		root->_left = insert(root->_left, it);
		root->_left->_parent = root;
	}
	else {
		root->_right = insert(root->_right, it);
		root->_right->_parent = root;
	}
	
	return root;
}

// Container for nodes
template<typename ValueType>
class RedBlackTree {
	using TreeType = RedBlackNode<ValueType>;
	TreeType _root;
	
	void rebalance(TreeType & root, TreeType & node) {
		
	}
	
public:
	explicit RedBlackTree()
		:_root(nullptr)
	{}
	
	~RedBlackTree() noexcept = default;
	
	void insert(ValueType & data) {
		
	}
};

#endif // FILE_REDBLACK_H_INCLUDED