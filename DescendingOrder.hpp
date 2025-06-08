//ronen.chereshn@msmail.ariel.ac.il

#ifndef DESCENDINGORDER_HPP
#define DESCENDINGORDER_HPP

#include <algorithm>
#include <vector>

namespace container
{
    template <typename T = int>
    class DescendingOrder
    {
    private:
        std::vector<const T*> sorted;
        int index = 0;
        static bool getSmaller(const T* a, const T* b) {
            return *a > *b;
        }
    public:
        DescendingOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (const auto& value : values)
            {
                sorted.push_back(&value);
            }
            std::sort(sorted.begin(), sorted.end(), getSmaller);
        }

        const T& operator*() const
        {
            return *sorted[index];
        }

        DescendingOrder& operator++()
        {
            index++;
            return *this;
        }

        bool operator!=(const DescendingOrder& other) const
        {
            return index != other.index;
        }

        bool operator==(const DescendingOrder& other) const
        {
            return index == other.index;
        }



    };
}

#endif //DESCENDINGORDER_HPP
