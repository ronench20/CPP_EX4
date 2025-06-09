//ronen.chereshn@msmail.ariel.ac.il

#ifndef MIDDLEOUTORDER_HPP
#define MIDDLEOUTORDER_HPP

namespace container
{
    template <typename T = int>
    class MiddleOutOrder
    {
    private:
        std::vector<const T*> sorted;
        int index = 0;

    public:

        /**
         * Constructs a MiddleOutOrder object from a vector of values.
         *
         * @param values The vector of values to go through in middle out order.
         * @param i The starting index for iteration (default is 0).
         */
        MiddleOutOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            if (values.size() == 0)
            {
                return;
            }

            size_t mid = values.size() / 2;
            sorted.push_back(&values[mid]);
            int left = static_cast<int> (mid) - 1;
            size_t right = mid + 1;
            bool odd = true;
            while (left >= 0 || right < values.size())
            {
                if (odd && left >= 0) {
                    sorted.push_back(&values[left]);
                    left--;
                } else if (!odd && right < values.size()) {
                    sorted.push_back(&values[right]);
                    right++;
                }
                odd = !odd;
            }
        }

        /**
         * "*" operator to access the current element.
         *
         * @return const T& Reference to the current element in the middle out order.
         */
        const T& operator*() const
        {
            return *sorted[index];
        }

        /**
         * "++" operator to move to the next element.
         *
         * @return MiddleOutOrder& Reference to the incremented object.
         */
        MiddleOutOrder& operator++()
        {
            index++;
            return *this;
        }

        /** "!=" operator to compare two MiddleOutOrder objects.
         *
         * @param other Another MiddleOutOrder object to compare with.
         * @return true if indices are not equal, false otherwise.
         */
        bool operator!=(const MiddleOutOrder& other) const
        {
            return index != other.index;
        }

        /** "==" operator to compare two MiddleOutOrder objects.
         *
         * @param other Another MiddleOutOrder object to compare with.
         * @return true if indices are equal, false otherwise.
         */
        bool operator==(const MiddleOutOrder& other) const
        {
            return index == other.index;
        }
    };
}

#endif //MIDDLEOUTORDER_HPP
