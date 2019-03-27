#include <iostream>
#include <list>
#include <math.h>

using namespace std;

struct Node
{
    long long data;
    Node* next;
};

class List
{
    public:
    Node* head;
    Node* tail;
    int m_size;

    public:
        List()
        {
            head = tail = NULL;
            m_size = 0;
        }

        void insertAtEnd(long long value)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;
            if(head == NULL)
            {
                head = tail = newNode;
                newNode = NULL;
            } else
            {
                tail->next = newNode;
                tail = newNode;
                newNode = NULL;
            }
            m_size++;
        }
        bool searchInList(long long x)
        {
            Node* temp = head;
            while(temp != NULL)
            {
                if(temp->data == x)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        void print()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int hashFunction(long long key, int m)
{
    //int a = rand() % 20000;
    //int b = rand() % 20000;

    return abs(key)%m;
}

int main()
{
    int m;
    cin >> m;
    List* hashTable = new List[m];
    for(int i = 0; i < m; i++)
    {
        long long key;
        cin >> key;
        int idx = hashFunction(key, m);
        if(!hashTable[idx].searchInList(key))
        {
             hashTable[idx].insertAtEnd(key);
        }
    }
    int cntUnique = 0;
    for(int i = 0; i < m; i++)
    {
        cntUnique+= hashTable[i].m_size;
    }
    cout << cntUnique << endl;
    for(int i = 0; i < m; i++)
    {
        cout << "List " << i << ": ";
        hashTable[i].print();
        cout << endl;
    }
    delete[] hashTable;
    return 0;
}
