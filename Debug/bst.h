#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
};
class BinarySearchTree
{
private:
    Node* root;
    int size;
    void postorder(Node* n);
    void inorder(Node* n);
    void preorder(Node* n);
public:
    BinarySearchTree();
    void insert(int data);
    bool find(int data);
    int getLevel(int data);
    void printPreorder();
    void printInorder();
    void printPostorder();
};