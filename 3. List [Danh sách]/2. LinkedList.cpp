#include <iostream>

template <typename T>
class linkedList
{
public:
    struct Node
    {
        Node(T Info, Node *nextPtr);
        friend std::ostream &operator<<(std::ostream os, Node &node)
        {
            os << node.mInfo;
            return os;
        }
        T mInfo;
        Node *nextPtr;
    };

public:
    linkedList();
    linkedList(const linkedList<T> &other);
    ~linkedList();
    int size() const;
    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    bool empty() const;
    Node *begin();
    Node *end();
    T at(int index);

private:
    size_t mSize;
    Node *mfirstNode;
};

template <typename T>
linkedList<T>::Node::Node(T Info, Node *nextPtr)
{
    this->mInfo = Info;
    this->nextPtr = nextPtr;
}

template <typename T>
linkedList<T>::linkedList()
{
    this->mfirstNode = nullptr;
    this->mSize = 0;
}

template <typename T>
linkedList<T>::linkedList(const linkedList<T> &other)
{
    if (this != other)
    {
        this->mfirstNode = nullptr;
        this->mSize = 0;
        linkedList<T>::Node *currentPtr = other.mfirstNode;
        while (currentPtr != nullptr)
        {
            this->push_back(currentPtr);
            currentPtr = currentPtr->nextPtr;
        }
    }
}

template <typename T>
linkedList<T>::~linkedList()
{
    Node *currentNode = this->mfirstNode;
    while (currentNode != nullptr)
    {
        Node *deleteNode = currentNode;
        currentNode = currentNode->nextPtr;
        delete deleteNode;
    }
}

template <typename T>
int linkedList<T>::size() const
{
    return this->mSize;
}

template <typename T>
void linkedList<T>::push_back(T value)
{
    if (this->mfirstNode == nullptr)
    {
        this->push_front(value);
        return;
    }
    this->mSize++;
    Node *newNode = new Node(value, nullptr);
    Node *lastNode = this->mfirstNode;
    while (lastNode->nextPtr != nullptr)
        lastNode = lastNode->nextPtr;
    lastNode->nextPtr = newNode;
}

template <typename T>
void linkedList<T>::push_front(T value)
{
    Node *newNode = new Node(value, this->mfirstNode);
    this->mfirstNode = newNode;
    this->mSize++;
}

template <typename T>
void linkedList<T>::pop_back()
{
    if (this->empty())
        throw std::logic_error("[ERROR] List is empty, can't remove any element!\n");
    if (this->mfirstNode->nextPtr == nullptr)
    {
        this->pop_front();
        return;
    }
    this->mSize--;
    Node *lastNode = this->mfirstNode;
    while (lastNode->nextPtr->nextPtr != nullptr)
        lastNode = lastNode->nextPtr;
    Node *deleteNode = lastNode->nextPtr;
    delete deleteNode;
}

template <typename T>
void linkedList<T>::pop_front()
{
    if (this->empty())
        throw std::logic_error("[ERROR] List is empty, can't remove any element!\n");
    this->mSize--;
    Node *deleteNode = this->mfirstNode;
    this->mfirstNode = this->mfirstNode->nextPtr;
    delete deleteNode;
}

template <typename T>
bool linkedList<T>::empty() const
{
    return this->mfirstNode == nullptr;
}

template <typename T>
typename linkedList<T>::Node *linkedList<T>::begin()
{
    if (this->empty())
        return nullptr;
    return this->mfirstNode;
}

template <typename T>
typename linkedList<T>::Node *linkedList<T>::end()
{
    if (this->empty())
        return nullptr;
    Node *lastNode = this->mfirstNode;
    while (lastNode->nextPtr != nullptr)
        lastNode = lastNode->nextPtr;
    return lastNode;
}

template <typename T>
T linkedList<T>::at(int index)
{
    if (index < 0 || index >= this->mSize)
        throw std::logic_error("[ERROR] Out of range!\n");
    Node *targetNode = this->mfirstNode;
    for (int i = 0; i < index; i++)
        if (targetNode != nullptr)
            targetNode = targetNode->nextPtr;
    return targetNode->mInfo;
}

int main()
{
    linkedList<int> *A = new linkedList<int>();
    A->push_back(4);
    A->push_back(5);
    A->push_back(44);
    A->push_back(12);
    A->push_back(32);
    A->push_back(49);
    A->push_back(6); // 4 5 44 12 32 49 6
    A->pop_back();   // 4 5 44 12 32 49
    A->pop_front();  // 5 44 12 32 49
    for (int i = 0; i < A->size(); i++)
    {
        std::cout << A->at(i) << ' ';
    }
}
