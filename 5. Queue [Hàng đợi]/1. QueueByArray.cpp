#include <iostream>

template <typename T>
class Queue
{
public:
    Queue();
    Queue(int Capacity);
    Queue(const Queue<T> &other);
    ~Queue();
    T front();
    T back();
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
Queue<T>::Queue()
{
    this->mArray = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
Queue<T>::Queue(int Capacity)
{
    this->mCapacity = Capacity;
    this->mArray = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &other)
{
    if (this != other)
    {
        this->~Queue();
        this->mCapacity = other->mCapacity;
        this->mSize = other->mSize;
        this->mArray = other->mArray;
    }
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] this->mArray;
    delete this->mSize;
    delete this->mCapacity;
}

template <typename T>
T Queue<T>::front()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Queue is empty!\n");
    }
    return this->mArray[0];
}

template <typename T>
T Queue<T>::back()
{
    if (this->empty())
    {
        throw std::logic_error("[ERROR] Queue is empty!\n");
    }
    return this->mArray[this->mSize - 1];
}

template <typename T>
int Queue<T>::size() const
{
    return this->mSize;
}

template <typename T>
bool Queue<T>::empty() const
{
    return this->mSize == 0;
}

template <typename T>
void Queue<T>::push(T value)
{
    if (this->full())
    {
        throw std::logic_error("[ERROR] Queue is full, can't insert any element");
    }
    this->mArray[this->mSize] = value;
    this->mSize++;
}

template <typename T>
void Queue<T>::pop()
{
    for (int i = 0; i < this->mSize; i++)
    {
        this->mArray[i] = this->mArray[i + 1];
    }
    this->mSize--;
}

template <typename T>
bool Queue<T>::full() const
{
    return this->mSize == this->mCapacity;
}

int main()
{
    Queue<int> *A = new Queue<int>();
    A->push(4);
    A->push(5);
    A->push(6);
    A->push(7);
    Queue<int> *B = A;
    while (!B->empty())
    {
        std::cout << B->front() << ' ';
        B->pop();
    }
}