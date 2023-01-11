//
// Created by Adrian Leventiu on 11.01.2023.
//

#include "../headers/SubstituteTeacher.h"
#include "../headers/Exceptions.h"

SubstituteTeacher::SubstituteTeacher() : Professor() {}

SubstituteTeacher::SubstituteTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

SubstituteTeacher::SubstituteTeacher(const SubstituteTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> SubstituteTeacher::clone() const {
    return std::make_shared<SubstituteTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const SubstituteTeacher &other) {
    os << dynamic_cast<const Professor&>(other);
    other.print(os);

    return os;
}

void SubstituteTeacher::createExam(const std::string &classSubject) {
    std::cout << "Unfortunately, you cannot create any exams as you are a Substitute Teacher. If you would've been a " << classSubject << " course or laboratory teacher, you could've created an exam.\n";
}

void SubstituteTeacher::print([[maybe_unused]] std::ostream &os) const {
    os << "Teaching subject (substituting the teacher): " << get_subject() << "\n\n";
}

SubstituteTeacher::~SubstituteTeacher() {}