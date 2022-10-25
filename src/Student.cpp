//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/Student.h"

Student::Student() = default;

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& age, const std::vector<Subject>& subjects) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> age = age;
    this -> subjects = subjects;
    calculateOverallAverage();
}

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& age) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> age = age;
}

Student::Student(const Student& other) : firstName{other.firstName}, lastName{other.lastName}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, age{other.age}, id{other.id}, overallAverage{other.overallAverage}, tuitionFree{other.tuitionFree}, subjects{other.subjects} {
//    std::cout << "Creating Student via copy-constructor.\n";
}

Student::~Student() {
//    std::cout << "Killing the student.\n";
}

void Student::set_id(const int& other) { this -> id = other; }

void Student::calculateOverallAverage() {
    for(auto c : (this -> subjects))
        (this -> overallAverage) += c.get_average();
    (this -> overallAverage) /= (this -> subjects).size();
}

float Student::get_overallAverage() { return this -> overallAverage; }

int Student::get_group() { return this -> group; }

void Student::print() {
    std::cout << "Full name: " << this -> lastName << " " << this -> firstName << "\n";
    std::cout << "E-mail: " << this -> email << "\n";
    std::cout << "Phone number: " << this -> phoneNumber << "\n";
    std::cout << "Group: " << this -> group << "\n";
    std::cout << "Age: " << this -> age << "\n";
    std::cout << "ID: " << this -> id << "\n";
    std::cout << "Overall average: " << this -> overallAverage << "\n";
    for(auto c : this -> subjects)
        c.print();
    std::cout << "Tuition free: " << this -> tuitionFree << "\n\n\n";
}

void Student::set_tuitionFree(const bool& status) { this -> tuitionFree = status; }

std::string Student::get_firstName() { return this -> firstName; }
std::string Student::get_lastName() { return this -> lastName; }
/*std::string Student::get_email() { return this -> email; }
std::string Student::get_phoneNumber() { return this -> phoneNumber; }
int Student::get_group() { return this -> group; }
int Student::get_age() { return this -> age; }
bool Student::get_tuitionFree() { return this -> tuitionFree; } */