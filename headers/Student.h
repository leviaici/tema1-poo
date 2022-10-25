//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H

#include <iostream>
#include <vector>
#include "Subject.h"

class Student {
private:
    std::string firstName = "Unknown";
    std::string lastName = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int group = 0;
    int age = 0;
    int id = 0;
    float overallAverage = .0;
    bool tuitionFree = false;

    std::vector<Subject> subjects;

public:
    Student();

    Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& age, const std::vector<Subject>& subjects);

    Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& age);

    Student(const Student& other);

    Student& operator = (const Student& other) {
        firstName = other.firstName;
        lastName = other.lastName;
        email = other.email;
        phoneNumber = other.phoneNumber;
        group = other.group;
        age = other.age;
        id = other.id;
        overallAverage = other.overallAverage;
        tuitionFree = other.tuitionFree;
        subjects = other.subjects;
        std::cout << "Student Operator =\n";
        return *this;
    }

    ~Student();

    void set_id(const int& other);

    void calculateOverallAverage();

    float get_overallAverage();

    int get_group();

    void print();

    void set_tuitionFree(const bool& status);

    std::string get_firstName();
    std::string get_lastName();
    /*std::string get_email();
    std::string get_phoneNumber();
    int get_group();
    int get_age();
    bool get_tuitionFree();*/
};


#endif //OOP_STUDENT_H
