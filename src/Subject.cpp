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

void Subject::print() {
    std::cout << this -> subject << "\n" << "Grades: ";
    for(auto c : this -> grades)
        std::cout << c << " ";
    std::cout << "\n" << "Average: " << this -> average << "\n";
    std::cout << "Passed/Failed (1/0): " << this -> passed << "\n\n";
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

float Subject::get_average() { return this ->  average; }