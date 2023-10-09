#include <bits/stdc++.h>
#define size 5
using namespace std;

class Queue
{
private:
    int arr[size];
    int front;
    int rear;
    int itemcount;

public:
    Queue()
    {
        itemcount = 0;
        front = rear = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if (((rear + 1) % size) == front)
            return true;
        return false;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
            rear = (rear + 1) % size;

        itemcount++;
        arr[rear] = value;
    }

    int dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
            itemcount--;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % size;
            itemcount--;
            return x;
        }
    }

    int count()
    {
        // if (front == -1 && rear == -1)
        //     return 0;
        // else if (front <= rear)
        //     return (rear - front) + 1;
        // return (size - (front - rear)) + 1;

        return itemcount;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Front: " << front + 1 << " Rear: " << rear + 1 << endl;
    }
};

int main()
{
    Queue q;
    int option, value;
    do
    {
        cout << "Choose your option for respective operation." << endl;
        cout << "0. Exit." << endl;
        cout << "1. Enqueue." << endl;
        cout << "2. Dequeue." << endl;
        cout << "3. isEmpty?" << endl;
        cout << "4. isFull?" << endl;
        cout << "5. Count." << endl;
        cout << "6. Display." << endl;
        cout << "7. Clear screen." << endl
             << endl;

        cout << "Enter your option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 0:
            break;

        case 1:
            cout << "Enter the value to be enqueued: ";
            cin >> value;
            q.enqueue(value);
            cout << endl;
            break;

        case 2:
            cout << "Dequeued value: " << q.dequeue();
            cout << endl;
            break;

        case 3:
            if (q.isEmpty())
                cout << "Queue is empty.";
            else
                cout << "Queue is not empty.";
            cout << endl;
            break;

        case 4:
            if (q.isFull())
                cout << "Queue is full.";
            else
                cout << "Queue is not full.";
            cout << endl;
            break;

        case 5:
            cout << "Number of items available in queue: " << q.count();
            cout << endl;
            break;

        case 6:
            cout << "Available items in queue:" << endl;
            q.display();
            cout << endl;
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Please enter valid option." << endl;
            break;
        }

    } while (option != 0);

    return 0;
}