#include <iostream>

template <typename T>
class DynamicList
{
private:
    T* _arr;
    int _size;
    int _maxsize;

public:
    DynamicList(int size)
    {
        _arr = new T[size];
        _size = 0;
        _maxsize = size;
    }

    ~DynamicList()
    {
        delete[] _arr;
        _arr = NULL;
    }

    void add(T& newEntry);
    void print();
};

template <typename T>
void DynamicList<T>::add(T& newEntry)
{
    if(_size+1 == _maxsize) {
        _maxsize = 2*_maxsize;
        T* temp = new T[_maxsize];

        for(int i = 0; i < _size; i++) {
            temp[i] = _arr[i];
        }

        delete [] _arr;
        _arr = temp;
    }

    _arr[_size] = newEntry;
    _size++;
}

template <typename T>
void DynamicList<T>::print()
{
    for(int i = 0; i < _size; i++)
    {
        std::cout<<_arr[i]<<" ";
    }

    std::cout<<std::endl;
}
