#include <iostream>

template <typename T>
class Stack
{
public:
    struct Node
    {
        Node *mPreviousNode;
        T mInfo;
        Node(T mInfo, Node *node);
    };

public:
    Stack();
    Stack(const Stack<T> &other);
    ~Stack();
    T top();
    int size() const;
    bool empty() const;
    void push(T value);
    void pop();

private:
    size_t mSize;
    Node *lastNode;
};

template <typename T>
Stack<T>::Node::Node(T mInfo, Node *node)
{
    this->mInfo = mInfo;
    this->mPreviousNode = node;
}

template <typename T>
Stack<T>::Stack()
{
    lastNode = nullptr;
    this->mSize = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    if (this != other)
    {
        this->~Stack();
        this->mSize = other->mSize;
        Stack<T>::Node *currentNode = other->lastNode;
        while (currentNode != nullptr)
        {
            this->push(currentNode->mInfo);
            currentNode = currentNode->mPreviousNode;
        }
    }
}

template <typename T>
Stack<T>::~Stack()
{
    while (this->lastNode->mPreviousNode != nullptr)
    {
        Node *currentNode = lastNode;
        lastNode = lastNode->mPreviousNode;
        delete currentNode;
    }
}

template <typename T>
T Stack<T>::top()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Stack is empty, can't remove any element!\n");
    }
    return this->lastNode->mInfo;
}

template <typename T>
int Stack<T>::size() const
{
    return this->mSize;
}

template <typename T>
bool Stack<T>::empty() const
{
    return lastNode == nullptr;
}

template <typename T>
void Stack<T>::push(T value)
{
    Node *newNode = new Node(value, lastNode);
    lastNode = newNode;
    this->mSize++;
}

template <typename T>
void Stack<T>::pop()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Stack is empty, can't remove any element!\n");
    }
    this->mSize--;
    Node *deleteNode = lastNode;
    lastNode = lastNode->mPreviousNode;
    delete deleteNode;
}

int main()
{
    Stack<int> *A = new Stack<int>();
    A->push(4);
    A->push(5);
    Stack<int> *B = A;
    std::cout << B->size() << std::endl;
    std::cout << B->top();
}