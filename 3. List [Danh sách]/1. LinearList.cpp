#include <iostream>

template <typename T>
class linearList
{
private:
    T *mNodes;
    size_t mSize;
    int mCapacity = INT32_MAX;

public:
    linearList();
    linearList(int capacity);
    linearList(const linearList<T> &other);
    ~linearList();
    int size() const;
    int capacity() const;
    bool empty() const;
    bool full() const;
    void clear() noexcept;
    T at(int index);
    void push_back(int value);
    void push_front(int value);
    void push_at(int index, int value);
    void pop_back();
    void pop_front();
    void pop_at(int index);
    linearList<T> &operator=(const linearList<T> &other);
};

template <typename T>
linearList<T>::linearList()
{
    this->mNodes = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
linearList<T>::linearList(int capacity)
{
    this->mCapacity = capacity;
    this->mNodes = new T[this->mCapacity];
    this->mSize = 0;
}

template <typename T>
linearList<T>::linearList(const linearList<T> &other)
{
    if (this != other)
    {
        delete[] this->mNodes;
        this->mNodes = other->mNodes;
        this->mSize = other->mSize;
        this->mCapacity = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++)
        {
            this->mNodes[i] = other->mNodes[i];
        }
    }
}

template <typename T>
linearList<T>::~linearList()
{
    delete[] this->mNodes;
}

template <typename T>
int linearList<T>::size() const
{
    return this->mSize;
}
template <typename T>
int linearList<T>::capacity() const
{
    return this->mCapacity;
}
template <typename T>
bool linearList<T>::empty() const
{
    return this->mSize == 0;
}
template <typename T>
bool linearList<T>::full() const
{
    return this->mSize >= this->mCapacity;
}
template <typename T>
void linearList<T>::clear() noexcept
{
    std::destroy(this->mNodes, this->mNodes + this->mSize);
    this->mSize = 0;
}
template <typename T>
void linearList<T>::push_back(int value)
{
    if (this->full())
    {
        throw std::overflow_error("[ERROR] List is full, can't insert new element!\n");
    }
    this->mNodes[this->mSize] = value;
    this->mSize++;
}
template <typename T>
void linearList<T>::push_front(int value)
{
    if (this->full())
    {
        throw std::overflow_error("[ERROR] List is full, can't insert new element!\n");
    }
    for (int i = this->mSize; i > 0; i--)
    {
        this->mNodes[i] = this->mNodes[i - 1];
    }
    this->mNodes[0] = value;
    this->mSize++;
}
template <typename T>
void linearList<T>::push_at(int index, int value)
{
    if (this->full())
    {
        throw std::overflow_error("[ERROR] List is full, can't insert new element!\n");
    }
    if (index > this->mSize || index < 0)
    {
        throw std::logic_error("[ERROR] Out of range!\n");
    }
    for (int i = this->mSize; i > index; i--)
    {
        this->mNodes[i] = this->mNodes[i - 1];
    }
    this->mNodes[index] = value;
    this->mSize++;
}
template <typename T>
void linearList<T>::pop_back()
{
    if (this->empty())
    {
        throw std::overflow_error("[ERROR] List is empty, can't remove element!\n");
    }
    this->mSize--;
}
template <typename T>
void linearList<T>::pop_front()
{
    if (this->empty())
    {
        throw std::overflow_error("[ERROR] List is empty, can't remove element!\n");
    }
    for (int i = 0; i < this->mSize; i++)
    {
        this->mNodes[i] = this->mNodes[i + 1];
    }
    this->mSize--;
}
template <typename T>
void linearList<T>::pop_at(int index)
{
    if (this->empty())
    {
        throw std::overflow_error("[ERROR] List is empty, can't remove element!\n");
    }
    for (int i = index; i < this->mSize; i++)
    {
        this->mNodes[i] = this->mNodes[i + 1];
    }
    this->mSize--;
}

template <typename T>
T linearList<T>::at(int index)
{
    if (this->empty())
        throw std::logic_error("[ERROR] Empty list\n");
    if (index >= this->mSize || index < 0)
    {
        throw std::logic_error("[ERROR] Out of range\n");
    }
    return this->mNodes[index];
}

template <typename T>
linearList<T> &linearList<T>::operator=(const linearList<T> &other)
{
    if (this == other)
        return this;
    delete[] this->mNodes;
    this->mNodes = other->mNodes;
    this->mSize = other->mSize;
    this->mCapacity = new T[this->mCapacity];
    for (int i = 0; i < this->mSize; i++)
    {
        this->mNodes[i] = other->mNodes[i];
    }
    return *this;
}

int main()
{
    linearList<int> A;
    std::cout << "Capacity: " << A.capacity() << std::endl;
    A.push_back(5);
    A.push_back(6);
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(6);
    A.push_back(1);
    A.push_back(3);
    // 5 6 1 3 5 6 1 3
    A.pop_at(2);   // 5 6 3 5 6 1 3
    A.pop_back();  // 5 6 3 5 6 1
    A.pop_front(); // 6 3 5 6 1
    std::cout << "size before clear: " << A.size() << std::endl;
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A.at(i) << ' ';
    }
    A.clear();
    std::cout << "\nsize after clear: " << A.size() << std::endl;
}