//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_PROFESSOR_H
#define OOP_PROFESSOR_H

#include <iostream>

class Professor {
private:
    std::string name = "Unknown";
    std::string subject = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int age = 0;

public:
    Professor();

    Professor(const std::string& name, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& age);

    Professor(const Professor& other);

    Professor& operator = (const Professor& other) {
        name = other.name;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        age = other.age;
//        std::cout << "Professor Operator =\n";
        return *this;
    }

    ~Professor();

    void print();

    /*std::string get_name();
    [[maybe_unused]] std::string get_subject();
    [[maybe_unused]] std::string get_email();
    [[maybe_unused]] std::string get_phoneNumber();
    [[maybe_unused]] int get_age(); */
};

#endif //OOP_PROFESSOR_H
