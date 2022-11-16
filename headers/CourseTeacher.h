//
// Created by Adrian Leventiu on 16.11.2022.
//

#ifndef OOP_COURSETEACHER_H
#define OOP_COURSETEACHER_H


#include "Professor.h"

class CourseTeacher : public Professor {
public:
    CourseTeacher();

    CourseTeacher(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear);

    CourseTeacher(const CourseTeacher& other);

    std::shared_ptr<Professor> clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const CourseTeacher &other);

    ~CourseTeacher();
};


#endif //OOP_COURSETEACHER_H
