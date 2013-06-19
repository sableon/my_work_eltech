#include "Tree.h"

Tree::Tree(void)
{
	root = new Node(0);
}
Tree::Tree(Node *node)
{
	root = node;
}

Tree::~Tree(void)
{

}

void Tree::cut(Node *node)
{
	if(!node->hasChildren())
	{
		if(node->parent == 0)
		{
			delete node;
			return;
		}
		if(node->isLeftChild())
			node->parent->left = 0;
		if(node->isRightChild())
			node->parent->right = 0;
		delete node;
		return;
	}
	if(node->left)
	{
		node->left->parent = node->parent;
		if(node->isLeftChild())
			node->parent->left = node->left;
		if(node->isRightChild())
			node->parent->right = node->left;
	}
	if(node->right)
	{
		Tree subright(node->left);
		Node* new_place;
		new_place = subright.add(node->right->value);
		new_place->right = node->right->right;
		new_place->left = node->right->left;
	}
}
Node* Tree::add(int val)
{
	if(val <= root->value)
	{
		if(! root->left)
		{
			root->left = new Node(root,val);
			return root->left;
		}
		else
		{
			Tree sub(root->left);
			sub.add(val);
		}
	}
	else
	{
		if(! root->right)
		{
			root->right = new Node(root,val);
			return root->right;
		}
		else
		{
			Tree sub(root->right);
			sub.add(val);
		}
	}
}
ostream& operator<<(ostream& out, Tree * tree)
{
	if(!tree->root->hasChildren())
	{
		out<<tree->root;
		return out;
	}
	out<<tree->root;
	if(tree->root->left )
	{
		Tree leftsub(tree->root->left);
		out<<"["<<&leftsub<<"]";
	}
	if(tree->root->right )
	{
		Tree rightsub(tree->root->right);
		out<<"{"<<&rightsub<<"}";
	}
	return out;
}