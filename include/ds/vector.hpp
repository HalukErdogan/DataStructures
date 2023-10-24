#ifndef DS_VECTOR_HPP
#define DS_VECTOR_HPP

#include <cstddef>

namespace ds {
    
template<typename T>
class Vector {
public:
    // Constructor
    Vector();

    // Destructor
    ~Vector();

    // Copy constructor
    Vector(const Vector<T> &other);
    
    // Copy assignment operator
    Vector& operator=(const Vector &other);

    // Returns the number of elements in the vector
    size_t Size() const;

    // Returns the current capacity of the vector
    size_t Capacity() const;

    // Return true if the vector is empty
    bool Empty() const;

    // Increases the capacity of the vector
    void Reserve(const size_t &size);

    // Clear the vector
    void Clear();

    // Push back an element to the end of the vector
    void PushBack(const T &obj);

    // Removes an element from the back
    void PopBack();

    // Returns the reference of the element at the index idx
    T& At(const size_t &idx);

    // Returns the reference of the element at the back
    T& Back() ;

    // Returns the reference of the element at the front
    T& Front();

    // Operator overloading that returns the reference of the element at the index idxs  
    T& operator[](const size_t &idx);

    // Returns the const reference of the element at index idx 
    const T& At(const size_t &idx) const;

    // Returns the const reference of the element at the back
    const T& Back() const;

    // Returns the const reference of the element at the front
    const T& Front() const;

    // Operator overloading that returns the const reference of the element at the index idxs  
    const T& operator[](const size_t &idx) const;

    // Operator overloading for equality
    bool operator==(const Vector<T> &other) const;

private:
    // Size of the vector
    size_t size_;

    // Capacity of the vector
    size_t capacity_;

    // Data of the vector
    T* data_;
};

} // namespace ds

#endif // DS_VECTOR_HPP