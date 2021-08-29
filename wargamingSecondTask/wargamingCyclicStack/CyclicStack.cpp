#include <iostream>

/*(Циклический буфер реализующий Stack (Lifo) на С++ с адаптивным количеством элементов,
 плюсом которого является возможность хранения большого количества данных, с другой стороны мы жертвуем памятью.
 Обычно стек используют для эффективной работы с другими типами данных, деревьями и графами
 так же предоставлена строгая гарантия безопасности)*/

template<typename T>
class CyclicStack
{
public:
    CyclicStack(std::size_t size);
    CyclicStack(const CyclicStack& cyclicStack);
    CyclicStack(CyclicStack&& cyclicStack) noexcept;
    ~CyclicStack();

    void Push(const T& value);
    T& Pop();
    T& First() const;
    int getSize() const;
    int elementsCount() const;
    int getReadIndex() const;
    int getWriteIndex() const;
    bool isFull() const;
    bool isEmpty() const;

    CyclicStack& operator =(const CyclicStack& cyclicStack);
    CyclicStack& operator =(CyclicStack&& cyclicStack) noexcept;

private:

    T* buffer_;
    int index_;
    std::size_t size_;
    int elementsCount_;
};

template<typename T>
CyclicStack<T>::CyclicStack(std::size_t size):
        buffer_(new T[size]),
        index_(0),
        size_(size),
        elementsCount_(0)
{}

template<typename T>
CyclicStack<T>::CyclicStack(const CyclicStack& cyclicStack)
{
    buffer_ = new T[cyclicStack.size_];
    index_ = cyclicStack.index_;
    size_ = cyclicStack.size_;
    elementsCount_ = cyclicStack.elementsCount_;

    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = cyclicStack.buffer_[i];
    }
}

template<typename T>
CyclicStack<T>::CyclicStack(CyclicStack&& cyclicStack) noexcept:
        buffer_(cyclicStack.buffer_),
        index_(cyclicStack.index_),
        size_(cyclicStack.size_),
        elementsCount_(cyclicStack.elementsCount_)
{
    cyclicStack.buffer_ = nullptr;
}

template<typename T>
CyclicStack<T>::~CyclicStack()
{
    delete[] buffer_;
}

template<typename T>
void CyclicStack<T>::Push(const T& value)
{
    if (isFull())
    {
        std::size_t new_size = size_*2+1;
        T* new_buffer = new T [new_size];

        for (int i = 0; i < size_; ++i)
        {
            new_buffer[i] = buffer_[i];
        }

        new_buffer[size_] = value;
        elementsCount_++;
        index_++;

        delete[] buffer_;
        buffer_ = new_buffer;
        size_ = new_size;
    }
    else
    {
        index_ = index_ % size_;
        buffer_[index_++] = value;
        elementsCount_++;
    }
}

template<typename T>
T& CyclicStack<T>::Pop()
{
    if (isEmpty())
    {
        throw std::logic_error("cyclicStack is already Empty");
    }
    else
    {
        elementsCount_--;
        index_ = index_ % size_;
        return buffer_[--index_];
    }
}

template<typename T>
T& CyclicStack<T>::First() const
{
    if (isEmpty())
    {
        throw std::logic_error("cyclicStack is already Empty");
    }
    else
    {
        return buffer_[index_];
    }
}

template<typename T>
int CyclicStack<T>::getSize() const
{
    return size_;
}

template<typename T>
int CyclicStack<T>::getReadIndex() const
{
    return index_;
}

template<typename T>
int CyclicStack<T>::getWriteIndex() const
{
    return index_;
}

template<typename T>
bool CyclicStack<T>::isFull() const
{
    return (elementsCount_ == size_);
}

template<typename T>
bool CyclicStack<T>::isEmpty() const
{
    return (elementsCount_ == 0);
}

template<typename T>
CyclicStack<T>& CyclicStack<T>::operator=(const CyclicStack& cyclicStack)
{
    if(cyclicStack != this) {
        delete[] buffer_;
        size_ = cyclicStack.size_;
        index_ = cyclicStack.index_;
        buffer_ = new T[size_];
        elementsCount_ = cyclicStack.elementsCount_;
        for (int i = 0; i < size_; i++) {
            buffer_[i] = cyclicStack.buffer_[i];
        }
    }
    return* this;
}

template<typename T>
CyclicStack<T>& CyclicStack<T>::operator=(CyclicStack&& cyclicStack) noexcept
{
    delete[] buffer_;
    buffer_ = cyclicStack.buffer_;
    index_ = cyclicStack.index_;
    size_ = cyclicStack.size_;
    elementsCount_ = cyclicStack.elementsCount_;
    cyclicStack.buffer_ = nullptr;

    return *this;
}

template<typename T>
int CyclicStack<T>::elementsCount() const
{
    return elementsCount_;
}