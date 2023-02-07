#ifndef CONTAINERS_CPP_VECTOR_H
#define CONTAINERS_CPP_VECTOR_H

#include <cstdio>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <utility>

namespace s21 {

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

        void ReallocVec(size_type new_capacity_) {
            iterator tmp = new value_type[new_capacity_];
            for (size_type i = 0; i < size_; ++i)
                tmp[i] = std::move(array_[i]);

            delete[] array_;
            array_ = tmp;
            capacity_ = new_capacity_;
        }
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

        vector(std::initializer_list<value_type> const &init) : size_{init.size()}, capacity_{init.size()}, array_{new value_type[capacity_]} {
            std::copy(init.begin(), init.end(), array_);
        }

        vector(const vector &vec) {
            size_ = vec.size_;
            capacity_ = vec.capacity_;
            array_ = nullptr;
            if (size_) {
                array_ = new value_type[capacity_];
            }
            std::copy(vec.begin(), vec.end(), array_);
        }

        vector(vector &&vec) noexcept {
            size_ = std::exchange(vec.size_, 0);
            capacity_ = std::exchange(vec.capacity_, 0);
            array_ = std::exchange(vec.array_, nullptr);
        }

        ~vector() {
            delete[] array_;
        }

        constexpr vector &operator=(vector &&vec) noexcept {
            if (this != &vec) {
                size_ = std::exchange(vec.size_, 0);
                capacity_ = std::exchange(vec.capacity_, 0);
                array_ = std::exchange(vec.array_, nullptr);
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
            return array_;
        }

        constexpr const_iterator begin() const noexcept {
            return array_;
        }

        constexpr iterator end() noexcept {
            return array_ + size_;
        }

        constexpr const_iterator end() const noexcept {
            return array_ + size_;
        }

        constexpr reference at(size_type pos) {
            if (pos >= size_)
                throw std::out_of_range(
                        "s21::vector::at The index is out of range");

            return array_[pos];
        }

        constexpr const_reference at(size_type pos) const {
            if (pos >= size_)
                throw std::out_of_range(
                        "s21::vector::at The index is out of range");

            return array_[pos];
        }

        constexpr reference operator[](size_type pos) {
            return at(pos);
        }

        constexpr const_reference operator[](size_type pos) const {
            return at(pos);
        }
        constexpr reference front() {
            if (!size_)
                throw std::out_of_range("s21::vector::front Using methods on a "
                                        "zero sized container results ");

            return *begin();
        }

        constexpr const_reference front() const{
            if (!size_)
                throw std::out_of_range("s21::vector::front Using methods on a "
                                        "zero sized container results ");

            return *begin();
        }

        constexpr reference back() {
            if (!size_)
                throw std::out_of_range("s21::vector::back Using methods on a "
                                        "zero sized container results ");

            return *std::prev(end());
        }

        constexpr const_reference back() const{
            if (!size_)
                throw std::out_of_range("s21::vector::back Using methods on a "
                                        "zero sized container results ");

            return *std::prev(end());
        }

        constexpr iterator data() noexcept {
            return array_;
        }

        constexpr const_iterator data() const noexcept {
            return array_;
        }

        [[nodiscard]] bool empty() const noexcept {
            return begin() == end();
        }

        [[nodiscard]] constexpr size_type size() const noexcept {
            return std::distance(begin(), end());
        }

        [[nodiscard]] constexpr size_type max_size() const noexcept {
            return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
        }

        constexpr void reserve(size_type new_capacity_) {
            if (new_capacity_ <= capacity_)
                return;

            if (new_capacity_ > max_size())
                throw std::length_error(
                        "s21::vector::reserve Reserve capacity can't be larger than "
                        "Vector<T>::max_size()");

            ReallocVec(new_capacity_);
        }

        constexpr size_type capacity() const noexcept {
            return capacity_;
        }

        constexpr void shrink_to_fit() {
            if (capacity_ == size_)
                return;

            ReallocVec(size_);
        }

        constexpr void clear() noexcept {
            size_ = 0;
        }

        constexpr iterator insert(const_iterator pos, value_type &&value) {
            size_type tmp = pos - begin();
            if (tmp > size_)
                throw std::out_of_range(
                        "s21::vector::insert Unable to insert into a position out of "
                        "range of begin() to end()");

            if (size_ == capacity_) {
                if (size_) {
                    ReallocVec(size_ * 2);
                } else {
                    ReallocVec(1);
                }
            }
            std::copy(begin() + tmp, end(), begin() + tmp + 1);
            *(array_ + tmp) = std::move(value);

            ++size_;
            return begin() + tmp;
        }

        constexpr iterator insert(const_iterator pos, const_reference value) {
            size_type tmp = pos - begin();
            if (tmp > size_)
                throw std::out_of_range(
                        "s21::vector::insert Unable to insert into a position out of "
                        "range of begin() to end()");

            if (size_ == capacity) {
                if (size_) {
                    ReallocVec(size_ * 2);
                } else {
                    ReallocVec(1);
                }
            }
            std::copy(begin() + tmp, end(), begin() + tmp + 1);
            *(array_ + tmp) = value;

            ++size_;
            return begin() + tmp;
        }

        constexpr iterator erase(iterator pos) {
            size_type tmp = pos - begin();
            if (tmp >= size_)
                throw std::out_of_range(
                        "s21::vector::erase Unable to erase a position out of range of "
                        "begin() to end()");

            std::copy(begin(), pos, array_);
            std::copy(pos + 1, end(), array_ + tmp);

            --size_;
            return begin() + tmp;
        }

        constexpr void push_back(const_reference value) {
            if (size_ == capacity_) {
                if (size_) {
                    reserve(size_ * 2);
                } else {
                    reserve(1);
                }
            }
            array_[size_] = std::move(value);
            ++size_;
        }

        constexpr void push_back(value_type &&value) {
            if (size_ == capacity_) {
                if (size_) {
                    reserve(size_ * 2);
                } else {
                    reserve(1);
                }
            }
            array_[size_] = std::move(value);
            ++size_;
        }

        constexpr void pop_back() {
            if (size_ == 0)
                throw std::length_error(
                        "s21::vector::pop_back Calling pop_back on an empty container");
            --size_;
        }

        constexpr void swap(vector &other) noexcept {
            std::swap(array_, other.array_);
            std::swap(size_, other.size_);
            std::swap(capacity_, other.capacity_);
        }

    };

}

#endif //CONTAINERS_CPP_VECTOR_H