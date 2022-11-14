//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/Professor.h"

Professor::Professor() = default;

Professor::Professor(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> subject = subject;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> birthDay = birthDay;
    this -> birthMonth = birthMonth;
    this -> birthYear = birthYear;
}

Professor::Professor(const Professor& other) : firstName{other.firstName}, lastName{other.lastName}, subject{other.subject}, email{other.email}, phoneNumber{other.phoneNumber}, birthDay{other.birthDay}, birthMonth{other.birthMonth}, birthYear{other.birthYear} {
//    std::cout << "Creating Professor via copy-constructor.\n";
}

Professor::~Professor() {
//    std::cout << "Killing the professor.\n";
}

std::string Professor::get_subject() const { return this -> subject; }
/*std::string Professor::get_firstName() { return this -> firstName; }
std::string Professor::get_lastName() { return this -> lastName; }
[[maybe_unused]] std::string Professor::get_email() { return this -> email; }
[[maybe_unused]] std::string Professor::get_phoneNumber() { return this -> phoneNumber; }*/