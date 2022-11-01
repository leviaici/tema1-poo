//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_PROFESSOR_H
#define OOP_PROFESSOR_H

#include <iostream>

class Professor {
private:
    std::string firstName = "Unknown";
    std::string lastName = "Unknown";
    std::string subject = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int age = 0;

public:
    Professor();

    Professor(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& age);

    Professor(const Professor& other);

    Professor& operator = (const Professor& other) {
        firstName = other.firstName;
        lastName = other.lastName;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        age = other.age;
//        std::cout << "Professor Operator =\n";
        return *this;
    }

    ~Professor();

    friend std::ostream& operator<< (std::ostream& os, const Professor& other)
    {
        os << "Name: " << other.firstName << " " << other.lastName << "\n";
        os << "Subject: " << other.subject << "\n";
        os << "E-mail: " << other.email << "\n";
        os << "Phone number: " << other.phoneNumber << "\n";
        os << "Age: " << other.age << "\n\n";

        return os;
    }

    std::string get_subject();
    /*std::string get_firstName();
    std::string get_lastName();
    [[maybe_unused]] std::string get_email();
    [[maybe_unused]] std::string get_phoneNumber();
    [[maybe_unused]] int get_age(); */
};

#endif //OOP_PROFESSOR_H
