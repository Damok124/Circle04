#include <iostream>

class Person
{
public:
    std::string name;
    int age;
};

void print_person(const Person& p)
{
    std::cout << "Name: " << p.name << std::endl;
    std::cout << "Age: " << p.age << std::endl;
}

int main()
{
    Person my_person;
    my_person.name = "Alice";
    my_person.age = 30;
    print_person(my_person);
    return 0;
}
