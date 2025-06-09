//ronen.chereshn@msmail.ariel.ac.il

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "ReverseOrder.hpp"
#include "Order.hpp"
#include "MiddleOutOrder.hpp"

namespace container {

    template <typename T = int>
    class MyContainer
    {
    private:
        std::vector<T> data;

    public:

        /**
         * Default constructor.
         */
        MyContainer() = default;

        /**
         * Copy constructor.
         * @param other The container to copy from.
         */
        MyContainer(const MyContainer& other) = default;

        /**
         * Copy assignment operator.
         * @param other The container to assign from.
         * @return Reference to this container.
         */
        MyContainer& operator=(const MyContainer& other) = default;

        /**
         * Destructor.
         */
        ~MyContainer() = default;

        /**
         * Adds a value to the container.
         * @param value The value to add.
         */
        void add(const T& value) {
            data.push_back(value);
        }

        /**
         * Removes all occurrences of a value from the container.
         * @param value The value to remove.
         * @throws std::runtime_error if the value is not found.
         */
        void remove(const T& value) {
            auto it = std::remove(data.begin(), data.end(), value);
            if (it != data.end()) {
                data.erase(it, data.end());
            } else {
                throw std::runtime_error("Value is not in the container");
            }
        }

        /**
         * Returns the number of elements in the container.
         * @return The size of the container.
         */
        int size() const{
            return data.size();
        }

        /**
         * Returns an iterator to the beginning.
         * @return Iterator to the first element.
         */
        typename std::vector<T>::iterator begin() {return data.begin();}

        /**
         * Returns an iterator to the end.
         * @return Iterator to one past the last element.
         */
        typename std::vector<T>::iterator end() {return data.end();}

        /**
         * Returns a const iterator to the beginning.
         * @return Const iterator to the first element.
         */
        typename std::vector<T>::const_iterator begin() const {return data.begin();}

        /**
         * Returns a const iterator to the end.
         * @return Const iterator to one past the last element.
         */
        typename std::vector<T>::const_iterator end() const {return data.end();}

        /**
         * Outputs the contents of the container to a stream.
         * @param os The output stream.
         * @param container The container to output.
         * @return Reference to the output stream.
         */
        friend std::ostream& operator<<(std::ostream& os, const MyContainer& container)
        {
            for (const auto& value : container.data)
            {
                os << value << " ";
            }
            return os;
        }

        /**
         * Returns an iterator to the beginning in ascending order.
         * @return AscendingOrder iterator at the beginning.
         */
        AscendingOrder<T> begin_ascending_order () const
        {
            return AscendingOrder<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in ascending order.
         * @return AscendingOrder iterator at the end.
         */
        AscendingOrder<T> end_ascending_order() const
        {
            return AscendingOrder<T>(data, data.size());
        }

        /**
         * Returns an iterator to the beginning in descending order.
         * @return DescendingOrder iterator at the beginning.
         */
        DescendingOrder<T> begin_descending_order () const
        {
            return DescendingOrder<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in descending order.
         * @return DescendingOrder iterator at the end.
         */
        DescendingOrder<T> end_descending_order() const
        {
            return DescendingOrder<T>(data, data.size());
        }

        /**
         * Returns an iterator to the beginning in side-cross order.
         * @return SideCrossOrder iterator at the beginning.
         */
        SideCrossOrder<T> begin_side_cross_order () const
        {
            return SideCrossOrder<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in side-cross order.
         * @return SideCrossOrder iterator at the end.
         */
        SideCrossOrder<T> end_side_cross_order() const
        {
            return SideCrossOrder<T>(data, data.size());
        }

        /**
         * Returns an iterator to the beginning in reverse order.
         * @return ReverseOrder iterator at the beginning.
         */
        ReverseOrder<T> begin_reverse_order () const
        {
            return ReverseOrder<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in reverse order.
         * @return ReverseOrder iterator at the end.
         */
        ReverseOrder<T> end_reverse_order() const
        {
            return ReverseOrder<T>(data, data.size());
        }

        /**
         * Returns an iterator to the beginning in default order.
         * @return Order iterator at the beginning.
         */
        Order<T> begin_order () const
        {
            return Order<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in default order.
         * @return Order iterator at the end.
         */
        Order<T> end_order() const
        {
            return Order<T>(data, data.size());
        }

        /**
         * Returns an iterator to the beginning in middle-out order.
         * @return MiddleOutOrder iterator at the beginning.
         */
        MiddleOutOrder<T> begin_middle_out_order () const
        {
            return MiddleOutOrder<T>(data, 0);
        }

        /**
         * Returns an iterator to the end in middle-out order.
         * @return MiddleOutOrder iterator at the end.
         */
        MiddleOutOrder<T> end_middle_out_order() const
        {
            return MiddleOutOrder<T>(data, data.size());
        }

    };

}

#endif //MYCONTAINER_HPP