//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/Subject.h"
#include <iostream>

Subject::Subject() = default;

Subject::Subject(const std::string& subject, const std::vector<int>& grades) {
    this -> subject = subject;
    this -> grades = grades;
    this -> average = calculateAverage();
    this -> passed = passedOrFailed();
}

Subject::Subject(const Subject& other) : subject{other.subject}, grades{other.grades}, average{other.average}, passed{other.passed} {
//    std::cout << "Creating Subject via copy-constructor.\n";
}

Subject::~Subject() {
//    std::cout << "Killing the grades.\n";
}

float Subject::calculateAverage() {
    float sum = 0;
    for(auto c : this -> grades)
        sum += c;
    return float(sum / (this -> grades).size());
}

bool Subject::passedOrFailed() {
    return this -> average >= 5;
}

//void Subject::sortGrades() { sort((this -> grades).begin(), (this -> grades).end()); }

std::string Subject::get_subject() const { return this -> subject; }

std::vector<int> Subject::get_grades() const { return this -> grades; }

float Subject::get_average() const { return this ->  average; }

bool Subject::get_passed() const { return this -> passed; }

void Subject::addGrade(int grade) {
    if(grade > 0 && grade <= 10) {
        (this->grades).push_back(grade);
        (this->average) = calculateAverage();
    }
}