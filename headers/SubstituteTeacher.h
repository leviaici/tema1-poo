//
// Created by Adrian Leventiu on 11.01.2023.
//

#ifndef OOP_SUBSTITUTETEACHER_H
#define OOP_SUBSTITUTETEACHER_H

#include "Professor.h"

class SubstituteTeacher : public Professor {
private:
    void print([[maybe_unused]] std::ostream &os) const override;
public:
    SubstituteTeacher();

    SubstituteTeacher(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear);

    SubstituteTeacher(const SubstituteTeacher& other);

    std::shared_ptr<Professor> clone() const override;

    virtual void createExam(const std::string& classSubject) override;

    friend std::ostream &operator<<(std::ostream &os, const SubstituteTeacher &other);

    ~SubstituteTeacher();
};


#endif //OOP_SUBSTITUTETEACHER_H
