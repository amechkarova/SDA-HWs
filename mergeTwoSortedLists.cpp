#include <iostream>

using namespace std;

template<class T>
class List
{
    private:
    struct Node
    {
        T data;
        Node* pNext;
    };
        Node* head;
        Node* tail;
        int m_size;

    public:
        List<T>();
        void insertAtEnd(T value);
        void insertAtStart(T value);
        void insertAt(int pos, T value);

        void deleteAtEnd();
        void deleteAtStart();
        void deleteAt(int pos);

        void print();
        bool searchInList(T x);
        bool isEmpty();
        void reverseList();
        void mergeLists(List& list2)
        {
            Node* new_head;
            Node* s;
            Node* p = head;
            Node* q = list2.head;
            if(this->head == NULL)
            {
                new_head = list2.head;
            }
            if(list2.head == NULL)
            {
                new_head = head;
            }
            if(p != NULL && q != NULL)
            {
                if(p->data <= q->data)
                {
                    s = p;
                    p = p->pNext;

                } else
                {
                    s = q;
                    q = q->pNext;
                }
            }
            new_head = s;

            while( p != NULL && q != NULL)
            {
                if(p->data <= q->data)
                {
                    s->pNext = p;
                    s = p;
                    p = p->pNext;
                } else
                {
                    s->pNext = q;
                    s = q;
                    q = q->pNext;
                }
            }
            if(p == NULL)
                s->pNext = q;
            if(q == NULL)
                s->pNext = p;

            this->head = new_head;
        }
};

template<class T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    m_size = 0;
}

template<class T>
void List<T>::insertAtEnd(T value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    if(head == NULL)
    {
        head = tail = newNode;
        newNode = NULL;
    } else
    {
        tail->pNext = newNode;
        tail = newNode;
        newNode = NULL;
    }
    m_size++;

}

template<class T>
void List<T>::insertAtStart(T value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    if(head == NULL)
    {
        head = tail = newNode;
        newNode = NULL;
    } else
    {
        newNode->pNext = head;
        head = newNode;
        newNode = NULL;
    }
    m_size++;
}

template<class T>
void List<T>::insertAt(int pos, T value)
{
    Node* previous;
    Node* current;
    Node* newNode = new Node;
    newNode->data = value;
    current = head;
    for(int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->pNext;
    }
    previous->pNext = newNode;
    newNode->pNext = current;
    newNode = NULL;

    m_size++;
}

template<class T>
void List<T>::deleteAtEnd()
{
    Node* previous;
    Node* temp = head;
    while(temp->pNext != NULL)
    {
        previous = temp;
        temp = temp->pNext;
    }
    tail = previous;
    previous->pNext = NULL;
    delete temp;
    m_size--;

}

template<class T>
void List<T>::deleteAtStart()
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    m_size--;
}

template<class T>
void List<T>::deleteAt(int pos)
{
    Node* previous;
    Node* temp;
    temp = head;
    for(int i = 1; i < pos; i++)
    {
        previous = temp;
        temp = temp->pNext;
    }
    previous->pNext = temp->pNext;
    delete temp;
    m_size--;
}

template<class T>
bool List<T>::searchInList(T x)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        temp = temp->pNext;
    }
    return false;
}

template<class T>
void List<T>::print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->pNext;
    }
}

template<class T>
void List<T>::reverseList()
{
    Node* current = head->pNext;
    Node* next = current->pNext;
    head->pNext = NULL;
    tail = head;
    while(next != NULL)
    {
        current->pNext = head;
        head = current;
        current = next;
        next = next->pNext;
    }
    current->pNext = head;
    head = current;
}

//template<class T>

int main()
{
    List<int> list1;
   // list1.insertAtEnd(2);
  //  list1.insertAtEnd(4);
   // numberList.insertAtEnd(10);
  //  numberList.insertAtEnd(20);
  /*  int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        list1.insertAtEnd(val);
    }*/
    List<int> list2;
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    List<int> result;
    list1.mergeLists(list2);
    list1.print();


    return 0;
}
