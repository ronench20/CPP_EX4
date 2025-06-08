//ronen.chereshn@msmail.ariel.ac.il

#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

namespace container {

    template <typename T = int>
    class MyContainer
    {
    private:
        std::vector<T> data;

    public:
        MyContainer() = default;
        MyContainer(const MyContainer& other) = default;
        MyContainer& operator=(const MyContainer& other) = default;
        ~MyContainer() = default;

        void add(const T& value) {
            data.push_back(value);
        }

        void remove(const T& value) {
            auto it = std::remove(data.begin(), data.end(), value);
            if (it != data.end()) {
                data.erase(it, data.end());
            } else {
                throw std::runtime_error("Value is not in the container");
            }
        }

        int size() const{
            return data.size();
        }

        typename std::vector<T>::iterator begin() {return data.begin();}
        typename std::vector<T>::iterator end() {return data.end();}
        typename std::vector<T>::const_iterator begin() const {return data.begin();}
        typename std::vector<T>::const_iterator end() const {return data.end();}

        friend std::ostream& operator<<(std::ostream& os, const MyContainer& container)
        {
            for (const auto& value : container.data)
            {
                os << value << " ";
            }
            return os;
        }

    };


}

#endif //MYCONTAINER_HPP
