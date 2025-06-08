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
        static bool compare(const T* a, const T* b) {
            return *a < *b;
        }
    public:
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

        const T& operator*() const
        {
            return *cross[index];
        }

        SideCrossOrder& operator++()
        {
            index++;
            return *this;
        }

        bool operator!=(const SideCrossOrder& other) const
        {
            return index != other.index;
        }

        bool operator==(const SideCrossOrder& other) const
        {
            return index == other.index;
        }
    };
}

#endif //SIDECROSSORDER_HPP
