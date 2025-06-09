//ronen.chereshn@msmail.ariel.ac.il

#ifndef SIDECROSSORDER_HPP
#define SIDECROSSORDER_HPP
#include <algorithm>
#include <vector>

namespace container
{
    template <typename T = int>
    class SideCrossOrder
    {
    private:
        std::vector<const T*> sorted{};
        std::vector<const T*> cross{};
        int index = 0;

        /**
         * Comparison function for sorting pointers to elements.
         *
         * @param a Pointer to the first element.
         * @param b Pointer to the second element.
         * @return true if *a < *b, false otherwise.
         */
        static bool compare(const T* a, const T* b) {
            return *a < *b;
        }
    public:

        /**
         * Constructs a SideCrossOrder object from a vector of values.
         *
         * @param values The vector of values to go through in side cross order.
         * @param i The starting index for iteration (default is 0).
         */
        SideCrossOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (const auto& value : values)
            {
                sorted.push_back(&value);
            }
            std::sort(sorted.begin(), sorted.end(), compare);

            int left = 0;
            int right = sorted.size() - 1;
            bool odd = true;

            while (left <= right)
            {
                if (odd){
                    cross.push_back(sorted[left]);
                    left++;
                }else{
                    cross.push_back(sorted[right]);
                    right--;
                }
                odd = !odd;
            }
        }

        /**
         * "*" operator to access the current element.
         *
         * @return const T& Reference to the current element in side cross order.
         */
        const T& operator*() const
        {
            return *cross[index];
        }

        /**
         * "++" operator to move to the next element.
         *
         * @return SideCrossOrder& Reference to the incremented object.
         */
        SideCrossOrder& operator++()
        {
            index++;
            return *this;
        }

        /** "!=" operator to compare two SideCrossOrder objects.
         *
         * @param other Another SideCrossOrder object to compare with.
         * @return true if indices are not equal, false otherwise.
         */
        bool operator!=(const SideCrossOrder& other) const
        {
            return index != other.index;
        }

        /** "==" operator to compare two SideCrossOrder objects.
         *
         * @param other Another SideCrossOrder object to compare with.
         * @return true if indices are equal, false otherwise.
         */
        bool operator==(const SideCrossOrder& other) const
        {
            return index == other.index;
        }
    };
}

#endif //SIDECROSSORDER_HPP
