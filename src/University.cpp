//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/University.h"
#include <iostream>
#include <algorithm>
#include <vector>

University::University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<Professor>& p, const std::vector<Student>& s) {
    this -> name = name;
    this -> subject = subject;
    this -> foundationYear = foundationYear;
    this -> p = p;
    this -> s = s;
}

University::University(const University& other) : name{other.name}, subject(other.subject), foundationYear{other.foundationYear}, p{other.p}, s{other.s} {
    std::cout << "Creating University via copy-constructor.\n";
}

University::~University() {
    std::cout << "Destructing the university.\n";
}

/*std::string University::get_name() { return this -> name; }
std::string University::get_subject() { return this -> subject; }
int University::get_foundationYear() { return this -> foundationYear; }
std::vector<Student> University::get_students() { return this -> s; }*/

void University::print() {
    std::cout << this -> name << " cu specializarea " << this -> subject << " a fost fondata in anul " << this -> foundationYear << ".\nAre un cumul de 500 profesori de exceptie printre care si " << (this -> p)[2].get_name() << "\n";
}

void University::add_professor(const Professor& other) {
    (this -> p).push_back(other);
}

void University::add_student(const Student& other) {
    (this -> s).push_back(other);
}

void University::add_vectorOfProfessors(const std::vector<Professor>& other) {
    for(auto& pr : other)
        (this -> p).push_back(pr);
}

void University::add_vectorOfStudents(const std::vector<Student>& other) {
    for(auto& st : other)
        (this -> s).push_back(st);
}

void University::print_students() {
    for(auto c : this -> s)
        c.print();
}

//void University::print_professors() {
//    for(auto c : this -> p)
//        c.print();
//}

void University::reclassify() {
    sort((this -> s).begin(), (this -> s).end(), [](Student s1, Student s2) { return(s1.get_overallAverage() > s2.get_overallAverage()); });
    unsigned count = 1;
    for(Student& c: this -> s) {
        c.set_id(int(count));
        c.set_tuitionFree((count++ <= ((this -> s).size() * 80 /100)));
    }
}