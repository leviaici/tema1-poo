//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/CourseTeacher.h"

CourseTeacher::CourseTeacher() : Professor() {}

CourseTeacher::CourseTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

CourseTeacher::CourseTeacher(const CourseTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> CourseTeacher::clone() const {
    return std::make_shared<CourseTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const CourseTeacher &other) {
    os << static_cast<const Professor&>(other) << "Course subject: " << other.get_subject() << "\n\n";

    return os;
}

CourseTeacher::~CourseTeacher() {}