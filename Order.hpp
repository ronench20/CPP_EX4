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
        Order(const std::vector<T>& values, int i = 0 ) :index(i)
        {
            for (auto it = values.begin(); it != values.end(); ++it){
                sorted.push_back(&(*it));
            }
        }

        const T& operator*() const
        {
            return *sorted[index];
        }

        Order& operator++()
        {
            index++;
            return *this;
        }

        bool operator!=(const Order& other) const
        {
            return index != other.index;
        }

        bool operator==(const Order& other) const
        {
            return index == other.index;
        }

    };
}

#endif //ORDER_HPP
