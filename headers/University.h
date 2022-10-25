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

    std::vector<Professor> professors;
    std::vector<Student> students;

public:
    University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<Professor>& professors, const std::vector<Student>& students);

    University(const University& other);

    University& operator = (const University &other) {
        name = other.name;
        subject = other.subject;
        foundationYear = other.foundationYear;
        professors = other.professors;
        students = other.students;
//        std::cout << "University Operator =\n";
        return *this;
    }

    ~University();

    /*std::string get_name();
    std::string get_subject();
    int get_foundationYear();
    std::vector<Student> get_students();*/

//    void print();

    void add_professor(const Professor& other);

    void add_student(const Student& other);

    void add_multipleProfessors(const std::vector<Professor>& other);

    void add_multipleStudents(const std::vector<Student>& other);

    void print_students();

//    void print_professors();

    void reclassify();

    void divisionIntoGroups();

    void print_groups();
};


#endif //OOP_UNIVERSITY_H