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

	void cut(Node *node); //���������� ������� �������� ����.

	/*
	������ ��������� ��������������� �� ������� ������ - �����, ������ - ������
	����������� ����� ���������� ���������� ����� �������� add (��� �������)
	��������� � ������� � ���� [����� �����] {������ �����}
	������� �������� �������� ���, ����� ���������� �����������
	*/
};

ostream& operator<<(ostream& out, Tree * tree);
