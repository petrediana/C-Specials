#include <iostream>
#include <functional>
#include <vector>

double multiply_by_2(double number) {
    return 2 * number;
}

double multiply_by_3(double number) {
    return 3 * number;
}

double hold_function(std::function<double(double)> function, double number) {
    return function(number);
}


int main() {
    //use variables to store different functions
    //use variables to store a function that stores a function
    auto call_first_function = multiply_by_2;
    std::cout << "10 * 2 = " << call_first_function(10) << "\t -> use variable to store function\n";

    auto call_second_function = hold_function;
    std::cout << "15 * 2 = " << call_second_function(call_first_function, 15) << "\t -> use variable"
               << "to store a function that stores a function\n";

    //using a vector to hold functions
    std::vector<std::function<double(double)>> functions(2);
    functions[0] = multiply_by_2;
    functions[1] = multiply_by_3;

    //iterating through the functions vector
    std::cout << "\nIterating through the vector; multiply 2 by 2 than by 3 ->: ";
    for (auto &funcs : functions) {
        std::cout << funcs(2) << " ";
    }
    std::cout << std::endl;


    std::vector<std::function<double(double)>> func2;
    func2.emplace_back(multiply_by_2);
    func2.emplace_back(multiply_by_3);


    std::cout << "\nIterating through the vector; multiply 3 by 2 than by 3 ->: ";
    for (auto &funcs : func2) {
        std::cout << funcs(3) << " ";
    }

    std::cout << std::endl;

    return 0;
}