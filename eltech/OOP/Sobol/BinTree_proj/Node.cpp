#include "Node.h"

Node::Node(Node * _parent, int Value)
{
	left = 0;
	right = 0;
	value = Value;
	parent = _parent;
}
Node::~Node(void)
{
}

ostream& operator<<(ostream& out, Node* node)
{
	out<<""<<node->value<<"";
	return out;
}
