#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstring>

class Person{
public:
    virtual void show_info() = 0;
};

class Student{
public:
    std::string show() {
        return "I am a student\n";
    }
};

template <typename T>
class Lazy : public T{
public:
    std::string show() {
        return "I am lazy because " + T::show();
    }
};

template <typename T>
class NotEmployed : public T, public Person{
public:
    void show_info() {
        std::cout << "I am not employed because " << T::show();
    }
};


int main() {

    Lazy<Student> stud;
    std::cout  << stud.show();

    NotEmployed<Student> notEmployed;
    notEmployed.show_info();

    Person *pPerson = new NotEmployed<Student>();
    std::cout << "Pointer of not employed student: "; pPerson->show_info();

    Person *pPerson2 = new NotEmployed<Lazy<Student> >();
    std::cout << "Pointer of not employed lazy: "; pPerson2->show_info();

    std::vector<std::unique_ptr<Person>> Ppeople;
    Ppeople.emplace_back(new NotEmployed<Lazy<Student> >());
    Ppeople.emplace_back(new NotEmployed<Student>());

    for (auto &person : Ppeople) {
        person->show_info();
    }

    return 0;
}