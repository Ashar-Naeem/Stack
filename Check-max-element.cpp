
/// Chech max element in the stack
#include <iostream>
#include <climits>
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

    int checkMax()
    {
        if (top == -1)
        {
            cout << "Empty Stack";
            return -1;
        }

        Stack_i temp;
        int max = INT_MIN;

        // Check all elements using pop
        while (!isEmpty())
        {
            int value = pop();

            if (value > max)
            {
                max = value;
            }

            temp.push(value);
        }

        // Restore original stack
        while (!temp.isEmpty())
        {
            int value = temp.pop();
            push(value);
        }

        return max;
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

    cout << "Maximum: " << s1.checkMax() << endl;

    cout << "Stack after checkMax: ";
    s1.display();

    return 0;
}