#include <iostream>
using namespace std;

template <class T>
class IntBinaryTree
{
private:
   // The TreeNode struct is used to build the tree.
   struct TreeNode
   {     
      T value;
      TreeNode *left;
      TreeNode *right;
      TreeNode(T value1, 
              TreeNode *left1 = nullptr,
              TreeNode *right1 = nullptr)
      {
         value = value1;
         left = left1;
         right = right1;
      }
   };

   TreeNode *root;     // Pointer to the root of the tree

   // Various helper member functions.
   void insert(TreeNode *&, T);
   void destroySubtree(TreeNode *);
   void remove(TreeNode *&, T);
   void makeDeletion(TreeNode *&);
   int findLevel(TreeNode*&,int);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;

public:
   // These member functions are the public interface.
   void findItem(T) const;
   IntBinaryTree()		// Constructor
   {
      root = nullptr;
   }
   ~IntBinaryTree()		// Destructor
   {
      destroySubtree(root);
   }
   void insert(T num)
   {
      insert(root, num);
   }
   bool search(T) const;
   void remove(int num)
   {
      remove(root, num);
   }
   void showInOrder(void) const
   {
      displayInOrder(root);
   }
   void showPreOrder() const
   {
      displayPreOrder(root);
   }
   void showPostOrder() const
   {
      displayPostOrder(root);
   }
   void isBalanced()
   {
       int levelL = 0,
           levelR=0;
       if (root) 
       {
           levelL = findLevel(root->left, 0);
               //findLevel(root->left);
           levelR = findLevel(root->right,0);
       }
       cout << "\n\nThe left level is " << levelL <<
           "\nThe right level is " << levelR << endl;

   }
};

template <class T>
void IntBinaryTree<T>::insert(TreeNode*& tree, T num)
{
    // If the tree is empty, make a new node and make it 
    // the root of the tree.
    if (!tree)
    {
        tree = new TreeNode(num);
        return;
    }

    // If num is already in tree: return.
    // duplicate values are not allowed
    else if (tree->value == num)
        return;

    // The tree is not empty: insert the new node into the
    // left or right subtree.
    else if (num < tree->value)
        insert(tree->left, num);
    else
        insert(tree->right, num);
}

template <class T>
void IntBinaryTree<T>::destroySubtree(TreeNode* tree)
{
    if (!tree) return;
    destroySubtree(tree->left);
    destroySubtree(tree->right);
    // Delete the node at the root.
    delete tree;
}


template <class T>
bool IntBinaryTree<T>::search(T num) const
{
    TreeNode* tree = root;

    while (tree)
    {
        if (tree->value == num)
            return true;
        else if (num < tree->value)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return false;
}

template <class T>
void IntBinaryTree<T>::findItem(T num) const
{
	TreeNode* tree = root;
	
	while (tree)
	{
		if (tree->value == num)
		{
			cout<<"The searched value was found.\n\t"<<tree->value;
			return;
		}
		else if (num < tree->value)
			tree = tree->left;
		else
			tree = tree->right;
	}
	cout<<"The searched value was not found in the tree.\n";
}

template <class T>
void IntBinaryTree<T>::remove(TreeNode*& tree, T num)
{
    if (tree == nullptr) return;
    if (num < tree->value)
        remove(tree->left, num);
    else if (num > tree->value)
        remove(tree->right, num);
    else
        // We have found the node to delete.
        makeDeletion(tree);
}

template <class T>
void IntBinaryTree<T>::makeDeletion(TreeNode*& tree)
{
    // Used to hold node that will be deleted.
    TreeNode* nodeToDelete = tree;

    // Used to locate the  point where the 
    // left subtree is attached.
    TreeNode* attachPoint;

    if (tree->right == nullptr)
    {
        // Replace tree with its left subtree. 
        tree = tree->left;
    }
    else if (tree->left == nullptr)
    {
        // Replace tree with its right subtree.
        tree = tree->right;
    }
    else
        //The node has two children
    {
        // Move to right subtree.
        attachPoint = tree->right;

        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left != nullptr)
            attachPoint = attachPoint->left;

        // Attach the left subtree of the original tree
        // as the left subtree of the smallest node 
        // in the right subtree.
        attachPoint->left = tree->left;

        // Replace the original tree with its right subtree.
        tree = tree->right;
    }

    // Delete root of original tree
    delete nodeToDelete;
}


template <class T>
int IntBinaryTree<T>::findLevel(TreeNode*& tree, int level)
{
    if (tree)
    {
        int left, right;
        right = findLevel(tree->right, level) + 1;
        left = findLevel(tree->left, level) + 1;
        if (left > right)  level += left;
        else level += right;
    }
    return level;
}

template <class T>
void IntBinaryTree<T>::displayInOrder(TreeNode* tree) const
{
    if (tree)
    {
        //InOrder
        //Left side->Root->Right side
        displayInOrder(tree->left);
        cout << tree->value << "\t";
        displayInOrder(tree->right);
    }
}

template <class T>
void IntBinaryTree<T>::displayPreOrder(TreeNode* tree) const
{
    if (tree)
    {
        //PreOrder
        //Root->Left side->Right side
        cout << tree->value << "\t";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

template <class T>
void IntBinaryTree<T>::displayPostOrder(TreeNode* tree) const
{
    if (tree)
    {
        //PostOrder
        //Left side->Right side->Root
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        cout << tree->value << "\t";
    }
}
