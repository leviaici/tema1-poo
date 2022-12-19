//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_PROFESSOR_H
#define OOP_PROFESSOR_H

#include <iostream>
#include <memory>

class Professor {
private:
    std::string firstName = "Unknown";
    std::string lastName = "Unknown";
    std::string subject = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";

    int birthDay = 0;
    int birthMonth = 0;
    int birthYear = 0;

    virtual void print([[maybe_unused]] std::ostream &os) const;
public:
    Professor();

    Professor(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear);

    Professor(const Professor& other);

    Professor& operator = (const Professor& other) {
        firstName = other.firstName;
        lastName = other.lastName;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        birthDay = other.birthDay;
        birthMonth = other.birthMonth;
        birthYear = other.birthYear;
//        std::cout << "Professor Operator =\n";
        return *this;
    }

    virtual std::shared_ptr<Professor> clone() const = 0;

    virtual ~Professor();

    friend std::ostream& operator<< (std::ostream& os, const Professor& other)
    {
        os << "Full name: " << other.firstName << " " << other.lastName << "\n";
        os << "E-mail: " << other.email << "\n";
        os << "Phone number: " << other.phoneNumber << "\n";
        os << "Birth date: " << other.birthDay << "/" << other.birthMonth << "/" << other.birthYear << "\n";
        other.print(os);

        return os;
    }

//    virtual void createExam(const std::string& subject) = 0;

/// TBA FUNCTIE VIRTUALA DE EXAMEN
    std::string get_subject() const;
    /*std::string get_firstName();
    std::string get_lastName();
    [[maybe_unused]] std::string get_email();
    [[maybe_unused]] std::string get_phoneNumber();
    [[maybe_unused]] std::string get_birthDate(); */
};

#endif //OOP_PROFESSOR_H