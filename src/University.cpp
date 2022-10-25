//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/University.h"
#include <iostream>
#include <algorithm>
#include <vector>

University::University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<Professor>& professors, const std::vector<Student>& students) {
    this -> name = name;
    this -> subject = subject;
    this -> foundationYear = foundationYear;
    this -> professors = professors;
    this -> students = students;
}

University::University(const University& other) : name{other.name}, subject(other.subject), foundationYear{other.foundationYear}, professors{other.professors}, students{other.students} {
    std::cout << "Creating University via copy-constructor.\n";
}

University::~University() {
    std::cout << "Destructing the university.\n";
}

/*std::string University::get_name() { return this -> name; }
std::string University::get_subject() { return this -> subject; }
int University::get_foundationYear() { return this -> foundationYear; }
std::vector<Student> University::get_students() { return this -> students; }*/

/*void University::print() {
    std::cout << this -> name << " cu specializarea " << this -> subject << " a fost fondata in anul " << this -> foundationYear << ".\nAre un cumul de 500 profesori de exceptie printre care si " << (this -> professors)[2].get_name() << "\n";
}*/

void University::add_professor(const Professor& other) {
    (this -> professors).push_back(other);
}

void University::add_student(const Student& other) {
    (this -> students).push_back(other);
}

void University::add_multipleProfessors(const std::vector<Professor>& other) {
    for(auto& pr : other)
        (this -> professors).push_back(pr);
}

void University::add_multipleStudents(const std::vector<Student>& other) {
    for(auto& st : other)
        (this -> students).push_back(st);
}

void University::print_students() {
    for(auto c : this -> students)
        c.print();
}

//void University::print_professors() {
//    for(auto c : this -> professors)
//        c.print();
//}

void University::reclassify() {
    sort((this -> students).begin(), (this -> students).end(), [](Student s1, Student s2) { return(s1.get_overallAverage() > s2.get_overallAverage()); });
    unsigned count = 1;
    for(Student& c: this -> students) {
        c.set_id(int(count));
        c.set_tuitionFree((count++ <= ((this -> students).size() * 80 /100)));
    }
}

void University::divisionIntoGroups() {
    sort((this -> students).begin(), (this -> students).end(), [](Student s1, Student s2) {
        if(s1.get_group() == s2.get_group())
            if(s1.get_lastName() == s2.get_lastName())
                return s1.get_firstName() < s2.get_firstName();
            else return s1.get_lastName() < s2.get_lastName();
        else return(s1.get_group() < s2.get_group());
    });
}

void University::print_groups() {
    divisionIntoGroups();
    std::cout << "All groups found in this University:\n";

    int group = (this -> students)[0].get_group();
    std::cout << group << "\n\n\n";
    for(Student& c: this -> students) {
        if(c.get_group() != group) {
            group = c.get_group();
            std::cout << group << "\n\n\n";
        }
        c.print();
    }
}