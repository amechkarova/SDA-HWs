#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
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
        } else
        {
            root->left = insert(root->left, value);
            return root;
        }
    }

    void calculateLevelAverage(Node* root)
    {
        if(root == NULL)
        {
            return;
        }

        queue<Node*> q;
        vector<double> average;

        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int border = q.size();
            double sum = 0.0;
            cout << "Level " << level << " : ";
            for(int i = 0; i < border; i++)
            {
                Node* temp = q.front();
                cout << " temp->data : " << temp->data << " ";
                q.pop();

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
                sum+=temp->data;
            }
            cout << "SUM: " << sum<< endl;
            average.push_back(sum/border);
            level++;
        }

        for(int i = 0; i < average.size(); i++)
        {
            cout << showpoint <<  setprecision(3)<< average[i] << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Tree myTree;
    Node* root = NULL;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = myTree.insert(root, val);
    }

    myTree.calculateLevelAverage(root);
    return 0;
}
