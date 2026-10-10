#include <iostream>
#include <string>
using namespace std;
class History_Stack
{
private:
    string arr[10];
    int top;

public:
    History_Stack()
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
    string getTop()
    {
        if (top == -1)
        {
            return "Empty";
        }

        string value = arr[top];
        return value;
    }

    void addHistory(string value)
    {
        if (top == 9)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << value << "Added" << endl;
    }

    string removeRecentHistory()
    {
        if (top == -1)
        {
            return "Stack Underflow\n";
        }

        string value = arr[top];
        top--;

        return value;
    }

    void currentlyStoredHistory()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top value is: " << arr[top] << endl;
    }
    void displayHistory()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        History_Stack temp;

        cout << "Stack : ";

        while (!isEmpty())
        {
            string value = removeRecentHistory();

            cout << value << " ";

            temp.addHistory(value);
        }

        while (!temp.isEmpty())
        {
            addHistory(temp.removeRecentHistory());
        }

        cout << endl;
    }
};
int main()
{
    History_Stack h1;
    int choice;
    string webpage;
    
    do
    {
        cout << "\n -- Browser History Menu --\n";
        cout << "1. Add webpage\n";
        cout << "2. Remove most recent webpage\n";
        cout << "3. View current webpage\n";
        cout << "4. Display all history\n";
        cout << "5. Check if history is empty\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter webpage name: ";
            cin >> webpage;
            h1.addHistory(webpage);
            break;

        case 2:
            h1.removeRecentHistory();
            break;

        case 3:
            h1.currentlyStoredHistory();
            break;

        case 4:
            h1.displayHistory();
            break;

        case 5:
            if (h1.isEmpty())
                cout << "History is Empty\n";
            else
                cout << "History is not Empty\n";
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}