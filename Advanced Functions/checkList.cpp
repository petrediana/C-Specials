#include <iostream>
#include <functional>
#include <vector>

bool check_if_odd (int number) {
    return (number % 2) ? true : false;
}

std::vector<int> get_odd_numbers(std::function<bool(int)> function, std::vector<int> my_vector) {
    std::vector<int> odd_vector;

    for (auto &number : my_vector) {
        if (function(number)) {
            odd_vector.emplace_back(number);
        }
    }

    return odd_vector;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is 4 an odd number? -> " <<check_if_odd(4); //not odd good

    std::vector<int> my_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> odd_vector = get_odd_numbers(check_if_odd, my_vector);

    std::cout << "\nPrint the odd numbers from the vector: ";
    for (auto &number : odd_vector) {
        std:: cout << number << " ";
    }
}