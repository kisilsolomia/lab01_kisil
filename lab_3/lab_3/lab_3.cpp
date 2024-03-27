#include <iostream>
#include <vector>
#include <algorithm>

class StringArray {

private:
    std::vector<std::string> arr;

public:
    // Додавання рядка до масиву
    void add(const std::string& str) {
        arr.push_back(str);
    }

    // Отримання рядка за індексом
    std::string get(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Індекс виходить за межі масиву.\n";
            return "";
        }
        return arr[index];
    }

    // Зчеплення двох масивів
    StringArray concatenate(const StringArray& other) {
        StringArray result;
        result.arr = this->arr;
        result.arr.insert(result.arr.end(), other.arr.begin(), other.arr.end());
        return result;
    }

    // Злиття двох масивів з виключенням повторюваних елементів
    StringArray merge(const StringArray& other) {
        StringArray result;
        result.arr = this->arr;
        for (const auto& str : other.arr) {
            if (std::find(result.arr.begin(), result.arr.end(), str) == result.arr.end()) {
                result.arr.push_back(str);
            }
        }
        return result;
    }

    // Друк елементів масиву
    void print() {
        for (const auto& str : arr) {
            std::cout << str << '\n';
        }
    }

    // Друк всього масиву
    void printAll() {
       
        for (int i = 0; i < arr.size(); i++) {
            std::cout << "Індекс: " << i << ", Значення: " << arr[i] << '\n';
        }
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    StringArray arr1;
    arr1.add("Hello");
    arr1.add("World");

    StringArray arr2;
    arr2.add("Students");
    arr2.add("!");

    std::cout << "Елементи першого масиву:\n";
    arr1.print();

    std::cout << "Елементи другого масиву:\n";
    arr2.print();

    StringArray arr3 = arr1.concatenate(arr2);
    std::cout << "Елементи всього масиву:\n";
    arr3.printAll();

    return 0;
}
