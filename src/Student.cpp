//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/Student.h"

Student::Student() = default;

Student::Student(const std::string& name, const std::string& email, const std::string& phoneNumber, const int& group, const int& age, const std::vector<Grades>& g) {
    this -> name = name;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> age = age;
    this -> g = g;
    calculateOverallAverage();
}

Student::Student(const std::string& name, const std::string& email, const std::string& phoneNumber, const int& group, const int& age) {
    this -> name = name;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> age = age;
}

Student::Student(const Student& other) : name{other.name}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, age{other.age}, id{other.id}, overallAverage{other.overallAverage}, tuitionFree{other.tuitionFree}, g{other.g} {
    std::cout << "Creating Student via copy-constructor.\n";
}

Student::~Student() {
    std::cout << "Killing the student.\n";
}

void Student::set_id(const int& other) { this -> id = other; }

void Student::calculateOverallAverage() {
    for(auto c : (this -> g))
        (this -> overallAverage) += c.get_average();
    (this -> overallAverage) /= (this -> g).size();
}

float Student::get_overallAverage() { return this -> overallAverage; }

void Student::print() {
    std::cout << this -> name << "\n";
    std::cout << this -> email << "\n";
    std::cout << this -> phoneNumber << "\n";
    std::cout << this -> group << "\n";
    std::cout << this -> age << "\n";
    std::cout << this -> id << "\n";
    std::cout << this -> overallAverage << "\n";
    for(auto c : this -> g)
        c.print();
    std::cout << "TUITION FREE: " << this -> tuitionFree << "\n\n\n\n";
}

void Student::set_tuitionFree(const bool& status) { this -> tuitionFree = status; }

/*std::string Student::get_name() { return this -> name; }
std::string Student::get_email() { return this -> email; }
std::string Student::get_phoneNumber() { return this -> phoneNumber; }
int Student::get_group() { return this -> group; }
int Student::get_age() { return this -> age; }
bool Student::get_tuitionFree() { return this -> tuitionFree; } */