#pragma once

#include "Node.h"

class Tree
{
public:
	Tree(void);
	Tree(Node *node);
	~Tree(void);

	Node* root;

	Node* add(int val);

	void cut(Node *node); //собственно фукнция удаления узла.

	/*
	дерево считается отсортированным по правилу меньше - слева, больше - справа
	заполняется путем поштучного добавления узлов функцией add (для отладки)
	выводится в консоль в виде [левая часть] {правая часть}
	функция удаления работает так, чтобы сортировка сохранялась
	*/
};

ostream& operator<<(ostream& out, Tree * tree);
