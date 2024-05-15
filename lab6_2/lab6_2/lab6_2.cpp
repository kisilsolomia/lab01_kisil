#include <iostream>
#include <set>
#include <algorithm>
#include <iterator> 

class Set {
    std::set<int> s;

public:
    Set() {}
    Set(const std::initializer_list<int>& list) : s(list) {}
    Set(const Set& other) : s(other.s) {}

    void add(int element) {
        s.insert(element);
    }

    Set intersection(const Set& other) const {
        Set result;
        std::set_intersection(s.begin(), s.end(), other.s.begin(), other.s.end(),
            std::inserter(result.s, result.s.begin()));
        return result;
    }

    bool contains(int element) const {
        return s.find(element) != s.end();
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            s = other.s;
        }
        return *this;
    }

    bool operator==(const Set& other) const {
        return s == other.s;
    }

    void print() const {
        for (const auto& element : s) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Set s1 = { 1, 2, 3, 4, 5 };
    Set s2 = { 4, 5, 6, 7, 8 };

    int choice;
    do {
        std::cout << "1. Додати елемент до множини\n";
        std::cout << "2. Перетин множин\n";
        std::cout << "3. Перевірити наявність елемента\n";
        std::cout << "4. Вихід\n";
        std::cout << "Введіть свій вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int element;
            std::cout << "Введіть елемент для додавання: ";
            std::cin >> element;
            s1.add(element);
            break;
        }
        case 2: {
            std::cout << "Перетин множин: ";
            Set s3 = s1.intersection(s2);
            s3.print();
            break;
        }
        case 3: {
            int element;
            std::cout << "Введіть елемент для перевірки: ";
            std::cin >> element;
            if (s1.contains(element)) {
                std::cout << "Елемент присутній у множині\n";
            }
            else {
                std::cout << "Елемент відсутній у множині\n";
            }
            break;
        }
        case 4:
            std::cout << "Вихід...\n";
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 4);

    return 0;
}

