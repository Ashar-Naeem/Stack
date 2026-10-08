
#include <iostream>
using namespace std;

class Stack_i
{
private:
    string arr[10];
    int top;

public:
    Stack_i()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void removeRedElement(string element)
    {
        if(top==-1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        Stack_i temp;
        while(!isEmpty())
        {

            string value=pop();
            if(value==element)
            {
                break;
            }

            temp.push(value);
        }
        while(!temp.isEmpty())
        {
            push(temp.pop());
        }
    }

    string getTop()
    {
        if (top == -1)
        {
            return "Empty";
        }

        string value = arr[top];
        return value;
    }

    void push(string value)
    {
        if (top == 9)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " Pushed" << endl;
    }

    string pop()
    {
        if (top == -1)
        {
            return "Stack Underflow\n";
        }

        string value = arr[top];
        top--;

        return value;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top value is: " << arr[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack: ";

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};
int main()
{

    Stack_i s1;
    s1.push("red");
    s1.push("green");
    s1.push("yellow");
    s1.push("blue");
    s1.push("red");
    s1.push("orange");
    s1.removeRedElement("red");
    s1.display();
    return 0;
}