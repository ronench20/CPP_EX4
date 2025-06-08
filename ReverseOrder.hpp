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
        ReverseOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (auto it = values.rbegin(); it != values.rend(); ++it){
                sorted.push_back(&(*it));
            }
        }

        const T& operator*() const
        {
            return *sorted[index];
        }

        ReverseOrder& operator++()
        {
            index++;
            return *this;
        }

        bool operator!=(const ReverseOrder& other) const
        {
            return index != other.index;
        }

        bool operator==(const ReverseOrder& other) const
        {
            return index == other.index;
        }

    };
}

#endif //REVERSEORDER_HPP
