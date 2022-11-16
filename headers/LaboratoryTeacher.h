//
// Created by Adrian Leventiu on 16.11.2022.
//

#ifndef OOP_LABORATORYTEACHER_H
#define OOP_LABORATORYTEACHER_H


#include "Professor.h"
#include <memory>

class LaboratoryTeacher : public Professor {
private:
    void print([[maybe_unused]] std::ostream &os) const override;
public:
    LaboratoryTeacher();

    LaboratoryTeacher(const std::string& firstName, const std::string& lastName, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear);

    LaboratoryTeacher(const LaboratoryTeacher& other);

    std::shared_ptr<Professor> clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const LaboratoryTeacher &other);


    ~LaboratoryTeacher();
};


#endif //OOP_LABORATORYTEACHER_H
