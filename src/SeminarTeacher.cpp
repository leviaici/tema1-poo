//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/SeminarTeacher.h"
#include "../headers/Exceptions.h"

SeminarTeacher::SeminarTeacher() : Professor() {}

SeminarTeacher::SeminarTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

SeminarTeacher::SeminarTeacher(const SeminarTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> SeminarTeacher::clone() const {
    return std::make_shared<SeminarTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const SeminarTeacher &other) {
    os << dynamic_cast<const Professor&>(other);
    other.print(os);

    return os;
}

//void SeminarTeacher::createExam(const std::string &subject) {
//    std::cout << "Unfortunately, you cannot create any exams as you are a Seminar Teacher. If you would've been a " << subject << "course or laboratory teacher, you could've created an exam.\n";
//}

void SeminarTeacher::print([[maybe_unused]] std::ostream &os) const {
    os << "Seminar subject: " << get_subject() << "\n\n";
}

SeminarTeacher::~SeminarTeacher() {}