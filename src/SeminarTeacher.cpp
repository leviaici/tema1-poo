//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/SeminarTeacher.h"

SeminarTeacher::SeminarTeacher() : Professor() {}

SeminarTeacher::SeminarTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

SeminarTeacher::SeminarTeacher(const SeminarTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> SeminarTeacher::clone() const {
    return std::make_shared<SeminarTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const SeminarTeacher &other) {
    os << static_cast<const Professor&>(other) << "Seminar subject: " << other.get_subject() << "\n\n";

    return os;
}

SeminarTeacher::~SeminarTeacher() {}