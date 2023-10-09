#include <bits/stdc++.h>
#define size 5
using namespace std;

class Stack
{
private:
    int top;
    int arr[size];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (top == size - 1)
            return true;
        return false;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack-overflow occurs." << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack-underflow occurs." << endl;
            return 0;
        }
        int x = arr[top];
        arr[top] = 0;
        top--;
        return x;
    }

    int topp()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return 0;
        }
        return arr[top];
    }

    int bottom()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return 0;
        }
        return arr[0];
    }

    int count()
    {
        return top + 1;
    }

    int peek(int position)
    {
        return arr[position - 1];
    }

    void change(int position, int value)
    {
        cout << "Value changed in position " << position << " from " << arr[position - 1] << " to ";
        arr[position - 1] = value;
        cout << arr[position - 1] << endl;
    }

    void display()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s;
    int option, position, value;

    do
    {
        cout << "Choose your option for respective operation." << endl;
        cout << "0. Exit." << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. isEmpty?" << endl;
        cout << "4. isFull?" << endl;
        cout << "5. Peek." << endl;
        cout << "6. Change." << endl;
        cout << "7. Count." << endl;
        cout << "8. Display." << endl;
        cout << "9. Top." << endl;
        cout << "10. Bottom." << endl;
        cout << "11. Clear screen." << endl
             << endl;

        cout << "Enter your option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Enter the value to be pushed: ";
            cin >> value;
            s.push(value);
            cout << endl;
            break;

        case 2:
            cout << "Popped value: " << s.pop();
            cout << endl;
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is empty.";
            else
                cout << "Stack is not empty.";
            cout << endl;
            break;

        case 4:
            if (s.isFull())
                cout << "Stack is full.";
            else
                cout << "Stack is not full.";
            cout << endl;
            break;

        case 5:
            cout << "Enter position to be peeked at: ";
            cin >> position;
            cout << "Item in position " << position << " is " << s.peek(position);
            cout << endl;
            break;

        case 6:
            cout << "Enter position holding value to be changed: ";
            cin >> position;
            cout << "Enter changed value: ";
            cin >> value;
            s.change(position, value);
            cout << endl;
            break;

        case 7:
            cout << "Number of items available in stack: " << s.count();
            cout << endl;
            break;

        case 8:
            cout << "Available items in stack:" << endl;
            s.display();
            cout << endl;
            break;

        case 9:
            cout << "Stack top value: " << s.topp();
            cout << endl;
            break;

        case 10:
            cout << "Stack bottom value: " << s.bottom();
            cout << endl;
            break;

        case 11:
            system("cls");
            break;

        default:
            cout << "Please enter valid option." << endl;
            break;
        }

    } while (option != 0);

    return 0;
}