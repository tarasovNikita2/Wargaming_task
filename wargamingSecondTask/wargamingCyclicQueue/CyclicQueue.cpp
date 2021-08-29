#include <iostream>

/*(Циклический буфер на С++ реализующий Очередь, с адаптивным количеством элементов,
плюсом которого является возможность хранения большого количества данных, с другой стороны мы жертвуем памятью.
Очередь является довольно популярной структурой данных, которая используется в различных сферах программирования.
Например, я сталкивался с необходимостью использования этой структуры данных, в курсовой работе при моделировании
работы марского порта, так же предоставлена строгая гарантия безопасности)*/

template<typename T>
class CyclicQueue
{
public:
    CyclicQueue(std::size_t size);
    CyclicQueue(const CyclicQueue& cyclicQueue);
    CyclicQueue(CyclicQueue&& cyclicQueue) noexcept;
    ~CyclicQueue();

    void Push(const T& value);
    T& Pop();
    T& First() const;
    int getSize() const;
    int elementsCount() const;
    int getReadIndex() const;
    int getWriteIndex() const;
    bool isFull() const;
    bool isEmpty() const;

    CyclicQueue& operator =(const CyclicQueue& cyclicQueue);
    CyclicQueue& operator =(CyclicQueue&& cyclicQueue) noexcept;

private:

    T* buffer_;
    int readIndex_;
    int writeIndex_;
    std::size_t size_;
    int elementsCount_;
};

template<typename T>
CyclicQueue<T>::CyclicQueue(std::size_t size):
        buffer_(new T[size]),
        readIndex_(0),
        writeIndex_(0),
        size_(size),
        elementsCount_(0)
{}

template<typename T>
CyclicQueue<T>::CyclicQueue(const CyclicQueue& cyclicQueue)
{
    buffer_ = new T[cyclicQueue.size_];
    readIndex_ = cyclicQueue.readIndex_;
    writeIndex_ = cyclicQueue.writeIndex_;
    size_ = cyclicQueue.size_;
    elementsCount_ = cyclicQueue.elementsCount_;

    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = cyclicQueue.buffer_[i];
    }
}

template<typename T>
CyclicQueue<T>::CyclicQueue(CyclicQueue&& cyclicQueue) noexcept:
        buffer_(cyclicQueue.buffer_),
        readIndex_(cyclicQueue.readIndex_),
        writeIndex_(cyclicQueue.writeIndex_),
        size_(cyclicQueue.size_),
        elementsCount_(cyclicQueue.elementsCount_)
{
    cyclicQueue.buffer_ = nullptr;
}

template<typename T>
CyclicQueue<T>::~CyclicQueue()
{
    delete[] buffer_;
}

template<typename T>
void CyclicQueue<T>::Push(const T& value)
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
        writeIndex_++;
        buffer_ = new_buffer;
        size_ = new_size;
    }
    else
    {
        writeIndex_ = writeIndex_ % size_;
        buffer_[writeIndex_++] = value;
        elementsCount_++;
    }
}

template<typename T>
T& CyclicQueue<T>::Pop()
{
    if (isEmpty())
    {
        throw std::logic_error("cyclicQueue is already Empty");
    }
    else
    {
        elementsCount_--;
        readIndex_ = readIndex_ % size_;
        return buffer_[readIndex_++];
    }
}

template<typename T>
T& CyclicQueue<T>::First() const
{
    if (isEmpty())
    {
        throw std::logic_error("cyclicQueue is already Empty");
    }
    else
    {
        return buffer_[readIndex_];
    }
}

template<typename T>
int CyclicQueue<T>::getSize() const
{
    return size_;
}

template<typename T>
int CyclicQueue<T>::getReadIndex() const
{
    return readIndex_;
}

template<typename T>
int CyclicQueue<T>::getWriteIndex() const
{
    return writeIndex_;
}

template<typename T>
bool CyclicQueue<T>::isFull() const
{
    return (elementsCount_ == size_);
}

template<typename T>
bool CyclicQueue<T>::isEmpty() const
{
    return (elementsCount_ == 0);
}

template<typename T>
CyclicQueue<T>& CyclicQueue<T>::operator=(const CyclicQueue& cyclicQueue)
{
    if(cyclicQueue != this) {
        delete[] buffer_;
        size_ = cyclicQueue.size_;
        writeIndex_ = cyclicQueue.writeIndex_;
        readIndex_ = cyclicQueue.readIndex_;
        buffer_ = new T[size_];
        elementsCount_ = cyclicQueue.elementsCount_;
        for (int i = 0; i < size_; i++) {
            buffer_[i] = cyclicQueue.buffer_[i];
        }
    }
    return* this;
}

template<typename T>
CyclicQueue<T>& CyclicQueue<T>::operator=(CyclicQueue&& cyclicQueue) noexcept
{
    delete[] buffer_;
    buffer_ = cyclicQueue.buffer_;
    readIndex_ = cyclicQueue.readIndex_;
    writeIndex_ = cyclicQueue.writeIndex_;
    size_ = cyclicQueue.size_;
    elementsCount_ = cyclicQueue.elementsCount_;
    cyclicQueue.buffer_ = nullptr;

    return *this;
}

template<typename T>
int CyclicQueue<T>::elementsCount() const
{
    return elementsCount_;
}
