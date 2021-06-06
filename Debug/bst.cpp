#include "bst.h"

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
	size = 0;
}
void BinarySearchTree::insert(int data)
{
	Node* newNode = new Node;
	newNode->value = data;
	newNode->left = NULL;
	newNode->right = NULL;
	if (root == NULL)
		root = newNode;
	else
	{
		Node* temp1 = root, * temp2 = root;
		while (temp2 != NULL)
			if (data > temp2->value)
			{
				temp1 = temp2;
				temp2 = temp2->right;
			}
			else if (data < temp2->value)
			{
				temp1 = temp2;
				temp2 = temp2->left;
			}
			else
				return;
		if (data > temp1->value)
			temp1->right = newNode;
		else
			temp1->left = newNode;
	}
	size++;
}
bool BinarySearchTree::find(int data)
{
	if (root == NULL)
		return false;
	else
	{
		Node* temp = root;
		while (temp != NULL)
			if (data > temp->value)
				temp = temp->right;
			else if (data < temp->value)
				temp = temp->left;
			else
				return true;
		return false;
	}
}
int BinarySearchTree::getLevel(int data)
{
	if (root == NULL)
		return -1;
	else
	{
		int level = 1;
		Node* temp = root;
		while (temp != NULL)
		{
			if (data > temp->value)
				temp = temp->right;
			else if (data < temp->value)
				temp = temp->left;
			else
				return level;
			level++;
		}
		return -1;
	}
}
void BinarySearchTree::postorder(Node* n)
{
	if (n == NULL)
		return;
	postorder(n->left);
	postorder(n->right);
	cout << n->value << " ";
}
void BinarySearchTree::inorder(Node* n)
{
	if (n == NULL)
		return;
	inorder(n->right);
	cout << n->value << " ";
	inorder(n->left);
}
void BinarySearchTree::preorder(Node* n)
{
	if (n == NULL)
		return;
	cout << n->value << " ";
	preorder(n->left);
	preorder(n->right);
}
void BinarySearchTree::printPreorder()
{
	preorder(root);
}
void BinarySearchTree::printInorder()
{
	inorder(root);
}
void BinarySearchTree::printPostorder()
{
	postorder(root);
}