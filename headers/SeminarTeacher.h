//
// Created by Adrian Leventiu on 16.11.2022.
//

#ifndef OOP_SEMINARTEACHER_H
#define OOP_SEMINARTEACHER_H

#include "Professor.h"
#include <memory>

class SeminarTeacher : public Professor {
private:
    void print([[maybe_unused]] std::ostream &os) const override;
public:
    SeminarTeacher();

    SeminarTeacher(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear);

    SeminarTeacher(const SeminarTeacher& other);

    std::shared_ptr<Professor> clone() const override;

//    virtual void createExam(const std::string& subject) override;

    friend std::ostream &operator<<(std::ostream &os, const SeminarTeacher &other);

    ~SeminarTeacher();
};


#endif //OOP_SEMINARTEACHER_H