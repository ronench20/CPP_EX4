//ronen.chereshn@msmail.ariel.ac.il

#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>

namespace container
{
    template <typename T = int>
    class Order
    {
    private:
        std::vector<const T*> sorted;
        int index = 0;

    public:

        /**
         * Constructs an Order object from a vector of values.
         *
         * @param values The vector of values to go through in order.
         * @param i The starting index for iteration (default is 0).
         */
        Order(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (auto it = values.begin(); it != values.end(); ++it){
                sorted.push_back(&(*it));
            }
        }

        /**
         * "*" operator to access the current element.
         *
         * @return const T& Reference to the current element in order.
         */
        const T& operator*() const
        {
            return *sorted[index];
        }

        /**
         * "++" operator to move to the next element.
         *
         * @return Order& Reference to the incremented object.
         */
        Order& operator++()
        {
            index++;
            return *this;
        }

        /**
         * "!=" operator to compare two Order objects.
         *
         * @param other Another Order object to compare with.
         * @return true if indices are not equal, false otherwise.
         */
        bool operator!=(const Order& other) const
        {
            return index != other.index;
        }

        /**
         * "==" operator to compare two Order objects.
         *
         * @param other Another Order object to compare with.
         * @return true if indices are equal, false otherwise.
         */
        bool operator==(const Order& other) const
        {
            return index == other.index;
        }

    };
}

#endif //ORDER_HPP
