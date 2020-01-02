#include <iostream>
using namespace std;

enum color{red,black};

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->parent=NULL;
    }
};

class RedBlackTree
{
private:
    Node* root;
    
public:
    RedBlackTree();
    ~RedBlackTree();
    void Rotateleft(Node *&parent,Node *& pt);

};

RedBlackTree::RedBlackTree(){root=NULL;}
RedBlackTree::~RedBlackTree(){}

void RedBlackTree::Rotateleft(Node *&root,Node *& pt){
    Node* pt_right = pt->right;

}




int main(int argc, char const *argv[])
{
    
    return 0;
}
