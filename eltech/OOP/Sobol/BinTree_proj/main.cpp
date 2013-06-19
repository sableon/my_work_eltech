
#include "Tree.h"

int main(int argc, char *argv[])
{
	Tree tree;
	Node * del;

	tree.add(15);
	del = tree.add(2);
	tree.add(12);
	tree.add(34);
	tree.add(11);
	tree.add(-2);
	tree.add(4);
	tree.add(8);
	tree.add(1);
	tree.add(9);
	tree.add(15);
	tree.add(8);

	cout << &tree << endl;

	tree.cut(del);
	cout << &tree << endl;
	
	system("pause");
	return 0;
}
