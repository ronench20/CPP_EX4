//ronen.chereshn@msmail.ariel.ac.il

#ifndef ASCENDINGORDER_HPP
#define ASCENDINGORDER_HPP
#include <algorithm>
#include <vector>

namespace container
{
    template <typename T = int>
    class AscendingOrder
    {
    private:
        std::vector<const T*> sorted;
        int index = 0;

        /**
         * Comparison function for sorting pointers to elements.
         *
         * @param a Pointer to the first element.
         * @param b Pointer to the second element.
         * @return true if *a < *b, false otherwise.
         */
        static bool compare(const T* a, const T* b)
        {
            return *a < *b;
        }

    public:

        /**
         * Constructs an AscendingOrder object from a vector of values.
         *
         * @param values The vector of values to go through in ascending order.
         * @param i The starting index for iteration (default is 0).
         */
        AscendingOrder(const std::vector<T>& values, int i = 0) : index(i)
        {
            for (const auto& value : values)
            {
                sorted.push_back(&value);
            }
            std::sort(sorted.begin(), sorted.end(), compare);
        }

        /**
         * "*" operator to access the current element.
         *
         * @return const T& Reference to the current element in ascending order.
         */
        const T& operator*() const
        {
            return *sorted[index];
        }

        /**
         * "++" operator to move to the next element.
         *
         * @return AscendingOrder& Reference to the incremented object.
         */
        AscendingOrder& operator++()
        {
            index++;
            return *this;
        }

        /**
         * "!=" operator to compare two AscendingOrder objects.
         *
         * @param other Another AscendingOrder object to compare with.
         * @return true if indices are not equal, false otherwise.
         */
        bool operator!=(const AscendingOrder& other) const
        {
            return index != other.index;
        }

        /**
         * "==" operator to compare two AscendingOrder objects.
         *
         * @param other Another AscendingOrder object to compare with.
         * @return true if indices are equal, false otherwise.
         */
        bool operator==(const AscendingOrder& other) const
        {
            return index == other.index;
        }
    };
}

#endif //ASCENDINGORDER_HPP