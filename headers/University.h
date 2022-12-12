//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_UNIVERSITY_H
#define OOP_UNIVERSITY_H

#include <iostream>
#include "Professor.h"
#include "Student.h"
#include "SeminarTeacher.h"

class University {
private:
    std::string name;
    std::string subject;
    int foundationYear;

    std::vector<std::shared_ptr<Professor>> professors;
    std::vector<Student> students;

public:
    University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<std::shared_ptr<Professor>>& professors, const std::vector<Student>& students);

    University(const University& other);

    friend void swap(University &u1, University &u2) {
        using std::swap;
        swap(u1.name, u2.name);
        swap(u1.subject, u2.subject);
        swap(u1.foundationYear, u2.foundationYear);
        swap(u1.professors, u2.professors);
        swap(u1.students, u2.students);
    }

    University& operator = (University other) {
        swap(*this, other);
        return *this;
    }

    ~University();

    /*std::string get_name();
    std::string get_subject();
    int get_foundationYear();
    std::vector<Student> get_students();*/

//    void print();

    void add_professor(const std::shared_ptr<Professor>& other);

    void add_student(const Student& other);

    void add_multipleProfessors(std::vector<std::shared_ptr<Professor>>& other);

    void add_multipleStudents(const std::vector<Student>& other);

    void print_students();

    void print_professors();

    void reclassify();

    void sortProfessors();

    void divisionIntoGroups();

    void print_groups();
};


#endif //OOP_UNIVERSITY_H