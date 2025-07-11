//ronen.chereshn@msmail.ariel.ac.il

#include "MyContainer.hpp"

using namespace container;

int main()
{
    // Container for integers
    std::cout << "Container for integers:\n";
    MyContainer<> integers;
    integers.add(1);
    integers.add(5);
    integers.add(3);
    integers.add(2);
    integers.add(5);
    integers.add(8);

    std::cout << "Container size: " << integers.size() << "\n";
    std::cout << "Container contents: " << integers << "\n";
    std::cout << "Removing 5 from the container:\n";
    integers.remove(5);
    std::cout << "Container size: " << integers.size() << "\n";
    std::cout << "Container contents: " << integers << "\n";
    std::cout << "Ascending order of integers:\n";
    for (auto it = integers.begin_ascending_order(); it != integers.end_ascending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Descending order of integers:\n";
    for (auto it = integers.begin_descending_order(); it != integers.end_descending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Side cross order of integers:\n";
    for (auto it = integers.begin_side_cross_order(); it != integers.end_side_cross_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Reverse order of integers:\n";
    for (auto it = integers.begin_reverse_order(); it != integers.end_reverse_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Order of integers:\n";
    for (auto it = integers.begin(); it != integers.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Middle out order of integers:\n";
    for (auto it = integers.begin_middle_out_order(); it != integers.end_middle_out_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout <<"\n";


    // Container for doubles
    std::cout << "Container for doubles:\n";
    MyContainer<double> doubles;
    doubles.add(1.2);
    doubles.add(5.3);
    doubles.add(3.4);
    doubles.add(2.5);
    doubles.add(5.6);
    doubles.add(5.3);

    std::cout << "Container size: " << doubles.size() << "\n";
    std::cout << "Container contents: " << doubles << "\n";
    std::cout << "Removing 5 from the container:\n";
    doubles.remove(5.3);
    std::cout << "Container size: " << doubles.size() << "\n";
    std::cout << "Container contents: " << doubles << "\n";
    std::cout << "Ascending order of doubles:\n";
    for (auto it = doubles.begin_ascending_order(); it != doubles.end_ascending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Descending order of doubles:\n";
    for (auto it = doubles.begin_descending_order(); it != doubles.end_descending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Side cross order of doubles:\n";
    for (auto it = doubles.begin_side_cross_order(); it != doubles.end_side_cross_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Reverse order of doubles:\n";
    for (auto it = doubles.begin_reverse_order(); it != doubles.end_reverse_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Order of doubles:\n";
    for (auto it = doubles.begin(); it != doubles.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Middle out order of doubles:\n";
    for (auto it = doubles.begin_middle_out_order(); it != doubles.end_middle_out_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";


    std::cout <<"\n";

    // Container for strings
    std::cout << "Container for strings:\n";
    MyContainer<std::string> strings;
    strings.add("my");
    strings.add("name");
    strings.add("is");
    strings.add("Ronen");
    strings.add("is");

    std::cout << "Container size: " << strings.size() << "\n";
    std::cout << "Container contents: " << strings << "\n";
    std::cout << "Removing is from the container:\n";
    strings.remove("is");
    std::cout << "Container size: " << strings.size() << "\n";
    std::cout << "Container contents: " << strings << "\n";
    std::cout << "Ascending order of strings:\n";
    for (auto it = strings.begin_ascending_order(); it != strings.end_ascending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Descending order of strings:\n";
    for (auto it = strings.begin_descending_order(); it != strings.end_descending_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Side cross order of strings:\n";
    for (auto it = strings.begin_side_cross_order(); it != strings.end_side_cross_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Reverse order of strings:\n";
    for (auto it = strings.begin_reverse_order(); it != strings.end_reverse_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Order of strings:\n";
    for (auto it = strings.begin(); it != strings.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Middle out order of strings:\n";
    for (auto it = strings.begin_middle_out_order(); it != strings.end_middle_out_order(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";


    return 0;
}

