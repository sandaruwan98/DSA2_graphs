// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    int color; // 1 = red , 0 = black
    Node *left, *right, *parent;

    // Constructor
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
        this->color = 1;
    }
};

// This is Class to Red-Black Tree
class RedBlackTree
{

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
   
    Node *root;
    RedBlackTree() { root = NULL; }
    void insert(const int &n);
    void inorder(Node* root);
    Node* Search(Node* root,int val);
};



Node*  RedBlackTree::Search(Node* root,int val) { 
    

}

void RedBlackTree::inorder( Node* root) { 
  
     if (root != NULL)
    {
         inorder(root->left);
         cout << root->data << "  ";
         inorder(root->right);
    }

}

Node *BSTinsert(Node *root, Node *ptr)
{
    if (root == NULL)
        return ptr;

    if (ptr->data < root->data)
    {
        root->left = BSTinsert(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data)
    {
        root->right = BSTinsert(root->right, ptr);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

void RedBlackTree::insert(const int &data)
{
    Node *ptr = new Node(data);
    root = BSTinsert(root, ptr);
    fixViolation(root, ptr);
}

void RedBlackTree::rotateRight(Node *&root, Node *&ptr)
{
    Node *ptr_left = ptr->left;

    ptr->left = ptr_left->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    ptr_left->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = ptr_left;

    else if (ptr == ptr->parent->left)
        ptr->parent->left = ptr_left;

    else
        ptr->parent->right = ptr_left;

    ptr_left->right = ptr;
    ptr->parent = ptr_left;
}

void RedBlackTree::rotateLeft(Node *&root, Node *&ptr)
{
    Node *ptr_right = ptr->right;

    ptr->right = ptr_right->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    ptr_right->parent = ptr->parent;

    if (ptr->parent == NULL)
        root = ptr_right;

    else if (ptr == ptr->parent->left)
        ptr->parent->left = ptr_right;

    else
        ptr->parent->right = ptr_right;

    ptr_right->left = ptr;
    ptr->parent = ptr_right;
}


void RedBlackTree::fixViolation(Node *&root, Node *&ptr)
{
    Node *parent_ptr = NULL;
    Node *grand_parent_ptr = NULL;

    while ((ptr != root) && (ptr->color != 0) &&
           (ptr->parent->color == 1))
    {

        parent_ptr = ptr->parent;
        grand_parent_ptr = ptr->parent->parent;

        /*  Case : A 
            Parent of ptr is left child of Grand-parent of ptr */
        if (parent_ptr == grand_parent_ptr->left)
        {

            Node *uncle_ptr = grand_parent_ptr->right;

            /* Case : 1 
               The uncle of ptr is also red 
               Only Recoloring required */
            if (uncle_ptr != NULL && uncle_ptr->color == 1)
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                ptr = grand_parent_ptr;
            }

            else
            {
                /* Case : 2 
                   ptr is right child of its parent 
                   Left-rotation required */
                if (ptr == parent_ptr->right)
                {
                    rotateLeft(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }

                /* Case : 3 
                   ptr is left child of its parent 
                   Right-rotation required */
                rotateRight(root, grand_parent_ptr);
                swap(parent_ptr->color, grand_parent_ptr->color);
                ptr = parent_ptr;
            }
        }

        /* Case : B 
           Parent of ptr is right child of Grand-parent of ptr */
        else
        {
            Node *uncle_ptr = grand_parent_ptr->left;

            /*  Case : 1 
                The uncle of ptr is also red 
                Only Recoloring required */
            if ((uncle_ptr != NULL) && (uncle_ptr->color == 1))
            {
                grand_parent_ptr->color = 1;
                parent_ptr->color = 0;
                uncle_ptr->color = 0;
                ptr = grand_parent_ptr;
            }
            else
            {
                /* Case : 2 
                   ptr is left child of its parent 
                   Right-rotation required */
                if (ptr == parent_ptr->left)
                {
                    rotateRight(root, parent_ptr);
                    ptr = parent_ptr;
                    parent_ptr = ptr->parent;
                }

                /* Case : 3 
                   ptr is right child of its parent 
                   Left-rotation required */
                rotateLeft(root, grand_parent_ptr);
                swap(parent_ptr->color, grand_parent_ptr->color);
                ptr = parent_ptr;
            }
        }
    }

    root->color = 0;
}

bool hasCommonNums(RedBlackTree tree,int setB[]){
    int i;
    for ( i = 0; i < sizeof(setB)/sizeof(int); i++){

    }
}

// Driver Code
int main()
{
    RedBlackTree tree;
    int setA[] = {12,11,34,9,3};
    int setB[] = {12,11,34,9,3};
    int i;
    for ( i = 0; i < sizeof(setA)/sizeof(int); i++)
        tree.insert(setA[i]);

    cout << hasCommonNums(tree,setB);
    
  

    cout << "Inoder Traversal of Created Tree\n";
    tree.inorder(tree.root);

    return 0;
}