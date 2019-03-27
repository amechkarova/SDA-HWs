#include <iostream>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <string>
#include <fstream>

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
                newNode = NULL;

            } else
            {
                tail->pNext = newNode;
                tail = newNode;
                newNode = NULL;

            }

        }
        void printList()
        {
            Node* tmp = head;
            while(tmp != NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->pNext;
            }
        }
        int countUniquePairs(unordered_set<long>& numbers)
        {
            int pairCount = 0;
            unordered_set<string> visited;
            Node* previous = head;
            Node* next = head->pNext;
            while(next != NULL)
            {
                unordered_set<long>::iterator it1 = numbers.find(previous->data);
                unordered_set<long>::iterator it2 = numbers.find(next->data);
                if(it1 != numbers.end() && it2 != numbers.end())
                {
                   string tmp = to_string(previous->data) + to_string(next->data);
                   unordered_set<string>::iterator iter = visited.find(tmp);
                   if(iter == visited.end() && previous->data != next->data)
                   {
                            string reverseTmp = to_string(next->data) + to_string(previous->data);
                            visited.insert(tmp);
                            visited.insert(reverseTmp);
                            pairCount++;
                    } else if(iter == visited.end() && previous->data == next->data)
                    {
                        visited.insert(tmp);
                        pairCount++;
                    }
                }
                previous = next;
                next = next->pNext;
            }
            return pairCount;
        }

    private:
        Node* head;
        Node* tail;
};


int main()
{
    List numberList;
   /* ifstream ifs ("data1.txt", ifstream::in);
    int n;
    ifs >> n;
    int tmp;

    while(!ifs.eof())
    {
        ifs >> tmp;
        numberList.insertAtEnd(tmp);
    }
    ifs.close();
    ifstream ifs1 ("pData.txt", ifstream::in);
    int p;
    ifs1 >> p;
    int num;
    unordered_set<long> pNumbers;
    while(!ifs1.eof())
    {
        ifs1 >> num;
        if( num <= 1234)
        {
            pNumbers.insert(num);
        }
    }
    ifs1.close();*/
 // numberList.printList();
    int n;
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        numberList.insertAtEnd(tmp);
    }

    int p;
    cin >> p;
    unordered_set<long> pNumbers;
    long num;
    for(int i = 0; i < p; i++)
    {
        cin >> num;
        if( num <= 1234)
        {
            pNumbers.insert(num);
        }
    }
   cout << numberList.countUniquePairs(pNumbers);

    return 0;
}
