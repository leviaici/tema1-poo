//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "Professor.h"

Professor::Professor() = default;

Professor::Professor(const std::string& name, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& age) {
    this -> name = name;
    this -> subject = subject;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> age = age;
}

Professor::Professor(const Professor& other) : name{other.name}, subject{other.subject}, email{other.email}, phoneNumber{other.phoneNumber}, age{other.age} {
    std::cout << "Creating Professor via copy-constructor.\n";
}

Professor::~Professor() {
    std::cout << "Killing the professor.\n";
}

void Professor::print() {
    std::cout << this -> name << "\n";
    std::cout << this -> subject << "\n";
    std::cout << this -> email << "\n";
    std::cout << this -> phoneNumber << "\n";
    std::cout << this -> age << "\n\n\n";
}

std::string Professor::get_name() { return this -> name; }
/*[[maybe_unused]] std::string Professor::get_subject() { return this -> subject; }
[[maybe_unused]] std::string Professor::get_email() { return this -> email; }
[[maybe_unused]] std::string Professor::get_phoneNumber() { return this -> phoneNumber; }
[[maybe_unused]] int Professor::get_age() { return this -> age; } */