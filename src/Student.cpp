//
// Created by Adrian Leventiu on 23.10.2022.
//

#include "../headers/Student.h"

Student::Student() = default;

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear, const std::vector<Subject>& subjects) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> birthDay = birthDay;
    this -> birthMonth = birthMonth;
    this -> birthYear = birthYear;
    this -> subjects = subjects;
    calculateOverallAverage();
}

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> email = email;
    this -> phoneNumber = phoneNumber;
    this -> group = group;
    this -> birthDay = birthDay;
    this -> birthMonth = birthMonth;
    this -> birthYear = birthYear;
}

Student::Student(const Student& other) : firstName{other.firstName}, lastName{other.lastName}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, birthDay{other.birthDay}, birthMonth{other.birthMonth}, birthYear{other.birthYear}, id{other.id}, overallAverage{other.overallAverage}, tuitionFree{other.tuitionFree}, subjects{other.subjects} {
//    std::cout << "Creating Student via copy-constructor.\n";
}

Student::~Student() {
//    std::cout << "Killing the student.\n";
}

void Student::set_id(const int& other) {
    this -> id = other;
    if(other > id_max)
        id_max = other;
}

void Student::calculateOverallAverage() {
    for(auto c : (this -> subjects))
        (this -> overallAverage) += c.get_average();
    (this -> overallAverage) /= (this -> subjects).size();
}

float Student::get_overallAverage() const { return this -> overallAverage; }

int Student::get_group() const { return this -> group; }

void Student::set_tuitionFree(const bool& status) { this -> tuitionFree = status; }

//int Student::get_id_max() { return id_max; } // never used, so it's commented

//void Student::set_subjects(const std::vector<Subject>& other) { this -> subjects = other; }

std::string Student::get_firstName() const { return this -> firstName; }

std::string Student::get_lastName() const { return this -> lastName; }

//std::vector<Subject> Student::get_subjects() { return this -> subjects; }

/*std::string Student::get_email() { return this -> email; }
std::string Student::get_phoneNumber() { return this -> phoneNumber; }
int Student::get_group() { return this -> group; }
bool Student::get_tuitionFree() { return this -> tuitionFree; } */

int Student::id_max = 0;