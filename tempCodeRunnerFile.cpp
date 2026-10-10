#include <iostream>
#include <string>
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
        return top == -1;
    }

    void push(string value)
    {
        if (top == 9)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    string pop()
    {
        if (isEmpty())
        {
            return "";
        }

        return arr[top--];
    }

    void removeRedElement()
    {
        Stack_i temp;

        while (!isEmpty())
        {
            string value = pop();

            if (value == "Red" || value == "red")
            {
                continue;
            }

            temp.push(value);
        }

        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Final Stack : ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack_i s1;
    string colour;

    cout << "Enter 5 marble colours:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> colour;
        s1.push(colour);
    }

    s1.removeRedElement();

    s1.display();

    return 0;
}
