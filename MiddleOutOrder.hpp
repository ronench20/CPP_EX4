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
        MiddleOutOrder(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            int mid = (values.size() - 0.9) / 2;
            sorted.push_back(&values[mid]);
            int left = mid - 1;
            int right = mid + 1;
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

        const T& operator*() const
        {
            return *sorted[index];
        }

        MiddleOutOrder& operator++()
        {
            index++;
            return *this;
        }

        bool operator!=(const MiddleOutOrder& other) const
        {
            return index != other.index;
        }

        bool operator==(const MiddleOutOrder& other) const
        {
            return index == other.index;
        }
    };
}

#endif //MIDDLEOUTORDER_HPP
