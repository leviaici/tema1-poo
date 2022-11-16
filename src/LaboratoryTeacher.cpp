//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/LaboratoryTeacher.h"

LaboratoryTeacher::LaboratoryTeacher() : Professor() {}

LaboratoryTeacher::LaboratoryTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

LaboratoryTeacher::LaboratoryTeacher(const LaboratoryTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> LaboratoryTeacher::clone() const {
    return std::make_shared<LaboratoryTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const LaboratoryTeacher &other) {
    os << static_cast<const Professor&>(other);
    os << "Laboratory subject: " << other.get_subject() << "\n\n";

    return os;
}

LaboratoryTeacher::~LaboratoryTeacher() {}