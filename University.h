//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_UNIVERSITY_H
#define OOP_UNIVERSITY_H

#include <iostream>
#include "Professor.h"
#include "Student.h"


class University {
private:
    std::string name;
    std::string subject;
    int foundationYear;

    std::vector<Professor> p;
    std::vector<Student> s;

public:
    University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<Professor>& p, const std::vector<Student>& s);

    University(const std::string& name, const std::string& subject, const int& foundationYear);

    University(const University& other);

    University& operator = (const University &other) {
        name = other.name;
        subject = other.subject;
        foundationYear = other.foundationYear;
        p = other.p;
        s = other.s;
        std::cout << "University Operator =\n";
        return *this;
    }

    ~University();

    /*std::string get_name();
    std::string get_subject();
    int get_foundationYear();
    std::vector<Student> get_students();*/

    void print() ;

    void add_professor(const Professor& other);

    void add_student(const Student& other);

    void add_vectorOfProfessors(const std::vector<Professor>& other);

    void add_vectorOfStudents(const std::vector<Student>& other);

    void print_students();

//    void print_professors();

    void reclassify();
};


#endif //OOP_UNIVERSITY_H