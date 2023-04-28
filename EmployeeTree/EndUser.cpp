//hello
#include <iostream>
#include "IntBinaryTree.h"
#include "EmpTree.h"
#include <vector>
using namespace std;


int main()
{
	IntBinaryTree<EmpTree> tree;
	vector<EmpTree> employees =
		{EmpTree(1021,"John Williams"), EmpTree(1057,"Bill Witherspoon"),
		EmpTree(2487,"Jennifer Twain"), EmpTree(3769,"Sophia Lancaster"),
		EmpTree(1017,"Debbie Reece"), EmpTree(1275,"George McMullen"),
		EmpTree(1899,"Ashley Smith"), EmpTree(4218,"Josh Plemmons")};
	
	for (int i = 0; i < employees.size(); i++)
		tree.insert(employees[i]);


	cout << "Inorder traversal:\n\t";
	tree.showInOrder();

	//tree.isBalanced();
	
	int searchID;
	cout<<"\nEnter an ID number to search for: ";
	cin>>searchID;
	
	cout << "\nSearching the tree for "<<searchID<<": ";
	tree.findItem(EmpTree(searchID,""));

	cout << endl;
	return 0;

}
