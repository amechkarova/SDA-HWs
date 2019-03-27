#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    public:
    Node* root;
    Tree()
    {
        root = NULL;
    }

    Node* insert(Node* root, int value)
    {
        if(root == NULL)
        {
            root = new Node(value);
            return root;
        } else if(value >= root->data) //if an element is already existing, add it in the right subtree
        {
            root->right = insert(root->right, value);
            return root;
        } else if(value < root->data)
        {
            root->left = insert(root->left, value);
            return root;
        }
    }

    int numberOfLeaves(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        } else if(root->left == NULL && root->right == NULL)
        {
            return 1;
        } else
        {
            int l = numberOfLeaves(root->left);
            int r = numberOfLeaves(root->right);
            return l + r;
        }
    }

    int sumOfLeaves(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        } else if(root->left == NULL && root->right == NULL)
        {
            return root->data;
        } else
        {
            int l = sumOfLeaves(root->left);
            int r = sumOfLeaves(root->right);
            return l + r;
        }
    }

    int counSubtrees(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        } else if(root->left == NULL && root->right == NULL)
        {
            return 1;
        } else
        {
            int l = counSubtrees(root->left);
            int r = counSubtrees(root->right);
            return l + r + 2;
        }
    }

    int countNodes(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        } else
        {
            int l = countNodes(root->left);
            int r = countNodes(root->right);
            return l + r + 1;
        }
    }

    int innerNodes(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        } else
        {
            return countNodes(root) - numberOfLeaves(root);
        }
    }
};
int main()
{
    int n;
    cin >> n;
    Node* root = NULL;
    Tree myTree;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = myTree.insert(root, val);
    }

    cout << myTree.numberOfLeaves(root) << endl;
    cout << myTree.sumOfLeaves(root) << endl;
    cout << myTree.counSubtrees(root) << endl;
    cout << myTree.countNodes(root) << endl;
    cout << myTree.innerNodes(root);

    return 0;
}
