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
            listSize = 0;
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
                tail->pNext = head;

            } else
            {
                tail->pNext = newNode;
                tail = newNode;
                tail->pNext = head;

            }
            listSize++;

        }

        int getKnight()
        {
            Node* knight1 = head;
            Node* beats = head->pNext;
           // Node* knight2 = head->pNext->pNext;
        //    cout << "knight1 " << knight1->data << endl;
        //    cout << "beats " << beats->data << endl;
        //    cout << "knight2 " << knight2->data << endl;
            while(listSize > 1)
            {
                if(listSize != 2)
                {
                    if(knight1 == head)
                    {
                        head->pNext = beats->pNext;
                        knight1 = beats->pNext;
                        delete beats;
                        beats = knight1->pNext;
                        listSize--;

                    } else if(beats == tail)
                    {
                        tail = knight1;
                        tail->pNext = beats->pNext;
                        knight1 = beats->pNext;
                        delete beats;
                        beats = knight1->pNext;
                        listSize--;

                    } else if(beats == head)
                    {
                        head = head->pNext;
                        tail->pNext = head;
                        knight1 = beats->pNext;
                        delete beats;
                        beats = knight1->pNext;
                        listSize--;


                    } else
                    {
                        knight1->pNext = beats->pNext;
                        knight1 = beats->pNext;
                        delete beats;

                        beats = knight1->pNext;
                        listSize--;

                    }
                } else
                {
                    delete beats;
                    head = tail;
                    head->pNext = tail->pNext = NULL;
                    listSize--;
                }
            }
            return knight1->data;

        }

    private:
        Node* head;
        Node* tail;
        int listSize;

};


int main()
{
    int n;
    cin >> n;
    List knightList;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
        {
            knightList.insertAtEnd(i);
        }
    }

    cout << knightList.getKnight();


    return 0;
}

