#include <iostream>
#include <unordered_set>
#include <utility>
#include <algorithm>

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
        int countUniquePairs(unordered_set<long>& numbers)
        {
            int pairCount = 0;
            vector<pair<int, int>> visited;
            Node* previous = head;
            Node* next = head->pNext;
            while(next != NULL)
            {
                unordered_set<long>::iterator it1 = numbers.find(previous->data);
                unordered_set<long>::iterator it2 = numbers.find(next->data);
                if(it1 != numbers.end() && it2 != numbers.end())
                {
                   cout << "Numbers exist in P" << endl;
                   pair<int, int> tmp = make_pair(previous->data, next->data);
                   vector<pair<int, int>>::iterator iter = find(visited.begin(), visited.end(), tmp);
                   if(iter == visited.end() && previous->data != next->data)
                   {
                        pair<int, int> reverseTmp = make_pair(next->data, previous->data);
                        visited.push_back(tmp);
                        visited.push_back(reverseTmp);
                        pairCount++;
                   } else if(iter == visited.end() && previous->data == next->data)
                   {
                        visited.push_back(tmp);
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

