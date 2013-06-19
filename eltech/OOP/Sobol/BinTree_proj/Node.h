#pragma once

#include <iostream>
using namespace std;

class Node
{
public:
	Node(Node* _parent = 0, int Value = 0);
	~Node(void);

	Node *left;
	Node *right;

	Node *parent;

	int value;

	bool hasChildren()
	{
		return (left || right );
	}

	bool hasFreeSlot()
	{
		return !(left && right);
	}
	bool isRightChild()
	{
		return (this->parent->right == this);
	}
	bool isLeftChild()
	{
		return (this->parent->left == this);
	}
};

ostream& operator<<(ostream& out, Node* node);