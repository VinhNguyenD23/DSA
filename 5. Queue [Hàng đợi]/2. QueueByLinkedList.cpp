#include <iostream>

template <typename T>
class Queue
{
public:
    struct Node
    {
        T mInfo;
        Node *mNextNode;
        Node(T info, Node *nextNode);
    };

public:
    Queue();
    ~Queue();
    size_t size() const;
    bool empty() const;
    T front();
    T back();
    void push(T value);
    void pop();

private:
    Node *first, *last;
    size_t mSize;
};

template <typename T>
Queue<T>::Node::Node(T info, Node *nextNode)
{
    this->mInfo = info;
    this->mNextNode = nextNode;
}

template <typename T>
Queue<T>::Queue()
{
    this->first = nullptr;
    this->last = nullptr;
    this->mSize = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    while (first->mNextNode != nullptr)
    {
        Node *currentNode = first;
        first = first->mNextNode;
        delete currentNode;
    }
    while (last->mNextNode != nullptr)
    {
        Node *currentNode = last;
        last = last->mNextNode;
        delete currentNode;
    }
}

template <typename T>
size_t Queue<T>::size() const
{
    return this->mSize;
}

template <typename T>
bool Queue<T>::empty() const
{
    return this->first == nullptr;
}

template <typename T>
T Queue<T>::front()
{
    return this->first->mInfo;
}

template <typename T>
T Queue<T>::back()
{
    return this->last->mInfo;
}

template <typename T>
void Queue<T>::push(T value)
{
    Node *newNode = new Node(value, nullptr);
    this->mSize++;
    if (this->empty())
    {
        this->first = this->last = newNode;
        return;
    }
    last->mNextNode = newNode;
    last = newNode;
}

template <typename T>
void Queue<T>::pop()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Queue is empty!\n");
    }
    Node *currentNode = first;
    first = first->mNextNode;
    delete currentNode;
}

int main()
{
    Queue<int> *A = new Queue<int>();
    A->push(4);
    A->push(5);
    A->push(6);
    A->push(7);
    while (!A->empty())
    {
        std::cout << A->front() << ' ';
        A->pop();
    }
}