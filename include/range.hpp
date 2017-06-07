#ifndef _MARRAY_RANGE_HPP_
#define _MARRAY_RANGE_HPP_

#include "utility.hpp"

namespace MArray
{

template <typename T>
class range_t
{
    static_assert(std::is_integral<T>::value, "The type must be integral.");

    protected:
        T from_;
        T to_;
        T delta_;

        typedef T value_type;
        typedef T size_type;

    public:
        class iterator : std::iterator<std::random_access_iterator_tag,T>
        {
            protected:
                T val_;
                T delta_;

            public:
                using typename std::iterator<std::random_access_iterator_tag,T>::iterator_category;
                using typename std::iterator<std::random_access_iterator_tag,T>::value_type;
                using typename std::iterator<std::random_access_iterator_tag,T>::difference_type;
                using typename std::iterator<std::random_access_iterator_tag,T>::pointer;
                using typename std::iterator<std::random_access_iterator_tag,T>::reference;

                constexpr iterator() : val_(0), delta_(0) {}

                constexpr iterator(T val, T delta) : val_(val), delta_(delta) {}

                bool operator==(const iterator& other) const
                {
                    return val_ == other.val_ && delta_ == other.delta_;
                }

                bool operator!=(const iterator& other) const
                {
                    return val_ != other.val_ || delta_ != other.delta_;
                }

                value_type operator*() const
                {
                    return val_;
                }

                iterator& operator++()
                {
                    val_ += delta_;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator old(*this);
                    val_ += delta_;
                    return old;
                }

                iterator& operator--()
                {
                    val_ -= delta_;
                    return *this;
                }

                iterator operator--(int)
                {
                    iterator old(*this);
                    val_ -= delta_;
                    return old;
                }

                iterator& operator+=(difference_type n)
                {
                    val_ += n*delta_;
                    return *this;
                }

                iterator operator+(difference_type n) const
                {
                    return iterator(val_+n*delta_, delta_);
                }

                friend iterator operator+(difference_type n, const iterator& i)
                {
                    return iterator(i.val_+n*i.delta_, i.delta_);
                }

                iterator& operator-=(difference_type n)
                {
                    val_ -= n*delta_;
                    return *this;
                }

                iterator operator-(difference_type n) const
                {
                    return iterator(val_-n*delta_, delta_);
                }

                difference_type operator-(const iterator& other) const
                {
                    return (val_-other.val_)/delta_;
                }

                bool operator<(const iterator& other) const
                {
                    return val_ < other.val_;
                }

                bool operator<=(const iterator& other) const
                {
                    return val_ <= other.val_;
                }

                bool operator>(const iterator& other) const
                {
                    return val_ > other.val_;
                }

                bool operator>=(const iterator& other) const
                {
                    return val_ >= other.val_;
                }

                value_type operator[](difference_type n) const
                {
                    return val_+n*delta_;
                }

                friend void swap(iterator& a, iterator& b)
                {
                    using std::swap;
                    swap(a.val_, b.val_);
                    swap(a.delta_, b.delta_);
                }
        };

        constexpr range_t()
        : from_(0), to_(0), delta_(0) {}

        constexpr range_t(T from, T to, T delta)
        : from_(from), to_(from+((to-from+delta-1)/delta)*delta), delta_(delta) {}

        range_t(const range_t&) = default;

        range_t(range_t&&) = default;

        range_t& operator=(const range_t&) = default;

        range_t& operator=(range_t&&) = default;

        value_type step() const
        {
            return delta_;
        }

        size_type size() const
        {
            return (delta_ == 0 ? std::numeric_limits<size_type>::max() :
                    (to_-from_)/delta_);
        }

        iterator begin() const
        {
            return iterator(from_, delta_);
        }

        iterator end() const
        {
            return iterator(to_, delta_);
        }

        value_type front() const
        {
            return from_;
        }

        value_type back() const
        {
            return to_-delta_;
        }

        value_type operator[](size_type n) const
        {
            return from_+n*delta_;
        }

        template <typename U>
        operator std::vector<U>() const
        {
            return std::vector<U>(begin(), end());
        }

        template <typename T_=T, typename=typename std::enable_if<std::is_same<T_,char>::value>::type>
        operator std::string() const
        {
            return std::string(begin(), end());
        }
};

template <typename T>
range_t<T> range(T to)
{
    return {0, to, 1};
}

template <typename T>
range_t<T> range(T from, T to)
{
    return {from, to, 1};
}

template <typename T>
range_t<T> range(T from, T to, T delta)
{
    return {from, to, delta};
}

}

#endif
