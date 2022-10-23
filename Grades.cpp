//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "Grades.h"
#include <iostream>

Grades::Grades() = default;

Grades::Grades(const std::string& subject, const std::vector<int>& grades) {
    this -> subject = subject;
    this -> grades = grades;
    this -> average = calculateAverage();
    this -> passed = passedOrFailed();
}

Grades::Grades(const Grades& other) : subject{other.subject}, grades{other.grades}, average{other.average}, passed{other.passed} {
    std::cout << "Creating Grades via copy-constructor.\n";
}

Grades::~Grades() {
    std::cout << "Killing the grades.\n";
}

void Grades::print() {
    std::cout << this -> subject << "\n";
    for(auto c : this -> grades)
        std::cout << c << " ";
    std::cout << "\n" << this -> average << "\n";
    std::cout << this -> passed << "\n\n\n";
}

float Grades::calculateAverage() {
    float sum = 0;
    for(auto c : this -> grades)
        sum += c;
    return float(sum / (this -> grades).size());
}

bool Grades::passedOrFailed() {
    return this -> average >= 5;
}

//void Grades::sortGrades() { sort((this -> grades).begin(), (this -> grades).end()); }

float Grades::get_average() { return this ->  average; }