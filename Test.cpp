//ronen.chereshn@msmail.ariel.ac.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "ReverseOrder.hpp"
#include "Order.hpp"
#include "MiddleOutOrder.hpp"
#include <stdexcept>

using namespace container;

TEST_CASE("Container operations") {
    MyContainer<> container;

    SUBCASE("Adding values") {
        container.add(1);
        container.add(2);
        container.add(3);
        CHECK(container.size() == 3);
        CHECK(container.begin() != container.end());
    }

    SUBCASE("Removing values") {
        container.add(1);
        container.add(2);
        container.add(3);
        container.remove(2);
        CHECK(container.size() == 2);
        CHECK(std::find(container.begin(), container.end(), 2) == container.end());
    }

    SUBCASE("Removing non existent value") {
        container.add(1);
        CHECK_THROWS_AS(container.remove(4), std::runtime_error);
    }

    SUBCASE("Size of the container") {
        CHECK(container.size() == 0);
        container.add(1);
        CHECK(container.size() == 1);
    }

    SUBCASE("Iterating through the container") {
        container.add(1);
        container.add(2);
        std::vector<int> values;
        for (const auto& value : container) {
            values.push_back(value);
        }
        CHECK(values.size() == 2);
        CHECK(values[0] == 1);
        CHECK(values[1] == 2);
    }
    SUBCASE("Copy constructor") {
        container.add(1);
        container.add(2);
        MyContainer<> copy(container);
        CHECK(copy.size() == 2);
        CHECK(std::find(copy.begin(), copy.end(), 1) != copy.end());
        CHECK(std::find(copy.begin(), copy.end(), 2) != copy.end());
    }

    SUBCASE("Output stream operator") {
        container.add(1);
        container.add(2);
        std::ostringstream oss;
        oss << container;
        CHECK(oss.str() == "1 2 ");
    }
}

TEST_CASE("AscendingOrder iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints.add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_ascending_order(); it != ints.end_ascending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 5);
        CHECK(sortedValues[3] == 5);
        CHECK(sortedValues[4] == 8);

        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_ascending_order(); it != ints.end_ascending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 8);
    }

    SUBCASE("Strings") {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_ascending_order(); it != strings.end_ascending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "ONE");
        CHECK(sortedValues[1] == "one");
        CHECK(sortedValues[2] == "one");
        CHECK(sortedValues[3] == "three");
        CHECK(sortedValues[4] == "two");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_ascending_order(); it != strings.end_ascending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "ONE");
        CHECK(sortedValues[1] == "three");
        CHECK(sortedValues[2] == "two");
    }
}

TEST_CASE("DescendingOrder iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints .add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_descending_order(); it != ints.end_descending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 8);
        CHECK(sortedValues[1] == 5);
        CHECK(sortedValues[2] == 5);
        CHECK(sortedValues[3] == 4);
        CHECK(sortedValues[4] == 3);

        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_descending_order(); it != ints.end_descending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 8);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 3);
    }

    SUBCASE("Strings")
    {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_descending_order(); it != strings.end_descending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "two");
        CHECK(sortedValues[1] == "three");
        CHECK(sortedValues[2] == "one");
        CHECK(sortedValues[3] == "one");
        CHECK(sortedValues[4] == "ONE");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_descending_order(); it != strings.end_descending_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "two");
        CHECK(sortedValues[1] == "three");
        CHECK(sortedValues[2] == "ONE");
    }
}

TEST_CASE("SideCrossOrder iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints.add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_side_cross_order(); it != ints.end_side_cross_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 8);
        CHECK(sortedValues[2] == 4);
        CHECK(sortedValues[3] == 5);
        CHECK(sortedValues[4] == 5);


        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_side_cross_order(); it != ints.end_side_cross_order(); ++it)
        {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 8);
        CHECK(sortedValues[2] == 4);
    }

    SUBCASE("Strings") {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_side_cross_order(); it != strings.end_side_cross_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "ONE");
        CHECK(sortedValues[1] == "two");
        CHECK(sortedValues[2] == "one");
        CHECK(sortedValues[3] == "three");
        CHECK(sortedValues[4] == "one");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_side_cross_order(); it != strings.end_side_cross_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "ONE");
        CHECK(sortedValues[1] == "two");
        CHECK(sortedValues[2] == "three");
    }
}

TEST_CASE("ReverseOrder iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints.add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_reverse_order(); it != ints.end_reverse_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 5);
        CHECK(sortedValues[3] == 8);
        CHECK(sortedValues[4] == 5);

        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_reverse_order(); it != ints.end_reverse_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 3);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 8);
    }

    SUBCASE("Strings") {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_reverse_order(); it != strings.end_reverse_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "three");
        CHECK(sortedValues[1] == "one");
        CHECK(sortedValues[2] == "two");
        CHECK(sortedValues[3] == "ONE");
        CHECK(sortedValues[4] == "one");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_reverse_order(); it != strings.end_reverse_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "three");
        CHECK(sortedValues[1] == "two");
        CHECK(sortedValues[2] == "ONE");
    }
}

TEST_CASE("Order iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints.add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_order(); it != ints.end_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 5);
        CHECK(sortedValues[1] == 8);
        CHECK(sortedValues[2] == 5);
        CHECK(sortedValues[3] == 4);
        CHECK(sortedValues[4] == 3);

        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_order(); it != ints.end_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 8);
        CHECK(sortedValues[1] == 4);
        CHECK(sortedValues[2] == 3);
    }

    SUBCASE("Strings") {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_order(); it != strings.end_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "one");
        CHECK(sortedValues[1] == "ONE");
        CHECK(sortedValues[2] == "two");
        CHECK(sortedValues[3] == "one");
        CHECK(sortedValues[4] == "three");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_order(); it != strings.end_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "ONE");
        CHECK(sortedValues[1] == "two");
        CHECK(sortedValues[2] == "three");
    }
}

TEST_CASE("MiddleOutOrder iterator") {
    MyContainer<> ints;
    ints.add(5);
    ints.add(8);
    ints.add(5);
    ints.add(4);
    ints.add(3);

    MyContainer<std::string> strings;
    strings.add("one");
    strings.add("ONE");
    strings.add("two");
    strings.add("one");
    strings.add("three");

    SUBCASE("Integers") {
        std::vector<int> sortedValues;
        for (auto it = ints.begin_middle_out_order(); it != ints.end_middle_out_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == 5);
        CHECK(sortedValues[1] == 8);
        CHECK(sortedValues[2] == 4);
        CHECK(sortedValues[3] == 5);
        CHECK(sortedValues[4] == 3);

        ints.remove(5);
        sortedValues.clear();
        for (auto it = ints.begin_middle_out_order(); it != ints.end_middle_out_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == 4);
        CHECK(sortedValues[1] == 8);
        CHECK(sortedValues[2] == 3);
    }

    SUBCASE("Strings") {
        std::vector<std::string> sortedValues;
        for (auto it = strings.begin_middle_out_order(); it != strings.end_middle_out_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 5);
        CHECK(sortedValues[0] == "two");
        CHECK(sortedValues[1] == "ONE");
        CHECK(sortedValues[2] == "one");
        CHECK(sortedValues[3] == "one");
        CHECK(sortedValues[4] == "three");

        strings.remove("one");
        sortedValues.clear();
        for (auto it = strings.begin_middle_out_order(); it != strings.end_middle_out_order(); ++it) {
            sortedValues.push_back(*it);
        }
        CHECK(sortedValues.size() == 3);
        CHECK(sortedValues[0] == "two");
        CHECK(sortedValues[1] == "ONE");
        CHECK(sortedValues[2] == "three");
    }
}