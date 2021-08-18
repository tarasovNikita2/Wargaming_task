/*(Циклический буфер на С++ с фиксированным количеством элементов,
без перезаписи, плюсом которого является безопасность уже записанных
данных, так же предоставлена строгая гарантия безопастности)*/

template<typename T>
class Fifo
{
public:
    Fifo(std::size_t size);
    Fifo(const Fifo& fifo);
    Fifo(Fifo&& fifo) noexcept;
    ~Fifo();

    void Push(const T& value);
    T& Pop();
    T& First() const;
    int getSize() const;
    int getReadIndex() const;
    int getWriteIndex() const;
    bool isFull() const;
    bool isEmpty() const;

    Fifo& operator =(const Fifo& fifo);
    Fifo& operator =(Fifo&& fifo) noexcept;

private:

    T* buffer_;
    int readIndex_;
    int writeIndex_;
    int size_;
};

template<typename T>
Fifo<T>::Fifo(std::size_t size):
    buffer_(new T[size]),
    readIndex_(0),
    writeIndex_(0),
    size_(size)
{}

template<typename T>
Fifo<T>::Fifo(const Fifo& fifo)
{
    buffer_ = new T[fifo.size_];
    readIndex_ = fifo.readIndex_;
    writeIndex_ = fifo.writeIndex_;
    size_ = fifo.size_;

    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = fifo.buffer_[i];
    }
}

template<typename T>
Fifo<T>::Fifo(Fifo&& fifo) noexcept:
    buffer_(fifo.buffer_),
    readIndex_(fifo.readIndex_),
    writeIndex_(fifo.writeIndex_),
    size_(fifo.size_)
{
    fifo.buffer_ = nullptr;
}

template<typename T>
Fifo<T>::~Fifo()
{
    delete[] buffer_;
}

template<typename T>
void Fifo<T>::Push(const T& value)
{
    if (isFull())
    {
        throw std::logic_error("Fifo is already Full");
    }
    else
    {
        writeIndex_ = writeIndex_ % size_;
        buffer_[writeIndex_++] = value;
    }
}

template<typename T>
T& Fifo<T>::Pop()
{
    if (isEmpty())
    {
        throw std::logic_error("Fifo is already Empty");
    }
    else
    {
        readIndex_ = readIndex_ % size_;
        return buffer_[readIndex_++];      
    }
}

template<typename T>
T& Fifo<T>::First() const
{
    if (isEmpty())
    {
        throw std::logic_error("Fifo is already Empty");
    }
    else
    {
        return buffer_[readIndex_];
    }
}

template<typename T>
int Fifo<T>::getSize() const
{
    return size_;
}

template<typename T>
int Fifo<T>::getReadIndex() const
{
    return readIndex_;
}

template<typename T>
int Fifo<T>::getWriteIndex() const
{
    return writeIndex_;
}

template<typename T>
bool Fifo<T>::isFull() const
{
    return (readIndex_ + size_ == writeIndex_) ? true : false;;
}

template<typename T>
bool Fifo<T>::isEmpty() const
{
    return (readIndex_ == writeIndex_)? true: false;
}

template<typename T>
Fifo<T>& Fifo<T>::operator=(const Fifo& fifo)
{
    delete[] buffer_;
    size_ = fifo.size_;
    writeIndex_ = fifo.writeIndex_;
    readIndex_ = fifo.readIndex_;
    buffer_ = new T[size_];
    for (int i = 0; i < size_; i++)
    {
        buffer_[i] = fifo.buffer_[i];
    }
    return* this;
}

template<typename T>
Fifo<T>& Fifo<T>::operator=(Fifo&& fifo) noexcept
{
    delete[] buffer_;
    buffer_ = fifo.buffer_;
    readIndex_ = fifo.readIndex_;
    writeIndex_ = fifo.writeIndex_;
    size_ = fifo.size_;
    fifo.buffer_ = nullptr;

    return *this;
} 