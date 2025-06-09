//ronen.chereshn@msmail.ariel.ac.il

#ifndef REVERSEORDER_HPP
#define REVERSEORDER_HPP
#include <vector>

namespace container
{
    template <typename T = int>
    class ReverseOrder
    {
    private:
        std::vector<const T*> sorted;
        int index = 0;

    public:

        /**
         * Constructs a ReverseOrder object from a vector of values.
         *
         * @param values The vector of values to go through in reverse order.
         * @param i The starting index for iteration (default is 0).
         */
        ReverseOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (auto it = values.rbegin(); it != values.rend(); ++it){
                sorted.push_back(&(*it));
            }
        }

        /**
         * "*" operator to access the current element.
         *
         * @return const T& Reference to the current element in reverse order.
         */
        const T& operator*() const
        {
            return *sorted[index];
        }

        /**
         * "++" operator to move to the next element.
         *
         * @return ReverseOrder& Reference to the incremented object.
         */
        ReverseOrder& operator++()
        {
            index++;
            return *this;
        }

        /**
         * "!=" operator to compare two ReverseOrder objects.
         *
         * @param other Another ReverseOrder object to compare with.
         * @return true if indices are not equal, false otherwise.
         */
        bool operator!=(const ReverseOrder& other) const
        {
            return index != other.index;
        }

        /** "==" operator to compare two ReverseOrder objects.
         *
         * @param other Another ReverseOrder object to compare with.
         * @return true if indices are equal, false otherwise.
         */
        bool operator==(const ReverseOrder& other) const
        {
            return index == other.index;
        }

    };
}

#endif //REVERSEORDER_HPP
