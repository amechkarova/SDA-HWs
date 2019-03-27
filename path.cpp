#include <iostream>
#include <string>


using namespace std;

class Stack
{
    private:
        struct Node
        {
            int data;
            string color;
            Node* pNext;
        };
        Node* top;
        int m_size;

    public:
        Stack()
        {
            top = NULL;
            m_size = 0;
        }

        void push(const string& color, const int& value)
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->color = color;
            newNode->pNext = top;
            top = newNode;
            m_size++;
        }
        int pop()
        {
            int temp = top->data;
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

        void print()
        {
            Node* temp = top;
            while(temp != NULL)
            {
                cout << temp->color << " " << temp->data << endl;
;            }
        }
};


int main()
{
    Stack path;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string color;
        cin >> color;
        int number;
        cin >> number;
        if(color == "white")
        {
            path.push(color, number);
        }
        if(color == "green")
        {
            int sumOfNumbers = 0;
            for(int i = 0; i < number; i++)
            {
                if(!path.isEmpty())
                {
                    sumOfNumbers+= path.pop();
                }
            }
            path.push("white", sumOfNumbers);
        }
        if(color == "blue")
        {
            int maxStone = 0;
            for(int i = 0; i < number; i++)
            {
                if(!path.isEmpty())
                {
                    int tmp = path.pop();
                    if(tmp > maxStone)
                    {
                        maxStone = tmp;
                    }
                }
            }
            path.push("white", maxStone);
        }

    }

    Stack path2;
    while(!path.isEmpty())
    {
         path2.push("white", path.pop());
    }
    while(!path2.isEmpty())
    {
        cout << path2.pop() << " ";
    }


    return 0;
}

