#include <iostream>

template <typename T>
class Stack
{
public:
    Stack();
    Stack(int Capacity);
    Stack(const Stack<T> &other);
    ~Stack();
    T top();
    int size() const;
    bool empty() const;
    bool full() const;
    void push(T value);
    void pop();

private:
    T *mArray;
    size_t mSize;
    int mCapacity = INT32_MAX;
};

template <typename T>
Stack<T>::Stack()
{
    this->mArray = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
Stack<T>::Stack(int Capacity)
{
    this->mCapacity = Capacity;
    this->mArray = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    if (this != other)
    {
        this->~Stack();
        this->mCapacity = other->mCapacity;
        this->mSize = other->mSize;
        this->mArray = other->mArray;
    }
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] this->mArray;
    delete this->mSize;
    delete this->mCapacity;
}

template <typename T>
T Stack<T>::top()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Stack is empty!\n");
    }
    return this->mArray[this->mSize - 1];
}

template <typename T>
int Stack<T>::size() const
{
    return this->mSize;
}

template <typename T>
bool Stack<T>::empty() const
{
    return this->mSize == 0;
}

template <typename T>
void Stack<T>::push(T value)
{
    if (this->full())
    {
        throw std::logic_error("[ERROR] Stack is full, can't insert any element");
    }
    this->mArray[this->mSize] = value;
    this->mSize++;
}

template <typename T>
void Stack<T>::pop()
{
    this->mSize--;
}

template <typename T>
bool Stack<T>::full() const
{
    return this->mSize == this->mCapacity;
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