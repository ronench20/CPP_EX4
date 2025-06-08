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

namespace container {

    template <typename T = int>
    class MyContainer
    {
    private:
        std::vector<T> data;

    public:
        MyContainer() = default;
        MyContainer(const MyContainer& other) = default;
        MyContainer& operator=(const MyContainer& other) = default;
        ~MyContainer() = default;

        void add(const T& value) {
            data.push_back(value);
        }

        void remove(const T& value) {
            auto it = std::remove(data.begin(), data.end(), value);
            if (it != data.end()) {
                data.erase(it, data.end());
            } else {
                throw std::runtime_error("Value is not in the container");
            }
        }

        int size() const{
            return data.size();
        }

        typename std::vector<T>::iterator begin() {return data.begin();}
        typename std::vector<T>::iterator end() {return data.end();}
        typename std::vector<T>::const_iterator begin() const {return data.begin();}
        typename std::vector<T>::const_iterator end() const {return data.end();}

        friend std::ostream& operator<<(std::ostream& os, const MyContainer& container)
        {
            for (const auto& value : container.data)
            {
                os << value << " ";
            }
            return os;
        }


        AscendingOrder<T> begin_ascending_order () const
        {
            return AscendingOrder<T>(data, 0);
        }
        AscendingOrder<T> end_ascending_order() const
        {
            return AscendingOrder<T>(data, data.size());
        }

        DescendingOrder<T> begin_descending_order () const
        {
            return DescendingOrder<T>(data, 0);
        }
        DescendingOrder<T> end_descending_order() const
        {
            return DescendingOrder<T>(data, data.size());
        }

        SideCrossOrder<T> begin_side_cross_order () const
        {
            return SideCrossOrder<T>(data, 0);
        }
        SideCrossOrder<T> end_side_cross_order() const
        {
            return SideCrossOrder<T>(data, data.size());
        }

        ReverseOrder<T> begin_reverse_order () const
        {
            return ReverseOrder<T>(data, 0);
        }
        ReverseOrder<T> end_reverse_order() const
        {
            return ReverseOrder<T>(data, data.size());
        }

        Order<T> begin_order () const
        {
            return Order<T>(data, 0);
        }
        Order<T> end_order() const
        {
            return Order<T>(data, data.size());
        }

    };

}

#endif //MYCONTAINER_HPP
