#ifndef DS_VECTOR_HPP
#define DS_VECTOR_HPP

#include <cstddef>
#include <stdexcept>

namespace ds {

template <typename T>
class Vector {
   public:
    // Constructor
    Vector() : size_(0u), capacity_(1u), data_(new T[capacity_]) {}

    // Destructor
    ~Vector() { delete[] data_; }

    // Copy constructor
    Vector(const Vector<T>& other)
        : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (std::size_t i = 0u; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Move constructor
    Vector(Vector<T>&& other) noexcept
        : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            for (std::size_t i = 0u; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = other.data_;
            other.size_ = 0;
            other.capacity_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    // Returns the number of elements in the vector
    std::size_t Size() const { return size_; }

    // Returns the current capacity of the vector
    std::size_t Capacity() const { return capacity_; }

    // Return true if the vector is empty
    bool Empty() const { return size_ == 0u; }

    // Increases the capacity of the vector
    void Reserve(const std::size_t& new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }
        T* new_data = new T[new_capacity];
        for (std::size_t i = 0u; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    // Clear the vector
    void Clear() { size_ = 0u; }

    // Push back an element to the end of the vector
    void PushBack(const T& value) {
        if (size_ == capacity_) {
            Reserve(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    // Removes an element from the back
    void PopBack() {
        if (!Empty()) {
            --size_;
        }
    }

    // Returns the reference of the element at the index idx
    T& At(const std::size_t& idx) {
        if (idx >= size_) {
            throw std::out_of_range("Index " + std::to_string(idx) +
                                    " is out of range.");
        }
        return data_[idx];
    }

    // Returns the reference of the element at the back
    T& Back() {
        if (Empty()) {
            throw std::out_of_range("Vector is empty.");
        }
        return data_[size_ - 1u];
    }

    // Returns the reference of the element at the front
    T& Front() {
        if (Empty()) {
            throw std::out_of_range("Vector is empty.");
        }
        return data_[0u];
    }

    // Returns the reference of the element at the index idx
    T& operator[](const std::size_t& idx) {
        if (idx >= size_) {
            throw std::out_of_range("Index " + std::to_string(idx) +
                                    " is out of range.");
        }
        return data_[idx];
    }

    // Operator overloading for equality
    bool operator==(const Vector<T>& other) const {
        if (size_ != other.size_) return false;
        for (std::size_t i = 0u; i < size_; ++i) {
            if (data_[i] != other.data_[i]) return false;
        }
        return true;
    }

   private:
    // Size of the vector
    std::size_t size_;

    // Capacity of the vector
    std::size_t capacity_;

    // Data of the vector
    T* data_;
};

}  // namespace ds

#endif  // DS_VECTOR_HPP
