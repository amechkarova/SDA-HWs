#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class NodeHd
{
    public:
    Node* node;
    int hd;

    NodeHd(Node* node, int hd)
    {
        this->node = node;
        this->hd = hd;
    }
};
class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


        void topView(Node* root) {
             if(root == NULL)
            {
                return;
            }

            int currentMaxRight = 0;
            int currentMinLeft = 0;
            queue<NodeHd*> nodes;
            vector<NodeHd*> topViewElements;
            NodeHd* rootNode = new NodeHd(root, 0);
            nodes.push(rootNode);
            topViewElements.push_back(rootNode);

            while(!nodes.empty())
            {
                NodeHd* nodeHd = nodes.front();
                nodes.pop();
                if(nodeHd->node != NULL)
                {
                    NodeHd* left = new NodeHd(nodeHd->node->left, nodeHd->hd - 1);
                    if(left->node != NULL)
                    {
                        if(left->hd < currentMinLeft)
                        {
                            currentMinLeft--;
                            topViewElements.push_back(left);
                        }
                        nodes.push(left);
                    }

                    NodeHd* right = new NodeHd(nodeHd->node->right, nodeHd->hd + 1);
                    if(right->node != NULL)
                    {
                        if(right->hd > currentMaxRight)
                        {
                            currentMaxRight++;
                            topViewElements.push_back(right);
                        }
                        nodes.push(right);
                    }

                }
            }

            for(int i = 0; i < topViewElements.size(); i++)
            {
                int smallest = i;
                for(int j = i + 1; j < topViewElements.size(); j++)
                {
                    if(topViewElements[smallest]->hd > topViewElements[j]->hd)
                    {
                        cout << topViewElements[i]->hd << " > " << topViewElements[j]->hd << endl;
                        smallest = j;
                    }
                }
                NodeHd* tmp = topViewElements[smallest];
                topViewElements[smallest] = topViewElements[i];
                topViewElements[i] = tmp;
            }

            for(int i = 0; i < topViewElements.size(); i++)
            {
                cout << topViewElements[i]->hd<< " ";
            }

        }
};


int main()
{
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

	myTree.topView(root);

    return 0;
}
