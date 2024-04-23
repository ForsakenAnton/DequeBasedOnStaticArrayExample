#include <iostream>
using namespace std;

template <typename T, int SIZE> // non-type параметр
class Deque
{
private:
    T arr[SIZE]; // Масив для зберігання даних
    int front; // Індекс початку черги
    int rear; // Індекс кінця черги
    int count; // Кількість елементів у черзі

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == SIZE;
    }

public:
    Deque() :
        front(0),
        rear(-1),
        count(0)
    {
    }

    void enqueueFront(const T& value)
    {
        if (isFull())
        {
            cerr << "Deque is full. Cannot enqueue at front." << endl;

            return;
        }

        front = (front - 1 + SIZE) % SIZE;
        arr[front] = value;
        count++;
    }

    void enqueueRear(const T& value)
    {
        if (isFull())
        {
            cerr << "Deque is full. Cannot enqueue at rear." << endl;

            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    void dequeueFront()
    {
        if (isEmpty())
        {
            cerr << "Deque is empty. Cannot dequeue from front." << endl;

            return;
        }

        front = (front + 1) % SIZE;
        count--;
    }

    void dequeueRear()
    {
        if (isEmpty())
        {
            cerr << "Deque is empty. Cannot dequeue from rear." << endl;

            return;
        }

        rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }

    const T& peekFront() const
    {
        if (isEmpty())
        {
            cerr << "Deque is empty." << endl;

            static T dummy;

            return dummy;
        }
        return arr[front];
    }

    const T& peekRear() const
    {
        if (isEmpty())
        {
            cerr << "Deque is empty." << endl;

            static T dummy;

            return dummy;
        }
        return arr[rear];
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }

        cout << arr[rear] << endl;
    }
};

int main()
{
    const int SIZE = 5;
    Deque<int, SIZE> myDeque;

    myDeque.enqueueFront(1);
    myDeque.enqueueRear(2);
    myDeque.enqueueFront(3);

    cout << "Front of the deque: " << myDeque.peekFront() << endl;
    cout << "Rear of the deque: " << myDeque.peekRear() << endl;

    cout << "Deque elements: ";
    myDeque.display();

    myDeque.dequeueFront();
    cout << "After dequeue from front:" << endl;
    cout << "Front of the deque: " << myDeque.peekFront() << endl;
    cout << "Deque elements: ";
    myDeque.display();

    myDeque.dequeueRear();
    cout << "After dequeue from rear:" << endl;
    cout << "Rear of the deque: " << myDeque.peekRear() << endl;
    cout << "Deque elements: ";
    myDeque.display();

    return 0;
}
