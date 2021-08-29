#include <iostream>

/*(Циклический буфер на С++ реализующий очередь с фиксированным количеством элементов,
с перезаписью, плюсом которого является способность хранить последние данные, отбрасывая старые
(например по этой логике работает кэш), так же предоставлена строгая гарантия безопасности)*/

template<typename T>
class LimitedQueue
{
public:
    explicit LimitedQueue(std::size_t size);
    LimitedQueue(const LimitedQueue& limitedQueue);
    LimitedQueue(LimitedQueue&& limitedQueue) noexcept;
    ~LimitedQueue();

    void Push(const T& value);
    T& Pop();
    T& First() const;
    int getSize() const;
    int getReadIndex() const;
    int getWriteIndex() const;
    bool isFull() const;
    bool isEmpty() const;

    LimitedQueue& operator =(const LimitedQueue& limitedQueue);
    LimitedQueue& operator =(LimitedQueue&& limitedQueue) noexcept;

private:

    T* buffer_;
    int readIndex_;
    int writeIndex_;
    std::size_t size_;
    bool full_;
};

template<typename T>
LimitedQueue<T>::LimitedQueue(std::size_t size) :
        buffer_(new T[size]),
        readIndex_(0),
        writeIndex_(0),
        size_(size),
        full_(false)
{}

template<typename T>
LimitedQueue<T>::LimitedQueue(const LimitedQueue& limitedQueue)
{
    buffer_ = new T[limitedQueue.size_];
    readIndex_ = limitedQueue.readIndex_;
    writeIndex_ = limitedQueue.writeIndex_;
    size_ = limitedQueue.size_;
    full_ = limitedQueue.full_;

    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = limitedQueue.buffer_[i];
    }
}

template<typename T>
LimitedQueue<T>::LimitedQueue(LimitedQueue&& limitedQueue) noexcept :
        buffer_(limitedQueue.buffer_),
        readIndex_(limitedQueue.readIndex_),
        writeIndex_(limitedQueue.writeIndex_),
        size_(limitedQueue.size_),
        full_(limitedQueue.full_)
{
    limitedQueue.buffer_ = nullptr;
}

template<typename T>
LimitedQueue<T>::~LimitedQueue()
{
    delete[] buffer_;
}

template<typename T>
void LimitedQueue<T>::Push(const T& value)
{
    writeIndex_ = writeIndex_ % size_;
    buffer_[writeIndex_] = value;
    if (full_)
    {
        readIndex_++;
    }
    if (++writeIndex_ == size_)
    {
        full_ = true;
    }
}

template<typename T>
T& LimitedQueue<T>::Pop()
{
    if (isEmpty())
    {
        throw std::logic_error("LimitedQueue is already Empty");
    }
    else
    {
        readIndex_ = readIndex_ % size_;
        full_ = false;
        return buffer_[readIndex_++];
    }
}

template<typename T>
T& LimitedQueue<T>::First() const
{
    if (isEmpty())
    {
        throw std::logic_error("LimitedQueue is already Empty");
    }
    else
    {
        return buffer_[readIndex_];
    }
}

template<typename T>
int LimitedQueue<T>::getSize() const
{
    return size_;
}

template<typename T>
int LimitedQueue<T>::getReadIndex() const
{
    return readIndex_;
}

template<typename T>
int LimitedQueue<T>::getWriteIndex() const
{
    return writeIndex_;
}

template<typename T>
bool LimitedQueue<T>::isFull() const
{
    return full_;
}

template<typename T>
bool LimitedQueue<T>::isEmpty() const
{
    return (readIndex_ == writeIndex_ && !full_);
}

template<typename T>
LimitedQueue<T>& LimitedQueue<T>::operator=(const LimitedQueue& limitedQueue)
{
    delete[] buffer_;
    size_ = limitedQueue.size_;
    writeIndex_ = limitedQueue.writeIndex_;
    readIndex_ = limitedQueue.readIndex_;
    buffer_ = new T[size_];

    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = limitedQueue.buffer_[i];
    }
    return*this;
}

template<typename T>
LimitedQueue<T>& LimitedQueue<T>::operator=(LimitedQueue&& limitedQueue) noexcept
{
    delete[] buffer_;
    buffer_ = limitedQueue.buffer_;
    readIndex_ = limitedQueue.readIndex_;
    writeIndex_ = limitedQueue.writeIndex_;
    size_ = limitedQueue.size_;
    limitedQueue.buffer_ = nullptr;

    return *this;
}
