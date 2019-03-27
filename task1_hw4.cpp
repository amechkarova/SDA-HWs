#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

class List{

    public:
        List()
        {
            head = NULL; //pointer to the first node in the list
            tail = NULL; // pointer to the last node in the list
        }

        void insertAtEnd(int value)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->pNext = NULL;
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;

            } else
            {
                tail->pNext = newNode;
                tail = newNode;

            }

        }
        void getSum()
        {
            long int sum = 0;
            Node* current = head;
            int smallest = head->data;
            int largest = head->data;
            while(current != NULL)
            {
                if(smallest > current->data)
                {
                    smallest = current->data;
                }
                if(largest < current->data)
                {
                    largest = current->data;
                }
                sum+=current->data;
                current = current->pNext;
            }
            cout << smallest << " " << largest << " " << sum;
        }

    private:
        Node* head;
        Node* tail;
};


int main()
{
    List numberList;
    int n;
    ios_base::sync_with_stdio(false);
    while(cin >> n)
    {
        numberList.insertAtEnd(n);
    }
    numberList.getSum();

    return 0;
}
