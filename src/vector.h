#ifndef CONTAINERS_CPP_VECTOR_H
#define CONTAINERS_CPP_VECTOR_H

#include <cstdio>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <stdexcept>

using namespace s21 {

    template <class T>
    class vector {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = std::size_t;

    private:
        size_type size_ = 0;
        size_type capacity_ = 0;
        iterator array_ = nullptr;
    public:
        vector() {}

        explicit vector(size_type size) {
            size_ = size;
            capacity_ = size;
            array_ = nullptr;
            if (size) {
                array_ = new value_type[capacity_];
            }
        }

        explicit vector(std::initializer_list<value_type> const &init) : size_{init.size()}, capacity_{init.size()}, array_{new value_type[capacity_]} {
            srd::copy(init.begin(), init.end(), array_);
        }

        vector(const vector &vec) {
            size_ = vec.size_;
            capacity_ = vec.capacity_;
            bufer_ = nullptr;
            if (size_) {
                array_ = new value_type[capacity_];
            }
            std::copy(vec.begin(), vec.end(), array_);
        }

        vector(vector &&vec) noexept {
            size_ = std
        }

        vector(vector &&vec) noexcept {
            size_ = std::exchange(vec.size_, 0);
            capacity_ = std::exchange(vec.capacity_, 0);
            array_ = std::move(rhs.array_);
        }

        ~vector() {
            delete[] array_;
        }

        constexpr vector &operator=(vector &&vec) noexcept {
            if (this != &vec) {
                size_ = std::exchange(vec.size_, 0);
                capacity_ = std::exchange(vec.capacity_, 0);
                array_ = std::move(vec.array_);
            }
            return *this;
        }

        constexpr vector &operator=(const vector &vec) {
            if (this != &vec) {
                delete[] array_;

                if (vec.size_) {
                    array_ = new value_type[vec.capacity_];
                    std::copy(vec.begin(), vec.end(), array_);
                }
                size_ = vec.size_;
                capacity_ = vec.capacity_;
            }
            return *this;
        }

        constexpr iterator begin() noexcept {
            return buffer_;
        }

        constexpr const_iterator begin() const noexcept {
            return buffer_;
        }

        constexpr iterator end() noexcept {
            return buffer_ + size_;
        }

        constexpr const_iterator end() const noexcept {
            return buffer_ + size_;
        }
    };

}

#endif //CONTAINERS_CPP_VECTOR_H