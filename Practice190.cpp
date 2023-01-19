/*
191. Remove leaf nodes in Tree: Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
*/

// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {

        if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }

    if (root->right != NULL)
    {
        root->right = removeLeafNodes(root->right);
    }
    if (root->left != NULL)
    {
        root->left = removeLeafNodes(root->left);
    }

    return root;
}



