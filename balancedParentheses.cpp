#include <iostream>
#include <string>

using namespace std;

template<class T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node* pNext;
        };
        Node* top;
        int m_size;
        void clearStack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }
        void copyStack(Stack<T> const &other)
        {
            if(other.isEmpty())
            {
                clearStack();
                top = NULL;
            } else
            {
                this->top = new Node;
                top->data = other.top->data;
                Node* toCopy = other.top->pNext;
                Node* lastCopy = top;
                while(toCopy != NULL)
                {
                    Node* newCopy = new Node;
                    newCopy->data = toCopy->data;
                    lastCopy->pNext = newCopy;
                    toCopy = toCopy->pNext;
                    lastCopy = lastCopy->pNext;
                }
                lastCopy->pNext = NULL;
            }
        }
    public:
        Stack()
        {
            top = NULL;
            m_size = 0;
        }
        Stack(Stack<T> const &other)
        {
            m_size = other.m_size;
            copyStack(other);
        }
        void push(const T& value)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->pNext = top;
            top = newNode;
            m_size++;
        }
        T pop()
        {
            T temp = top->data;
            Node* current = top;
            top = top->pNext;
            delete current;
            m_size--;
            return temp;
        }
        bool isEmpty() const
        {
            return top == NULL;
        }
};

void areParanthesisBalanced(string str)
{
    if(str == "")
    {
        cout << "YES";
        return;
    }
    Stack<char> s;
    char c;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
        {
            s.push(str[i]);
            continue;
        }

        if(s.isEmpty())
        {
            cout << "NO";
            return;
        }

        if(str[i] == ')')
        {
            c = s.pop();
            if(c != '(')
            {
                cout << "NO";
                return;
            }
        }
    }
    if(s.isEmpty())
    {
        cout << "YES";
    } else
    {
        cout << "NO";
    }
}

int main()
{
    string s;
    cin >> s;
    areParanthesisBalanced(s);
    return 0;
}
