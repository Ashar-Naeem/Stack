

/// Remove n element from the stack
#include <iostream>
using namespace std;

class Stack_i
{
private:
    int arr[5];
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

    void removeElement(int element)
    {
        if(top==-1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        Stack_i temp;
        while(!isEmpty())
        {

            int value=pop();
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

    int getTop()
    {
        if (top == -1)
        {
            return -1;
        }

        int value = arr[top];
        return value;
    }

    void push(int value)
    {
        if (top == 4)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " Pushed" << endl;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        int value = arr[top];
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

    s1.push(23);
    s1.push(434);
    s1.push(44);
    s1.push(4);

    cout << "Original Stack: ";
    s1.display();

    s1.removeElement(44);

    cout << "Stack after checkMax: ";
    s1.display();

    return 0;
}